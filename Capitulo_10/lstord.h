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

    List()
    {
        inicio = NULL;
        fim = NULL;
    }

    int list_empty()
    {
        return (inicio == NULL);
    }

    void addToFinal(int m)
    {
        Node *novo = new Node(m);
        if (fim == NULL)
        {
            inicio = novo;
            fim = novo;
        }
        else
        {
            fim->prox = novo;
            fim = novo;
        }
    }

    void push(int e)
    {

        Node *novo = new Node(e);
        Node *atual = inicio, *aux;

        if (list_empty())
        {
            inicio = novo;
            return;
        }
        else if (novo->item < atual->item)
        {
            novo->prox = inicio;
            inicio = novo;
            return;
        }

        while (atual->prox && e > atual->prox->item)
            atual = atual->prox;
        novo->prox = atual->prox;
        atual->prox = novo;

        if (atual == fim)
            fim = novo;
    }

    void addToInicio(int m)
    {

        Node *novo = new Node(m);
        if (inicio == NULL)
        {
            inicio = novo;
            fim = inicio;
        }
        else
        {
            novo->prox = inicio;
            inicio = novo;
        }
        return;
    }

    void mostra()
    {
        if (list_empty())
        {
            printf("\nLista vazia!!!");
        }
        else
        {
            Node *aux = inicio;
            for (int i = 0; aux != NULL; aux = aux->prox)
            {
                printf("\nValor: %d\n", aux->item);
                i++;
            }
            printf("\n");
        }
    }

    int remove(int item)
    {

        Node *aux = busca(item);

        if (aux == NULL)
        {
            return 0;
        }

        if (aux->item == inicio->item)
        {
            inicio = inicio->prox;
            free(aux);
            return 1;
        }
        Node *aux2 = inicio;
        while (aux2->prox->item != aux->item)
        {
            aux2 = aux2->prox;
        }
        aux2->prox = aux->prox;
        free(aux);
        return 1;
    }

    Node *busca(int item)
    {
        if (list_empty())
        {
            return NULL;
        }
        else
        {
            Node *aux = inicio;

            do
            {
                if (aux->item == item)
                {
                    break;
                }
                aux = aux->prox;
            } while (aux != NULL);

            return aux;
        }
    }
};

typedef struct poli
{

    float coef;
    int expo;
    struct poli *prox;
} * Poli;

Poli termo(float c, int e, Poli p)
{
    Poli n = (Poli)malloc(sizeof(struct Poli));
    n->coef = c;
    n->expo = e;
    n->prox = p;
    return n;
}

void exibeop(Poli P) {
    if (P == NULL)
        return;
    printf("%+.lf", P->coef);
    if (P->expo != 0)
        printf("x^%d", P->expo);
    exibeop(P->prox);
}