#include <stdio.h>
#include <gmp.h>

void constanteE(int n, mpf_t result) {
    int i, j;
    mpf_t fat, termo;
    mpf_init_set_d(result, 1.0);
    mpf_init(fat);
    mpf_init(termo);

    for (i = 1; i <= n; i++) {
        mpf_set_ui(fat, 1);
        for (j = 1; j <= i; j++) {
            mpf_mul_ui(fat, fat, j);
        }
        mpf_ui_div(termo, 1, fat);
        mpf_add(result, result, termo);
    }

    mpf_clear(fat);
    mpf_clear(termo);
}

int main() {
    int n;
   // printf("Digite um número de N para o cálculo de E: ");
   // scanf("%d", &n);
   n = 10000;
    mpf_set_default_prec(33000);
    
    mpf_t euler;
    mpf_init(euler);

    constanteE(n, euler);
    gmp_printf("euler = %.9999Ff\n", euler);

    mpf_clear(euler);
    return 0;
}
