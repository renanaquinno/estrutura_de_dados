#include "./list.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int ultimo_item(List *l) {
    Node *aux = l->inicio;
    while (aux->prox != NULL){
        aux = aux->prox;
    }
    return aux->item;
}

int main() {
    List *l = new List();
    int op = 1;
    while (op != 0) {
        int valor;
        printf("Valor para inserir no fim da lista: ");
        scanf("%d", &valor);
        l->addToFinal(valor);

        printf("Continuar Inserindo? (1-sim, 0-nao): ");
        scanf("%d", &op);
    }

    printf("Lista inserida: \n");
    l->show();

    printf("\nO ultimo item: %d", ultimo_item(l));
}