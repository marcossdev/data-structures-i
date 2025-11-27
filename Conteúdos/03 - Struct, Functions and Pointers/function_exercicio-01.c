/*
 * Implemente a função potencia() que retorna o valor de X elevado a N.
 * Os valores de X e N devem ser enviados através de parâmetros.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

double potencia(int base, int expoente) {
    if (!expoente) return 1.0;

    double resultado = base;

    int expoente_abs = expoente, negativo = 0;
    if (expoente_abs < 0) {
        negativo++;
        expoente_abs = expoente * (-1);
    }

    for (int i = 0; i < expoente_abs - 1; i++)
        resultado *= base;

    if (negativo) return 1.0 / resultado;

    return resultado;
}

int main() {
    int E;
    double X;

    printf("-> Potenciação\n");

    printf("Digite o valor da base: ");
    scanf(" %lf", &X);
    printf("Digite o valor do expoente: ");
    scanf(" %i", &E);

    printf("Resultado: %.1lf elevado a %i é igual a %.1lf\n", X, E, potencia(X, E));
    return 0;
}
