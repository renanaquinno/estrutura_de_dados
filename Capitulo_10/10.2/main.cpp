#include <stdio.h>
#include "./lstord.h"

void listinvert(List *L1) {
    Node *atual = L1->inicio, *ant = atual->prox, *prox = NULL;
    atual->prox = NULL;
    L1->fim = atual;

    while (ant != NULL) {
        prox = ant->prox;
        ant->prox = atual;
        atual = ant;
        ant = prox;
    }

    L1->inicio = atual;
    return;
}

int main(void) {
    List *L1 = new List();
    L1->push(7);
    L1->push(6);
    L1->push(5);
    L1->push(3);

    printf("Ordem crescente: ");
    L1->mostra();
    puts("\n");
    printf("Ordem decrescente: ");
    listinvert(L1);
    L1->mostra();
    puts("");
    return 0;
}