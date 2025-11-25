/*
 * Implemente a solução do mesmo problema anterior, mas agora considerando que o algoritmo adotado seja o LFU (Least Frequently Used)Z.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int tamanho_inicial, min, max;
    printf("Digite o tamanho da memoria: ");
    scanf(" %d", &tamanho_inicial);
    printf("Digite o valor minimo: ");
    scanf(" %d", &min);
    printf("Digite o valor máximo: ");
    scanf(" %d", &max);

    int cache[tamanho_inicial];

    for (int i = 0; i < tamanho_inicial; i++)
        cache[i] = min + rand() % (max - min + 1);

    system("clear");
    printf("Memória Cache inicial: ");
    for (int i = 0; i < tamanho_inicial; i++)
        printf("[%d] ", cache[i]);
    printf("\n\n");

    // Remover todos os itens com a menor frequências
    int tamanho_atual = tamanho_inicial;
    while (tamanho_atual > 0) {
        // Descobrir a menor frequencia atual
        int freq_minima = tamanho_inicial + 1, elemento;
        for (int i = 0; i < tamanho_atual; i++) {
            int freq = 0;
            for (int j = 0; j < tamanho_atual; j++)
                if (cache[j] == cache[i]) freq++;
            if (freq < freq_minima) {
                freq_minima = freq;
                elemento = cache[i];
            }
        }

        int posicao = 0;
        for (int i = 0; i < tamanho_atual; i++) {
            if (cache[i] != elemento) {
                cache[posicao] = cache[i];
                posicao++;
            }
        }
        tamanho_atual = posicao;

        printf("Memória Cache (removido %d): ", elemento);
        if (tamanho_atual > 0) {
            for (int i = 0; i < tamanho_atual; i++) {
                printf("[%d] ", cache[i]);
            }
        } else {
            printf("[]");
            break;
        }
        printf("\n");
    }

    return 0;
}
