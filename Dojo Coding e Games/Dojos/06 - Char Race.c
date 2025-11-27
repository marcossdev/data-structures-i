#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define SIZE 70

typedef struct {
    char nome[11];
    char symbol;
    int distance;
} Player;

// Game functions
int getNumPlayers();
void configPlayers(Player[], int);
void loadingRace();
void runPlayers(Player[], int);
void sortPlayers(Player[], int);
void printRace(Player[], int, int);
int runRace(Player[], int);
void printResults(Player[], int);

// Utils
void printTitle();
void clearBuffer();

int main() {
    srand(time(NULL));

    int player_quantity = getNumPlayers();

    Player players[player_quantity];
    configPlayers(players, player_quantity);
    loadingRace();

    do {
        runPlayers(players, player_quantity);
        sortPlayers(players, player_quantity);
        printRace(players, player_quantity, 1);
    } while (runRace(players, player_quantity));

    printResults(players, player_quantity);

    return 0;
}

void printTitle() {
    system("clear");
    printf("============================== CHAR RACE =============================\n\n");
}

void clearBuffer() {
    while (getchar() != '\n') {};
}

int getNumPlayers() {
    int quantity;

    do {
        printTitle();
        printf("Quantos Competidores na Corrida? ");
        scanf(" %i", &quantity);
        clearBuffer();

        if (quantity <= 1) {
            printf("\nERRO: A quantidade players deve ser maior do que 1.\n");
            printf("Pressione ENTER para continuar...");
            clearBuffer();
            continue;
        }
    } while (quantity <= 1);

    return quantity;
}

void configPlayers(Player players[], int size) {
    printTitle();
    printf("OBS: Informe o nome dos %i competidores (MAX 10 caracteres/nome), seguido de um símbolo(char).\n\n", size);

    int idc = 0;
    while (idc < size) {
        printf("Digite o NOME e o SÍMBOLO do %iº jogador: ", (idc + 1));
        scanf(" %[^ ] %c", players[idc].nome, &players[idc].symbol);
        clearBuffer();

        if (strlen(players[idc].nome) > 10) {
            printf("ERRO: O 'nome' deve conter no MÁXIMO 10 caractéres.\n\n");
            continue;
        }

        players[idc].distance = 0;
        idc += 1;
    }
}

void loadingRace() {
    printTitle();
    printf("Vai começar a corrida, todos aos seus postos...\n");
    sleep(2);
}

void runPlayers(Player players[], int size) {
    for (int i = 0; i < size; i++) {
        players[i].distance += 1 + rand() % 3;
        if (players[i].distance > SIZE - 11) players[i].distance = SIZE - 11;
    }
}

void sortPlayers(Player players[], int size) {
    for (int i = 1; i < size; i++) {
        int j = (i - 1);
        Player player = players[i];
        while (j >= 0 && players[j].distance < player.distance) {
            players[j + 1] = players[j];
            j--;
        }
        players[j + 1] = player;
    }
}

void printRace(Player players[], int size, int timeout) {
    printTitle();
    for (int i = 0; i < size; i++) {
        printf("%s", players[i].nome);
        for (int j = 0; j < 11 - strlen(players[i].nome); j++) {
            printf(" ");
        }

        for (int j = 0; j < players[i].distance; j++) {
            printf("%c", players[i].symbol);
        }

        int final_line_distance = 10 + players[i].distance;
        for (int j = 0; j < SIZE - final_line_distance - 1; j++) {
            printf(" ");
        }

        printf("|");
        printf("\n");
    }
    sleep(timeout);
}

int runRace(Player players[], int size) {
    for (int i = 0; i < size; i++) {
        if (players[i].distance == SIZE - 11) return 0;
    }
    return 1;
}

void printResults(Player players[], int size) {
    int contWin = 0;
    for (int i = 0; i < size; i++) {
        if (players[i].distance == SIZE - 11) contWin++;
    }

    if (contWin > 1) {
        printf("\nEMPATE!\n");
        return;
    }

    printf("\nO JOGADOR %s, GANHOU!\n", players[contWin - 1].nome);
}
