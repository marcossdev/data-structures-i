#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ALUNOS 1000

typedef struct {
    char nome[100];
    int numero_matricula;
    char nome_disciplina[100];
    float nota_final;
} Aluno;

int main() {
    Aluno alunos[MAX_ALUNOS];

    int contA = 0;
    while (contA < MAX_ALUNOS) {
        system("clear");
        printf("------ CADASTRO DE ALUNOS E NOTAS ------\n\n");
        printf("OBS: Digite 'exit' em 'nome' para encerrar\n\n");
        printf("Digite o nome: ");
        scanf(" %[^\n]s", alunos[contA].nome);

        if (!strcmp(alunos[contA].nome, "exit")) {
            system("clear");
            break;
        }

        printf("Digite o número de matricula: ");
        scanf(" %i", &alunos[contA].numero_matricula);
        printf("Digite o nome da disciplina: ");
        scanf(" %[^\n]s", alunos[contA].nome_disciplina);
        printf("Digite a nota final na disciplina: ");
        scanf(" %f", &alunos[contA].nota_final);

        contA++;

        printf("\nCadastrado.\n");

        if (contA == MAX_ALUNOS) {
            printf("\nA quantidade máxima de alunos cadastrados foi alcançada.\n");
        }

        printf("Pressione ENTER para continuar...");
        while (getchar() != '\n') {};
        getchar();
    }

    while (1) {
        system("clear");
        int matricula_busca;
        printf("-> Pesquisa de alunos\n\nOBS: Digite um valor negativo para encerrar.\n\n");
        printf("Digite o número da matrícula: ");
        scanf(" %i", &matricula_busca);

        if (matricula_busca < 0) {
            printf("\nPrograma encerrado.\n");
            break;
        }

        // Ordenação
        Aluno aluno;
        int encontrado = 0;
        for (int i = 0; i < contA; i++) {
            aluno = alunos[i];
            if (aluno.numero_matricula == matricula_busca) {
                encontrado++;
                break;
            }
        }

        if (encontrado) {
            printf("\nAluno:\n");
            printf(" - Nome: %s\n - Matricula: %i\n - Disciplina: %s\n - Nota final na disciplina: %.2f\n", aluno.nome, aluno.numero_matricula,
                   aluno.nome_disciplina, aluno.nota_final);
        } else {
            printf("Aluno com matricula %i não encontrado!\n", matricula_busca);
        }

        printf("\nPressione ENTER para continuar...");
        while (getchar() != '\n') {};
        getchar();
    }

    return 0;
}
