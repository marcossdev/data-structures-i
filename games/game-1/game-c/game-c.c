// Jogo: Jogo da cobrinha (sem a cobrinha crescer)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../libraries/include/gconio.h"

void table(int, int);

#define DEFAULT_TABLE_X_SIZE 80
#define DEFAULT_TABLE_Y_SIZE 20
#define DEFAULT_TABLE_POS_X 4
#define DEFAULT_TABLE_POS_Y 5

#define SNAKE_POS_X_MIN (DEFAULT_TABLE_POS_X + 1)
#define SNAKE_POS_Y_MIN (DEFAULT_TABLE_POS_Y + 1)
#define SNAKE_POS_X_MAX (DEFAULT_TABLE_X_SIZE + DEFAULT_TABLE_POS_X - 2)
#define SNAKE_POS_Y_MAX (DEFAULT_TABLE_Y_SIZE + DEFAULT_TABLE_POS_Y - 2)

int main() {
    int target, applePosX, applePosY;
    int targetCount = 0, movCount = 0, hasApple = 0, snakePosX = SNAKE_POS_X_MIN, snakePosY = SNAKE_POS_Y_MIN;
    float mediaMov = 0.0;
    char snakeSymbol = '>', appleSymbol = '@';

    do {
        textbackground(BLACK);
        clrscr();
        printf("========== SNAKE ===========\n");
        printf("Digite quantos alvos deseja: ");
        scanf(" %d", &target);
    } while (target < 1);

    do {
        srand(time(NULL));

        cursor(0);

        mediaMov = targetCount > 0 ? (float)movCount / targetCount : 0.0;

        gotoxy(33, 0);
        textcolor(GREEN);
        printf("Movimentos: %d | Alvos: %d/%d | Media: %.2f\n", movCount, targetCount, target, mediaMov);

        gotoxy(0, 3);
        textcolor(WHITE);
        printf("Use os direcionais [A] [S] [D] [W]\n");

        table(DEFAULT_TABLE_X_SIZE, DEFAULT_TABLE_Y_SIZE);

        if (targetCount == target) {
            textcolor(GREEN);
            table(DEFAULT_TABLE_X_SIZE, 3);
            gotoxy((DEFAULT_TABLE_X_SIZE / 2), SNAKE_POS_Y_MIN);
            printf("PARABÉNS!!!\n\n");
            break;
        }

        if (!hasApple) {
            applePosX = SNAKE_POS_X_MIN + rand() % (DEFAULT_TABLE_X_SIZE - 2);
            applePosY = SNAKE_POS_Y_MIN + rand() % (DEFAULT_TABLE_Y_SIZE - 2);
            hasApple = 1;
        }

        gotoxy(applePosX, applePosY);
        textcolor(RED);
        printf("%c", appleSymbol);

        gotoxy(snakePosX, snakePosY);
        textcolor(GREEN);
        printf("%c", snakeSymbol);

        int keyPressed = getch();

        switch (keyPressed) {
            case 'W':
            case 'w':
                snakeSymbol = '^';
                snakePosY--;
                break;
            case 'S':
            case 's':
                snakeSymbol = 'v';
                snakePosY++;
                break;
            case 'A':
            case 'a':
                snakeSymbol = '<';
                snakePosX--;
                break;
            case 'D':
            case 'd':
                snakeSymbol = '>';
                snakePosX++;
                break;
        }

        movCount++;

        if (snakePosX > SNAKE_POS_X_MAX)
            snakePosX = SNAKE_POS_X_MIN;
        if (snakePosX < SNAKE_POS_X_MIN)
            snakePosX = SNAKE_POS_X_MAX;
        if (snakePosY > SNAKE_POS_Y_MAX)
            snakePosY = SNAKE_POS_Y_MIN;
        if (snakePosY < SNAKE_POS_Y_MIN)
            snakePosY = SNAKE_POS_Y_MAX;

        if (snakePosX == applePosX && snakePosY == applePosY) {
            hasApple = 0;
            targetCount++;
        }
    } while (1);

    return 0;
}

void table(int x, int y) {
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            gotoxy(DEFAULT_TABLE_POS_X + j, DEFAULT_TABLE_POS_Y + i);
            textcolor(GREEN);

            if ((i == 0 || i == y - 1) && (j > 0 && j < x - 1)) {
                printf("-");
                continue;
            }

            if (!(i == 0 || i == y - 1) && (j == 0 || j == x - 1)) {
                printf("|");
                continue;
            }

            printf(" ");
        }
        printf("\n");
    }
}
