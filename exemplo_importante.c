#include <stdio.h>

int total_alunos;
#define QNTALUNOS total_alunos

int main() {
    int opcao;
    do {
      printf("Deseja proseguir?(1 - SIM / 0 - NÃO): ");
      scanf("%d", &opcao);
      if (opcao == 0) {
        break;
      } else {
        printf("Digite a quantidade de alunos da disciplina(20 <= ALUNOS <= 30): ");
      scanf("%d", &total_alunos);
  
        if (total_alunos < 20 || total_alunos > 30) {
          printf("Quantidade de alunos inválida!\n");
        } else {
          printf("Total de alunos matrículados na disciplina: %d\n", QNTALUNOS);
        }
      }
      
    } while (opcao != 0);
    return 0;
}
  
