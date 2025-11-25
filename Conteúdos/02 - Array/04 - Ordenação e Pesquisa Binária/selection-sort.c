#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int main() {
    srand(time(NULL));

    int vetor[SIZE];
    for (int i = 0; i < SIZE; i++)
        vetor[i] = rand() % 101;

    printf("Vetor desordenado: ");
    for (int i = 0; i < SIZE; i++) {
        printf("[%i] ", vetor[i]);
    }
    printf("\n");

    // Selection sort
    for (int i = 0; i < SIZE - 1; i++) {
        int min = i;
        for (int j = (i + 1); j < SIZE; j++) {
            if (vetor[j] < vetor[min]) {
                min = j;
            }
        }
        int temp = vetor[min];
        vetor[min] = vetor[i];
        vetor[i] = temp;
    }

    printf("Vetor ordenado: ");
    for (int i = 0; i < SIZE; i++) {
        printf("[%i] ", vetor[i]);
    }
    printf("\n");

    return 0;
}
