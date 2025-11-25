// Jogo: Advinhe o número - Humano vs Máquina

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int randNum = 80 + rand() % (100 - 80 + 1);
    int userCount = 0, pcCount = 0;
    int isUser = 1;
    int userInsert;
    int pcMin = 1, pcMax = 100;
    char select;

    do {
        system("clear");
        printf("====================== ADIVINHE O NÚMERO ======================\n");
        printf("======================== HUMANO vs. PC ========================\n\n");

        if (isUser) {
            printf("O PC já escolheu um número entre 1 e 100.\n");
            printf("Tente divinhá-lo o mais breve possível...\n\n");
            printf("Digite um número de 1 a 100:\n");
            printf("> ");
            scanf(" %d", &userInsert);

            userCount++;

            if (userInsert == randNum) {
                printf("Parabéns você acertou o número após %d tentativas!\n", userCount);
                printf("Chegou a hora do PC competir com você...\n\n");
                printf("AGORA VOCÊ DEVE PENSAR EM UM NÚMERO ENTRE 1 E 100.\n");
                isUser = 0;
                continue;
            }

            randNum < userInsert ? printf("O número sorteado é MENOR que %d\n", userInsert) : printf("O número sorteado é MAIOR que %d\n", userInsert);
        }

        if (!isUser) {
            int pcNum = pcMin + rand() % (pcMax - pcMin + 1);
            printf("PC CHUTOU... %d\n", pcNum);
            printf("Digite:\n");
            printf("'=' Se o PC acertou\n'>' Se o seu número é maior\n'<' Se o seu número é menor\n: ");
            scanf(" %c", &select);

            pcCount++;

            switch (select) {
                case '=':
                    printf("\nO PC acertou seu número escolhido!\n");
                    printf("Foram necessárias %d tentativas para o PC!\n\n", pcCount);
                    printf("RESULTADO DO COMBATE: User %d x %d PC\n", userCount, pcCount);
                    userCount < pcCount ? printf("VOCÊ VENCEU! :D\n") : printf("A MÁQUINA TE VENCEU! :C\n");
                    break;
                case '>':
                    pcMin = pcNum;
                    break;
                case '<':
                    pcMax = pcNum;
                    break;
            }

            if (!(select == '>' || select == '<'))
                break;
            continue;
        }

        while (getchar() != '\n') {};

        printf("\nPressione ENTER para continuar...");
        getchar();
    } while (1);

    return 0;
}
