#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int** geraMatrizQuadrada(int n);
int encontrarMenor(int** matriz, int n, int *menorValor);
void printMatriz(int** matriz, int n);

int main()
{       
        int tamanho=5, menor;
        int** matriz = geraMatrizQuadrada(tamanho);
        printMatriz(matriz, tamanho);

        printf("\nO menor elemento da matriz esta na linha %d\n", encontrarMenor(matriz, tamanho, &menor));
        //printf("\nMenor Elemento: %d", menor);

        free(matriz);
        return 0;
 

}

int encontrarMenor(int** matriz, int n, int *menorValor)
{
    int linhaMenor=0, menor = matriz[0][0];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matriz[i][j] < menor){
                menor = matriz[i][j];
                linhaMenor = i;
            }
        }
    }
    *menorValor = menor;
    return linhaMenor;
}

int** geraMatrizQuadrada(int n)
{
    srand(time(NULL));

    int** M  = calloc(n, sizeof(int*));
    for(int i=0; i < n; i++){
        M[i] = calloc(n,sizeof(int));
        for(int j=0; j<n; j++){
            M[i][j] = i*n + j;
        }
    }

    for(int l=0; l<n; l++){
        for(int c=0; c<n; c++){
            int lin_aleatoria = rand() % n;
            int col_aleatoria = rand() % n;

            int temp = M[l][c];
            M[l][c] = M[lin_aleatoria][col_aleatoria];
            M[lin_aleatoria][col_aleatoria] = temp;
        }
    }

    return M;
}

void printMatriz(int** matriz, int n)
{
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

