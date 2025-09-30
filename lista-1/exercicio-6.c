/*
    6 - Faça um programa em C que leia um símbolo numérico em formato CHAR (%c) entre '0' e '9',
    e um valor número INTEIRO N. Faça a multiplicação dos valores e imprima o resultado (que deve ser correto).
    Por exemplo o char '5' multiplicado ao nº. inteiro 8 deve totalizar 40. Analise o porquê do problema não ser tão trivial quanto parece.
*/

#include <stdio.h>

int main() {
    char a;
    int b;

    printf("Insira o caractere de '0' a '9': ");
    scanf(" %c", &a);
    printf("Insira um número inteiro: ");
    scanf(" %d", &b);

    int result = (a - '0') * b;

    printf("O resultado da multiplicação dos dois valores é %d.\n", result);

    return 0;
}
