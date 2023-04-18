#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define MAX 4
#define M 5
#define N 5

double **A;
double *x, *y;
int thread_count = 3; // número de threads a serem usadas
pthread_mutex_t mutex;

void *Pth_mat_vect(void* rank) {
   long my_rank = (long) rank;

   int i, j, k;
   int local_m = M/thread_count;
   int my_first_row;
  
   int my_last_row;
   if(my_rank < (M % thread_count)){	
      local_m++;
      my_first_row = my_rank*local_m;
      my_last_row = (my_rank+1)*local_m - 1;
   }else{ 
      my_first_row = my_rank*local_m + (M % thread_count);
      my_last_row = (my_rank+1)*local_m - 1 + (M % thread_count);
   }
  //printf("teste %d ",my_first_row);

  for (i = my_first_row; i <= my_last_row; i++) {
      double aux = 0.0;
      for (j = 0; j < N; j++)
          aux += A[i][j]*x[j];
     pthread_mutex_lock(&mutex);
     y[i] = aux;
      //A[i][j] = y[i];
     pthread_mutex_unlock(&mutex);
   }

   return NULL;
}

double** gerarMatriz(int LIN, int COL){
   double** matriz = calloc(LIN, sizeof(double*));
   double valor = 1;
   for(int i=0; i < LIN; i++)
   {
      double* linha = calloc(COL, sizeof(double));
      for(int j=0; j < COL; j++){
        linha[j] = valor;
        valor++;
      }
      matriz[i] = linha;
   }
   return matriz;
}

void preencheVetor(double* vetor){
  for(int i=0; i < N; i++)
  {
    vetor[i] = i+1;    
  }
}

void printMatriz(double** matriz, int linhas, int colunas)
{
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }
}

void printVet(double* vet){
  for(int i=0; i < N; i++)
  {
    printf("%.2f ", vet[i]);    
  }
  printf("\n");
}

int main() {
  A = gerarMatriz(M, N);  // matriz A
  x = calloc(N, sizeof(double)); // vetor x
  y = calloc(N, sizeof(double)); // vetor y (resultado)
  preencheVetor(x);
  
  //printMatriz(A, M, N);
  //printVet(x);
  
  
  pthread_t* thread_handles;
  thread_handles = malloc(thread_count*sizeof(pthread_t));
  pthread_mutex_init(&mutex, NULL);
  long thread;
  for (thread = 0; thread < thread_count; thread++)
  {
    pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void*) thread);
  }
  
  for (thread = 0; thread < thread_count; thread++)
    pthread_join(thread_handles[thread], NULL);
  
  free(thread_handles);
  free(A);
  pthread_mutex_destroy(&mutex);
  
  printf("Resultado da multiplicação:\n");
  for (int i = 0; i < M; i++){
    printf(" %.2f |", y[i]);
  }
  printf("\n");

   return 0;
}
