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

    // Insertion sort
    for (int i = 1; i < SIZE; i++) {
        int j = i - 1;
        while (j >= 0 && vetor[j] > vetor[j + 1]) {
            int temp = vetor[j];
            vetor[j] = vetor[j + 1];
            vetor[j + 1] = temp;
            j--;
        }
    }

    printf("Vetor ordenado: ");
    for (int i = 0; i < SIZE; i++) {
        printf("[%i] ", vetor[i]);
    }
    printf("\n");

    return 0;
}
