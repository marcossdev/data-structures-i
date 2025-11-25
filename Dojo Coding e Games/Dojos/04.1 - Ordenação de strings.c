#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(){

	char palavras[100][50];
	char sorteadas[10][50];
	
	srand(time(NULL));
	
	FILE* archive;
	
	archive = fopen("livros-fantasia-[dojo-4].txt", "r");
	
	int cont = 0, esc1, esc2, ok = 0, tent = 0;
	
	while(1){
		fscanf(archive, " %[^\n]s", palavras[cont]);
		cont++;
		if(feof(archive)){
			break;
		}
		
	}
	
	int idc = 0;
	do{
		int repeat = 0;
		int randIDC = rand() % 100;
		
		if (idc) {
			for(int i = 0; i < idc; i++)
				if (!strcmp(sorteadas[i], palavras[randIDC])) {
					repeat = 1;
					break;
				}
		} 
		
		if (repeat) continue;
		
		strcpy(sorteadas[idc], palavras[randIDC]);
		idc++;
	} while(idc < 10);
	
	while (ok != 1) {
		system("clear");
		for(int i = 0; i < 10; i++){
			printf("[ %i ] %s\n",i , sorteadas[i]);
		}
		
		char temp[50];
		printf("Digite um par: ");
		scanf(" %i %i", &esc1, &esc2);
		
		tent++;
		
		strcpy(temp, sorteadas[esc1]);
		strcpy(sorteadas[esc1], sorteadas[esc2]);
		strcpy(sorteadas[esc2], temp);
		
		for (int i = 0; i < 9; i++) {
			if (strcmp(sorteadas[i], sorteadas[i+1]) <= 0) {
				ok = 1;
			} else {
				ok = 0;
				break;
			}
		}
	}
	
	system("clear");
	for(int i = 0; i < 10; i++){
		printf("[ %i ] %s\n",i , sorteadas[i]);
	}
	
	printf("\nVOÇÊ PRECISOU DE %i TENTATIVAS PARA FINALIZAR", tent);
}
