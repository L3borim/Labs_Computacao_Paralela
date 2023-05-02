#include <stdio.h>

long double constanteE(int n){
  int i, j;
  long double fat;
  long double E = 1.0;
  for(i=1; i<=n; i++){
    fat = 1;
    for (j=1; j<=i; j++){
      fat = fat * j;
    }
    E = E + 1.0/fat;
  } 
  return E;
}


int main(void) {
  int n;
  printf("Digite um número de N para o calculo de E: ");
  scanf("%d", &n);
  //n = 5;
  printf("%.150Lf", constanteE(n));
  return 0;
}

