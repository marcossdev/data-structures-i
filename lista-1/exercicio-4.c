/*
    4 - O custo final de um produto numa fábrica qualquer é a soma do custo de produção (float),
    acrescido de X% de impostos e, acumuladamente, Y% de custos do distribuidor. Sendo X e Y valores
    inteiros informados pelo usuário, faça um programa em C (função única) que imprime o custo final de
    um produto após a incidência das taxas.
*/

#include <stdio.h>

int main() {
    float custo_producao, custo_final;
    int imposto, custos_distribuicao;

    printf("Insira o preço de produção: ");
    scanf(" %f", &custo_producao);
    printf("Insira o valor percentual de acrescimo inteiro (ex: 10 -> 10%%): ");
    scanf(" %d", &imposto);
    printf("Insira o valor percentual de distribuição ineiro (ex: 10 -> 10%%): ");
    scanf(" %d", &custos_distribuicao);

    custo_final =
        custo_producao * (1 + (float)imposto / 100) * (1 + (float)custos_distribuicao / 100);

    printf("O custo final do produto é R$%.2f.\n", custo_final);

    return 0;
}
