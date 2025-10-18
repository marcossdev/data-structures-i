/*  
 * GAME: Memoria Numérica Sequêncial
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int nums[100] = {0};
    int arr_size = 100, cont_i = 0;

    printf("========== MEMÓRIA NUMÉRICA ==========\n");
    printf("Você é bom para memorizar números? Vamos ver...\n");
    printf("A cada rodada um novo número é gerado (você tem 1 segundo para memorizar).\n");
    printf("Você deve ser capaz de lembrar TODOS os números gerados anteriormente.\n");
    printf("LET'S PLAY\n\n");

    printf("tecle ENTER para começar o game...");
    getchar();

    do {
        system("clear");

        int player_num;
        int sequencia_correta = 1;
        int rand_num = rand() % 10;
        nums[cont_i] = rand_num;

        printf("Número gerado: %d\n", rand_num);
        system("sleep 1");

        system("clear");
        printf("Informe a sequencia correta (dê espaço ou enter entre os números)...\n");

        // Preenchendo array com números inseridos pelo player
        int p_nums[cont_i + 1];
        int cont = 0;
        do {
            scanf(" %d", &player_num);
            p_nums[cont] = player_num;
            cont++;
        } while (cont < (cont_i + 1));

        // Comparação dos números digitados pelo player com os números gerados
        cont = 0;
        do {
            if (p_nums[cont] != nums[cont]) {
                sequencia_correta = 0;
                break;
            }
            cont++;
        } while (cont < (cont_i + 1));

        if (!sequencia_correta) {
            system("clear");
            printf("=(\nVocê errou a sequencia...\nSequencia Correta: ");
            for (int i = 0; i < (cont_i + 1); i++) {
                if (!i)
                    printf("[");
                printf(" %d ", nums[i]);
                if (i == cont_i)
                    printf("]\n");
            }
            printf("Fim de Jogo.\nPontuação obtida: %d ", cont_i);
            break;
        }

        cont_i++;
    } while (cont_i < arr_size);

    return 0;
}
