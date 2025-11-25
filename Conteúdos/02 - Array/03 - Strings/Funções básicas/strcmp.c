#include <stdio.h>
#include <string.h>

int main() {
    char nomeA[100], nomeB[100];

    printf("Digite o primeiro nome: ");
    scanf(" %s", nomeA);
    printf("Digite o segundo nome: ");
    scanf(" %s", nomeB);

    printf("\n");

    if (strcmp(nomeA, nomeB) == 0) {
        printf("Os dois nomes, %s e %s, são iguais.\n", nomeA, nomeB);
    } else if (strcmp(nomeA, nomeB) < 0) {
        printf("Os dois nomes, %s e %s, são diferentes.\n", nomeA, nomeB);
        printf("E o nome %s vem primeiro que o nome %s, na ordem alfabética, sendo %s 'menor' que %s.\n", nomeA, nomeB, nomeA, nomeB);

    } else if (strcmp(nomeA, nomeB) > 0) {
        printf("Os dois nomes, %s e %s, são diferentes.\n", nomeA, nomeB);
        printf("E o nome %s vem primeiro que o nome %s, na ordem alfabética, sendo %s 'menor' que %s.\n", nomeB, nomeA, nomeB, nomeA);
    }
    return 0;
}
