#include <stdio.h>
long double fat(long double n){
  if(n == 0 || n == 1) return 1;
  else {
    return fat(n-1)*n;
  }
}

int main(void) {
  long double euler = 0;
  long double n;
  printf("n value:\n");
  scanf("%Lf",&n);
  for(long double i=0;i<n;i++){
    //printf("fat: %Lf\n",fat(i));
    euler = euler + 1.0/fat(i);
  }
  printf("%.150Lf",euler);
  return 0;
}
