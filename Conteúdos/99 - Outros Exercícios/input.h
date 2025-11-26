#ifndef INPUT_H
#define INPUT_H

#include <stdio.h>

#define INT " %d"
#define STR " %[^\n]s"
#define FLOAT " %f"
#define CHAR " %c"

void input(char tipo[], char label[], void* pont) {
    printf("%s", label);
    scanf(tipo, pont);
    while (getchar() != '\n') {};
}

#endif
