/* 
 * Faça uma função interface() que imprime um menu de operações matemáticas na tela 
 * (1–soma, 2–subtração, 3–multiplicação, 4–divisão e 5–potência).
 * Obtenha a opção escolhida pelo usuário e retorne-a como resultado da interface.
 * Este valor deverá ser tratado pela função main(), que irá processar a escolha,
 * encaminhando o usuário para função específica.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int interface() {
    int op;
    printf("------ OPERAÇÕES MATEMÁTICAS ------\n");
    printf("1 - Soma\n2 - Subtração\n3 - Multiplicação\n4 - Divisão\n5 - Potência\n");
    printf("Digite o número da operação: ");
    scanf(" %i", &op);
    return op;
}

double soma(double a, double b) {
    return a + b;
}

double subtracao(double a, double b) {
    return a - b;
}

double multiplicacao(double a, double b) {
    return a * b;
}

double divisao(double a, double b) {
    if (!b) {
        printf("\nERRO: Não é possível realizar divisão por zero.\n");
        return 0;
    }
    return a / b;
}

double potencia(double base, int expoente) {
    double resultado = 1.0;

    int negativo = expoente < 0;
    int expoente_abs = expoente < 0 ? expoente * (-1) : expoente;

    for (int i = 0; i < expoente_abs; i++) {
        resultado *= base;
    }

    if (negativo) return 1.0 / resultado;

    return resultado;
}

int main() {
    int operacao;
    while (1) {
        system("clear");
        operacao = interface();
        if (operacao < 1 || operacao > 5) {
            printf("\nERRO: Número de operação inválido.\n");
            printf("Pressione ENTER para tentar novamente...\n");
            while (getchar() != '\n') {};
            getchar();
            continue;
        }
        break;
    }

    double A, B, resultado;
    printf("\nDigite o valor de A: ");
    scanf(" %lf", &A);
    printf("Digite o valor de B: ");
    scanf(" %lf", &B);

    switch (operacao) {
        case 1:
            resultado = soma(A, B);
            printf("Resultado: %.2lf + %.2lf = %.2lf\n", A, B, resultado);
            break;
        case 2:
            resultado = subtracao(A, B);
            printf("Resultado: %.2lf - %.2lf = %.2lf\n", A, B, resultado);
            break;
        case 3:
            resultado = multiplicacao(A, B);
            printf("Resultado: %.2lf * %.2lf = %.2lf\n", A, B, resultado);
            break;
        case 4:
            resultado = divisao(A, B);
            if (!B) break;
            printf("Resultado: %.2lf / %.2lf = %.2lf\n", A, B, resultado);
            break;
        case 5:
            resultado = potencia(A, (int)B);
            printf("Resultado: %.2lf elevado a %.2lf = %.2lf\n", A, B, resultado);
            break;
    }
    return 0;
}
