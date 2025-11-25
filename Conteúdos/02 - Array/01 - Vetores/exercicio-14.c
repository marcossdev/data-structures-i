/*
 * Faça um programa que sorteie aleatoriamente N números, no intervalo entre X e Y (inclusive). Após o
 * sorteio, o programa deve imprimir os números sorteados originalmente. Após isso, e a cada iteração, o
 * programa deve imprimir novamente a relação, mas agora trocando as posições do MAIOR elemento pelo
 * MENOR elemento. Uma vez trocadas as posições, estes mesmos número não poderão ser mais trocados.
 * Repita essa operação até quando for possível...
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int N, X, Y;
    printf("Digite o tamanho do vetor:\n> ");
    scanf(" %i", &N);
    printf("Digite um valor minimo (X) e máximo (Y):\n> ");
    scanf(" %i %i", &X, &Y);

    int arr[N], indices[N];

    for (int i = 0; i < N; i++)
        arr[i] = X + rand() % (Y - X + 1);

    int cont = 0, iteracao = 0;

    while (cont <= N) {
        int maior = -1, menor;

        if (!iteracao) {
            printf("Original: ");
        } else {
            printf("%iª Iteração: ", iteracao);
        }
        for (int i = 0; i < N; i++) {
            printf(" [%i] ", arr[i]);
        }
        printf("\n");

        for (int i = 0; i < N; i++) {
            int usado = 0;

            for (int j = 0; j < cont; j++) {
                if (indices[j] == i) {
                    usado++;
                    break;
                }
                usado = 0;
            }
            if (usado) continue;

            if (maior == -1) {
                maior = menor = i;
            } else {
                if (arr[i] > arr[maior]) maior = i;
                if (arr[i] < arr[menor]) menor = i;
            }
        }

        int temp = arr[maior];
        arr[maior] = arr[menor];
        arr[menor] = temp;

        indices[cont] = maior;
        indices[++cont] = menor;

        cont++;
        iteracao++;
    }

    return 0;
}
