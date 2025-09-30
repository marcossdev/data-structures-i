/*
    2 - Faça um programa em C (em função única) que solicite 2 número inteiros do usuário e imprima:
        a) O resultado das quatro operações básicas (soma, adição, subtração e multiplicação).
        b) O quadrado da subtração do primeiro pelo segundo.
*/

#include <stdio.h>

int main() {
    int x, y;

    printf("Insira um número inteiro: ");
    scanf(" %d", &x);
    printf("Insira outro número inteiro: ");
    scanf(" %d", &y);

    // Letra a
    printf("Operações básicas: \n");
    printf("Soma: %d\n", x + y);
    printf("Subtração: %d\n", x - y);
    printf("Multiplicação: %d\n", x * y);
    printf("Divisão: %.2f\n", (float)x / y);

    // Letra b
    printf("Quadrado da subtração do primeiro pelo segundo: %d\n", (x - y) * (x - y));

    return 0;
}
