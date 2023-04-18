#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int m = 5, n = 5; 
double A[][5] = {{1, 2, 3, 4, 5}, {4, 5, 6, 7, 8}, {9, 10, 11, 12, 13}, {14,15,16, 17, 18}, {19,20,21, 22, 23}}; // matriz A
double x[] = {1, 2, 3, 4, 5}; // vetor x
double y[] = {0, 0, 0, 0, 0}; // vetor y (resultado)


int main() {
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
    y[i] += A[i][j]*x[j];
  }
  }
  printf("Resultado da multiplicação:\n");
  for(int i=0;i<m;i++) printf(" %.2f |",y[i]);
   return 0;
  printf("\n");
}
