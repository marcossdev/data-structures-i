/*
    7 - Faça um programa em C que leia dois valores do tipo inteiro X e Y.
    Após isso, faça a impressão da divisão entre X e Y (teste valores que não dê divisão exata).
    Imprima também o resultado do resto da divisão (mod) entre X e Y.
    Pesquise o conceito de typecast e porque foi necessário aplicá-lo.
*/

#include <stdio.h>

int main() {
    int a, b;

    printf("Insira o primeiro valor inteiro: ");
    scanf(" %d", &a);
    printf("Insira o segundo valor inteiro: ");
    scanf(" %d", &b);

    // Divisão inteiro
    int r1 = a / b;
    printf("Divisão inteira: %d\n", r1);

    // Resto da divsão dos dois números
    int r2 = a % b;
    printf("Resto da divisão: %d", r2);

    // Divisão real (com resultados que podem ser pontos flutuantes ou inteiros)
    float r3 = (float)a / b;
    printf("Divisão real: %.2f\n", r3);

    return 0;
}
