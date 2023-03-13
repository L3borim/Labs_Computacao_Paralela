#include <stdio.h>

void multiplicaLinha(int matriz[3][4], int num, int linha);
void multiplicaColuna(int matriz[3][4], int num, int linha);
void imprimeMatriz(int matriz[3][4]);

int main(void) {
  int matriz[3][4] = {{1, 6, 4, 3},
                      {5, 1, 4, 2},
                      {0, 1, 2, 5}};
  int matriz1[3][4] = {{1, 6, 4, 3},
                      {5, 1, 4, 2},
                      {0, 1, 2, 5}};
  int num, linha, coluna;
  printf("Matriz inicial:\n");
  imprimeMatriz(matriz);
  printf("\nDigite o numero a ser multiplicado: ");
  scanf("%d",&num); //%s - sem espaço
  printf("Digite a linha: ");
  scanf("%d",&linha);
  printf("Digite a coluna: ");
  scanf("%d",&coluna);
  multiplicaLinha(matriz, num, linha);
  printf("\n\n");
  multiplicaColuna(matriz1, num, coluna);
  
  return 0;
}

void multiplicaLinha(int matriz[3][4], int num, int linha){
  printf("\n\nMultiplicacao em linha:");
  linha = linha-1;
  for(int i=0;i<4;i++){
    //[0][i]
    matriz[linha][i] = matriz[linha][i] * num;
  }
  imprimeMatriz(matriz);
}

void multiplicaColuna(int matriz[3][4], int num, int coluna){
  coluna = coluna -1;
  printf("\n\nMultiplicacao em coluna:");
  for(int i=0;i<4;i++){
    //[0][i]
    matriz[i][coluna] = matriz[i][coluna] * num;
  }
  imprimeMatriz(matriz);
}

void imprimeMatriz(int matriz[3][4]){
  for(int i=0;i<3;i++){
    printf("\n");
    for(int j=0;j<4;j++){
      printf("%d ",matriz[i][j]);
    }
  }
}
