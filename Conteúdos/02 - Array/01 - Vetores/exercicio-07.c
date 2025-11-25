/*
 * Gere dois vetores, V1 e V2, cada um com K valores aleatórios sorteados no intervalo entre 0 e X (0<K<X).
 * O usuário deve informar o valor de K e X, desde que K < X. O programa NÃO deverá aceitar números
 * repetidos no mesmo vetor, e nem o mesmo número no mesmo índice dos dois vetores. Imprima os
 * valores sorteados nos dois vetores, e o resultado da multiplicação dos valores dos índices de V1 e V2.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int val_k, val_x;

    // Validação das entradas de dados
    do {
        system("clear");
        printf("A seguir, insira dois valores inteiros K e X, sendo K < X (K menor que X) e os dois valores devem ser maiores que 0 (zero).\n");
        printf("Digite o valor de K: ");
        scanf(" %d", &val_k);
        printf("Digite o valor de X: ");
        scanf(" %d", &val_x);
        if (val_k == val_x || val_x < val_k || val_k <= 0 || val_x <= 0) {
            while (getchar() != '\n');
            printf("\nValores inválidos.\nTente novamente...");
            getchar();
        }
    } while (val_k == val_x || val_k > val_x);

    int arrA[val_k], arrB[val_k];

    // Preenchimento dos vetores seguindo as restrições impostas
    int indice = 0;
    while (indice < val_k) {
        int numA = rand() % (val_x + 1);
        int numB = rand() % (val_x + 1);

        // Impede valores iguais nos mesmos indices
        if (numA == numB)
            continue;

        // Verficação se os valores já existem nos dois vetores
        int existeA = 0;
        int existeB = 0;

        for (int j = 0; j < indice; j++) {
            if (arrA[j] == numA)
                existeA = 1;
            if (arrB[j] == numB)
                existeB = 1;
        }

        // Impede que items que já existem em um dos vetores seja colocado novamente
        if (existeA || existeB) {
            continue;
        }

        arrA[indice] = numA;
        arrB[indice] = numB;
        indice++;
    }

    printf("\n");
    printf("Vetor A: ");
    for (int i = 0; i < val_k; i++) {
        if (!i)
            printf("[");
        printf(" %d ", arrA[i]);
        if (i == (val_k - 1))
            printf("]\n");
    }
    printf("Vetor B: ");
    for (int i = 0; i < val_k; i++) {
        if (!i)
            printf("[");
        printf(" %d ", arrB[i]);
        if (i == (val_k - 1))
            printf("]\n\n");
    }

    printf("Resultado da multiplicação dos indicies de A e B: \n");
    for (int i = 0; i < val_k; i++) {
        if (!i)
            printf("[");
        printf(" %d ", (arrA[i] * arrB[i]));
        if (i == (val_k - 1))
            printf("]\n");
    }

    return 0;
}
