#include <stdio.h>

void exibeMenu();
void cadastroAluno(int id_matricula);
// void atualizaDados(int id_matricula);

int main() {
    int escolhaMenu;
    int cadastro;

    do {
        // Chamamos a função para exibir o menu de escolha.
        exibeMenu();
        // Lê a opção selecionada pelo usuário.
        scanf("%d", &escolhaMenu);
        // Caso base onde o usuário encerra o programa.
        if (escolhaMenu == 0) {
            break;
        }

        // Usei a estrutura switch para chamar cada função para executar sua determinada tarefa.
        switch (escolhaMenu) {
            case 1:
                printf("Digite a sua matrícula(ex: 20220XX): ");
                scanf("%d", &cadastro);
                cadastroAluno(cadastro);
            break;

            case 3:
                printf("Digite a sua matrícula(ex: 20220XX): ");
                scanf("%d", &cadastro);
                cadastroAluno(cadastro);

            default:
                printf("Teste\n");
                break;
        }
    }while (escolhaMenu != 0);


    return 0;
}

void exibeMenu() {
    printf("#################### Menu ####################\n");
    printf("Escolha uma opção abaixo\n");
    printf("1 - Cadastar aluno\n2 - Remover aluno\n3 - Atualizar dados\n4 - Listar alunos\n5 - Listar alunos aprovados\n6 - Listar alunos reprovados por média\n7 - Listar alunos reprovados por falta\n0 - Sair\n");
    printf("#################### Menu ####################\n");
    printf("Digite sua escolha: ");
}

void cadastroAluno(int id_matricula) {
    int matricula[30];
    int faltas[30];
    double notas[30][4];
    int flag;

    // Checa se a matrícula já existe.
    for (int i = 0; i < 30; i++) {
        if (id_matricula == i) {
            printf("Matrícula já existente!\n");
        }
    }

    // Checa o tamanho do array.
    if (sizeof(matricula) / sizeof(int) == 29) {
        printf("Número máximo de matrículas atingido!\n");
    } else {
        // Checa se há vagas no array, caso haja adiciona uma nova matrícula, faltas e notas.
        for (int i = 0; i < 30; i++) {
            if (matricula[i] == NULL) {
                // Cadastra o usuário.
                printf("Digite a sua matrícula(ex: 20220XX): ");
                scanf("%d", &matricula[i]);
                // Cadastro as faltas.
                printf("Digite o total de faltas: ");
                scanf("%d", &faltas[i]);

                for (int j = 0; j < 4; j++) {
                    printf("Digite a nota %d: ", j + 1);
                    scanf("%lf", &notas[i][j]);
                }

                // Precisamos encerrar a estrutura, para isso fiz uma pequena flag.
                printf("Deseja continuar?(1 - Sim / 0 - Não): ");
                scanf("%d", &flag);

                if (flag == 0) {
                    break;
                } 
            }
        }
    }


}

// void atualizaDados(int id_matricula) {
//     for (int i = 0; i < 30; i++) {
//         if (cadastroAluno(id_matricula) == 1) {
//             printf("");
//         }
//     }
    
// }