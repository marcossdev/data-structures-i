/*
 * Crie um vetor contendo N números aleatórios (sendo N múltiplo de 4). Imprima-o. Após
 * isso, troque a metade inicial pela metade final. Imprima-o. Por fim, para cada metade 
 * inicial, troque também as sub-metades. Imprima-o.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int size;

    do {
        printf("Insira um valor inteiro multiplo de 4: ");
        scanf(" %d", &size);

        if (size % 4 == 0)
            break;

        printf("Valor inválido.\n");
        while (getchar() != '\n') {};
        printf("Prssione ENTER para tentar novamente...");
        getchar();
    } while (1);

    int nums[size];

    for (int i = 0; i < size; i++) {
        nums[i] = 1 + rand() % (size*size);
    }

    printf("Array inicial:\n");
    for (int i = 0; i < size; i++) {
        printf("[%02d] ", nums[i]);
    }
    printf("\n\n");

    // Troca de metades
    int temp;

    for (int i = 0; i < size / 2; i++) {
        temp = nums[size / 2 + i];
        nums[size / 2 + i] = nums[i];
        nums[i] = temp;
    }

    printf("Array trocando as metades:\n");
    for (int i = 0; i < size; i++) {
        printf("[%02d] ", nums[i]);
    }
    printf("\n\n");

    // Troca de sub-metades
    for (int i = 0; i < size / 4; i++) {
        temp = nums[i];
        nums[i] = nums[size / 4 + i];
        nums[size / 4 + i] = temp;
    }

    for (int i = size / 2; i < (size / 4 + size / 2); i++) {
        temp = nums[i];
        nums[i] = nums[size / 4 + i];
        nums[size / 4 + i] = temp;
    }

    printf("Array trocando as sub-metades:\n");
    for (int i = 0; i < size; i++) {
        printf("[%02d] ", nums[i]);
    }
    return 0;
}
