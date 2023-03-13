#include <stdio.h>
#include <stdlib.h>
#define N 3

void modulo(int M[][N], int lin, int col) {
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            if (M[i][j] < 0) {
                M[i][j] = abs(M[i][j]);
            }
        }
    }
}

void imprime_matriz(int M[][N], int lin, int col) {
    int i, j;
    for (i = 0; i < lin; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}


int main() {
  int M[N][N] = {{-3, 5, 2}, {4, 1, -7}, {6, -9, 8}};

  printf("Antes da substituicao: " "\n");
  imprime_matriz(M, N, N);
  printf("\n");
  printf("Substituindo pelo seu modulo: " "\n");
  modulo(M, N, N);

  imprime_matriz(M, N, N);

  return 0;

}
