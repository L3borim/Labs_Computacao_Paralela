#include <stdio.h>
#include <math.h>
#include <gmp.h>
#include <omp.h>
#include <stdlib.h>

#define NUM_THREADS 2

void constanteE(int n, mpf_t euler, int bits) {
    int i, tid;
    mpf_t termo;
    mpf_init2(termo, bits);
    mpf_set_ui(termo, 1);

    mpf_t result_local[NUM_THREADS];
    for (tid = 0; tid < NUM_THREADS; tid++) {
        mpf_init2(result_local[tid], bits);
        mpf_set_ui(result_local[tid], 0);
    }

    #pragma omp parallel private(i, tid) num_threads(NUM_THREADS)
    {
        tid = omp_get_thread_num();
        mpf_t termo_local;
        mpf_init2(termo_local, bits);
        mpf_set_ui(termo_local, 1);

        #pragma omp for
        for (i = 1; i <= n; i++) {
            mpf_div_ui(termo_local, termo_local, i);
            mpf_add(result_local[tid], result_local[tid], termo_local);
        }

        mpf_clear(termo_local);
    }
    
    for (tid = 1; tid < NUM_THREADS; tid++) {
        mpf_add(result_local[0], result_local[0], result_local[tid]);
        mpf_clear(result_local[tid]);
    }

    #pragma omp critical
    {
        mpf_add(euler, euler, result_local[0]);
    }

    mpf_clear(termo);
    mpf_clear(result_local[0]);
}

int main() {
    int n = 10000;
    int n_casas = 10000;
    int bits = ceil(n_casas * log2(10));

    mpf_t euler;
    mpf_init2(euler, bits);
    mpf_set_ui(euler, 1);

    constanteE(n, euler, bits);
    gmp_printf("euler para  %d de casas decimais e n = %d\n", n_casas, n);
    // gmp_printf("euler = %.10000Ff\n", euler);
    
    // Abrir o arquivo para escrita
    
    FILE *arquivo = fopen("resultado.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Converter o valor de euler em uma string
    int n_casas_decimais = n_casas + 2;  // Número de casas decimais desejadas
    mp_exp_t exp;
    char *euler_str = mpf_get_str(NULL, &exp, 10, n_casas_decimais, euler);

    // Gravar a string no arquivo
    fprintf(arquivo, "%s\n", euler_str);

    // Liberar a memória alocada
    free(euler_str);

    // Fechar o arquivo
    fclose(arquivo);

    mpf_clear(euler);
    return 0;
}

