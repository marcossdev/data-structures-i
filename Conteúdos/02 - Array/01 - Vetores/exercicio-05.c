/*
 * Faça um programa que preencha um vetor com N números aleatórios, sorteados no intervalo entre X e Y.
 * O programa deve informar a posição (índice) onde se encontra o menor número sorteado, seguido da
 * posição onde se encontra o segundo menor número sorteado, e assim sucessivamente…
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int x, y, n;
    printf("Digite dois valores inteiros (um espaçado do outro): ");
    scanf(" %d %d", &x, &y);
    printf("Digite o tamanho do vetor: ");
    scanf(" %d", &n);

    int v[n];
    int valor, i_valor;
    int max = (x > y ? x : y), min = (x < y ? x : y);

    for (int i = 0; i < n; i++) {
        v[i] = min + rand() % (max - min + 1);
    }

    printf("\nVetor: \n");
    for (int i = 0; i < n; i++) {
        printf("[%d] ", v[i]);
    }
    printf("\n");

    printf("Valores em ordem crescente (do menor valor sorteado ao manior valor sorteado): \n");
    for (int i = min; i <= max; i++) {
        for (int j = 0; j < n; j++) {
            if (i == v[j]) {
                i_valor = j;
                valor = v[j];
                printf("[ indice: %d valor: %d ]\n", i_valor, valor);
            }
        }
    }

    return 0;
}
