# --------__... Atividade ...__--------

**2.1) Qual a saida exibida pelo programa a seguir? Por que?:**
### Erro de Pilha Vazia, por que apenas dois itens foram adicionados na pilha e a função desempilha foi chamada 3 vezes, na ultima chamada a função nao encontrou itens.


**2.2) Qual a saida exibida pelo programa a seguir? Por que?:**
### Mostra a sequencia dos numeros divisiveis por 2 que foram inseridos a partir do 8.


**2.3) Usando Pilha, crie um programa para inverter as ordens das letras nas palavras.**

```
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
```


**2.4) Supondo que um usuario digite as cadeias "um", "dois" e "tres". Qual a saida exibida pelo programa a seguir? Por que?** 
### "SIM", porque vai exibindo os ultimos caracteres das palavras.