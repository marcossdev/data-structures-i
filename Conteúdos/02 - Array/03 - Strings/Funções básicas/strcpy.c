#include <stdio.h>
#include <string.h>

int main() {
    char fonte[] = "Olá, mundo!";
    char destino[50];

    printf("Fonte: %s\n", fonte);
    printf("Destino: %s\n\n", destino);

    strcpy(destino, fonte);

    printf("Destino (aṕos a cópia): %s\n", destino);
    return 0;
}
