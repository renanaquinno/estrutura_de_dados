#include "./list.h"
#include <stdio.h>
#include <iostream>

using namespace std;

void substituir(int x, int y, Node *inicio) {
    if (inicio != NULL) {
        if (inicio->item == x)
            inicio->item = y;
        substituir(x, y, inicio->prox);
    }
    return;
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

    int x, y;
    printf("Valor Antigo: \n=> ");
    scanf("%d", &x);
    printf("Valor Novo: \n=>");
    scanf("%d", &y);
    substituir(x, y, l->inicio);
    printf("Lista Atualizada: \n");
    l->show();
}