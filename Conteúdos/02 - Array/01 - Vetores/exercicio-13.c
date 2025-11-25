/*
 * Gere um vetor de tamanho aleatório (no máximo 30) e preencha-o com valores também aleatórios entre
 * 0 e 10. Sabe-se que o ponto de equilíbrio de um vetor é o índice no qual, partindo deste índice o lado
 * esquerdo possui exatamente o mesmo valor de soma do que o lado direito. Gere e imprima inúmeros
 * vetores até encontrar algum que possua ponto de equilíbrio, e qual é este ponto.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int flag = 0, cont = 0;

    while (flag == 0) {
        cont++;
        int tamanho = 1 + rand() % 30, idc_equilibrio = 0;
        int vetor[tamanho];

        for (int i = 0; i < tamanho; i++)
            vetor[i] = rand() % 11;

        int soma_total = 0;
        for (int i = 0; i < tamanho; i++)
            soma_total += vetor[i];

        int soma_direita = soma_total, soma_esquerda = 0;
        for (int i = 0; i < tamanho; i++) {

            soma_direita -= vetor[i];

            if (soma_direita == soma_esquerda) {
                idc_equilibrio = i;
                flag = 1;
                break;
            }

            soma_esquerda += vetor[i];
        }

        if (flag == 0) {
            printf("Vetor %i: ", cont);
            for (int i = 0; i < tamanho; i++) {
                printf(" [%i] ", vetor[i]);
            }
        } else {
            printf("\nVetor %i: ", cont);
            for (int i = 0; i < tamanho; i++) {
                printf(" [%i] ", vetor[i]);
            }
            printf("\n");
            printf("Ponto de equilibrio (indice): %i\n", idc_equilibrio);
            printf("Elemento no ponto de equilibrio (valor): %i\n", vetor[idc_equilibrio]);
        }
        printf("\n");
    }

    return 0;
}
