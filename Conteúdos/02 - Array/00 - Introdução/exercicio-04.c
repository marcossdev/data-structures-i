#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int sorteados[15] = {0};
    int contIndex = 0, st_size = 15, qt_numeros = 25;

    while (contIndex < 15) {
        int sorteado = 0;
        int numero_sorteado = 1 + rand() % qt_numeros;

        for (int j = 0; j < st_size; j++) {
            if (numero_sorteado == sorteados[j]) {
                sorteado = 1;
                break;
            }
            sorteado = 0;
        }

        if (!sorteado) {
            sorteados[contIndex] = numero_sorteado;
            contIndex++;
        }
    }

    printf("Números sorteados:\n");
    for (int i = 0; i < st_size; i++) {
        printf("[%d] ", sorteados[i]);
        if (i == st_size - 1)
            printf("\n");
    }

    printf("Números não sorteados: \n");
    for (int i = 0; i < qt_numeros; i++) {
        int sorteado = 0;
        int numero = (i + 1);

        for (int j = 0; j < st_size; j++) {
            if (numero == sorteados[j]) {
                sorteado = 1;
                break;
            }
        }

        if (!sorteado) {
            printf("[%d] ", numero);
        }
    }

    return 0;
}
