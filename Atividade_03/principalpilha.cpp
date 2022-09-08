#include <stdio.h>
#include <stdlib.h>
#include "pilha1.h"


int main() {
    Pilha *p = pilha(5);
    char s[11];
    for (int i=1; i<=3; i++){
        printf("?\n");
        fgets(s,50, stdin);
        push(s[i],p);
    }
    while (!pilhaVazia(p)) {
        putchar(pop(p));
    }

    return 0;
}
