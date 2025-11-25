#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 9

int main () {
	srand(time(NULL));

	int cartas[SIZE];

	for (int i = 0; i < SIZE; i++)
		cartas[i] = 1 + rand() % 13;

	printf("Cartas desordenadas: ");
	for (int i = 0; i < SIZE; i++)
		printf("[%02d] ", cartas[i]);
	printf("\n");

	int indice = 0, c;

	while (1) {
		for (int i = 1; i < SIZE; i++) {
			int j = i-1;
			while (j >= 0 && cartas[j] > cartas[j+1]) {
				int temp = cartas[j];
				cartas[j] = cartas[j+1];
				cartas[j+1] = temp;
				j--;
			}
		}

		if (indice == SIZE) {
			printf("PARABENS!\n");
			break;
		};
		
		printf("Cartas ordenadas: ");
		for (int i = indice; i < SIZE; i++) {
			printf("[%02d] ", cartas[i]);
		}
		printf("\n");

		// Verificação de trinca
		int cont = 0;
		for (int i = indice; i < SIZE-1; i++) {
			if (cartas[i] == cartas[i+1] && cartas[i] == cartas[i+2]) {
				indice += 3;

				printf("Trinca: [%i] [%i] [%i]\n\n", cartas[i], cartas[i+1], cartas[i+2]);
				cartas[i] = cartas[i+1] = cartas[i+2] = 0;
				
				cont++;
				break;
			}

			if (cartas[i]+1 == cartas[i+1] && cartas[i+1]+1 == cartas[i+2]) {
				indice += 3;

				printf("Trinca: [%i] [%i] [%i]\n\n", cartas[i], cartas[i+1], cartas[i+2]);
				cartas[i] = cartas[i+1] = cartas[i+2] = 0;
				
				cont++;
				break;
			}
		}

		if (cont) {
			continue;
		}

		printf("\nEscolha uma carta para substituir: ");
		scanf(" %d", &c);

		if (c < 1 || c > 13) {
			printf("Carta inválida!\n\n");
			continue;
		}

		int inc = indice;
		int fim = SIZE;
		int indiceC = -1;

		while (inc <= fim) {
			int meio = (inc+fim)/2;

			if (c == cartas[meio]) {
				indiceC = meio;
				break;
			} else if (c > cartas[meio]) {
				inc = meio + 1;
			} else {
				fim = meio - 1;
			}
		}

		if (indiceC < 0) {
			printf("Carta não disponível!\n\n");
			continue;
		}

		cartas[indiceC] = 1 + rand() % 13;

		printf("\nA carta %i foi substituida por %i.\n\n", c, cartas[indiceC]);
	} 
	
	
	return 0;
}
