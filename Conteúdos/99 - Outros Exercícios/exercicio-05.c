#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "input.h"

#define MAX_DB_SIZE 100

typedef struct {
    char nome[100];
    int idade;
    float altura;
} Pessoa;

int interface();
void cadastrar(Pessoa[], int*);
void ordenar(Pessoa[], int);
void listar(Pessoa[], int);

int main() {
    Pessoa pessoas[MAX_DB_SIZE];

    int cont = 0;
    while (1) {
        system("clear");
        switch (interface()) {
            case 1:
                if (cont > MAX_DB_SIZE) {
                    printf("O cadastro de pessoas atingiu o volume máximo.\n");
                    break;
                }
                cadastrar(pessoas, &cont);
                break;
            case 2:
                ordenar(pessoas, cont);
                break;
            case 3:
                listar(pessoas, cont);
                break;
            default:
                return 0;
        }

        printf("\nPressione ENTER para continuar...\n");
        getchar();
    }
    return 0;
}

int interface() {
    int op;
    printf("1 - Cadastrar Pessoa\n");
    printf("2 - Ordenar Pessoas\n");
    printf("3 - Listar Pessoas\n");
    input(INT, "Opção Desejada: ", &op);
    return op;
}

void cadastrar(Pessoa pessoas[], int* indice) {
    Pessoa* p = &pessoas[*indice];

    printf("\n --> CADASTRO\n");
    input(STR, "Nome: ", p->nome);
    input(INT, "Idade: ", &p->idade);
    input(FLOAT, "Altura: ", &p->altura);

    *indice += 1;
    printf("\nINFO: Cadastro realizado com sucesso.\n");
}

void listar(Pessoa pessoas[], int tamanho) {
    if (!tamanho) {
        printf("\nINFO: Nenhuma pessoa cadastrada\n");
        return;
    }

    printf("\n--> PESSOAS CADASTRADAS\n");
    for (int i = 0; i < tamanho; i++) {
        Pessoa p = pessoas[i];
        printf("Pessoa nº %i:\n - Nome: %s\n - Idade: %i\n - Altura: %.2f\n\n", (i + 1), p.nome, p.idade, p.altura);
    }
}

void ordenar(Pessoa pessoas[], int tamanho) {
    if (!tamanho) {
        printf("\nINFO: Nenhuma pessoa cadastrada\n");
        return;
    }

    for (int i = 1; i < tamanho; i++) {
        int j = i - 1;
        Pessoa key = pessoas[i];

        // Ordenação por ordem alfabética
        while (j >= 0 && strcmp(pessoas[j].nome, key.nome) > 1) {
            pessoas[j + 1] = pessoas[j];
            j--;
        }
        pessoas[j + 1] = key;
    }

    printf("\nINDO: Ordenado com sucesso.\n");
}
