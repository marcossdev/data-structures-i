/*
 * Faça um programa que sorteia aleatoriamente um vetor de tamanho N com valores que representam as
 * 03 cores da bandeira italiana. Seu programa deve gerar como resultado a quantidade de bandeiras que
 * podem ser formadas a partir desse Array. Todas operações devem ser in-place (Não é permitido usar arrays auxiliares).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL));

    const int VERDE = 0, BRANCO = 1, VERMELHO = 2;

    int N = 12;
    int arr[N];
    int contVerde = 0, contBranco = 0, contVermelho = 0;

    printf("Cores: ");
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 3;
        printf(" [%i] ", arr[i]);
    }
    printf("\n");

    // Contar cores
    for (int i = 0; i < N; i++) {
        if (arr[i] == VERDE) contVerde++;
        if (arr[i] == BRANCO) contBranco++;
        if (arr[i] == VERMELHO) contVermelho++;
    }

    int menorQuantidade = contVerde;
    if (contBranco < menorQuantidade) menorQuantidade = contBranco;
    if (contVermelho < menorQuantidade) menorQuantidade = contVermelho;

    printf("\nÉ possível formar apenas %i bandeira(s) completa(s).\n", menorQuantidade);
    return 0;
}
