#include <stdio.h>
#include <math.h>
#include <gmp.h>
#include <omp.h>

#define NUM_THREADS 2

void constanteE(int n, mpf_t result, int bits) {
    int i, j;
    mpf_t fat, termo;
    mpf_init_set_d(result, 1.0);
    mpf_init2(fat, bits);
    mpf_init2(termo, bits);

    #pragma omp parallel for private(i, j, fat, termo) shared(result) num_threads(NUM_THREADS)
    for (i = 1; i <= n; i++) {
        mpf_init2(fat, bits);
        mpf_init2(termo, bits);

        mpf_set_ui(fat, 1);
        for (j = 1; j <= i; j++) {
            mpf_mul_ui(fat, fat, j);
        }
        mpf_ui_div(termo, 1, fat);

        #pragma omp critical
        {
            mpf_add(result, result, termo);
        }

        mpf_clear(fat);
        mpf_clear(termo);
    }
}

int main() {
    int n, n_casas;
    n = 10000;
    n_casas = 10000;
    int bits = ceil(n_casas * log2(10));
    mpf_set_default_prec(bits);

    mpf_t euler;
    mpf_init(euler);

    constanteE(n, euler, bits);
    gmp_printf("euler = %.10000Ff\n", euler);

    mpf_clear(euler);
    return 0;
}

