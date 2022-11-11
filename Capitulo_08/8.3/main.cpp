#include <iostream>
using namespace std;

void bubble_sort(int v[], int tamanho){
   int aux = tamanho;
   for(int i = 0; i < tamanho; i++){
      bool c = false;
      for(int j = 0; j < aux; j++){
         if(v[j]>v[j+1]){
           int x = v[j];
           v[j] = v[j+1];
           v[j+1] = x;
           c = true;
         }
      }
      if(c == false){
         break;
      }
   }
}

int main(){
   int v[] = {5,2,4,5,7};   
   bubble_sort(v, 5);
   for(int i = 0; i < 5; i++){
      cout << v[i] <<endl;
   }
}