#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    char n[100], aux;

    printf("Expressao: ");
    scanf("%s", &n);

    Pilha *A = pilha(strlen(n));

    for (int i = 0; n[i] != '\0'; i++)
    {

        if (pilhaVazia(A))
        {
            push(n[i], A);
        }
        else
        {
            switch (getTopo(A))
            {
            case '[':
                if (n[i] == ')' || n[i] == '}')
                {
                    printf("Expressao nao balanceada \n!!");
                    abort();
                }
                else
                {
                    push(n[i], A);
                }
                break;
            case '{':
                if (n[i] == ')' || n[i] == ']')
                {
                    printf("Expressao nao balanceada \n!!");
                    abort();
                }
                else
                {
                    push(n[i], A);
                }
                break;
            case '(':
                if (n[i] == '}' || n[i] == ']')
                {
                    printf("Expressao nao balanceada \n!!");
                    abort();
                }
                else
                {
                    push(n[i], A);
                }
                break;
            }
        }
    }
    printf("Expressao Balanceada");

    return 0;
}
