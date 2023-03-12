#include <stdio.h>

int posicao(char *str, char carac);

int main(void) {
  char str[100];
  char opcao;
  
  printf("Digite a string desejada: ");
  scanf("%[A-Z a-z]",str); //%s - sem espaço
  printf("Digite o caractere a ser encontrado: ");
  scanf(" %c",&opcao);
  
  if(posicao(str,opcao) != 0) printf("Posicao: %d",posicao(str,opcao));
  return 0;
}

//'\0'
int posicao(char *str, char carac){
  int i=0;
  while(str[i]!='\0'){
    if(str[i] == carac) return i+1;
    i++;
  }
  printf("Caractere nao encontrado");
  return 0;
}
