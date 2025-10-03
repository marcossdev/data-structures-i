/*
    11 - Faça um programa em C (função única) que leia do usuário um valor inteiro N. Faça a impressão crescente de
    todos os valores pares de 0 até N e a impressão decrescente de todos os valores ímpares de N até 0.
*/

#include <limits.h>
#include <stdio.h>

int main() {
    int value;

    do {
        printf("Insira um valor inteiro: ");
        if (scanf(" %d", &value) != 1) {
            printf("Valor inválido! Tente novamente.\n");
            while (getchar() != '\n') {};
        } else {
            break;
        }
    } while (1);

    printf("Números pares de 0 até %d em ordem crescente: \n", value);
    if (value >= 0) {
        for (int idx = 0; idx <= value; idx += 2) {
            printf("%d\n", idx);
        }
    } else {
        for (int idx = value; idx <= 0; idx += 2) {
            if (idx % 2 != 0) {
                printf("%d\n", idx + 1);
            } else {
                printf("%d\n", idx);
            }
        }
    }

    printf("Números impares de 0 até %d em ordem decrescente: \n", value);
    if (value >= 0) {
        for (int idx = value; idx >= 0; idx--) {
            if (idx % 2 != 0) {
                printf("%d\n", idx);
            }
        }
    } else {
        for (int idx = 0; idx >= value; idx--) {
            if (idx % 2 != 0) {
                printf("%d\n", idx);
            }
        }
    }

    return 0;
}
