/*
 * Gere uma matriz N x N onde os valores da diagonal principal sejam exatamente
 * a soma dos demais valores existentes na sua linha e coluna.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    
    int num, soma = 0;
    
    printf("Digite o tamanho da tabela: ");
    scanf(" %i", &num);
    
    int mat[num][num];
    
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            int randNum = 1 + rand() % (num*num);
            if (i == j) {
                mat[i][j] = 0;
                continue;
            }
            mat[i][j] = randNum;
        }
    }
    
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (i != j) 
                soma += mat[i][j];
        }
        for (int j = 0; j < num; j++) {
            if (i != j) 
                soma += mat[j][i];
        }
        mat[i][i] = soma;
        soma = 0;
    }
    
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            printf("[%02d] ", mat[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
