#include "./list.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int soma(List *l){
    if (l->inicio == NULL)
        return 0;
    List *aux = new List();
    aux->inicio = l->inicio->prox;
    return l->inicio->item + soma(aux);
}

int main() {
    List *l = new List();
    int op = 1;

    while (op == 1) {
        int valor;

        printf("Valor para inserir no fim da lista: ");
        scanf("%d", &valor);
        l->addToFinal(valor);

        printf("Continuar Inserindo? (1-sim, 0-nao): ");
        scanf("%d", &op);
    }

    printf("Lista inserida: \n");
    l->show();

    printf("\nSoma: %d", soma(l));
}