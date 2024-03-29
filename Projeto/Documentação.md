1. **Metodologia** 
- Para realizar esse projeto, adotamos uma abordagem na qual o nosso código paralelo divide o problema em N partes. Usa um vetor onde o tamanho é a quantidade de threads e cada posição do vetor calcula o resultado intermediário de cada thread. Ao longo do código utilizamos o OMP para organização da memória compartilhada.

2. **GMP** 
- Utilizamos a biblioteca GMP para iniciar as variáveis para os cálculos e estabelecer uma unidade de precisão que satisfizesse o desafio em questão.
Utilizamos a função `ceil(n_casas * log2(10));` para calcular a melhor precisão a partir da quantidade de casas que desejamos.

- A função mpf_set_ui permite atribuir um valor a partir de um inteiro sem sinal (unsigned int). Ela converte o valor inteiro em um número de ponto flutuante de precisão arbitrária e o armazena em uma variável mpf_t. No entato, se você deseja atribuir o valor de uma variável de ponto flutuante existente a outra variável mpf_t, você deve usar mpf_set.

- A função mpf_div_ui realiza uma divisão do segundo parâmetro de tipo mpf_t por um terceiro parâmetro do tipo uint. O resultado é armazenado em uma variável do tipo mpf_t. Essa função foi utilizada pois utilizamos um valor inteiro para a divisão sucessiva.

- A função mpf_add é utilizada para a operação de soma entre variáveis de tipo mpf_t e armazenar o resultado em uma variável de tipo mpf_t.

3. **OMP** 
- Utilizamos a biblioteca OMP para realizar a programação paralela em plataforma compartilhadas de memória, como CPUs multicores. Ela oferece um conjunto de diretivas de compilação, rotinas de biblioteca e variáveis de ambiente para facilitar o desenvolvimento de programas paralelos.

- Diretiva OpenMP ‘#pragma omp parallel num_threads(thread_count)’ cria um bloco paralelo com o número de threads especificado. A função 'thread Euler' será executada em paralelo pelas threads.

- Região crítica(‘# pragma omp critical’) garante que apenas uma thread por vez pode atualizar a variável 'global euler' de forma segura, a soma do valor local de ‘euler’ e adicionado ao valor global.

4. **Versões anteriores**
-Tentamos diversas formas de paralelizar o código, a ultima era uma versão onde para realizar os calculos intermediarios de euler, utilizava dois 'for', o que estava fazendo com que o codigo ficasse muito mais demorado com versao serial e paralelo para n = 100.000 com tempo igual a 2 horas.



# Instalação da Biblioteca GMP

O GMP foi utilizado em ambas a versões serial e paralela para auxiliar no aumento da precisão. Segue o passo a passo para instalar a biblioteca para o correto funcionamento do código

1. **Digitar o comando `sudo apt-get install libgmp-dev`**
2. **Compilar usando o seguinte comando:**
   - Para a versão serial: **`gcc -o SerialGMP.bin SerialGMP.c -lgmp -lm`**
   - Para versão paralela usando openmp: **`gcc -o ParalelaTh.bin ParalelaTh.c -lgmp -lm -fopenmp`**

Documentação disponível em: https://gmplib.org/
### N = 100.000
![image](https://github.com/L3borim/Labs_Computacao_Paralela/assets/82789071/66df9911-1ad7-450a-990f-b2ac57c263ea)

- Tempo serial: 2.585s
- Tempo paralelo: 2.468s
- Speedup: 2.585s/2.468s = 1,0474

### N = 1.000.000
![image](https://github.com/L3borim/Labs_Computacao_Paralela/assets/82789071/94b8fa4d-9ec0-40e0-b948-9649924682b6)

- Tempo serial: 269.826s
- Tempo paralelo: 241.106s
- Speedup: 269.826s/241.106s = 1,1203


