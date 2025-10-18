/*
 * Para um conjunto de dados (array) de 100 valores aleatórios sorteados entre 1 e 20, faça 
 * um programa que peça ao usuário um valor X e imprima todos os números da base de
 * dados e quantas vezes o valor X aparece nele (Marque o símbolo * ao lado de cada
 * aparição do valor X). Repita toda operação para o mesmo conjunto de dados até X <= 0.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    system("clear");

    int nums[100] = {0};

    for (int idx = 0; idx < 100; idx++)
        nums[idx] = 1 + rand() % 20;

    do {
        system("clear");

        int valueFromUser, repeatCount = 0;

        printf("Digite um número inteiro de 1 a 20 (ou 0 para encerrar): ");
        scanf(" %d", &valueFromUser);

        if (!valueFromUser) {
            system("clear");
            break;
        }

        printf("\n");
        int array_size = 10;
        for (int l = 0; l < 10; l++) {
            for (int idx = array_size - 10; idx < array_size; idx++) {
                int valueFromArray = nums[idx];
                if (valueFromUser == valueFromArray) {
                    repeatCount++;
                    printf("*%d\t", valueFromArray);
                    continue;
                }
                printf("%2d\t", valueFromArray);
            }
            array_size += 10;
            printf("\n");
        }
        printf("\nO número %d repetiu %d vez(es).\n\n", valueFromUser, repeatCount);

        while (getchar() != '\n') {}
        printf("Pressione ENTER para continuar...");
        getchar();
    } while (1);

    return 0;
}
