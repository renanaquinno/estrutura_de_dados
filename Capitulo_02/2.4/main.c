#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    int n, valor;

    printf("Quantidade de Numeros: ");
    scanf("%d", &n);

    Pilha *A = pilha(n);
    Pilha *B = pilha(n);

    for(int i = 0; i < n; i++) {
        if(i == 0) {
            printf("Numero: ");
            scanf("%d", &valor);
            push(valor, A);
        } else {
            printf("Numero: ");
            scanf("%d", &valor);
             if (valor < getTopo(A)) {
                push(valor, A);
            } else {
                while (valor > getTopo(A) && pilhaVazia(A) == 0){
                    if (valor > getTopo(A)){
                        push(pop(A), B);
                    } else {
                        push(pop(B), A);
                    }
                }

                push(valor,A);

                while(pilhaVazia(B) == 0){
                    push(pop(B), A);
                }
            }
        }
    }

    printf("Pilha A\n");
    while(pilhaVazia(A) == 0){
          printf("%d \n", pop(A));
    }

    return 0;
}

