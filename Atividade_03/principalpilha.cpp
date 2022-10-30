#include <iostream>
#include "pilha1.h"
using namespace std;


int main() {
	Pilha *p = pilha(5);
    char s[11];
    for (int i = 1; i<=3; i++){
        printf("?");
        gets(s);
        push(s, p);
    }
}
