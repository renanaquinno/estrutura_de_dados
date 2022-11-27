#include<stdio.h>
#include<iostream>
#define troca(a, b) {int c = a; a = b; b = c; }

using namespace std;

int particiona (int v[], int ini, int fim) {
    int x = v[ini];
    ini--;
    fim++;
    while(ini<fim){
        do fim--; while(v[fim]>x);
        do ini++; while(v[ini]<x);
        if (ini < fim) troca(v[ini], v[fim]);
    }
    return fim;
}

void Quick(int v[], int ini, int fim){
    if(ini >= fim) return;
    int m = particiona(v, ini, fim);
    Quick(v, ini, m);
    Quick(v, m+1, fim);
}

int main(){
   int vetor[6] = {1,9,3,5,2,7};
   int i;
   Quick(vetor, 0, 5);
   printf("\n.Vetor ordenado:\n");
   for(i = 0; i <= 5; i++){
      printf("%d ", vetor[i]);
   }
   printf("\n");
}
