/*
    12 - Faça um programa em C (função única) que leia dois valores inteiros, sendo que obrigatoriamente
    um deve ser par e outro ímpar (independente da ordem de entrada). O programa deve continuar solicitando
    valores que este requisito seja atendido. Após isso, o programa deve imprimir todos os números situados no
    intervalo entre os dois valores.
*/

#include <stdio.h>

int main() {
    int a, b;

    do {
        printf(
            "A seguir dois valores serão requisitados, tendo que ser um impar "
            "e o outro par, não importando a ordem.\n");

        printf("Insira o primeiro número inteiro: ");
        scanf(" %d", &a);
        printf("Insira o segundo número inteiro: ");
        scanf(" %d", &b);

        if ((a % 2) != (b % 2)) {
            break;
        } else {
            printf("Os dois valores são impares ou pares!\n");
            printf("Tente novamente.\n");
        }
    } while (1);

    int start = (a < b) ? a : b;
    int end = (b < a) ? a : b;

    printf("Valores entre %d e %d: \n", start, end);
    for (int idx = start + 1; idx < end; idx++) {
        printf("%d\n", idx);
    }

    return 0;
}
