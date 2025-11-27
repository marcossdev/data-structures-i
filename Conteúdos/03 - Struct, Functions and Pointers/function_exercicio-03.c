/*
 * Desenvolva uma função que recebe por parâmetro um valor inteiro X.
 * Essa função deve calcular o primeiro número primo maior ou igual a X.
 * Na função main() preencha um vetor de N números aleatórios, e para cada número gerado,
 * invoque a função criada.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int verificarPrimo(int);
int encontrarPrimo(int);

int main() {
    srand(time(NULL));

    int N;

    printf("Digite um valor para N: ");
    scanf(" %i", &N);

    int vetor[N];
    for (int i = 0; i < N; i++)
        vetor[i] = 1 + rand() % (N * 2);

    for (int i = 0; i < N; i++) {
        printf("Valor: %i - Número primo: %i\n", vetor[i], encontrarPrimo(vetor[i]));
    }
    return 0;
}

int verificarPrimo(int value) {
    if (value < 2) return 0;
    if (value == 2) return 1;
    if (value % 2 == 0) return 0;

    for (int i = 3; i * i <= value; i += 2) {
        if (value % i == 0) return 0;
    }

    return 1;
}

int encontrarPrimo(int value) {
    while (1) {
        int primo = verificarPrimo(value);
        if (primo) break;
        value++;
    }
    return value;
}
