#include "./list.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int enesimo_item(int n, Node *inicio, int atual = 1) {

    if (inicio == NULL || n <= 0) {
        printf("N é invalido!!\n");
        return '\0';
    } if (atual < n){
        return enesimo_item(n, inicio->prox, atual + 1);
    }
    return inicio->item;
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

    int n, item;

    op = 1;
    while (op == 1) {
        printf("Posicao do elemento procurado: ");
        scanf("%d", &n);

        item = enesimo_item(n, l->inicio);

        if (item != '\0'){
            printf("\nElemento esta na %d pos e: %d", n, item);
        }
        printf("\nContinuar Procurando? (1-sim, 0-nao): ");
        scanf("%d", &op);
    }
}