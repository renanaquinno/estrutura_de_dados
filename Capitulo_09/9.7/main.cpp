#include "./list.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int igual(Node *A, Node *B) {
    if (A == NULL && B == NULL) {
        return 1;
    } if (A->item == B->item){
        return igual(A->prox, B->prox);
    }
    return 0;
}

void inserir(List *l) {
    int op = 1;
    while (op == 1) {
        int valor;

        printf("Valor para inserir no fim da lista: ");
        scanf("%d", &valor);
        l->addToFinal(valor);

        printf("Continuar Inserindo? (1-sim, 0-nao): ");
        scanf("%d", &op);
    }
    return;
}

int main() {
    List *A = new List();
    List *B = new List();
    printf("----- Lista A -----\n");
    inserir(A);
    printf("----- Lista B -----\n");
    inserir(B);

    printf("Lista A: \n");
    A->show();

    printf("Lista B: \n");
    B->show();

    if (igual(A->inicio, B->inicio)) {
        printf("Listas sao iguais\n");
    } else {
        printf("Listas sao diferentes\n");
    }
}