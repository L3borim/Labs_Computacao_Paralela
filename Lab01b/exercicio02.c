#include <stdio.h>

void mediaAvaliacao(float n1, float n2, float n3, float me);

int main()
{
    float n1, n2, n3, me;
    printf("Digite o valor das notas (N1 N2 N3):\n");
    scanf("%f %f %f", &n1, &n2, &n3);
    printf("Digite o valor da média dos execícios:\n");
    scanf("%f", &me);

    mediaAvaliacao(n1, n2, n3, me);

    return 0;
}

void mediaAvaliacao(float n1, float n2, float n3, float me)
{
    float ma = (n1 + n2*2 + n3*3 + me)/7;

    printf("Média da Avaliação: ");
    if(ma >= 9){
        printf("A\n");
    }
    else if(ma >= 7.5){
        printf("B\n");
    }
    else if(ma >= 6){
        printf("C\n");
    }
    else if(ma >= 4){
        printf("D\n");
    }
    else{
        printf("E\n");
    }
}
