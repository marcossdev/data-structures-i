/*
 * Métodos: map, filter e reduce são bastante comuns em linguagens de alto nível para tratamento de
 * Arrays. Faça um programa que implemente o método…
 * MAP => Dado um vetor V1, com N números inteiros sorteados entre 0 e 1023, crie um novo vetor V2,
 * preenchendo-o com os valores do primeiro array convertidos para a base binária. Imprima V1 e V2.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int vSize;
    printf("Digite o tamamnho do vetor: ");
    scanf(" %i", &vSize);

    int vetorA[vSize], vetorAB[vSize];

    for (int i = 0; i < vSize; i++)
        vetorA[i] = rand() % 1024;

    for (int i = 0; i < vSize; i++) {
        int auxiliar = vetorA[i], binario = 0, multiplicador = 1, resto;
        while (auxiliar > 0) {
            resto = auxiliar % 2;
            auxiliar /= 2;
            binario += resto * multiplicador;
            multiplicador *= 10;
        }
        vetorAB[i] = binario;
    }

    printf("Vetor A (decimal): ");
    for (int i = 0; i < vSize; i++)
        printf("[%i] ", vetorA[i]);
    printf("\n");

    printf("Vetor A (binário): ");
    for (int i = 0; i < vSize; i++)
        printf("[%i] ", vetorAB[i]);
    printf("\n");

    return 0;
}
