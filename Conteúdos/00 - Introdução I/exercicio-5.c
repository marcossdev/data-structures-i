/*
    5 - Faça um programa em C (função única) que leia uma variável do tipo char e
    imprima o conteúdo dessa variável usando os formatos %c e %d. Estude o motivo da
    impressão de um mesmo conteúdo ser diferente. O que aconteceria se lêssemos uma variável
    do tipo char sob formato %d? Faça testes...
*/

#include <stdio.h>

int main() {
    char a;
    int b;

    printf("Insira uma caractere (ex: A): ");
    scanf(" %c", &a);
    printf("Insira um número inteiro qualquer (ex: 10): ");
    scanf(" %d", &b);

    printf("Impressão do \"char\":\n");
    printf("%%c: %c\n", a);
    printf("%%d: %d\n", a);

    printf("Impressão do \"int\":\n");
    printf("%%d: %d\n", b);
    printf("%%c: %c\n", b);
    return 0;
}
