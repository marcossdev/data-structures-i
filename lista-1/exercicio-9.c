/*
    9 - Faça um programa em C (função única) que através da estrutura switch-case implementa um menu interativo de
    opções que vai do valor 1 até 5. Cada opção quando acionada deve imprimir o valor da opção em extenso.
    O menu interativo deve ser executado indefinidamente, até o usuário informar o valor 0, que é a opção para encerrar o programa.
*/

#include <stdio.h>

int main() {
    int menu;
    float price = 0.0;

    do {
        printf("--> MENU SORVETERIA - PICOLES\n");
        printf("[1] - Picolé de Chocolate - R$ 3.50\n");
        printf("[2] - Picolé de Limão - R$ 2.50\n");
        printf("[3] - Picolé de Milho Verde - R$ 3.00\n");
        printf("[4] - Picolé de Morango - R$ 2.80\n");
        printf("[5] - Picolé de Gelo Azul - R$ 2.00\n");
        printf("[0] - Encerrar o pedido\n");
        printf("Insira o número do produto ou o código de encerramento: ");

        if (scanf(" %d", &menu) != 1) {
            printf("O valor inserido é inválido! Insira apenas números inteiros de 0 a 5.\n");
            while (getchar() != '\n')
                ;
            menu = -1;
            continue;
        }

        if (menu == 0)
            break;

        switch (menu) {
            case 1:
                price += 3.5;
                break;
            case 2:
                price += 2.5;
                break;
            case 3:
                price += 3.0;
                break;
            case 4:
                price += 2.8;
                break;
            case 5:
                price += 2.0;
                break;
            default:
                printf("Produto inexistente!\n");
                break;
        }
    } while (menu != 0);

    if (price > 0.0) {
        printf("Predido concluído.\n");
        printf("O preço total do pedido é R$%.2f.\n", price);
    } else {
        printf("Pedido encerrado.\n");
    }

    return 0;
}
