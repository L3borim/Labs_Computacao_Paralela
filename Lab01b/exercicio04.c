#include <stdio.h>
#include <string.h>

#define LEN 100

int main()
{
    char nome1[LEN], nome2[LEN];
    printf("Digite o 1º nome: ");
    scanf("%s", nome1);

    printf("Digite o 2º nome: ");
    scanf("%s", nome2);

    printf("\nNomes em ordem alfabetica: \n");
    if(strcmp(nome1, nome2) > 0){
        printf("\n%s\n%s\n", nome2, nome1);
    }
    else{
        printf("%s\n%s\n", nome1, nome2);
    }

    return 0;
}
