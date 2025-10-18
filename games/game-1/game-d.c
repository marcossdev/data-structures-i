// Jogo: Jokenpô (melhor de 7)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int pcPlay, userPlay;
    int userCount = 0, pcCount = 0, playCount = 0, equalCount = 0;

    do {
        system("clear");

        if (userCount == 5) {
            printf("O USUÁRIO VENCEU! :D\n");
            printf("Foram necessárias %d jogadas.\n", playCount);
            break;
        }

        if (pcCount == 5) {
            printf("O PC VENCEU! :(\n");
            printf("Foram necessárias %d jogadas.\n", playCount);
            break;
        }

        printf("=========== JOKENPÔ (MELHOR DE 7) ==========\n");
        printf("PLACAR: PC: %d - USER: %d - EMPATE: %d\n\n", pcCount, userCount, equalCount);
        printf("[1] PEDRA\n[2] PAPEL\n[3] TESOURA\n\n");
        printf("Quantidade de jogadas: %d\n", playCount);
        printf("=============================================\n");

        while (getchar() != '\n') {};
        printf("Qual a sua opção? ");
        scanf(" %d", &userPlay);

        pcPlay = 1 + rand() % 3;

        system("clear");

        printf("=============================================\n");

        switch (userPlay) {
            case 1:
                printf("Você jogou PEDRA ");
                break;
            case 2:
                printf("Você jogou PAPEL ");
                break;
            case 3:
                printf("Você jogou TESOURA ");
                break;
        }

        switch (pcPlay) {
            case 1:
                printf("e o PC jogou PEDRA.\n\n");
                break;
            case 2:
                printf("e o PC jogou PAPEL.\n\n");
                break;
            case 3:
                printf("e o PC jogou TESOURA.\n\n");
                break;
        }

        if (userPlay == pcPlay) {
            equalCount++;
            printf("--> EMPATE\n");
        } else if ((userPlay - pcPlay == -2) || (userPlay - pcPlay == 1)) {
            userCount++;
            printf("--> VOCÊ VENCEU A RODADA!\n");
        } else {
            pcCount++;
            printf("--> O PC VENCEU A RODADA\n");
        }
        printf("=============================================\n\n");

        playCount++;

        while (getchar() != '\n') {};
        printf("Pressione ENTER para ir a próxima rodada...\n");
        getchar();
    } while (1);

    return 0;
}
