#include <stdio.h>
#include <math.h>
#include <gmp.h>
#include <stdlib.h>

void constanteE(int n, mpf_t *euler, int bits) {
    int i;
    mpf_t termo;
    mpf_set_ui(*euler, 1);
    mpf_init2(termo, bits);
    mpf_set_ui(termo, 1);
    for (i = 1; i <= n; i++) {
        mpf_div_ui(termo, termo, i);
        mpf_add(*euler, *euler, termo);
    }
    mpf_clear(termo);
}
int main() {
    int n, n_casas;

    n = 100000;
    n_casas = 100000;

    int bits = ceil(n_casas*log2(10));
    mpf_set_default_prec(bits);
    
    mpf_t euler;
    mpf_init2(euler, bits);

    constanteE(n, &euler, bits);
    //gmp_printf("euler = %.100Ff\n", euler);
    gmp_printf("euler para %d de casas decimais e n = %d\n", n_casas, n);
   
    FILE *arquivo = fopen("resultado.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    // Converte o valor de euler em uma string
    int n_casas_decimais = n_casas + 2;  // Número de casas decimais desejadas
    mp_exp_t exp;
    char *euler_str = mpf_get_str(NULL, &exp, 10, n_casas_decimais, euler);

    // Grava a string no arquivo
    fprintf(arquivo, "%s\n", euler_str);

    // Libera a memória alocada
    free(euler_str);

    // Fecha o arquivo
    fclose(arquivo);
    

    mpf_clear(euler);
    return 0;
}
