///*
//* O algoritmo LRU (Least Recently Used) é uma política de gerenciamento de memória cache que invalida o
//* item que foi acessado menos recentemente. Isso significa que se um item não foi acessado há muito
//* tempo, ele terá prioridade na remoção. Considere um vetor com N elementos, sorteados no intervalo
//* entre X e Y (inclusive). Considerando que os primeiros índices foram os acessados recentemente, exclua
//* da lista o elemento conforme algoritmo LRU (todos os itens iguais devem ser excluídos na mesma
//* iteração). Solução in-place (não deve-se usar vetor auxiliar). Execute essa operação N vezes, ou seja, até
//* que o array esteja vazio novamente. Imprima o conteúdo da “memória cache” em cada iteração.
//*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
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

    int memoria_cache[tamanho_inicial];

    for (int i = 0; i < tamanho_inicial; i++)
        memoria_cache[i] = min + rand() % (max - min + 1);

    system("clear");
    printf("Memória Cache inicial: ");
    for (int i = 0; i < tamanho_inicial; i++)
        printf("[%d] ", memoria_cache[i]);
    printf("\n\n");

    int tamanho_atual = tamanho_inicial;
    while (tamanho_atual > 0) {
        // Descobre qual o elemento foi usado a mais tempo (lru)
        int lru = memoria_cache[0];
        for (int i = 1; i < tamanho_atual; i++) {
            int ja_apareceu = 0;
            for (int j = 0; j < i; j++) {
                if (memoria_cache[j] == memoria_cache[i]) {
                    ja_apareceu = 1;
                    break;
                }
            }
            if (!ja_apareceu) lru = memoria_cache[i];
        }

        // Move o lru elemento e suas repetições para o final do memoria_cache
        int indice = 0;
        for (int i = 0; i < tamanho_atual; i++) {
            if (memoria_cache[i] != lru) {
                memoria_cache[indice] = memoria_cache[i];
                indice++;
            }
        }
        tamanho_atual = indice;

        printf("Memória Cache (removido %d): ", lru);
        if (tamanho_atual > 0) {
            for (int i = 0; i < tamanho_atual; i++) {
                printf("[%d] ", memoria_cache[i]);
            }
        } else {
            printf("[]");
            break;
        }
        printf("\n");
    }

    return 0;
}
