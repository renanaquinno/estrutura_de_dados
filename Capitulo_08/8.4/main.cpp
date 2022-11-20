#include <iostream>
using namespace std;

#define troca(a, b) \
{                   \
        int x = a;  \
        a = b;      \
        b = x;      \
}

int seleciona(int a[], int c){
    int i = 0;
    for (int j = 1; j < c; j++)
        if (a[i] < a[j])
            i = j;
    return i;
}

void selectionsort(int a[], int c){
    if (c == 1){
        return;
    }
    troca(a[seleciona(a, c)], a[c - 1]);
    selectionsort(a, c - 1);
}

int main(){
    int a[] = {3, 4, 2, 3, 5};
    selectionsort(a, 5);

    for (int i = 0; i < 5; i++){
        cout << a[i] << endl;
    }
    return 0;
}