#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define troca1(a, b) {int c = a; a = b; b = c;}
#define troca2(a, b) {string c = a; a = b; b = c;}

typedef struct aluno {
	int matricula;
	string nome;
}Aluno;


void insere(int x, Aluno v[], int n, string nome){
	while(n > 0 && x < v[n-1].matricula){
		v[n].matricula = v[n-1].matricula;
		v[n].nome = v[n-1].nome;
		n--;
	}
	v[n].matricula = x;
	v[n].nome = nome;
}

void ord_insercao(Aluno v[], int tamanho){
	for(int i = 0; i < tamanho; i++){
		insere(v[i].matricula, v, i, v[i].nome);
	}
}

int seleciona(Aluno v[], int n){
	int i = 0;
	for (int j = 1; j < n; j++){
		if(v[i].nome < v[j].nome) {
			i = j;
		}
	}
	return i;
}

void selection_sort(Aluno v[],int n){
	while(n>1){
		troca1(v[seleciona(v,n)].matricula, v[n-1].matricula);
		troca2(v[seleciona(v,n)].nome, v[n-1].nome);
		n--;
	}
};

void bubble_sort(Aluno v[],int n){
	for (int i = 1; i < n-1; i++){
		for (int j = 0; j < n-i; j++){
			if(v[j].matricula > v[j+1].matricula){
				troca1(v[j].matricula, v[j+1].matricula);
				troca2(v[j].nome, v[j+1].nome);
			}
		}
	}
};

void mostra_alunos(Aluno v[], int n){
	for (int i = 0; i < 4; i++){
		cout <<"\nAluno: " <<endl ;
		cout << v[i].nome << " - Matricula: ";
		cout << v[i].matricula;
		cout << endl;
	}
	cout << endl;
}

Aluno myarray[20];



main(){
	int matricula[] = {10, 07, 19, 99};
	string nome[] = {"renan", "dowglas", "coutinho", "aquino"};

	//1:  A. leia os valores e adicione no vetor de dados
	// ordene pelo campo matricula
	//   B. Ordene por:
	//   c. Insercao
	// mostre o resultado ordenado

	for (int i = 0; i < 4; i++){
		myarray[i].nome = nome[i];
		myarray[i].matricula = matricula[i];
	}

	ord_insercao(myarray, 4);
	mostra_alunos(myarray, 4);

	// 2: A. leia os valores e adicione no vetor de dados
	// ordene pelo campo nome
	//  B. Ordene por:
	//  c. selection_sort
	// mostre o resultado ordenado

	selection_sort(myarray, 4);
	mostra_alunos(myarray, 4);

	// 3: A. leia os valores e adicione no vetor de dados
	// ordene pelo campo matricula
	//  B. Ordene por:
	//  c. bubble_sort
	// mostre o resultado ordenado

	bubble_sort(myarray, 4);
	mostra_alunos(myarray, 4);
}
