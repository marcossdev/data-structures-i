/*
 * Faça um programa que sorteie N nºs entre 0 e X.
 * Faça a ordenação do Array na função main(), mas levando em consideração a qtd. de bits 1
 * que os números formam em binário (crie função específica para calcular isso).
 * Imprima o resultado em decimal e binário (crie outra função para isso).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int converterParaBinario(int);
int contagemBits(int);
int compararQuantidadeBits(int, int);

int main() {
    srand(time(NULL));

    int N, X;

    printf("Digite um valor para N (tamanho vetor): ");
    scanf(" %i", &N);
    printf("Digite um valor para X: ");
    scanf(" %i", &X);

    int vetor[N];
    for (int i = 0; i < N; i++)
        vetor[i] = rand() % (X + 1);

    // Ordenação com base na quantidade de bits 1 (menor quantidade até maior quantidade) - insertion sort
    for (int i = 1; i < N; i++) {
        int j = i - 1, key = vetor[i];
        while (j >= 0 && compararQuantidadeBits(vetor[j], key) > 0) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = key;
    }

    for (int i = 0; i < N; i++) {
        printf("\nIndice %i:\n - Valor (decimal): %i\n - Valor (binário): %i\n - Quantidade de bits 1: %i\n", i, vetor[i], converterParaBinario(vetor[i]),
               contagemBits(vetor[i]));
    }

    return 0;
}

int converterParaBinario(int valor) {
    if (!valor) return 0;
    int bin = 0, mult = 1;
    while (valor > 0) {
        bin += (valor % 2) * mult;
        mult *= 10;
        valor /= 2;
    }
    return bin;
}

int contagemBits(int valor) {
    int contagem = 0;

    while (valor > 0) {
        if (valor % 2 == 1) contagem++;
        valor /= 2;
    }

    return contagem;
}

int compararQuantidadeBits(int valorA, int valorB) {
    int contA = contagemBits(valorA), contB = contagemBits(valorB);
    if (contA == contB) {
        return 0;
    } else if (contA > contB) {
        return 1;
    } else {
        return -1;
    }
}
