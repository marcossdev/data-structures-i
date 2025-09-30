/*
    17 - Faça um programa em C (função única) que imprima N números aleatórios
    gerados no intervalo entre 0 e X (Os valores N e X devem ser informados pelo usuário no início da execução).
    esquise sobre o conceito de números pseudo-aleatórios e sementes (seeds) na computação.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int quant, limit, random_num;

    printf("Insira quantos números aleatórios devem ser gerados: ");
    scanf(" %d", &quant);
    printf("Insira qual o valor máximo que pode ser gerado: ");
    scanf(" %d", &limit);

    srand(time(NULL));

    for (int idx = 0; idx < quant; idx++) {
        random_num = rand() % (limit + 1);
        printf("[%d] = %d\n", idx + 1, random_num);
    }
}
