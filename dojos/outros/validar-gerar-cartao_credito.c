#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int tamanho_cartao = 16;
    char cartao[tamanho_cartao + 1];

    while (1) {
        int opcao;
        int verificador;

        system("clear");
        printf("======= OPÇÕES ======\n");
        printf("1 - VALIDAR CARTÃO DE CREDITO\n");
        printf("2 - GERAR CARTÃO DE CREDITO\n");
        printf("3 - ENCERRAR\n\n");
        printf("Selecione uma opção: ");
        scanf(" %i", &opcao);

        if (opcao == 1) {
            system("clear");
            printf("======= VALIDAR CARTÃO DE CREDITO =======\n");
            printf("Informe o Cartão de Credito para validar: ");
            scanf(" %[^\n]s", cartao);

            // Validação da entrada de dados
            // - Validação da quantidade de digitos do cartão
            int tamanho_cartao_inserido = strlen(cartao);
            if (tamanho_cartao_inserido != tamanho_cartao) {
                printf("\nO Cartão de Credito deve conter 16 digitos!\n");
                printf("\nPressione ENTER para continuar...");
                while (getchar() != '\n') {};
                getchar();
                continue;
            }
            // - Validação se há somente números
            int tem_letras = 0;
            for (int i = 0; i < tamanho_cartao; i++) {
                int digito = cartao[i];
                if (digito < '0' || digito > '9') {
                    tem_letras = 1;
                    break;
                }
            }
            if (tem_letras) {
                printf("\nO Cartão de Credito deve conter apenas números!\n");
                printf("\nPressione ENTER para continuar...");
                while (getchar() != '\n') {};
                getchar();
                continue;
            }

            // Validar cartão de crédito
            verificador = 0;
            for (int i = 0; i < tamanho_cartao; i++) {
                int digito = (cartao[i] - '0');
                if (i % 2 == 0) {
                    verificador += digito * 2 >= 10 ? (digito * 2 / 10) + (digito * 2 % 10) : digito * 2;
                } else
                    verificador += digito;
            }

            printf(" %i\n", verificador);

            if (verificador % 10 == 0) {
                printf("Cartão de Credito válido!\n");
            } else {
                printf("Cartão de Crédito inválido!\n");
            }
        } else if (opcao == 2) {
            system("clear");

            // Gerar cartão
            int indice_final = tamanho_cartao - 1;
            for (int i = 0; i < indice_final; i++)
                cartao[i] = '0' + rand() % 10;

            int verificador = 0;
            for (int i = 0; i < indice_final; i++) {
                int digito = (cartao[i] - '0');
                if (i % 2 == 0)
                    verificador += digito * 2 >= 10 ? (digito * 2 / 10) + (digito * 2 % 10) : digito * 2 % 10;
                else
                    verificador += digito;
            }

            cartao[indice_final] = '0' + (verificador % 10 != 0 ? 10 - verificador % 10 : 0);
            cartao[tamanho_cartao] = '\0';

            printf("Cartão de Credito gerado: %s\n", cartao);

            // Validar cartão de crédito
            verificador = 0;
            for (int i = 0; i < tamanho_cartao; i++) {
                int digito = (cartao[i] - '0');
                if (i % 2 == 0)
                    verificador += digito * 2 >= 10 ? (digito * 2 / 10) + (digito * 2 % 10) : digito * 2 % 10;
                else
                    verificador += digito;
            }

            if (verificador % 10 == 0) {
                printf("Cartão de Credito válido!\n");
            } else {
                printf("Cartão de Crédito inválido!\n");
            }
        } else if (opcao == 3) {
            break;
        } else {
            printf("Opção inválida\n");
        }

        printf("\nPressione ENTER para continuar...");
        while (getchar() != '\n') {};
        getchar();
    }
    return 0;
}
