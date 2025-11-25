#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char nome[100];
    char cpf[12];
    int idade;
    float altura, peso;
} Pessoa;

int main() {
    Pessoa pessoa;

    printf("-> Preenchimento de dados\n");
    printf("Digite o nome: ");
    scanf(" %[^\n]s", pessoa.nome);
    printf("Digite o CPF: ");
    scanf(" %[^\n]s", pessoa.cpf);
    printf("Digite a idade (em metros): ");
    scanf(" %i", &pessoa.idade);
    printf("Digite a altura: ");
    scanf(" %f", &pessoa.altura);
    printf("Digite o peso: ");
    scanf(" %f", &pessoa.peso);

    system("clear");

    printf("-> Dados preenchidos\n");
    printf("Nome: %s\nCPF: %s\nIdade: %i\nAltura: %.2f\nPeso: %.2f\n\n", pessoa.nome, pessoa.cpf, pessoa.idade, pessoa.altura, pessoa.peso);

    float imc = pessoa.peso / (pessoa.altura * pessoa.altura);
    printf("IMC: %.2f - ", imc);
    if (imc < 18.5) {
        printf("Abaixo do peso\n");
    } else if (imc >= 18.5 || imc < 25) {
        printf("Saudável\n");
    } else if (imc >= 25 || imc < 30) {
        printf("Acima do peso\n");
    } else {
        printf("Obesidade\n");
    }
    return 0;
}
