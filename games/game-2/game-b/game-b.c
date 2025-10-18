/* GAME: Memória de Cartas */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int q_pares;

    printf("================= JOGO DA MEMÓRIA [PARES DE CARTAS] =================\n\n");

    do {
        printf("Com quantos pares de cartas deseja jogar? ");
        scanf(" %d", &q_pares);
    } while (q_pares < 1);

    int q_cartas = q_pares * 2;

    // Geração dos valores que ficaram no baralho
    int valores[q_cartas];
    for (int i = 0; i < q_cartas; i++) {
        valores[i] = (i + 1);
    }
    for (int i = 0; i < q_cartas / 2; i++) {
        valores[q_cartas / 2 + i] = valores[i];
    }

    int baralho[q_cartas], preenchidos[q_cartas], descobertos[q_cartas];
    int cont = 0, tentativas = 0;

    // Embaralhando e preenchendo baralho
    while (cont < q_cartas) {
        int rand_indice = rand() % q_cartas;
        int tem_numero = 0;

        for (int i = 0; i < q_cartas; i++) {
            if (preenchidos[i] == rand_indice) {
                tem_numero = 1;
                break;
            }
        }

        if (!tem_numero) {
            baralho[rand_indice] = valores[cont];
            preenchidos[cont] = rand_indice;
            cont++;
        }
    }

    cont = 0;
    do {
        int idc_a, idc_b;

        while (1) {
            system("clear");
            printf("================= JOGO DA MEMÓRIA [PARES DE CARTAS] =================\n\n");

            // Imprime as cartas que não foram descobertas
            for (int i = 0; i < q_cartas; i++) {
                int ja_descoberto = 0;

                for (int j = 0; j < cont; j++) {
                    if (descobertos[j] == i) {
                        ja_descoberto = 1;
                    }
                }

                if (ja_descoberto) {
                    printf("   ");
                    continue;
                }

                printf("[] ");
            }
            printf("\n");
            for (int i = 0; i < q_cartas; i++) {
                int ja_descoberto = 0;

                for (int j = 0; j < cont; j++) {
                    if (descobertos[j] == i) {
                        ja_descoberto = 1;
                    }
                }

                if (ja_descoberto) {
                    printf("   ");
                    continue;
                }

                printf("%02d ", i);
            }
            printf("\n\n");

            printf("Escolha um PAR de cartas:\n");
            scanf(" %d %d", &idc_a, &idc_b);

            // Verificação dos indices inseridos pelo jogador
            int idc_correto = 1;

            if (idc_a > (q_cartas - 1) || idc_b > (q_cartas - 1)) {
                idc_correto = 0;
            }
            if (idc_a < 0 || idc_b < 0) {
                idc_correto = 0;
            }
            if (idc_a == idc_b) {
                idc_correto = 0;
            }
            for (int j = 0; j < cont; j++) {
                if (descobertos[j] == idc_a || descobertos[j] == idc_b) {
                    idc_correto = 0;
                    break;
                }
            }

            if (!idc_correto) {
                while (getchar() != '\n') {};
                printf("Entrada inválida! Tente novamente...\n");
                getchar();
                continue;
            }

            tentativas++;
            break;
        }

        system("clear");
        printf("================= JOGO DA MEMÓRIA [PARES DE CARTAS] =================\n\n");

        // Imprime as cartas que não foram descobertas
        for (int i = 0; i < q_cartas; i++) {
            int ja_descoberto = 0;

            for (int j = 0; j < cont; j++) {
                if (descobertos[j] == i) {
                    ja_descoberto = 1;
                }
            }

            if (ja_descoberto) {
                printf("   ");
                continue;
            }

            if (!(i == idc_a || i == idc_b)) {
                printf("[] ");
                continue;
            }
            printf("%02d ", baralho[i]);
        }
        printf("\n");
        for (int i = 0; i < q_cartas; i++) {
            int ja_descoberto = 0;

            for (int j = 0; j < cont; j++) {
                if (descobertos[j] == i) {
                    ja_descoberto = 1;
                }
            }

            if (ja_descoberto) {
                printf("   ");
                continue;
            }
            printf("%02d ", i);
        }
        printf("\n\n");

        // Mensagens se encontrou e não encontrou o par de cartas
        if (baralho[idc_a] == baralho[idc_b]) {
            printf("SHOW! Você encontrou um par \\o/\n");
            descobertos[cont] = idc_a;
            descobertos[cont + 1] = idc_b;
            cont += 2;
        } else {
            printf("Ainda não foi dessa vez :(\n");
        }

        // Verificação para finalizar o jogo
        if (cont == q_cartas) {
            system("clear");
            printf("================= JOGO DA MEMÓRIA [PARES DE CARTAS] =================\n\n");
            printf("JOGO FINALIZADO!! :D\n");
            printf("VOÇÊ PRECISOU DE %d TENTATIVAS PARA FINALIZAR. ", tentativas);
            break;
        }

        while (getchar() != '\n') {};
        getchar();
    } while (1);

    return 0;
}
