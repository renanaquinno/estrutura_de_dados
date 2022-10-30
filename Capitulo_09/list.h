#include <stdio.h>
#include <stdlib.h>
class Node {
public:
    int item;
    Node *prox;
    Node(int m)
    {
        item = m;
        prox = NULL;
    }
};

class List {
public:
    Node *inicio;
    Node *fim;

    List() {
        inicio = NULL;
        fim = NULL;
    }

    int list_empty() {
        return (inicio == NULL);
    }

    void addToFinal(int m) {
        Node *novo = new Node(m);
        if (fim == NULL) {
            inicio = novo;
            fim = novo;
        } else {
            fim->prox = novo;
            fim = novo;
        }
    }

    void addToInicio(int m) {
        Node *novo = new Node(m);
        if (inicio == NULL) {
            inicio = novo;
            fim = inicio;
        } else {
            novo->prox = inicio;
            inicio = novo;
        }
        return;
    }

    void show() {
        if (list_empty()) {
            printf("\nLista vazia");
        } else {
            Node *aux = inicio;
            for (int i = 0; aux != NULL; aux = aux->prox) {
                printf("\nValor: %d\n", aux->item);
                i++;
            }
            printf("\n");
        }
    }

    int remove(int item) {
        Node *aux = search(item);

        if (aux == NULL) {
            return 0;
        }

        if (aux->item == inicio->item) {
            inicio = inicio->prox;
            free(aux);
            return 1;
        }
        Node *aux2 = inicio;
        while (aux2->prox->item != aux->item) {
            aux2 = aux2->prox;
        }
        aux2->prox = aux->prox;
        free(aux);
        return 1;
    }

    Node *search(int item) {
        if (list_empty()) {
            return NULL;
        } else {
            Node *aux = inicio;
            do {
                if (aux->item == item) {
                    break;
                } 
                aux = aux->prox;
            } while (aux != NULL);
            return aux;
        }
    }
};