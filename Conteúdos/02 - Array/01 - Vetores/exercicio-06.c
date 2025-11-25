/*
 * Gere um array de N números inteiros sorteados no intervalo entre X e Y (inclusive). Imprima o array
 * sorteado e depois elimine deste array os valores repetidos, mantendo a ordem original.
 * A solução deve ser in place, ou seja, todas as operações devem acontecer diretamente no mesmo array
 * de entrada (in-place), não sendo permitido portanto utilizar outros arrays auxiliares para ajudar na tarefa.
 * Imprima o array resultante após as exclusões.
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
    int max = (x > y ? x : y), min = (x < y ? x : y);

    for (int i = 0; i < n; i++) {
        v[i] = min + rand() % (max - min + 1);
    }

    printf("\nVetor: \n");
    for (int i = 0; i < n; i++) {
        if (!i)
            printf("[");

        printf(" %d ", v[i]);

        if (i == n - 1)
            printf("]\n");
    }

    // Reordena os itens repitidos, porem mantendo a ordem dos distintos
    int indice = 0;
    for (int i = 0; i < n; i++) {
        int existe = 0;

        for (int j = 0; j < i; j++) {
            if (v[i] == v[j]) {
                existe = 1;
                break;
            }
        }

        if (!existe) {
            v[indice] = v[i];
            indice++;
        }
    }

    printf("\nVetor com repetições removidadas: \n");
    for (int i = 0; i < indice; i++) {
        if (!i)
            printf("[");

        printf(" %d ", v[i]);

        if (i == indice - 1)
            printf("]\n");
    }

    return 0;
}
