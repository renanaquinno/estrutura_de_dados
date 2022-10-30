#include <stdio.h>
#include "./lstord.h"
#include <iostream>
using namespace std;

Poli soma(Poli P, Poli Q) {
    Poli retorno = NULL;
    Poli aux = P;

    while (aux) {
        retorno = termo(aux->coef, aux->expo, retorno);
        aux = aux->prox;
    }
    aux = Q;
    while (aux) {
        adt(aux->coef, aux->expo, &retorno);
        aux = aux->prox;
    }
    return retorno;
}

void adt(float c, int e, Poli *P) {

    if (*P == NULL || (*P)->expo < e){
        *P = termo(c, e, *P);
    }
    else if ((*P)->expo == e) {
        (*P)->coef += c;
        if ((*P)->coef == 0) {
            Poli aux = *P;
            *P = aux->prox;
            free(aux);
        }
    } else { 
        adt(c, e, &(*P)->prox);
    }
}

int main() {

    Poli p1 = NULL;
    Poli q1 = NULL;
    adt(+2, 0, &p1);
    adt(-5, 4, &p1);
    adt(+2, 6, &p1);
    adt(+3, 8, &p1);
    adt(+9, 0, &q1);
    adt(-3, 8, &q1);
    adt(+4, 7, &q1);
    adt(+4, 0, &q1);

    cout << "----- P1 -----" << endl;
    exibeop(p1);
    puts("\n");
    cout << "----- Q1 -----" << endl;
    exibeop(q1);
    puts("\n");
    cout << "----- P1 + Q1 -----" << endl;
    exibeop(soma(p1, q1));
}