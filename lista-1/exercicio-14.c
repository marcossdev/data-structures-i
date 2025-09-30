/*
    14 - Faça um programa em C (função única) que dado um valor inicial (por exemplo 6), imprima o seguinte padrão na tela:
    * * * * * * (6)
    * * * * *
    * * * *
    * * *
    * *
    *
*/

#include <stdio.h>

int main() {
    int n, i, j;

    printf("Insira um valor inteiro: ");
    scanf(" %d", &n);

    for (i = 0; i < n; i++) {
        for (j = n - i; j >= 1; j--) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
