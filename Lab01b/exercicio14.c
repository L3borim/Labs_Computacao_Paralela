#include <stdio.h>

void insereChar(char str[], char opcao, int n);

int main(void) {
  char str[100];
  char opcao;
  int posicao;
  
  printf("Digite a string: ");
  scanf("%[A-Z a-z]",str); //%s - sem espaço
  printf("Digite o caractere a ser inserido: ");
  scanf(" %c",&opcao);
  printf("Digite a posicao a ser inserida: ");
  scanf(" %d",&posicao);
  printf("\nString: %s\n",str);
  insereChar(str, opcao, posicao);
  printf("\nResultado apos insercao: %s",str);
  return 0;
}
/*
   0 1 2 3 0 0
*/
void insereChar(char str[], char opcao, int n){
  n = n-1;
  for(int i=99;i>n;i--) str[i] = str[i-1];
  str[n] = opcao;
}
