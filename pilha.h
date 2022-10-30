#include <stdio.h>
#include <stdlib.h>

typedef char Itemp;
typedef struct pilha{
	int max;
	int topo;
	Itemp *item;
}Pilha;


Pilha* pilha(int m){
	Pilha *P = (Pilha*)malloc(sizeof(Pilha));
	P->max=m;
	P->topo=-1;
	P->item=(char*)malloc(m*sizeof(char));
    return P;
}

int pilhaCheia(Pilha *P){
	if (P->topo == P->max-1){
		return 1;
	} else {
		return 0;
	}
}

int pilhaVazia (Pilha *P){
	if (P->topo == -1){
		return 1;
	} else {
		return 0;
	}
}

void push(Itemp x,Pilha *P){
	if (pilhaCheia(P)){
		puts("Erro: Pilha Cheia !!");
		abort();
	}
    P->topo++;
    P->item[P->topo] = x;
}

int pop(Pilha *P){
	if (pilhaVazia(P) == 1){
		puts("Erro: Pilha Vazia pop!!");
		abort();
	} else {
		Itemp x = P->item[P->topo];
		P->topo--;
		return x;
	}
}

char desempilha(Pilha *P){
     while(pilhaVazia(P) == 0){
          printf("%d \n", pop(P));
    }
}

//void destroi(Pilha *Q){
//    free((Q)->item);
//    free(Q);
//    Q = NULL;
//}

void destroi(Pilha** p){
    free((*p)->item);
    free(*p);
    *p = NULL;
}

char getTopo(Pilha *P){
//int getTopo(Pilha *P){
    if (pilhaVazia(P) == 1) {
        puts("Erro: Pilha Vazia getTopo!!");
		abort();
    } else {
        return P->item[P->topo];
    }
}

char *posfixa(char *e) {
    static char s[256];
    int j = 0;
    Pilha *P = pilha(256);

    for(int i = 0; e[i]; i++) {

        if(isdigit(e[i])) {
            s[j++] = e[i];
        }

        if(strchr("+*-/", e[i])) {
            push(e[i], P);
        }

        if(e[i] == ')') {
            s[j++] = pop(P);
        }
    }

    s[j] = '\0';
    destroi(&P);

    return s;
}




