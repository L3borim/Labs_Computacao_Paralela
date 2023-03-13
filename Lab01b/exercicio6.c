#include <stdio.h>
#define N 3

void transposta(int matriz[][N], int transposta[][N], int linhas, int colunas) {
    int i, j;
    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            transposta[j][i] = matriz[i][j];
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
    int M[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int T[N][N];

    transposta(M, T, N, N);

    // Imprime a matriz original
    printf("Matriz original:\n");
    imprime_matriz(M, N, N);
    printf("\n");

    // Imprime a matriz transposta
    printf("Matriz transposta:\n");
    imprime_matriz(T, N, N);

    return 0;
}

