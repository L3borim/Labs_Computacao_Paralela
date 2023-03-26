#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  int shmid;
  key_t key = 1235;
  int *shared_var;
  int pid;

  // Cria um segmento de memória compartilhada e verifica se deu certo
  shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);

  // Anexa o segmento de memória compartilhada ao processo
  shared_var = shmat(shmid, NULL, 0);
  // Variável compartilhada começa com 1
  *shared_var = 1;

  // Imprime o valor inicial da variável compartilhada
  printf("\nValor inicial da variável compartilhada: %d\n", *shared_var);

  pid = fork();
  if (pid < 0) {
    perror("fork");
    exit(1);
  } else if (pid == 0) {
    // Processo filho
    printf("Processo filho iniciado\n");

    //Ver se é necessário fazer isso sempre antes de mudar o valor da variavel, porque funciona dos dois jeitos
    // Anexa o segmento de memória compartilhada ao processo
    shared_var = shmat(shmid, NULL, 0);
    // Adiciona 2 ao valor da variável compartilhada
    *shared_var += 2;

    // Imprime o novo valor da variável compartilhada
    printf("\nNovo valor da variável ao adicionar o numero 2 (processo filho): %d\n",
           *shared_var);

    //Ver se é necessário ou se é uma boa prática
    // Libera o segmento de memória compartilhada
    /*if (shmdt(shared_var) == -1) {
      perror("shmdt");
      exit(1);
    }*/

    exit(0);
  } else {
    // Processo pai
    printf("Processo pai esperando pelo processo filho\n");

    // Espera pelo processo filho terminar
    wait(NULL);

  
    // Anexa o segmento de memória compartilhada ao processo
    shared_var = shmat(shmid, NULL, 0);
    // Multiplica o valor da variável compartilhada por 4
    *shared_var *= 4;

    // Imprime o novo valor da variável compartilhada
    printf("Novo valor da variável ao multiplicar pelo valor 4 (processo pai): %d\n",
           *shared_var);

    //Ver se é necessário ou se é uma boa prática
    // Libera o segmento de memória compartilhada
    /*if (shmdt(shared_var) == -1) {
      perror("shmdt");
      exit(1);
    }*/

    // Remove o segmento de memória compartilhada
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
      perror("shmctl");
      exit(1);
    }
  }

  return 0;
}

