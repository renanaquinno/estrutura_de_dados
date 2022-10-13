#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct aluno {
	int mat;
	string nome;

} Aluno;


Aluno lista[30];
int ultimo = 0;


void incluirDesordenado(Aluno e){
    if (ultimo < 29){
        lista[ultimo] = e;
        ultimo++;
        cout<<"Aluno Inserido!";
    } else {
        cout<<"Lista Cheia!";
    }
}

//retorna a posicao do elemento procurado
int procura(int mat){
    for (int i = 0; i < 29; i++ ){
        if (lista[i].mat == mat){
            return i;
        }
    }
    return false;
}

//recebe a posicao e imprime o elemento na tela
void mostrar(int pos){
    cout<<lista[pos].mat<<endl;
    cout<<lista[pos].nome<<endl;
}

//procura o elemento e depois mostra o elemento encontrado (se nao for encontrado informa q ele nao existe)
void consultar(int mat){
    int i = procura(mat);
    if (i){
        cout<<"Matricula: "<<lista[i].mat<<endl;
        cout<<"Nome: "<<lista[i].nome<<endl;
    } else {
        cout<<"Elemento nao Existe"<<endl;
    }
}

//estrat�gia 1: colocar o ultimo elemento da lista na posi��o do elemento removido
void remover00(int mat){
    int i = procura(mat);
    int aux = i;
    if (i){
        lista[i] = lista[ultimo - 1];
        ultimo--;
    }
}

//estrat�gia 2: mover TODOS os elementos que est�o AP�S  o elemento que deve ser removido UMA POSI��O A FRENTE.
void remover01(int mat){
    int i = procura(mat);
    int aux = i;
    if (i){
        for (i; i < (ultimo-1); i++){
            lista[i] = lista[i+1];
        }
        ultimo--;
    }
}

main(){
    Aluno a1;
    a1.mat = 1;
    a1.nome = "Joao";
    Aluno a2;
    a2.mat = 2;
    a2.nome = "Jose";
    Aluno a3;
    a3.mat = 3;
    a3.nome = "Maria";
    incluirDesordenado(a1);
    incluirDesordenado(a2);
    incluirDesordenado(a3);

    //remover00(1);
    remover01(2);
    consultar(1);
    consultar(2);
    consultar(3);
}