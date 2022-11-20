#include <iostream>

using namespace std;

void insertionSort(int v[], int n){
    if (n <= 1){
        return;
    }

    insertionSort(v, n - 1);
    int ant = v[n - 1];
    int i = n - 2;

    while (i >= 0 && v[i] > ant){
        v[i + 1] = v[i];
        i--;
    }

    v[i + 1] = ant;
}

int main() {
    int v[] = {3, 5, 6, 2, 9};

    insertionSort(v, 5);

    for (int i = 0; i < 5; i++){
        cout << v[i] << endl;
    }

    return 0;
}