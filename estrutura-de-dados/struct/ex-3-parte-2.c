#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DISCIPLINAS 10
#define MAX_ALUNOS 1000

typedef struct {
    char nome[100];
    float nota_final;
} Disciplina;

typedef struct {
    char nome[100];
    int numero_matricula;
    int cont_diciplinas;
    Disciplina disciplinas[10];
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

        int contD = 0;
        printf("\n-> Cadastro de disciplinas do aluno\n\n");
        while (contD < MAX_DISCIPLINAS) {
            printf("-> Diciplina %02i\n", (contD + 1));
            printf("Digite o nome da disciplina ('exit' para finalizar): ");
            scanf(" %[^\n]s", alunos[contA].disciplinas[contD].nome);

            if (!strcmp(alunos[contA].disciplinas[contD].nome, "exit")) {
                break;
            }

            printf("Digite a nota final: ");
            scanf(" %f", &alunos[contA].disciplinas[contD].nota_final);

            printf("\n");
            contD++;
        }

        if (contD == MAX_DISCIPLINAS) {
            printf("O aluno alcançou o número máximo de disciplinas (%i).\n", contD);
        }

        alunos[contA].cont_diciplinas = contD;

        contA++;

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
            printf(" - Nome: %s\n - Número de matricula: %i\n", aluno.nome, aluno.numero_matricula);
            for (int i = 0; i < aluno.cont_diciplinas; i++)
                printf("\n- Diciplina %02i:\n  - None: %s\n  - Nota final na disciplina: %.2f\n", (i + 1), aluno.disciplinas[i].nome,
                       aluno.disciplinas[i].nota_final);

        } else {
            printf("Aluno com número de matricula %i não encontrado!\n", matricula_busca);
        }

        printf("\nPressione ENTER para continuar...");
        while (getchar() != '\n') {};
        getchar();
    }

    return 0;
}
