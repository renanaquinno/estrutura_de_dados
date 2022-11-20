#include <iostream>
using namespace std;

int linearSearch(int search, int v[], int tam)
{

    if (tam < 0)
    {
        return 0;
    }

    if (search == v[tam])
    {
        return 1;
    }

    return linearSearch(search, v, tam - 1);
}

int main()
{
    int v[] = {3, 9, 6, 5, 8};

    int x = 5;

    if (linearSearch(x, v, 5))
    {
        cout << "Encontrado : " << x << endl;
    }
    else
    {
        cout << "Valor nao encontrado: " << x << endl;
    }
}