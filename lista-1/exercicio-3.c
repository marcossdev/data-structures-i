/*
    3 - Faça um programa em C (função única) que simule o software de uma bomba de combustível:
    o usuário informar o preço do litro de combustível e o valor que o motorista deseja abastecer (ambos float).
    Imprima como resposta a quantidade de combustível que a bomba irá dispensar com 3 casas decimais.
*/

#include <stdio.h>

int main() {
    float precoC, valorAB, quantLC;

    printf("Insira o preço do litro de combustível: ");
    scanf(" %f", &precoC);
    printf("Insira o valor que pretende abastecer: ");
    scanf(" %f", &valorAB);

    quantLC = valorAB / precoC;

    printf("A quantidade de litros abastecidos será: %.3f\n", quantLC);

    return 0;
}
