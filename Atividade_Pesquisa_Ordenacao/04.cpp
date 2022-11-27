#include<stdio.h>
#include<iostream>
#include <string.h>

using namespace std;

#define troca1(a, b) {int c = a; a = b; b = c; }

bool pesquisa_linear(int c, int v[], int n){
    if(c == v[n]){
        return true;
    }
    n--;

    if(n == 0){
        return false;
    }

    return pesquisa_linear(c, v, n);     
}

bool pesquisa_binaria(int c, int v[], int n, int u){
    int m = (u+n)/2;

    if(c == v[m]){
        return true;
    }

    if(c < v[m]) {
        n = m-1;
    } else {
        u = m+1;
    }

    if(n < u){
        return false;
    }

    return pesquisa_binaria(c, v, n, u);     
}

void bubble_sort(int v[],int n){
	for (int i = 1; i < n-1; i++){
		for (int j = 0; j < n-i; j++){
			if(v[j] > v[j+1]){
				troca1(v[j], v[j+1]);
			}
		}
	}
};

int main(){

   int mat[] = {10, 07, 19, 99, 20, 22};

   if(pesquisa_linear(5, mat, 6)){
      cout << "item encontrado" << endl;
   } else {
      cout << "item nao encontrado" << endl;
   } 

   bubble_sort(mat, 6);

   if(pesquisa_binaria(10, mat, 6, 0)){
      cout << "item encontrado" << endl;
   } else {
      cout << "item nao encontrado" << endl;
   }
}