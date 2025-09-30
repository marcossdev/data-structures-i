/*
    8 - Faça um programa em C (em função única) que leia 3 variáveis de valor inteiro e
    imprima-os em ordem crescente e depois em ordem decrescente. Analise porque é mais eficiente
    trocar o conteúdo das variáveis do que apenas comparar os valores entre si.
    (Faça o código apenas comparando os valores, sem realizar trocas, e veja a diferença entre os códigos).
*/

#include <stdio.h>

int main() {
    int a, b, c;

    printf("Insira três valores inteiros diferentes (um deopois o outro):\n");
    scanf(" %d", &a);
    scanf(" %d", &b);
    scanf(" %d", &c);

    // METODO 1
    printf("METODO 1 - CRESCENTE\n");
    if (a < b && a < c && b < c) {
        printf("%d, %d, %d\n", a, b, c);
    } else if (a > b && a < c && b < c) {
        printf("%d, %d, %d\n", b, a, c);
    } else if (a > b && a > c && b < c) {
        printf("%d, %d, %d\n", b, c, a);
    } else if (a > b && a > c && b > c) {
        printf("%d, %d, %d\n", c, b, a);
    } else if (a < b && a > c && b > c) {
        printf("%d, %d, %d\n", c, a, b);
    } else if (a < b && a < c && b > c) {
        printf("%d, %d, %d\n", a, c, b);
    }

    // METODO 1
    printf("\nMETODO 1 - DECRESCENTE\n");
    if (a > b && a > c && b > c) {
        printf("%d, %d, %d\n", a, b, c);
    } else if (a > b && a > c && b < c) {
        printf("%d, %d, %d\n", a, c, b);
    } else if (a > b && a < c && b < c) {
        printf("%d, %d, %d\n", c, a, b);
    } else if (a < b && a > c && b > c) {
        printf("%d, %d, %d\n", b, a, c);
    } else if (a < b && a < c && b > c) {
        printf("%d, %d, %d\n", b, c, a);
    } else if (a < b && a < c && b < c) {
        printf("%d, %d, %d\n", c, b, a);
    }

    // METODO 2
    int temp;
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    if (b > c) {
        temp = c;
        c = b;
        b = temp;
    }
    if (b > a) {
        temp = a;
        a = b;
        b = temp;
    }

    printf("\nMETODO 2 - CRESCENTE\n");
    printf("%d, %d, %d\n", a, b, c);

    printf("\nMETODO 2 - DECRESCENTE\n");
    printf("%d, %d, %d\n", c, b, a);
    return 0;
}
