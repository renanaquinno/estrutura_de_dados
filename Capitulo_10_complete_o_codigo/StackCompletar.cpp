#include <stack>
#include <iostream>
using namespace std;

template <class T>
class Stack: public stack<T> {
	protected:
		stack<T> pilha;
	public:
	T popStack(){
		T tmp=pilha.top();
		pilha.pop();
		return tmp;
	}

    void popTodos(){
        for(int c = 0; c < pilha.size(); c++){
            pilha.pop();
        }
    }

    void simulaFila(T novo){
        int elemento[pilha.size()];
        for(int c = pilha.size() - 1; c >= 0; c++){
            elemento[c] = pilha.top();
            pilha.pop();
        }

        for(int c = 0; c < pilha.size(); c++){
            pilha.push(elemento[c]);
        }
    }
};

main(){
    Stack<int> pilha;

    pilha.push(1);
    pilha.push(2);
    pilha.push(3);
    pilha.push(4);

    cout << pilha.top() << endl;
    pilha.popTodos();
    pilha.push(5);
    cout << pilha.top() << endl;

    pilha.push(1);
    pilha.push(2);


    pilha.simulaFila(1);
    cout << pilha.top() << endl;
    pilha.popTodos();

}
