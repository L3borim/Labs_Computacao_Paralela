#include <stdio.h>

void somaLinhas(int matriz[3][4]);
void multiplicaLinhas(int matriz[3][4]);
void imprimeMatriz(int matriz[3][4]);

int main(void) {
  int matriz[3][4] = {{1, 6, 4, 3},
                      {5, 1, 4, 2},
                      {0, 1, 2, 5}};
  int matriz1[3][4] = {{1, 6, 4, 3},
                      {5, 1, 4, 2},
                      {0, 1, 2, 5}};
  printf("Matriz inicial:\n");
  imprimeMatriz(matriz);
  somaLinhas(matriz);
  printf("\n\n");
  multiplicaLinhas(matriz1);
  
  return 0;
}

void imprimeMatriz(int matriz[3][4]){
  for(int i=0;i<3;i++){
    printf("\n");
    for(int j=0;j<4;j++){
      printf("%d ",matriz[i][j]);
    }
  }
}

void somaLinhas(int matriz[3][4]){
  printf("\n\nSomas:");
  for(int i=0;i<4;i++){
    //[0][i]
    matriz[1][i] = matriz[1][i] + matriz[0][i];
  }
  imprimeMatriz(matriz);
}

void multiplicaLinhas(int matriz[3][4]){
  printf("\nMultiplicacoes:");
  for(int i=0;i<4;i++){
    //[0][i]
    matriz[1][i] = matriz[1][i] * matriz[0][i];
  }
  imprimeMatriz(matriz);
}
