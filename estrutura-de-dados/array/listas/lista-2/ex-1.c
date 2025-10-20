/*
 * Gere um vetor com 30 valores inteiros que representam a umidade relativa do ar em cada dia deste
 * período. Alimente o vetor com valores aleatórios entre 12 e 80. Conte e escreva os dias com maior e
 * menor umidade relativa, a média mensal, e a quantidade de dias acima da média.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int vet_size = 30, vet[vet_size];
    int min = 12, max = 80;
    int dia_maior_umidade, maior_umidade, dia_menor_umidade, menor_umidade, soma_mensal = 0, cont_acima_media = 0;
    float media_mensal;

    // Preenchimento do vetor com valores aleatorios de 12 a 80
    for (int i = 0; i < vet_size; i++)
        vet[i] = min + rand() % (max - min + 1);

    for (int i = 0; i < vet_size; i++) {
        soma_mensal += vet[i];

        // Inicializa os valores de maior e menor umaidade
        if (!i) {
            maior_umidade = menor_umidade = vet[i];
            dia_maior_umidade = dia_menor_umidade = (i + 1);
        }

        // Verifica quais oo maior e menor umidade relativa
        if (vet[i] > maior_umidade) {
            maior_umidade = vet[i];
            dia_maior_umidade = (i + 1);
        }
        if (vet[i] < menor_umidade) {
            menor_umidade = vet[i];
            dia_menor_umidade = (i + 1);
        }
    }

    // Calculo da média mensal de umidade relativa
    media_mensal = (float)soma_mensal / vet_size;

    // Contagem dos dias com umidade acima da media
    for (int i = 0; i < vet_size; i++) {
        if (vet[i] > media_mensal)
            cont_acima_media++;
    }

    printf(
        "Maior umidade relativa: Dia %d com %d%% \nMenor umidade relativa: Dia %d com %d%% \nMedia mensal da umidade relativa: %.2f%% \nQuantidade de dias com "
        "umidade relativa acima da media: %d dia(s)\n",
        dia_maior_umidade, maior_umidade, dia_menor_umidade, menor_umidade, media_mensal, cont_acima_media);
    return 0;
}
