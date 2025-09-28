/*
    13 - Faça um programa em C que leia um valor inteiro N, e após isso, leia N números
    inteiros positivos - valores 0 e negativos devem ser ignorados. Apresente como resultado:
    o menor e maior valor (válidos) inseridos, a soma e média simples (descartando os inválidos).
*/

#include <limits.h>
#include <stdio.h>

int main() {
    int n, idx, value, maior = INT_MIN, menor = INT_MAX, soma = 0, media_divisor = 0;
    float media = 0.0;

    printf("Insira um valor inteiro para repedir 'n' vezes: ");
    scanf(" %d", &n);

    for (idx = 0; idx < n; idx++) {
        printf("Insira um valor inteiro: ");
        scanf(" %d", &value);

        if (value > 0) {
            soma += value;
            media_divisor += 1;

            if (value > maior) {
                maior = value;
            }

            if (value < menor) {
                menor = value;
            }
        }
    }

    printf("Os números válidos são os números maiores que 0.\n");

    if (media_divisor > 0) {
        media = (float)soma / media_divisor;

        printf("Menor número inserido (válido): %d\n", menor);
        printf("Maior número inserido (válido): %d\n", maior);
        printf("Soma dos números (válidos): %d\n", soma);
        printf("Média simples dos números (válidos): %.2f\n", media);
    } else {
        printf("Nenhum número válido foi inserido!\n");
    }
    return 0;
}
