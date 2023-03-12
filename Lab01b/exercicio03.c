#include <stdio.h>
#include <stdlib.h>

void preencheVetor(int *vetor, int tam);
void PiramideImpar(int i, int meio, int *vet, int tam);

int main()
{
    int input;
    do{
        printf("Digite um número impar: ");
        scanf("%d", &input);
    }
    while(input%2 == 0);

    int* vetor = calloc(input, sizeof(int));
    preencheVetor(vetor, input);

    int meio = input/2;
    PiramideImpar(0, meio, vetor, input);
    printf("\n");

    free(vetor);
    return 0;
}

void preencheVetor(int *vetor, int tam){
    for(int i=0; i<tam; i++)
    {
        vetor[i] = i+1;

    }
}

void PiramideImpar(int i, int meio, int *vet, int tam)
{
    if(i==meio){
        for(int c=0; c < tam; c++){
            if(vet[c] != vet[meio]){
                printf("   ");
            }
            else{
                printf(" %d ", vet[meio]);
            }
        }
        
    }
    else{
        for(int k=0; k<=meio; k++){
            if(k < i){
                printf("   ");
            }
            else{
                printf(" %d ", vet[k]);
            }
        }

        for(int n=meio+1; n<tam; n++)
        {
            if(n > tam-i-1){
                printf("   ");
            }
            else{
                printf(" %d ", vet[n]);
            }
        }
        printf("\n");
        PiramideImpar(i+1, meio, vet, tam);
    }
}
