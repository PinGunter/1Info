#include "Lista.h"
#include <iostream>

using namespace std;


void imprimirLista(Celda*& lista) {
	Celda* p = lista;
	while (p != nullptr) {
		cout << p->dato << " ";
		p = p->siguiente;
	}
	cout << endl;
}

void aniadirLista(Celda*& lista, double valor) {
	Celda* p;
	if (lista != nullptr) {
		p = lista;
		Celda* nuevo = new Celda;
		nuevo->dato = valor;
		nuevo->siguiente = nullptr;
		while (p->siguiente != nullptr)
			p = p->siguiente;
		p->siguiente = nuevo;
	}
	else {
		p = new Celda;
		p->dato = valor;
		p->siguiente = nullptr;
		lista = p;
	}
}
