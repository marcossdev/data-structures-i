/*
 * Faça um programa C para ler do usuário dois valores inteiros X e Y. Alimente dois vetores de tamanhos X
 * e Y com números inteiros aleatórios, não repetitivos, sorteados no intervalo entre 0 e X+Y (inclusive).
 * Faça a impressão das seguintes informações:
 * a) Vetores X e Y;
 * b) Todos os números exclusivos do vetor X;
 * c) Todos os números exclusivos do vetor Y;
 * d) Os números existentes nos dois vetores;
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int x, y;
    printf("Digite dois valores inteiros (um espaçado do outro): ");
    scanf(" %d %d", &x, &y);

    int vx[x], vy[y], cont = 0;

    while (cont < x) {
        int rand_num = rand() % (x + y + 1);
        int existe = 0;

        for (int i = 0; i < x; i++) {
            if (vx[i] == rand_num) {
                existe = 1;
                break;
            }
        }

        if (!existe) {
            vx[cont] = rand_num;
            cont++;
        }
    }

    cont = 0;
    while (cont < y) {
        int rand_num = rand() % (x + y + 1);
        int existe = 0;

        for (int i = 0; i < y; i++) {
            if (vy[i] == rand_num) {
                existe = 1;
                break;
            }
        }

        if (!existe) {
            vy[cont] = rand_num;
            cont++;
        }
    }

    printf("\nVetor X: ");
    for (int i = 0; i < x; i++) {
        printf("[%d] ", vx[i]);
    }
    printf("\n");

    printf("Vetor Y: ");
    for (int i = 0; i < y; i++) {
        printf("[%d] ", vy[i]);
    }

    printf("\n\n");

    printf("Valores exclusivos de X: ");
    for (int i = 0; i < x; i++) {
        int exclusivo = 1;
        for (int j = 0; j < y; j++) {
            if (vx[i] == vy[j]) {
                exclusivo = 0;
            }
        }
        if (exclusivo)
            printf("[%d] ", vx[i]);
    }
    printf("\n");

    printf("Valores exclusivos de Y: ");
    for (int i = 0; i < y; i++) {
        int exclusivo = 1;
        for (int j = 0; j < x; j++) {
            if (vy[i] == vx[j]) {
                exclusivo = 0;
            }
        }
        if (exclusivo)
            printf("[%d] ", vy[i]);
    }
    printf("\n");

    printf("Valores existentes existentes em X e Y: ");
    for (int i = 0; i < x; i++) {
        int existe = 0;
        for (int j = 0; j < y; j++) {
            if (vx[i] == vy[j]) {
                existe = 1;
            }
        }
        if (existe)
            printf("[%d] ", vx[i]);
    }

    return 0;
}
