#include <queue>
#include <iostream>
using namespace std;

template <class T>
class Queue: public queue<T> {
	protected:
		queue<T> fila;
	public:
	T popQueue(){
		T tmp=fila.front();
		fila.pop();
		return tmp;
	}


	void popTodos(){
        for(int i=0;i<fila.size();i++){
           fila.pop();
        }
    }

    void simulaFila(T novo){
        queue<T> aux;

        for(int i = 0; i < fila.size(); i++){
            aux.push(fila.front());
            fila.pop();
        }

        fila.push(novo);

        for(int c = 0; c < fila.size(); c++){
          fila.push(aux.front());
            aux.pop();
        }
    }
};

main(){
	Queue<int> fila;

    fila.push(1);
    fila.push(2);
    fila.push(3);
    fila.push(4);

    cout << fila.front() << endl;
    fila.popTodos();
    fila.push(0);
    cout << fila.front() << endl;

    fila.push(1);
    fila.push(2);
    fila.push(3);
    fila.push(4);

    fila.simulaFila(1);
    cout << fila.front() << endl;
    fila.pop();
	cout<<fila.front()<<endl;
}
