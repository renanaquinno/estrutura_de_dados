#include "./list.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int ocorrencias(int x, List *l) {
    Node *aux = l->inicio;
    int qtd = 0;

    while (aux != NULL) {
        if (aux->item == x) {
            qtd++;
        }
        aux = aux->prox;
    }
    return qtd;
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

    printf("Valor para verificar\n=> ");
    scanf("%d", &op);
    printf("\nValor: %d, aparece %d vezes na lista\n", op, ocorrencias(op, l));
}