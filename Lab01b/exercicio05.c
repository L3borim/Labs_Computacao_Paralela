#include <stdio.h>
#include <stdlib.h>

int** geraMatriz(int lin, int col);
void printMatriz(int** matriz, int lin, int col);

int main()
{
    int linhas, colunas, **matriz;

    printf("**  Multiplicando a matriz  **\n");
    printf("\nInsira a quantidade de linhas e colunas: \n");
    
    printf("Numero de linhas: ");
    scanf("%d", &linhas);
    printf("Numero de colunas: ");
    scanf("%d", &colunas);
    
    matriz = geraMatriz(linhas, colunas);
    printMatriz(matriz, linhas, colunas);

    int pos_option;
    printf("\nQual multiplicacao você deseja realizar?\n-> Digite 0 para LINHA\n-> Digite 1 para COLUNA\nSua escolha: ");
    scanf("%d", &pos_option);

    if(pos_option == 0){
        int L, valor;
        printf("\nDigite a linha a ser multiplicada: ");
        scanf("%d", &L);
        printf("\nDigite um valor para ser multiplicado pelos valores na linha: ");
        scanf("%d", &valor);

        for(int j=0; j<colunas; j++){
            matriz[L][j] = valor*matriz[L][j];
        }
    }
    else if(pos_option == 1){
        int C, valor;
        printf("\nDigite a coluna a ser multiplicada: ");
        scanf("%d", &C);
        printf("\nDigite um valor para ser multiplicado pelos valores na coluna: ");
        scanf("%d", &valor);

        for(int i=0; i<linhas; i++){
            matriz[i][C] = valor*matriz[i][C];
        }
    }
    
    printf("\nMatriz Resultado: \n");
    printMatriz(matriz, linhas, colunas);
    return 0;
}

int** geraMatriz(int lin, int col)
{
    int** M  = calloc(lin, sizeof(int*));
    for(int i=0; i < lin; i++){
        M[i] = calloc(col,sizeof(int));
        for(int j=0; j<col; j++){
            M[i][j] = i*lin+j*col;
        }
    }
    return M;
    
}
void printMatriz(int** matriz, int lin, int col)
{
    for(int i=0; i < lin; i++){
        for(int j=0; j < col; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
