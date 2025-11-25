/*
 * Sorteie nºs aleatórios entre 1 e X para preencher uma tabela N x N (valor de N e X
 * definidos pelo usuário). Imprima os nºs na tela em formato de tabela (linhas e colunas).
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tamanho_tabela, qt_numeros;

    printf("Insira o número máximo que pode ser gerado aleatoriamente: \n> ");
    scanf(" %d", &qt_numeros);
    printf("Insira a tamanho da tabela: \n> ");
    scanf(" %d", &tamanho_tabela);

    int tabela[tamanho_tabela][tamanho_tabela];
    for (int i = 0; i < tamanho_tabela; i++) {
        for (int j = 0; j < tamanho_tabela; j++) {
            int numero_aleatorio = 1 + rand() % qt_numeros;
            tabela[i][j] = numero_aleatorio;
        }
    }

    printf("Tabela %dx%d:\n", tamanho_tabela, tamanho_tabela);
    for (int i = 0; i < tamanho_tabela; i++) {
        for (int j = 0; j < tamanho_tabela; j++) {
            printf("[%02d] ", tabela[i][j]);
        }
        printf("\n");
    }
    return 0;
}
