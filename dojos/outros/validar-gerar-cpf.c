#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int tamanho_cpf = 11;
    char cpf[tamanho_cpf + 1];

    while (1) {
        int opcao;
        int somaA = 0, somaB = 0;

        system("clear");
        printf("======= OPÇÕES ======\n");
        printf("1 - VALIDAR CPF\n");
        printf("2 - GERAR CPF\n");
        printf("3 - ENCERRAR\n\n");
        printf("Selecione uma opção: ");
        scanf(" %i", &opcao);

        if (opcao == 1) {
            system("clear");
            printf("======= VALIDAR CPF =======\n");
            printf("Informe o CPF para validar: ");
            scanf(" %[^\n]s", cpf);

            // Verficação da entrada de dados
            int tamanho = 0;
            while (cpf[tamanho] != '\0') {
                tamanho++;
            }
            if (tamanho != tamanho_cpf) {
                printf("\nO CPF deve conter 11 digitos!\n");
                printf("\nPressione ENTER para continuar...");
                while (getchar() != '\n') {};
                getchar();
                continue;
            }

            //  Verificação se são há somente números
            int tem_letras = 0;
            for (int i = 0; i < tamanho_cpf; i++) {
                int digito = cpf[i];
                if (digito < '0' || digito > '9') {
                    tem_letras = 1;
                    break;
                }
            }
            if (tem_letras) {
                printf("\nO CPF não pode conter apenas números!\n");
                printf("\nPressione ENTER para continuar...");
                while (getchar() != '\n') {};
                getchar();
                continue;
            }

            for (int i = 0; i <= 8; i++)
                somaA += (cpf[i] - '0') * (i + 1);

            for (int i = 0; i <= 9; i++)
                somaB += (cpf[i] - '0') * i;

            int dv1 = somaA % 11 > 9 ? 0 : somaA % 11;
            int dv2 = somaB % 11 > 9 ? 0 : somaB % 11;

            int dv1_cpf = (cpf[9] - '0'), dv2_cpf = (cpf[10] - '0');
            if (dv1 == dv1_cpf && dv2 == dv2_cpf) {
                printf("O CPF é válido!\n");
            } else {
                if (dv1 != dv1_cpf) {
                    printf("CPF inválido: O digito de verificação 1 é inválido.\n");
                }
                if (dv2 != dv2_cpf) {
                    printf("CPF inválido: O digito de verificação 2 é inválido.\n");
                }
            }
        } else if (opcao == 2) {
            // Gerador de CPF
            system("clear");
            printf("======= GERAR CPF =======\n");
            somaA = somaB = 0;
            for (int i = 0; i < 11; i++) {
                if (i < 9) {
                    cpf[i] = '0' + rand() % 10;
                } else {
                    somaA = somaB = 0;
                    // Primeiro digito verificador
                    for (int j = 0; j <= 8; j++)
                        somaA += (cpf[j] - '0') * (j + 1);
                    cpf[i] = '0' + (somaA % 11 > 9 ? 0 : somaA % 11);
                    // Segundo digito verificador
                    for (int j = 0; j <= 9; j++)
                        somaB += (cpf[j] - '0') * j;
                    cpf[i + 1] = '0' + (somaB % 11 > 9 ? 0 : somaB % 11);
                    // Fechando a string
                    cpf[i + 2] = '\0';
                    // Finalizando o loop
                    break;
                }
            }
            printf("CPF gerado: %s\n", cpf);

            // Verificação CPF
            somaA = somaB = 0;
            for (int i = 0; i <= 8; i++)
                somaA += (cpf[i] - '0') * (i + 1);

            for (int i = 0; i <= 9; i++)
                somaB += (cpf[i] - '0') * i;

            int dv1 = somaA % 11 > 9 ? 0 : somaA % 11;
            int dv2 = somaB % 11 > 9 ? 0 : somaB % 11;

            int dv1_cpf = (cpf[9] - '0'), dv2_cpf = (cpf[10] - '0');
            if (dv1 == dv1_cpf && dv2 == dv2_cpf) {
                printf("CPF válido.\n");
            } else {
                if (dv1 != dv1_cpf) {
                    printf("CPF inválido: O digito de verificação 1 é inválido.\n");
                }
                if (dv2 != dv2_cpf) {
                    printf("CPF inválido: O digito de verificação 2 é inválido.\n");
                }
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
