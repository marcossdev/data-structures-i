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

    // Bubble sort
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

    printf("Vetor ordenado: ");
    for (int i = 0; i < SIZE; i++) {
        printf("[%i] ", vetor[i]);
    }
    printf("\n");

    return 0;
}
