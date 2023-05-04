# Instalação da Biblioteca GMP

O GMP foi utilizado em ambas a versões serial e paralela para auxiliar no aumento da precisão. Segue o passo a passo para instalar a biblioteca para o correto funcionamento do código

1. **Digitar o comando `sudo apt-get install libgmp-dev`**
2. **Compilar usando o seguinte comando:**
   - Para a versão serial: **`gcc -o Serial1.bin Serial1.c -lgmp -lm`**
   - Para versão paralela:****

Documentação disponível em: https://gmplib.org/
