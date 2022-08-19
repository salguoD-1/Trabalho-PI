// Aluno: DOUGLAS CUNHA DE JESUS
// Matrícula: 202200059722

#include "stdio.h"

// Valores pré-definidos.
#define TOTAL_ALUNOS 2
#define TOTAL_FALTAS 36
// Contador de matrículas a nível global.
int count = 0;

// Lista de funções pré-definidas.
void exibeMenu();

void cadastraAluno();

void listaAlunos();

void atualizarDados();

void listarAprovados();

void listarReprovadosMedia();

void listarReprovadosFalta();

void removerAluno();

// Registro que permite trabalhar com varíveis de tipos diferentes.
typedef struct {
    int alunos[TOTAL_ALUNOS];
    int faltas[TOTAL_FALTAS];
    double notas[TOTAL_ALUNOS][4];
} info_pessoa;

// Criamos uma variavel do tipo info_pessoa.
info_pessoa info;

// Função main executa o programa.
int main() {
    // Realiza a chamada do menu.
    exibeMenu();
    return 0;
}
// Exibe o menu de apções disponíveis.
void exibeMenu() {
    int operacao;

    do {
        printf("\n########################### Menu ###########################");
        printf("\n1 - Cadastrar aluno\n2 - Remover aluno\n3 - Atualizar dados\n4 - Listar alunos cadastrados\n5 - Listar alunos aprovados\n6 - Listar alunos reprovados por média\n7 - Listar alunos reprovados por falta\n0 - Sair\n");
        printf("########################### Menu ###########################\n");
        // Solicita a operação e armazena o valor.
        printf("\nDigite sua escolha: ");
        scanf("%d", &operacao);

        switch (operacao) {
            case 0:
                break;
            case 1:
                cadastraAluno();
                break;

            case 2:
                removerAluno();
                break;

            case 3:
                atualizarDados();
                break;

            case 4:
                listaAlunos();
                break;

            case 5:
                listarAprovados();
                break;

            case 6:
                listarReprovadosMedia();
                break;

            case 7:
                listarReprovadosFalta();
                break;

            default:
                printf("Operação inválida!\n");
                break;
        }
    } while (operacao != 0);
}

// Realiza o cadastro do aluno.
void cadastraAluno() {
    int matricula;
    int faltas;
    double notas;
    int operacao;

    do {
        printf("\nDeseja adicionar uma matrícula?(1 - Sim / 0 - Não): ");
        scanf("%d", &operacao);

        if (operacao == 0) {
            break;
        } else {
            printf("Digite sua matrícula(Ex: 20220XX): ");
            scanf("%d", &matricula);

            if (count >= TOTAL_ALUNOS) {
                printf("Número máximo de matrículas atingido!\n");
                break;
            }

            for (int i = 0; i < TOTAL_ALUNOS; ++i) {
                if (info.alunos[i] == matricula) {
                    printf("\nMatrícula ja existente!");
                    break;
                    // Analisa se o total de matrículas excede o total permitido.
                }
                if (info.alunos[i] != '\0') {
                    // Pulamos para o próximo elemento caso o índice não seja nulo.
                    continue;
                } else {
                    // Armazena a matrícula.
                    info.alunos[i] = matricula;
                    // Solicita as notas e as armazena.
                    printf("Digite a quantidade de faltas: ");
                    scanf("%d", &faltas);
                    info.faltas[i] = faltas;

                    // Percorre a matriz e solicita/armazena as notas.
                    for (int j = 0; j < 4; ++j) {
                        printf("Digite a nota %d: ", j + 1);
                        scanf("%lf", &notas);
                        info.notas[i][j] = notas;
                    }
                    count++;
                    break;
                }
            }
        }

    } while (operacao != 0);
}

// Remove uma determinada matrícula.
void removerAluno() {
    int matricula;
    int opcao;
    int flag = 0;
    do {
        printf("\nExibindo todas as matrículas\n");
        // Exibe todas as matrículas no sistema.
        listaAlunos();
        // Solicita uma opção.
        printf("\nDeseja excluir alguma das matrículas?(1 - Sim / 0 - Não): ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            break;
        } else {
            // Solicita a matrícula.
            printf("\nDigite a matrícula a ser removida: ");
            scanf("%d", &matricula);

            for (int i = 0; i < TOTAL_ALUNOS; ++i) {
                // Analisa se a matrícula faz parte do vetor.
                if (info.alunos[i] == matricula) {
                    // Define o valor da matrícula como nulo(vazio)
                    info.alunos[i] = '\0';
                    // Define o valor das faltas como nulo(vazio)
                    info.faltas[i] = '\0';
                    // Define o valor das notas como nulo(vazio)
                    for (int j = 0; j < 4; ++j) {
                        info.notas[i][j] = '\0';
                    }
                    // Decrementamos o contador para poder ceder uma vaga de matrícula no vetor.
                    count--;
                    // Flag responsável por setar false caso a matrícula exista.
                    flag = 0;
                    break;
                }
                // Caso a matrícula não seja igual, passamos para a próxima matrícula.
                else if (info.alunos[i] != matricula) {
                    // Flag responsável por setar true caso a matrícula não exista.
                    flag = 1;
                    continue;
                }
            }
            // Flag que é responsável por exibir se uma matrícula não foi encontrada.
            if (flag) {
                printf("Matrícula não encontrada!\n");
                break;
            }
        }
    } while (opcao != 0);
}

// Atualiza dados do aluno.
void atualizarDados() {
    int matricula;
    int opcao;
    int faltas;
    int qlNota;
    double notas;

    do {
        printf("Digite uma opção(1 - Alterar as faltas / 2 - Alterar as notas / 0 - Sair): ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            break;
        }

        printf("Digite a sua matrícula(Ex: 20220XX): ");
        scanf("%d", &matricula);

        switch (opcao) {
            case 1:
                for (int i = 0; i < TOTAL_ALUNOS; ++i) {
                    if (info.alunos[i] == matricula) {
                        printf("Digite o total de faltas para realizar a alteração: ");
                        scanf("%d", &faltas);
                        info.faltas[i] = faltas;
                    }
                }
                break;

            case 2:
                for (int i = 0; i < TOTAL_ALUNOS; ++i) {
                    if (info.alunos[i] == matricula) {
                        printf("Qual nota você deseja alterar?(1 - Primeira nota / 2 - Segunda nota / 3 - Terceira nota / 4 - Quarta nota / 0 - Todas as notas\n: ");
                        scanf("%d", &qlNota);

                        switch (qlNota) {
                            case 1:
                                for (int j = 0; j < 1; ++j) {
                                    printf("Digite a primeira nota: ");
                                    scanf("%lf", &notas);
                                    info.notas[i][qlNota - 1] = notas;
                                }
                                break;
                            case 2:
                                for (int j = 1; j < 2; ++j) {
                                    printf("Digite a segunda nota: ");
                                    scanf("%lf", &notas);
                                    info.notas[i][qlNota - 1] = notas;
                                }
                                break;
                            case 3:
                                for (int j = 2; j < 3; ++j) {
                                    printf("Digite a terceira nota: ");
                                    scanf("%lf", &notas);
                                    info.notas[i][qlNota - 1] = notas;
                                }
                                break;
                            case 4:
                                for (int j = 3; j < 4; ++j) {
                                    printf("Digite a quarta nota: ");
                                    scanf("%lf", &notas);
                                    info.notas[i][qlNota - 1] = notas;
                                }
                                break;
                            case 0:
                                for (int j = 0; j < 4; ++j) {
                                    printf("Digite a nota %d: ", j + 1);
                                    scanf("%lf", &notas);
                                    info.notas[i][j] = notas;
                                }
                                break;
                            default:
                                printf("Opção inválida!\n");
                                break;
                        }
                    }
                }
                break;
        }
    } while (opcao != 0);
}

// Lista todas as matrículas existentes.
void listaAlunos() {
    for (int i = 0; i < TOTAL_ALUNOS; ++i) {
        // Analisa para ver se o vetor está vazio.
        if (info.alunos[i] != '\0') {
            printf("\nMatrícula: %d\n", info.alunos[i]);
            printf("Faltas: %d\n", info.faltas[i]);

            for (int j = 0; j < 4; ++j) {
                printf("Nota %d = %.1lf\n", j + 1, info.notas[i][j]);
            }
        } else {
            // Caso o elemento no vetor estiver vazio, pula para a próxima matrícula.
            continue;
        }
    }
}

// Lista todos os aprovados.
void listarAprovados() {
    double faltas;
    double media = 0;
    for (int i = 0; i < TOTAL_ALUNOS; ++i) {
        // Analisa se o vetor está vazio.
        if (info.alunos[i] != '\O') {
            // Fazemos o somatório das notas.
            for (int j = 0; j < 4; ++j) {
                media += info.notas[i][j];
            }
            // Armazenamos a média.
            media /= 4;

            // Armazena o total de faltas.
            faltas = info.faltas[i];

            // Cálculo de frequência do aluno.
            faltas = ((36 - faltas) / 36) * 100;

            // Condição de aprovação.
            if (media >= 7 && faltas >= 60) {
                printf("\nMatrícula: %d\n", info.alunos[i]);
                printf("Faltas: %d\n", info.faltas[i]);
                printf("Frequência: %.1lf%\n", faltas);
                printf("Média: %.1lf\n", media);
                printf("Situação: Aprovado\n");
                // Resetamos a variável média.
                media = 0;
            }
        }
    }
}

// Lista todos os reprovados por média.
void listarReprovadosMedia() {
    double media;
    for (int i = 0; i < TOTAL_ALUNOS; ++i) {
        // Analisa se o vetor alunos é nulo.
        if (info.alunos[i] != '\0') {
            for (int j = 0; j < 4; ++j) {
                media += info.notas[i][j];
            }
            // Armazena a média final.
            media /= 4;

            // Condição de reprovação.
            if (media < 7) {
                printf("\nMatrícula: %d\n", info.alunos[i]);
                printf("Média: %.1lf\n", media);
                printf("Situação: Reprovado por média\n");
            }
        }
    }
}

// Lista todos os reprovados por falta.
void listarReprovadosFalta() {
    double faltas;

    for (int i = 0; i < TOTAL_ALUNOS; ++i) {
        // Analisa se o vetor é nulo(vazio).
        if (info.alunos[i] != '\0') {
            // Armazena as faltas.
            faltas = info.faltas[i];
            // Calcula a frequência.
            faltas = ((36 - faltas) / 36) * 100;
            // Condição de reprovação.
            if (faltas < 60) {
                printf("\nMatrícula: %d\n", info.alunos[i]);
                printf("Frequência: %.1lf%\n", faltas);
                printf("Situação: Reprovado por faltas\n");
            }
        }
    }
}

