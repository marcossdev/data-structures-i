/*
 * Métodos: map, filter e reduce são bastante comuns em linguagens de alto nível para tratamento de
 * Arrays. Faça um programa que implemente o método…
 * REDUCE => Dado um vetor V, com N números inteiros sorteados aleatoriamente (entre 0 e 9),
 * imprima a maior sequência crescente do vetor (em caso de empate, imprima a primeira sequência).
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int valorN;
    printf("Digite o valor de N (tamanho do vetor): ");
    scanf(" %i", &valorN);

    int vetorV[valorN];

    for (int i = 0; i < valorN; i++)
        vetorV[i] = rand() % 10;

    int inicio_maior = 0;
    int final_maior = 1;

    int inicio_atual = 0;
    int final_atual = 1;

    for (int i = 1; i < valorN; i++) {
        if (vetorV[i] > vetorV[i - 1]) {
            final_atual++;
        } else {
            if ((final_atual - inicio_atual) > (final_maior - inicio_maior)) {
                inicio_maior = inicio_atual;
                final_maior = final_atual;
            }

            inicio_atual = i;
            final_atual = (i + 1);
        }
    }

    if ((final_atual - inicio_atual) > (final_maior - inicio_maior)) {
        inicio_maior = inicio_atual;
        final_maior = final_atual;
    }

    printf("Maior frequência crescrente: ");
    for (int i = inicio_maior; i < final_maior; i++) {
        printf(" [%i] ", vetorV[i]);
    }
    printf("\n");
    return 0;
}
