// ALUNO: DOUGLAS CUNHA DE JESUS

#include <stdio.h>
#include "string.h"
#include "stdlib.h"

// Valores pré-definidos.
#define TOTAL_ALUNOS 3
#define TOTAL_FALTAS 36

// Contador de matrículas a nível global.
int count = 0;

FILE *fptr;


// Lista de funções pré-definidas.
void exibeMenu();

void cadastraAluno(int matricula, int faltas, double notas[], int codDaTurma);

void listarAlunos();

void atualizarDados(int matricula, int faltas);

void listarAprovados();

void listarReprovadosMedia();

void listarReprovadosFalta();

void removerAluno(int matricula);

// Registro que permite trabalhar com variáveis de tipos diferentes.
typedef struct {
    int alunos[TOTAL_ALUNOS];
    int faltas[TOTAL_FALTAS];
    int codTurma;
    double notas[TOTAL_ALUNOS][4];
    char nome[][TOTAL_ALUNOS];
} info_pessoa;

// Criamos uma variavel do tipo info_pessoa.
info_pessoa info;

// Função main executa o programa.
int main() {
    int operacao;
    int matriculaAluno;
    int faltasAluno;
    int codTurma;
    int flag = 0;
    double notasAluno[4];

    do
    {
      // Chama a função menu
      exibeMenu();
      // Solicita e armazena a operação solicitada
      printf("Digite a operacao desejada: ");
      scanf("%d", &operacao);

      switch (operacao) {
        case 0:
            break;

        case 1:
            printf("Digite sua matrícula(Ex: 20220XX): ");
            scanf("%d", &matriculaAluno);

            // Analisa se a matrícula já existe.
            for (int i = 0; i < TOTAL_ALUNOS; i++) {
                // Verifica se a matrícula já existe.
                if (info.alunos[i] == matriculaAluno) {
                    printf("Matrícula já cadastrada!\n");
                    flag = 1;
                    break;
                }

                if (count >= TOTAL_ALUNOS) {
                    printf("Número máximo de matrículas atingido!\n");
                    flag = 1;
                    break;
                }
            }
            // Caso a matrícula não exista, o programa continua.
            if (flag == 0) {
                printf("Digite o código da turma(Ex: 334): ");  
                scanf("%d", &codTurma);

                // Solicita as faltas e as armazena.
                printf("Digite a quantidade de faltas: ");
                scanf("%d", &faltasAluno);

                // Solicita as notas e as armazena.
                for (int i = 0; i < 4; i++) {
                    printf("Digite a nota %d: ", i + 1);
                    scanf("%lf", &notasAluno[i]);
                }
                // Limpa o buffer do teclado.
                setbuf(stdin, NULL);
                cadastraAluno(matriculaAluno, faltasAluno, notasAluno, codTurma);
            } else {
                // Reseta a flag.
                flag = 0;
            }
            break;

            case 2:
                removerAluno(matriculaAluno);
                break;

            case 3:
                atualizarDados(matriculaAluno, faltasAluno);
                break;

            case 4:
                listarAlunos();
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

    return 0;
}

// Exibe o menu de apções disponíveis.
void exibeMenu() {
    printf("\n########################### Menu ###########################");
    printf("\n1 - Cadastrar aluno\n2 - Remover aluno\n3 - Atualizar dados\n4 - Listar alunos cadastrados\n5 - Listar alunos aprovados\n6 - Listar alunos reprovados por média\n7 - Listar alunos reprovados por falta\n0 - Sair\n");
    printf("########################### Menu ###########################\n");
}

// Realiza o cadastro do aluno.
void cadastraAluno(int matricula, int faltas, double notas[], int codDaTurma) {
    int operacao;

    // Limpa o buffer do teclado.
    setbuf(stdin, NULL);
    printf("\nDeseja prosseguir?(1 - Sim / 0 - Não): ");
    scanf("%d", &operacao);
    // Limpa o buffer do teclado.
    setbuf(stdin, NULL);

    if (operacao == 0) {
        printf("\nOperação cancelada!\n");
    } else {
        for (int i = 0; i < TOTAL_ALUNOS; ++i) {
            
            if (info.alunos[i] != '\0') {
                // Pulamos para o próximo elemento caso o índice não seja nulo.
                continue;
            } else {
                // Armazena a matrícula.
                info.alunos[i] = matricula;

                // Passamos o código da turma.
                info.codTurma = codDaTurma;

                
                printf("Digite o seu nome completo: ");
                /* A função fgets recebe uma string, pré-defini o tamanho do nome como sendo no máximo 100 caracteres. Por fim, a função recebe o valor digitado e armazena na matriz nome.*/
                fgets(info.nome[i], 100, stdin);
                // Limpa o buffer do teclado.
                setbuf(stdin, NULL);

                // Armazena as faltas.
                info.faltas[i] = faltas;

                // Percorre a matriz e solicita/armazena as notas.
                for (int j = 0; j < 4; ++j) {
                    // Armazena as notas.
                    info.notas[i][j] = notas[j];
                }

                
                fptr = fopen("alunos.txt", "a");
                if (fptr == NULL) {
                    printf("Error!\n");
                    exit(1);
                }

                fprintf(fptr, "Matricula: %i\n", info.alunos[i]);
                fprintf(fptr, "Código da turma: %i\n", info.codTurma);
                fprintf(fptr, "Nome: %s", info.nome[i]);
                fprintf(fptr, "Faltas: %i\n", info.faltas[i]);

                for (int j = 0; j < 4; ++j) {
                    fprintf(fptr, "Nota(s): %.1lf\n", info.notas[i][j]);
                }
                fprintf(fptr, "\n");
                
                count++;
                break;
            }
        }
    }

    fclose(fptr);
}

// Remove uma determinada matrícula.
void removerAluno(int matricula) {
    int opcao;
    int flag = 0;
    do {
        printf("\nExibindo todas as matrículas\n");
        // Exibe todas as matrículas no sistema.
        listarAlunos();
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
                    // A função strcpy altera o valor da string nome.
                    strcpy(info.nome[i], "\0");
                    // Define o valor das faltas como nulo(vazio)
                    info.faltas[i] = '\0';
                    // Define o código da turma como sendo nulo(vazio).
                    info.codTurma = '\0';

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
            }
        }
    } while (opcao != 0);
}

// Lista todas as matrículas existentes.
void listarAlunos() {
    for (int i = 0; i < TOTAL_ALUNOS; ++i) {
        // Analisa para ver se o vetor está vazio.
        if (info.alunos[i] != '\0') {
            printf("\nMatrícula: %d\n", info.alunos[i]);
            printf("Código da turma: %i\n", info.codTurma);
            printf("Nome: %s", info.nome[i]);
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
        if (info.alunos[i] != '\0') {
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
                printf("Código da turma: %i\n", info.codTurma);
                printf("Nome: %s", info.nome[i]);
                printf("Faltas: %d\n", info.faltas[i]);
                printf("Frequência: %.1lf%%\n", faltas);
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
                printf("Código da turma: %i\n", info.codTurma);
                printf("Nome: %s", info.nome[i]);
                printf("Média: %.1lf\n", media);
                printf("Situação: Reprovado por média\n");
                media = 0;
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
                printf("Código da turma: %i\n", info.codTurma);
                printf("Nome: %s", info.nome[i]);
                printf("Frequência: %.1lf%%\n", faltas);
                printf("Situação: Reprovado por faltas\n");
            }
        }
    }
}

// Atualiza dados do aluno.
void atualizarDados(int matricula, int faltas) {
    int opcao;
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