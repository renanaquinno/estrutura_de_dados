#include <iostream>
using namespace std;

void insertionSort(int v[], int n)
{
    if (n <= 1)
    {
        return;
    }

    insertionSort(v, n - 1);

    int ant = v[n - 1];
    int k = n - 2;

    while (k >= 0 && v[k] > ant)
    {
        v[k + 1] = v[k];
        k--;
    }

    v[k + 1] = ant;
}

int binarySearch(int x, int v[], int u, int p = 0)
{
    if (p > u)
    {
        return 0;
    }

    int m = (p + u) / 2;
    if (x == v[m])
    {
        return 1;
    }
    else
    {
        if (x < v[m])
            binarySearch(x, v, m - 1, p);
        else
            binarySearch(x, v, u, m + 1);
    }
}

int main(){
    int v[] = {4, 5, 4, 2, 9};
    insertionSort(v, 5);

    int x = 3;

    if (binarySearch(x, v, 5))
    {
        cout << "Encontrado : " << x << endl;
    }
    else
    {
        cout << "Valor nao encontrado: " << x << endl;
    }
}
