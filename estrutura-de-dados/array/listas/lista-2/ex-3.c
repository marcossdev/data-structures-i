/*
 * Faça um programa que preencha um vetor com N números inteiros aleatórios, sorteados no intervalo
 * entre 0 e X. O programa deve imprimir os números sorteados, e ao final o seguinte resumo:
 * a) Quantos números distintos foram sorteados.
 * b) As posições (índices) do maior e do menor valor.
 * c) O(s) número(s) mais vezes sorteado, e quantas vezes.
 * d) O(s) número(s) menos vezes sorteado, e quantas vezes.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int v_size, max;
    printf("Digite o tamanho do vetor: ");
    scanf(" %d", &v_size);
    printf("Digite o valor maximo que pode ser sorteado: ");
    scanf(" %d", &max);

    int vet[v_size], maior_v, menor_v, cont_nd = 0, cont_rp = 0, freq_rp = 0;

    for (int i = 0; i < v_size; i++) {
        vet[i] = rand() % (max + 1);
    }

    printf("\nVetor: ");
    for (int i = 0; i < v_size; i++) {
        printf("[%d] ", vet[i]);
    }
    printf("\n");

    // Contador de números distintos
    for (int i = 0; i < (max + 1); i++) {
        cont_rp = 0;
        for (int j = 0; j < v_size; j++) {
            if (vet[j] == i) {
                cont_rp++;
                break;
            }
        }
        if (cont_rp >= 1)
            cont_nd++;
    }
    printf("Quantidade de números distintos sorteados: %d\n", cont_nd);

    // Descobre o maior e menor valor do vetor
    for (int i = 0; i < v_size; i++) {
        if (!i)
            maior_v = menor_v = vet[i];
        if (vet[i] > maior_v)
            maior_v = vet[i];
        if (vet[i] < menor_v)
            menor_v = vet[i];
    }

    printf("Indices que aparecem o maior valor (%d): ", maior_v);
    for (int i = 0; i < v_size; i++) {
        if (vet[i] == maior_v) {
            printf("[%d] ", i);
        }
    }
    printf("\n");

    printf("Indices que aparecem o menor valor (%d): ", menor_v);
    for (int i = 0; i < v_size; i++) {
        if (vet[i] == menor_v) {
            printf("[%d] ", i);
        }
    }
    printf("\n");

    printf("Número(s) mais vezes sorteado(s): \n");

    // Descobre a maior frequencia de repeticoes
    for (int i = 0; i < (max + 1); i++) {
        cont_rp = 0;
        for (int j = 0; j < v_size; j++) {
            if (vet[j] == i)
                cont_rp++;
        }
        if (cont_rp > freq_rp)
            freq_rp = cont_rp;
    }

    // Imprime os números com a maior frequência de repetições
    for (int i = 0; i < (max + 1); i++) {
        cont_rp = 0;
        for (int j = 0; j < v_size; j++) {
            if (vet[j] == i) {
                cont_rp++;
            }
        }
        if (cont_rp == freq_rp) {
            printf("[ valor: %d, quantidade: %d]\n", i, cont_rp);
        }
    }

    printf("Número(s) menos vezes sorteado(s): \n");

    // Descobre a maior frequencia de repeticoes
    for (int i = 0; i < (max + 1); i++) {
        cont_rp = 0;
        for (int j = 0; j < v_size; j++) {
            if (vet[j] == i)
                cont_rp++;
        }
        if (cont_rp && cont_rp < freq_rp)
            freq_rp = cont_rp;
    }

    for (int i = 0; i < (max + 1); i++) {
        cont_rp = 0;
        for (int j = 0; j < v_size; j++) {
            if (vet[j] == i) {
                cont_rp++;
            }
        }
        if (cont_rp == freq_rp) {
            printf("[ valor: %d, quantidade: %d]\n", i, cont_rp);
        }
    }

    return 0;
}
