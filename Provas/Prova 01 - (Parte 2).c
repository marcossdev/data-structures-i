/* 
 * Prova 01 - (Parte 2)
 * Questão #02
 * Continuando o problema anterior, faça outro experimento baseado na mesma premissa do Paradoxo do Aniversário, e desenvolva um programa que faça simulações para responder a seguinte pergunta…
 * QUANTOS “DIAS” SERIAM NECESSÁRIOS EXISTIR PARA QUE UM DETERMINADO GRUPO ALEATÓRIO DE “N” PESSOAS TEREM PROBABILIDADE INFERIOR A 10% DE FAZER ANIVERSÁRIO NA MESMA DATA?
 * Observação! Para diminuir o tempo de processamento deste problema, reduza o número de cenários realizados para cada experimento de 100.000 para apenas 300 cenários de N pessoas aleatórias.
 * Seu programa deve rodar o experimento 10 vezes para cada valor de N informado. Para encerrar a execução, o valor de N deverá ser menor ou igual a 0.
 * Alguns resultados de referência (considerando 300 simulações para cada grupo de N pessoas)…
 * N: Qtde. Pessoas Qtde. de “Dias” Necessários
 * 10 Algo entre 200 e 400
 * 20 Algo entre 1000 e 1400
 * 25 Algo entre 1600 e 2000
 * 30 Algo entre 2300 e 2900
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIMULACAO 300

int main() {
    srand(time(NULL));

    int N;

    while (1) {
        printf("Digite um valor para N: ");
        scanf(" %i", &N);

        if (N <= 0) {
            break;
        }

        for (int v = 0; v < 10; v++) {
            int dias = 1;
            while (1) {
                int contMD = 0;

                for (int sml = 0; sml < SIMULACAO; sml++) {
                    int datas[N];

                    for (int i = 0; i < N; i++) {
                        datas[i] = 1 + rand() % dias;
                    }

                    int fazemMD = 0;
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                            if (i != j && datas[i] == datas[j]) {
                                fazemMD++;
                                break;
                            }
                        }
                        if (fazemMD) {
                            break;
                        };
                    }

                    if (fazemMD) {
                        contMD++;
                    }
                }

                float percent = ((float)contMD / SIMULACAO) * 100;

                if (percent < 10.0) {
                    break;
                }

                dias++;
            }

            printf("Days: %i\n", dias);
        }
    }
    return 0;
}
