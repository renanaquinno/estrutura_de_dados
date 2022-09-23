#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h"

int main() {
    char e[32];
    char *posfix;
    int y;
    int x;
    int n;
    Pilha *p = pilha(32);

    printf("Infixa: ");
    fgets(e,31,stdin);
    posfix = posfixa(e);
    printf("Posfixa: %s\n", posfix);

// ((2*3)+(8/4))
// ((2+3)+(8+4))
    for (int i = 0; posfix[i]; i++){
        if (isdigit(posfix[i])){
            push(posfix[i] - '0',p);
        } else {
            y = pop(p);
            x = pop(p);
            switch(posfix[i]){
                case '+':
                    push(y+x,p);
                    break;
                case '-':
                    push(y-x,p);
                    break;
                case '*':
                    push(y*x,p);
                    break;
                case '/':
                    if (x > y){
                        push(x/y,p);
                    } else {
                        push(y/x,p);
                    }
                    break;
            }
        }
    }

    printf("Resultado: %s",desempilha(p));

    return 0;
}
