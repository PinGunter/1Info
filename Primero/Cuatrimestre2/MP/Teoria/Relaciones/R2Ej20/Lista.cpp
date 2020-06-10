#include "Lista.h"
#include <iostream>
using namespace std;

Lista::Lista(){
	l = nullptr;
}


void Lista::aniadir(double dato){
	if (l == nullptr) {
		Celda* aux = new Celda;
		aux->info = dato;
		aux->sig = l;
		l = aux;
	}
	else {
		Celda* aux;
		aux = l;
		while (aux->sig != nullptr)
			aux = aux->sig;
		aux->sig = new Celda;
		aux = aux->sig;
		aux->info = dato;
		aux->sig = nullptr;
	}
}

void Lista::eliminarUltimo() {
	if (l != nullptr) {
		if (l->sig != nullptr) {
			Celda* p = l;
			while (p->sig->sig != nullptr)
				p = p->sig;
			delete p->sig;
			p->sig = nullptr;
		}
		else {
			delete l;
			l = nullptr;
		}
	}
}

void Lista::liberar(){
	Celda* p = l;
	while (l != nullptr) {
		p = l;
		l = p->sig;
		delete p;
	}
	l = nullptr;
}

void Lista::imprimir()const{
	Celda* p = l;
	while (p != nullptr){
		cout << p->info << " ";
		p = p->sig;
	}
	cout << endl;
}

void Lista::insertarTras(Celda* direccion, double dato){
	if (direccion == nullptr) {	//en caso de que la direccion sea la primera
		Celda* p = new Celda;
		p->info = dato;
		p->sig = l;
		l = p;
	}
	else {
		Celda* nueva = new Celda;
		nueva->info = dato;
		nueva->sig = direccion->sig;
		direccion->sig = nueva;
	}
}

void Lista::eliminar(Celda* celda){ //tanto para apartado h como i
	Celda* p = l;
	if (celda == p) {
		l = l->sig;
		delete p;
	}
	else {
		while (p->sig != celda && p != nullptr) {
			p = p->sig;
		}
		if (p != nullptr) {
			p->sig = celda->sig;
			delete celda;
		}
	}
}

Celda* Lista::getCelda(int posicion){
	Celda* pos = l;
	 for (int i=0; i < posicion && pos != nullptr; i++){
		pos = pos->sig;
	}
	return pos;
}


