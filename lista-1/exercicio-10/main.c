/*
    10 - Faça um programa em C (função única) que leia 10 valores inteiros e imprima como resultado:
    o maior valor lido, o menor valor e a média simples dos valores inseridos.
*/

#include <limits.h>
#include <stdio.h>

int main() {
    int value, idx;
    float media = 0.0;
    int max = INT_MIN, min = INT_MAX;

    for (idx = 0; idx < 10; idx++) {
        printf("Insira um número inteiro: ");
        if (scanf(" %d", &value) != 1) {
            printf("Valor invalido! Tente novamente.\n");

            while (getchar() != '\n')
                ;
            idx--;
            continue;
        }

        media += value;

        if (value > max)
            max = value;
        if (value < min)
            min = value;
    }

    media = (float)media / (float)idx;

    printf("Maior número: %d\n", max);
    printf("Menor número: %d\n", min);
    printf("Media simples dos números: %.2f\n", media);
    return 0;
}
