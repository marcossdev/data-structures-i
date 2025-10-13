/*
Um apostador joga um dado para o ar N vezes (N definido pelo usuário). Sabendo que um
dado possui 6 faces, faça um programa que simula o experimento. Como resultado,
imprima quantas vezes que cada face (não quais faces) caiu para cima e o % de cada face.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int qtJogadas, resultados[6] = {0};

    printf("Digite quantas vezes o dado será jogado: ");
    scanf(" %d", &qtJogadas);

    for (int i = 0; i < qtJogadas; i++) {
        int dado = 1 + rand() % 6;
        resultados[dado - 1] += 1;
    }

    printf("\n");
    for (int idx = 0; idx < 6; idx++) {
        float percentual = (float)resultados[idx] * 100 / qtJogadas;
        printf("A face %d caiu para cima %d vez(es) e seu percentual foi %.2f%%.\n", idx + 1, resultados[idx], percentual);
    }

    return 0;
}
