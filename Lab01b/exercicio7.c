#include <stdio.h>

#define N 3 // Define o tamanho do vetor de pessoas

// Definição da struct Pessoa
typedef struct {
  char nome[30];
  int idade;
  float peso;
  float altura;
} Pessoa;

int main() {
  Pessoa pessoas[N];

  for (int i = 0; i < N; i++) {
    printf("Digite o nome da pessoa %d: ", i + 1);
    scanf("%s", pessoas[i].nome);
    printf("Digite a idade da pessoa %d: ", i + 1);
    scanf("%d", &pessoas[i].idade);
    printf("Digite o peso da pessoa %d (em kg): ", i + 1);
    scanf("%f", &pessoas[i].peso);
    printf("Digite a altura da pessoa %d (em metros): ", i + 1);
    scanf("%f", &pessoas[i].altura);
    printf("\n");
  }

  printf("Dados das pessoas:\n");
  for (int i = 0; i < N; i++) {
    printf("Pessoa %d:\n", i + 1);
    printf("Nome: %s\n", pessoas[i].nome);
    printf("Idade: %d anos\n", pessoas[i].idade);
    printf("Peso: %.1f kg\n", pessoas[i].peso);
    printf("Altura: %.2f m\n", pessoas[i].altura);
    printf("\n");
  }

  return 0;
}
