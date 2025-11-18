#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 10

typedef struct {
    char rua[100];
    int numero;
    char bairro[100];
    char cidade[100];
    char estado[100];
} Endereco;

typedef struct {
    char nome[100];
    char cpf[12];
    int idade;
    float altura, peso;
    Endereco endereco;
} Pessoa;

int main() {
    Pessoa pessoas[MAX];
    int idc = 0;
    while (idc < MAX) {
        system("clear");
        printf("------ CADASTRO DE PESSOAS ------\n\n");
        printf("OBS: Digite 'exit' em 'nome' para encerrar.\n\n");

        printf("-> Dados básicos\n");
        printf("Digite o nome: ");
        scanf(" %[^\n]s", pessoas[idc].nome);

        // Encerrar o loop
        if (!strcmp(pessoas[idc].nome, "exit")) {
            break;
        }

        // Dados básicos
        printf("Digite o CPF: ");
        scanf(" %[^\n]s", pessoas[idc].cpf);
        printf("Digite a idade: ");
        scanf(" %i", &pessoas[idc].idade);
        printf("Digite a altura: ");
        scanf(" %f", &pessoas[idc].altura);
        printf("Digite a peso: ");
        scanf(" %f", &pessoas[idc].peso);

        // Endereço
        printf("\n-> Dados do endereço\n");
        printf("Digite a rua: ");
        scanf(" %[^\n]s", pessoas[idc].endereco.rua);
        printf("Digite o número: ");
        scanf(" %i", &pessoas[idc].endereco.numero);
        printf("Digite o bairro: ");
        scanf(" %[^\n]s", pessoas[idc].endereco.bairro);
        printf("Digite o cidade: ");
        scanf(" %[^\n]s", pessoas[idc].endereco.cidade);
        printf("Digite o estado: ");
        scanf(" %[^\n]s", pessoas[idc].endereco.estado);

        idc++;

        printf("\nRegistrado.\n");
        printf("Pressione ENTER para avançar...\n");
        while (getchar() != '\n') {};
        getchar();
    }

    system("clear");

    int quantity = idc;

    // Ordenação por ordem alfabética
    for (int i = 1; i < quantity; i++) {
        Pessoa pessoa = pessoas[i];
        int j = i - 1;
        while (j >= 0 && strcmp(pessoas[j].nome, pessoa.nome) > 0) {
            pessoas[j + 1] = pessoas[j];
            j--;
        }
        pessoas[j + 1] = pessoa;
    }

    // Impressão
    printf("------ PESSOAS REGISTRADAS ------\n\n");
    for (int i = 0; i < quantity; i++) {
        Pessoa pessoa = pessoas[i];
        printf(
            "-> Pessoa %02d\nNome: %s\nCPF: %s\nIdade: %i\nAltura: %.2f\nPeso: %.2f\nEndereço:\n - Rua: %s\n - Número: %i\n - Bairro: %s\n - Cidade: %s\n - Estado: %s\n\n",
            (i + 1), pessoa.nome, pessoa.cpf, pessoa.idade, pessoa.altura, pessoa.peso, pessoa.endereco.rua, pessoa.endereco.numero, pessoa.endereco.bairro,
            pessoa.endereco.cidade, pessoa.endereco.estado);
    }

    return 0;
}
