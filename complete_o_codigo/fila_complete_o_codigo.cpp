#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

class No{
	public:
		char nome;
		No *prox;
		No(char n){
			nome = n;
			prox = NULL;
		}
};

class Fila{
	public:
		No *inicio;
		No *fim;

		Fila(){
			inicio = NULL;
			fim = NULL;
		}

		void append(char n){
            No *tmp = new No(n);
            tmp->nome = n;
            tmp->prox = NULL;

            if(inicio == NULL) {
                inicio = tmp;
                fim = tmp;
            }   else {
                fim->prox = tmp;
                fim = fim->prox;
            }

            printf("Adicionado!");
		}

		char pop(class No** inicio){
            if (*inicio == NULL) {
                return 's';
            } else {
                return 'o';
            }

        //No(inicio)* inicio = *inicio;
        //char result = inicio->nome;

        //(*inicio) = (*inicio)->prox;

        //free(inicio);

        //return result;

		}

		bool isEmpty(){
			return (inicio == NULL);
		}

	//    public void popAll(){


//		}

};

int main(){

    Fila a;
    a.append('a');
    a.pop();

}
