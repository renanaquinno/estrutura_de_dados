2.1 
Erro de Pilha Vazia, por que apenas dois itens foram adicionados na pilha e a função desempilha foi chamada 3 vezes, na ultima chamada a função nao encontrou itens.

2.2
Mostra a sequencia dos numeros divisiveis por 2 que foram inseridos a partir do 8.

2.3

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct cel {
    char conteudo;
    struct cel *prox;
} celula;

typedef struct pilha {
    struct cel *cabeca;
} pilha;

void empilha(char c, pilha *p) {
    celula *nova = (celula *) malloc(sizeof(celula));
    nova->conteudo = c;
    nova->prox = p->cabeca;
    p->cabeca = nova;
}

char desempilha(pilha *p) {
    celula *pt = p->cabeca;
    char c = pt->conteudo;
    p->cabeca = pt->prox;
    free(pt);
    return c;
}

int main() {
    char frase[50];
    pilha p;
    p.cabeca = NULL;
    printf("Informe a frase: ");
    fgets(frase, 50, stdin);
    for (int i = 0; frase[i] != '\0'; i++) {
        empilha(frase[i], &p);
    }
    printf("\nInvertida: ");
    while (p.cabeca != NULL) {
        putchar(desempilha(&p));
    }
    putchar('\n');
    return 0;
}

2.4
sim, porque vai exibindo os ultimos caracteres das palavras

int main() {
    Pilha *p = pilha(5);
    char s[11];
    for (int i=1; i<=3; i++){
        printf("?\n");
        fgets(s,50, stdin);
        push(s[i],p);
    }
    while (!pilhaVazia(p)) {
        putchar(pop(p));
    }

    return 0;
}


