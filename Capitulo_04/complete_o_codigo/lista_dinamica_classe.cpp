#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class No{
	public:
		int mat;
		char nome[23];
		No *prox;
		No(int m,char n[23]){
			mat=m;
			strcpy(nome,n);
			prox=NULL;
		}
};

class Lista{
	public:
		No *inicio;
		No *fim;

	    Lista(){
	    	inicio = NULL;
	    	fim = NULL;
		}

		void addToFinal(int m, char n[23]){
			No *novo= new No(m,n);
			if (fim==NULL){
				inicio = novo;
				fim = novo;
			}
			else{
				fim->prox=novo;
				fim=novo;
			}
		}

		int lst_vazia(){
			return (inicio==NULL);
		}

		void addToInicio(int m,char n[23]){
            No *novo= new No(m,n);
			if (inicio==NULL){
				inicio = novo;
			}
			else{
				inicio->prox = novo;
                fim = novo;
			}
		}

		void mostra(){
			if (lst_vazia()){
				cout<<"\nLista vazia!!!";
			}
			else{
                No *atual = inicio;
                while (atual!= NULL){
					cout<<"\n Matricula: "<<atual->mat;
					cout<<"\n Nome: "<<atual->nome;
					atual = atual->prox;
                }
            }
        }


		int remove(int mat){
            No *aux = inicio;
            No *ant = NULL;
            while(aux != NULL) {
                if(aux->mat==mat) {
                    if (aux == fim){
                        ant->prox = NULL;
                        free(aux);
                        fim = ant;
                    } else if (aux == inicio){
                        aux = inicio;
                        inicio = inicio->prox;
                        free(aux);
                    } else {
                        ant->prox = aux->prox;
                        free(aux);
                    }
                }
                ant = aux;
                aux = aux->prox;
            }
		}

		// auxiliar no metodo remove, vai
		//retornar o endereco do anterior
		No *busca(int mat){
            No *aux = inicio;
             while(aux != NULL) {
                if(aux->mat==mat) {
                    return aux;
                } else {
                    aux = aux->prox;
                }
             }
		}

		void removeTodos(){
			No *atual=inicio;
			No *proximo=NULL;
			while (atual!=NULL){
					proximo=atual->prox;
					cout<<"\n Apaga:"<<atual->nome;
					free(atual);
					atual=proximo;
			}
			inicio=atual;
		}

		// criar uma nova lista que seja o inverso da primeira
		void crialistainversa(){
		    Lista *l2 = new Lista();
		    No *aux = inicio;
		    while (aux != NULL){
                    l2->addToFinal(aux);
                    aux = inicio->prox;
		    }
		}

		//inverter a propria lista
		void listainvertida(){
            Lista *l2 = new Lista();
		    No *aux = inicio;
		    while (aux != NULL){
                    l2->addToFinal(inicio);
                    aux = inicio->prox;
		    }

		    aux = l2->inicio;

		    while (aux != NULL){
                    addToFinal = aux;
                    aux = l2->prox;
		    }
		}
};


main(){
   Lista *l=new Lista();

    l->addToInicio(1,"Joana Oliveira");
    l->addToInicio(2,"Cristiano Oliveira");
    l->addToFinal(3,"Joao");
    l->addToFinal(4,"Gabriela");
    l->addToFinal(5,"Fabiola");
    l->mostra();
    l->listainvertida();
    l->mostra();
}
