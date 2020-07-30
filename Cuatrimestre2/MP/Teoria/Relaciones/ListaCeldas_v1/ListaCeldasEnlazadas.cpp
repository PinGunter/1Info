#include "ListaCeldasEnlazadas.h"

using namespace std;

void InsertarPrincipioLista(Celda * &Lista, double valor){
}

void InsertarAlFinalLista(Celda* &lista,double valor){
    Celda * p;
    if (lista == nullptr){
        lista = new Celda;
        lista->dato = valor;
        lista->sig = nullptr;
    } else{
        p = lista;
        while (p != nullptr){
            p = p->sig;
        }
        p->sig = new Celda;
        p = p->sig;
        //p->sig->dato = valor;
        //p->sig->sig = nullptr;
    }
    p->sig=nullptr;
    p->dato=valor;
    
}