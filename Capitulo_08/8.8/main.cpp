#include <iostream>
using namespace std;

void quick_sort(int v[6], int i, int f);

int main() {
    int v1[] = {4, 6, 5, 7, 8, 3};
    int v2[] = {8, 2, 4, 3, 1, 9};

    cout << "V1 ordenado:" << endl;
    quick_sort(v1, 0, 6);
    for (int i = 0; i < 6; i++){
        cout << "=> " << v1[i] << endl;
    }

    cout << "V2 ordenado:" << endl;
    quick_sort(v2, 0, 6);
    for (int i = 0; i < 6; i++){
        cout << "=> " << v2[i] << endl;
    }
}

int parciona(int v[], int ini, int f) {
    int x = v[ini];
    f++;
    ini--;
    while (ini < f) {
        do
            f--;
        while (v[f] > x);
        do
            ini++;
        while (v[ini] < x);
            if (ini < f){
                int aux = v[ini];
                v[ini] = v[f];
                v[f] = aux;
            }
    }
    return f;
}

void quick_sort(int v[6], int i, int f){
    if (i >= f){
        return;
    }
    int m = parciona(v, i, f);
    quick_sort(v, i, m);
    quick_sort(v, m + 1, f);
}
