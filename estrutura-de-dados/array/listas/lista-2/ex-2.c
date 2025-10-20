/*
 * Faça um programa que preencha um vetor com N números aleatórios, sorteados no intervalo entre 0 e N.
 * Imprima como resultado, todos os números sorteados e:
 * a) Os valores que coincidiram com o próprio índice do vetor.
 * b) Os valores que não foram sorteados.
 * c) Os valores sorteados repetidamente (mais de uma vez).
 * d) O menor valor da metade inicial e o maior valor da metade final.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int v_size;
    printf("Digite o tamanho do vetor: ");
    scanf(" %d", &v_size);

    int vet[v_size], menor_mi, maior_mf;

    for (int i = 0; i < v_size; i++) {
        vet[i] = rand() % (v_size + 1);
    }
    printf("\n");

    printf("Números sorteados: ");
    for (int i = 0; i < v_size; i++) {
        printf("[%d] ", vet[i]);
    }
    printf("\n");

    printf("Valores que coincidem com seu indice: ");
    for (int i = 0; i < v_size; i++) {
        if (i == vet[i]) {
            printf("[INDICE: %d | VALOR: %d] ", i, vet[i]);
        }
    }
    printf("\n");

    printf("Valores que não foram sorteados: ");
    for (int i = 0; i < (v_size + 1); i++) {
        int existe = 0;
        for (int j = 0; j < v_size; j++) {
            if (vet[j] == i) {
                existe = 1;
                break;
            }
        }
        if (!existe)
            printf("[%d] ", i);
    }
    printf("\n");

    printf("Valores repetidos: ");
    for (int i = 0; i < (v_size + 1); i++) {
        int cont_rp = 0;
        for (int j = 0; j < v_size; j++) {
            if (i == vet[j])
                cont_rp++;
        }
        if (cont_rp > 1)
            printf("[%d] ", i);
    }
    printf("\n");

    int met_size = v_size / 2;

    for (int i = 0; i < met_size; i++) {
        if (!i)
            menor_mi = vet[i];

        if (vet[i] < menor_mi)
            menor_mi = vet[i];
    }
    for (int i = met_size; i < v_size; i++) {
        if (i == met_size)
            maior_mf = vet[i];

        if (vet[i] > maior_mf)
            maior_mf = vet[i];
    }

    printf("Menor valor da primeira metade: %d\n", menor_mi);
    printf("Maior valor da segunda metade: %d\n", maior_mf);

    return 0;
}
