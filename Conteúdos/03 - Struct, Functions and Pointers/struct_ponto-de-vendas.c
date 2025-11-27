/* REQUISITOS DA APLICAÇÃO

1- DEVE SER POSSÍVEL CADASTRAR ATÉ 100 PRODUTOS.
2- TODO PRODUTO DEVE TER CODIGO ÚNICO (GARANTIDO PELO SW).
3- SAÍDA DO CADASTRO DE PRODUTOS SERÁ CODIGO <= 0;

FASE DE VENDAS!
1- SOLICITAR CODIGO DE ITEM PARA VENDA:
	1.1- VERIFICAR SE ITEM EXISTE
		1.1.1- IMPRIMIR TODOS OS DADOS DO PRODUTO, OU
		1.1.2- CODIGO NÃO EXISTENTE! TENTAR NOVAMENTE.

	1.2. SOLICITAR QUANTIDADE DESTE MESMO ITEM NO CARRINHO
		1.2.1- VERIFICAR SE A QTDE. ESTÁ DISPONÍVEL
		1.2.2- ATUALIZAR ESTOQUE DO ITEM
		
2. REPETIR TODO PROCESSO DE VENDA DO CARRINHO ATÉ CÓDIGO <=0

3. INFORMAR TOTAL DA VENDA
4. INFORMAR VALOR PAGO
5. INFORMAR TROCO DA VENDA

6. PERGUNTAR SE HÁ NOVO CARRINHO DE COMPRAS
	6.1. REPETIR TODO PROCESSO PARA NOVO CARRINHO.

7. NÃO HAVENDO...
	7.1 RELATÓRIO ATUALIZADO DE TODOS OS PRODUTOS
	7.2 FATURAMENTO DO DIA (TOTAL DE VENDAS)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DB 100

typedef struct {
    char nome[100];
    char descricao[500];
    int codigo;
    float valor;
    int estoque, estoque_inicial;
} Produto;

int main() {
    // Cadastro de produtos
    Produto produtos[MAX_DB];

    int contP = 0;
    while (1) {
        system("clear");

        // Ordenação por código
        for (int i = 1; i < contP; i++) {
            int j = i - 1;
            while (j >= 0 && produtos[j].codigo > produtos[j + 1].codigo) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
                j--;
            }
        }

        printf("------ CADASTRO DE PRODUTOS ------\n\n");
        printf("OBS: Digite um valor menor ou igual a '0' para finalizar o cadastro de produtos.\n\n");

        printf("Digite o código: ");
        scanf(" %i", &produtos[contP].codigo);

        // Verificação de encerramento
        if (!produtos[contP].codigo) {
            printf("\nCadastro de produtos encerrado.\n");
            printf("Pressione ENTER para avançar para as vendas...");
            while (getchar() != '\n') {};
            getchar();
            break;
        }

        // Verificação se o código já está cadastrado
        if (contP) {
            int inc = 0, fim = contP - 1, existe = 0;
            while (inc <= fim) {
                int meio = (inc + fim) / 2;
                if (produtos[meio].codigo == produtos[contP].codigo) {
                    existe++;
                    break;
                } else if (produtos[meio].codigo > produtos[contP].codigo) {
                    fim = meio - 1;
                } else {
                    inc = meio + 1;
                }
            }

            if (existe) {
                printf("INFO: Código de produto já cadastrado.\n\nPor favor, tente novamente.\n");
                printf("Pressione ENTER para continuar...");
                while (getchar() != '\n') {};
                getchar();
                continue;
            }
        }

        printf("Digite o nome: ");
        scanf(" %[^\n]", produtos[contP].nome);
        printf("Digite a descrição: ");
        scanf(" %[^\n]", produtos[contP].descricao);
        printf("Digite o valor: ");
        scanf(" %f", &produtos[contP].valor);
        printf("Digite a quantidade do estoque: ");
        scanf(" %i", &produtos[contP].estoque);

        // Definição do estoque definido inicialmente
        produtos[contP].estoque_inicial = produtos[contP].estoque;

        contP++;

        if (contP == MAX_DB) {
            printf("\nA quantidade máxima de produtos cadastrados foi atingida.\n");
            printf("Pressione ENTER para encerrar...");
            while (getchar() != '\n') {};
            getchar();
            break;
        }
    }

    float total_faturado = 0.0, valor_total = 0.0, valor_pago, troco_venda;
    while (1) {
        system("clear");

        printf("------ CARRINHO DE COMPRAS ------\n\n");
        printf("OBS: Digite um valor menor ou igual a '0' para finalizar a venda do carrinho.\n\n");

        int codigo_produto;
        printf("Informe o código do produto: ");
        scanf(" %i", &codigo_produto);

        // Finalização de carrinho de compras
        if (codigo_produto <= 0) {
            system("clear");

            printf("------ PAGAMENTO ------\n\n");

            // Pagamento do carrinho de compras
            printf("Valor total do carrinho: R$%.2f\n\n", valor_total);
            printf("Informe o valor pago: ");
            scanf(" %f", &valor_pago);

            troco_venda = valor_pago - valor_total;
            printf("Troco do pagamento: R$%.2f\n\n", troco_venda);

            // Encerramento ou novas vendas
            char opcao;
            printf("Deseja criar um Novo Carrinho de Compras? (S/N) ");
            scanf(" %c", &opcao);

            // Incrementação do total faturado no dia
            total_faturado += valor_total;

            // Reiniciando as váriaveis de valor
            valor_total = valor_pago = troco_venda = 0.0;

            if (opcao == 'N') {
                printf("\nVenda de produtos encerrada.\n");
                printf("Pressione ENTER para avançar para o relatório...");
                while (getchar() != '\n') {};
                getchar();
                break;
            }

            continue;
        }

        // Verificação de existência do produto
        int inc = 0, fim = contP - 1, indice_produto = -1;
        while (inc <= fim) {
            int meio = (inc + fim) / 2;
            if (produtos[meio].codigo == codigo_produto) {
                indice_produto = meio;
                break;
            } else if (produtos[meio].codigo > codigo_produto) {
                fim = meio - 1;
            } else {
                inc = meio + 1;
            }
        }

        if (indice_produto < 0) {
            printf("\nCódigo inexistente.\nPor favor, tente novamente.");
            printf("Pressione ENTER para continuar...");
            while (getchar() != '\n') {};
            getchar();
            continue;
        }

        Produto produto = produtos[indice_produto];

        printf("\n--> Produto\n");
        printf("Código do produto: %i\nNome do produto: %s\nDescrição do produto: %s\nPreço do produto: %.2f\nQuantidade em estoque: %i\n\n", produto.codigo,
               produto.nome, produto.descricao, produto.valor, produto.estoque);

        int q_compra;
        printf("Informe a quantidade de itens: ");
        scanf(" %i", &q_compra);

        if (produto.estoque < q_compra) {
            printf("Quantidade de itens do produto indisponível.\n");
            printf("Pressione ENTER para continuar...");
            while (getchar() != '\n') {};
            getchar();
            continue;
        }

        // Atualizando o estoque
        produtos[indice_produto].estoque -= q_compra;

        // Incrementação do valor das compras
        valor_total += (produto.valor * q_compra);
    }

    // Relatório final
    system("clear");
    printf("------- RELATÓRIO DE VENDAS ------\n\n");
    printf("--> Relatório referente aos produtos\n\n");
    for (int i = 0; i < contP; i++) {
        Produto produto = produtos[i];
        int unidades_vendidas = (produto.estoque_inicial - produto.estoque);
        printf(
            "Produto %03i:\n - Código do produto: %i\n - Nome do produto: %s\n - Estoque inicial: %i\n - Estoque atual: %i\n - Total de unidades vendidas: %i\n - Total faturado: R$%.2f\n\n",
            (i + 1), produto.codigo, produto.nome, produto.estoque_inicial, produto.estoque, unidades_vendidas, (produto.valor * unidades_vendidas));
    }

    printf("--> Relatório refente ao faturamento\n\n");
    printf("Faturamento total: R$%.2f\n", total_faturado);

    return 0;
}
