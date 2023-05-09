#include <stdio.h>
#include <math.h>
#include <gmp.h>
#include <pthread.h>

#define NUM_THREADS 4

typedef struct {
    int start;
    int end;
    mpf_t partial_result;
} thread_args;

void* constanteE_thread(void* args_ptr) {
    thread_args* args = (thread_args*) args_ptr;
    int i, j;
    mpf_t fat, termo;
    mpf_init_set_d(args->partial_result, 0.0);
    mpf_init(fat);
    mpf_init(termo);

    for (i = args->start; i <= args->end; i += NUM_THREADS) {
        mpf_set_ui(fat, 1);
        for (j = 1; j <= i; j++) {
            mpf_mul_ui(fat, fat, j);
        }
        mpf_ui_div(termo, 1, fat);
        mpf_add(args->partial_result, args->partial_result, termo);
    }

    mpf_clear(fat);
    mpf_clear(termo);
    pthread_exit(NULL);
}

void constanteE(int n, mpf_t result) {
    pthread_t threads[NUM_THREADS];
    thread_args args[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++) {
        args[i].start = i + 1;
        args[i].end = n;
        mpf_init(args[i].partial_result);
        pthread_create(&threads[i], NULL, constanteE_thread, (void*) &args[i]);
    }

    for (i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
        mpf_add(result, result, args[i].partial_result);
        mpf_clear(args[i].partial_result);
    }
}

int main() {
    int n, n_casas;
    n = 10000;
    n_casas = 10000;

    int bits = ceil(n_casas*log2(10));
    mpf_set_default_prec(bits);

//mpf_set_default_prec(40000);
    
    mpf_t euler;
    mpf_init(euler);

    constanteE(n, euler);
    gmp_printf("euler = %.9999Ff\n", euler);

    mpf_clear(euler);
    return 0;
}
