#include <stdio.h>
void removeChar(char str[], char opcao);

int main(void) {
  char str[100];
  char opcao;
  
  printf("Digite a string: ");
  scanf("%[A-Z a-z]",str); //%s - sem espaço
  printf("Digite o caractere a ser removido: ");
  scanf(" %c",&opcao);
  printf("\nString: %s\n",str);
  removeChar(str, opcao);
  printf("\nResultado apos tentativa de remocao: %s",str);
  return 0;
}

void removeChar(char str[], char opcao){
  int i=0;
  while(str[i]!=opcao && str[i]!='\0') i++;
  if(str[i]==opcao){
    while(str[i]!='\0'){
      str[i] = str[i+1];
      i++;
    }
  }
  else printf("Caractere nao encontrado");
}
