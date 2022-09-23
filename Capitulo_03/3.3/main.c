#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h"

// A*B+C/D

int main() {
    char e[32];
    char *posfix;
    Pilha *p = pilha(32);

    printf("Infixa: ");
    fgets(e,31,stdin);
    posfix = posfixa(e);
    printf("Posfixa: %s\n", posfix);


    return 0;
}
