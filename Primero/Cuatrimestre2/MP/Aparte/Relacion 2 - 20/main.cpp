#include <iostream>

using namespace std;

struct Celda {
    double dato;
    Celda *sig;
};

class Lista {
    Celda *l;
public:

    Lista() {
        l = nullptr;
    }

    void insertarFinal(double dato) {
        if (l == nullptr) {
            Celda *aux = new Celda;
            aux->dato = dato;
            aux->sig = l;
            l = aux;
        } else {
            while (l != nullptr)
                l = l->sig;
            Celda *aux = new Celda;
            aux->dato = dato;
            aux->sig = l->sig;
            l->sig = aux;
        }
    }

    void eliminarUltimo() {
        //buscamos la celda que apunta al ultimo elemento
        while (l->sig != nullptr)
            l = l->sig;
        //ahora apuntamos a nullptr
        l->sig = nullptr;
    }

    void liberar() {
        while (l != nullptr) {
            Celda *aux = l;
            l = aux->sig;
            delete aux;
        }
    }

    void imprime() {
        while (l != nullptr) {
            cout << l->dato << " ";
            l = l->sig;
        }
    }
    
};

int main() {

}
