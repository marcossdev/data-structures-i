/*
    16 - Aprimore o problema anterior... Faça um programa em C (função única) que leia do usuário um valor inteiro N.
    Seu programa deve encontrar e imprimir como resposta: o maior número primeiro menor que N, e o menor número primo maior que N.
*/

#include <stdio.h>

int main() {
    int n;
    int is_prime;
    int largest_prime, lowest_prime;

    printf("Insira um valor inteiro: ");
    scanf(" %d", &n);

    for (int idx = n - 1; idx >= 2; idx--) {
        is_prime = 1;

        if (idx == 2) {
            is_prime = 1;
        } else if (idx % 2 == 0) {
            is_prime = 0;
        } else {
            for (int divisor = 3; divisor < idx; divisor++) {
                if (idx % divisor == 0) {
                    is_prime = 0;
                    break;
                }
            }
        }

        if (is_prime) {
            largest_prime = idx;
            break;
        }
    }

    for (int idx = n + 1;; idx++) {
        is_prime = 1;

        if (idx == 2) {
            is_prime = 1;
        } else if (idx % 2 == 0) {
            is_prime = 0;
        } else {
            for (int divisor = 3; divisor < idx; divisor++) {
                if (idx % divisor == 0) {
                    is_prime = 0;
                    break;
                }
            }
        }

        if (is_prime) {
            lowest_prime = idx;
            break;
        }
    }

    printf("Maior número primo menor que %d: %d\n", n, largest_prime);
    printf("Menor número primo maior que %d: %d\n", n, lowest_prime);

    return 0;
}
