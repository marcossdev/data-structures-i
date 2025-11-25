/* GAME: Walking Dead */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./lib/gconio.h"

int main() {
    srand(time(NULL));

    int table_x = 10, table_y = 10;
    int posX = 0, posY = 2, maxX = (table_x * 2 - 1), maxY = (table_y + 1), minX = 0, minY = 2, tX = 0, tY = 0;
    int objX = maxX, objY = (maxY + 1), bonus_x = rand() % table_x, bonus_y = rand() % table_y;
    int oldPosX, oldPosY, oldX, oldY, ja_passou = 0;
    int municao = 0, max_municao = 50, passos_start = 0;
    int table[table_y][table_x], passos[table_x * table_y];
    char mouse_symbol = '_', passo_symbol = '*', objetivo_symbol = '@', bonus_symbol = '#';

    // Preenchimento da tabela
    for (int i = 0; i < table_y; i++) {
        for (int j = 0; j < table_x; j++) {
            int rand_num = rand() % 10;
            table[i][j] = rand_num;
        }
    }

    printf("---===============>> WALKING DEAD <<===============---\n\n");
    printf(
        "Alô Rick Grimes! Você precisa atravessar a cidade repleta de zumbis \nassassinos com apenas um rifle e 50 munições.\nCada quarteirão da cidade possui "
        "a quantidade de zumbis indicado pelo\nnúmero impresso, e você deve percorrer cada quarteirão uma única vez!\nMas atenção... Há também um quarteirão "
        "(#) com munições extras e você \nnão pode voltar aos locais que já passou, que estão marcados com (*).\n\nSEJA ESTRATÉGICO !Você será capaz de sair "
        "vivo desse desafio?\n\nTeclas de navegação:\n");
    printf("\t'w'\n\n'a'\t\t'd'\n\n\t's'\n\n");
    printf("Pressione 'x' para encerrar o jogo.\n\nPressione ENTER para começar...");
    while (getchar() != '\n') {};

    int start = 0;
    do {
        clrscr();

        gotoxy(0, 0);
        printf("%c", passo_symbol);

        gotoxy(0, 2);
        for (int i = 0; i < table_y; i++) {
            for (int j = 0; j < table_x; j++) {
                if (j == bonus_x && i == bonus_y) {
                    printf("%c ", bonus_symbol);
                    continue;
                }
                printf("%d ", table[i][j]);
            }
            printf("\n");
        }

        for (int i = 0; i < passos_start; i += 2) {
            int x = passos[i], y = passos[i + 1];
            if (x == posX && y == posY) {
                break;
            }
            gotoxy(x, y);
            printf("%c ", passo_symbol);
        }

        gotoxy(18, 12);
        printf("[%c]", objetivo_symbol);

        gotoxy(0, maxY + 3);
        printf("MUNIÇÃO UTILIZADA: %d/%d\n", municao, max_municao);

        int keyP;

        if (!start) {
            keyP = getch();

            if (keyP == 'x') {
                gotoxy(0, maxY + 5);
                printf("Você se Exterminou!\nGame Encerrado!\n");
                break;
            }

            start = 1;
        }

        gotoxy(posX, posY);
        printf("%c", mouse_symbol);

        if (posX == objX && posY == objY) {
            gotoxy(0, maxY + 5);
            printf("=D\nPARABÉNS! VOCÊ FOI SALVO!\n");
            break;
        }

        if (ja_passou == 0) {
            if ((tX != bonus_x || tY != bonus_y)) {
                municao += table[tY][tX];
            } else {
                max_municao += 10;
            }
        }

        gotoxy(0, maxY + 3);
        printf("MUNIÇÃO UTILIZADA: %d/%d\n", municao, max_municao);

        if (municao >= max_municao) {
            gotoxy(0, maxY + 5);
            printf("=(\nVOCÊ FOI ZUMBIFICADO\nGAME OVER\n");
            break;
        }

        passos[passos_start] = posX;
        passos[passos_start + 1] = posY;
        passos_start += 2;

        oldPosX = posX;
        oldPosY = posY;
        oldX = tX;
        oldY = tY;

        keyP = getch();

        if (keyP == 'x') {
            gotoxy(0, maxY + 5);
            printf("Você se Exterminou!\nGame Encerrado!\n");
            break;
        }

        switch (keyP) {
            case 'W':
            case 'w':
                posY -= 1;
                tY--;
                break;
            case 'S':
            case 's':
                posY += 1;
                tY++;
                break;
            case 'A':
            case 'a':
                posX -= posX == 3 ? 3 : 2;
                tX--;
                break;
            case 'D':
            case 'd':
                posX += !posX ? 3 : 2;
                tX++;
                break;
        }

        ja_passou = 0;

        for (int i = 0; i < passos_start; i += 2) {
            int x = passos[i], y = passos[i + 1];
            if (x == posX && y == posY) {
                gotoxy(0, 16);
                ja_passou = 1;
                break;
            }
        }

        if (ja_passou) {
            posX = oldPosX;
            posY = oldPosY;
            tX = oldX;
            tY = oldY;
            continue;
        }

        tX = tX >= table_x ? tX - 1 : tX;
        tX = tX < 0 ? 0 : tX;
        tY = tY >= table_y ? tY - 1 : tY;
        tY = tY < 0 ? 0 : tY;

        if (posX == maxX && posY > maxY) {
            posY = posY > maxY ? (maxY + 1) : posY;
            continue;
        }

        posX = posX > maxX ? maxX : posX;
        posX = posX < minX ? minX : posX;
        posY = posY < minY ? minY : posY;
        posY = posY > maxY ? maxY : posY;
    } while (1);

    return 0;
}
