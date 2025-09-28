/*
    18 - Faça um programa em C (função única) que imprima N números aleatórios gerados no intervalo
    entre X e Y (Os valores N, X e Y devem ser informados pelo usuário no início da execução).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int quant, min, max, random_num;

    printf("Insira quantos números aleatórios devem ser gerados: ");
    scanf(" %d", &quant);
    printf("Insira qual o valor minimo que pode ser gerado: ");
    scanf(" %d", &min);
    printf("Insira qual o valor máximo que pode ser gerado: ");
    scanf(" %d", &max);

    srand(time(NULL));

    for (int idx = 0; idx < quant; idx++) {
        random_num = min + rand() % (max - min + 1);
        printf("[%d] = %d\n", idx + 1, random_num);
    }
}
