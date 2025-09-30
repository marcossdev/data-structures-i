/*
    15 - Faça um programa em C (em única função) que leia um valor inteiro N e verifica se o número N é primo ou não
    (ou seja, só possui 1 e o próprio N como divisores possíveis). Estude sobre o conceito e utilidade de "variável lógica" e
    porque é muito útil neste problema.
*/

#include <stdio.h>

int main() {
    int n;
    int primo = 1;

    printf("Insira um valor inteiro: ");
    scanf(" %d", &n);

    if (n <= 1) {
        primo = 0;
    } else if (n == 2) {
        primo = 1;
    } else if (n % 2 == 0) {
        primo = 0;
    } else {
        for (int divisor = 3; divisor < n; divisor += 2) {
            if (n % divisor == 0) {
                primo = 0;
                break;
            }
        }
    }

    if (primo) {
        printf("O número %d é primo.\n", n);
    } else {
        printf("O número %d não é primo.\n", n);
    }

    return 0;
}
