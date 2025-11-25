#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int main() {
    srand(time(NULL));

    int vetor[SIZE];
    for (int i = 0; i < SIZE; i++) {
        vetor[i] = rand() % 101;
    }

    // Insertion sort
    for (int i = 1; i < SIZE; i++) {
        int j = (i - 1);
        while (j >= 0 && vetor[j] > vetor[j + 1]) {
            int temp = vetor[j];
            vetor[j] = vetor[j + 1];
            vetor[j + 1] = temp;
            j--;
        }
    }

    printf("Vetor: ");
    for (int i = 0; i < SIZE; i++) {
        printf("[%i] ", vetor[i]);
    }
    printf("\n");

    while (1) {
        int valor;
        printf("\nDigite um valor para buscar (valor negativo para encerrar): ");
        scanf(" %i", &valor);

        if (valor < 0) {
            printf("\nPrograma encerrado.\n");
            break;
        }

        // Binary search
        int inc = 0, fim = SIZE - 1, meio, encontrado = 0;
        while (inc <= fim) {
            meio = (inc + fim) / 2;
            if (vetor[meio] == valor) {
                encontrado++;
                break;
            } else if (vetor[meio] > valor) {
                fim = meio - 1;
            } else {
                inc = meio + 1;
            }
        }

        if (encontrado) {
            printf("Valor encontrado no indice: %i.\n", meio);
        } else {
            printf("Valor inexistente!\n");
        }
    }

    return 0;
}
