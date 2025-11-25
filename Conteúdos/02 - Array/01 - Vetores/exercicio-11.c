/*
 * Métodos: map, filter e reduce são bastante comuns em linguagens de alto nível para tratamento de
 * Arrays. Faça um programa que implemente o método…
 * FILTER => Dado um vetor V1, com N números inteiros sorteados entre 0 e 99, e um outro valor inteiro X,
 * crie um novo vetor V2, preenchendo-o apenas com valores do primeiro vetor que são múltiplos de X.
 * Um mesmo valor não deve ser filtrado mais de 1 vez. Imprima V1 e V2.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int valorN, valorX;
    printf("Digite o valor de N (tamamnho do vetor): ");
    scanf(" %i", &valorN);
    printf("Digite o valor de X (múltiplo): ");
    scanf(" %i", &valorX);

    printf("\n");

    int vetorA[valorN], vetorB[valorN];

    for (int i = 0; i < valorN; i++)
        vetorA[i] = rand() % 100;

    int tamanhoVB = 0;
    for (int i = 0; i < valorN; i++) {
        int ja_existe = 0;
        for (int j = 0; j < tamanhoVB; j++) {
            if (vetorB[j] == vetorA[i]) {
                ja_existe = 1;
                break;
            }
        }
        if (!ja_existe && (vetorA[i] % valorX) == 0) {
            vetorB[tamanhoVB] = vetorA[i];
            tamanhoVB++;
        }
    }

    printf("Vetor A: ");
    for (int i = 0; i < valorN; i++)
        printf(" [%i] ", vetorA[i]);
    printf("\n");

    printf("Vetor B (valores multiplos de %i): ", valorX);
    for (int i = 0; i < tamanhoVB; i++)
        printf(" [%i] ", vetorB[i]);
    printf("\n");

    return 0;
}
