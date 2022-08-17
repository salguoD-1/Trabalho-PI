#include "stdio.h"

#define TOTAL_ALUNOS 30
#define TOTAL_FALTAS 36

void exibeMenu();
void cadastraAluno();
void listaAlunos();

typedef struct {
    int alunos[TOTAL_ALUNOS];
    int faltas[TOTAL_ALUNOS];
    double notas[TOTAL_ALUNOS][4];
} info_pessoa;

// Criamos um objeto do tipo info.
info_pessoa info;

int main() {
    exibeMenu();
    return 0;
}

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
            case 1:
                cadastraAluno();
                break;

            case 4:
                listaAlunos();
                break;

            default:
                printf("Operação inválida!\n");
                break;
        }
    } while (operacao != 0);
}

void cadastraAluno() {
    int i = 0;
    int matricula;
    int faltas;
    double notas;
    int operacao;

    do {
        printf("Deseja adicionar uma matrícula?(1 - Sim / 0 - Não): ");
        scanf("%d", &operacao);

        switch (operacao) {
            case 1:
                printf("Digite sua matrícula(Ex: 20220XX): ");
                scanf("%d", &matricula);

                for (int j = 0; j < TOTAL_ALUNOS; ++j) {
                    if (matricula == info.alunos[j]) {
                        printf("Matrícula já existente!\n");
                        break;
                    } else {
                        // Adiciona a matrícula.
                        info.alunos[i] = matricula;

                        // Solicita a quantidade de faltas e adiciona ao vetor.
                        printf("Digite a quantidade de faltas: ");
                        scanf("%d", &faltas);
                        info.faltas[i] = faltas;

                        // Solicita a quantidade de notas e adiciona a matriz.
                        for (int k = 0; k < 4; ++k) {
                            printf("Digite a nota %d: ", k + 1);
                            scanf("%lf", &notas);
                            info.notas[i][k] = notas;
                        }
                        i++;
                        break;
                    }
                }

                break;

            case 0:
                break;

            default:
                printf("Operação invalida!\n");
        }
    } while (operacao != 0);
}

void listaAlunos() {
    for (int i = 0; i < TOTAL_ALUNOS; ++i) {
        if (info.alunos[i] != '\0') {
            printf("\nMatrícula: %d\n", info.alunos[i]);
            printf("Faltas: %d\n", info.faltas[i]);

            for (int j = 0; j < 4; ++j) {
                printf("Nota %d = %.1lf\n", j + 1, info.notas[i][j]);
            }
        }
    }
}