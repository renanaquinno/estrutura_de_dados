#include <stdio.h>
#include "./lstord.h"
#include <iostream>
using namespace std;

void insSR(int x,List *L1){

    int find = 0;
    Node *aux = L1->inicio;
    while(aux != NULL && find == 0){
        if(aux->item == x){
            find = 1;
        }
        aux = aux->prox;
    }

    if(!find) {
        L1->push(x);
    } else {
        cout << "O valor: " << x << " já foi encontrado na lista" << endl;
    }
}

int main(void) {
    List *L1 = new List();
    insSR(9,L1);
    insSR(7,L1);
    insSR(4,L1);
    insSR(3,L1);
    insSR(6,L1);
    puts("\n");
    printf("Oredm crescente: \n");
    L1->mostra();
    return 0;
}