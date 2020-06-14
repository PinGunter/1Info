#ifndef LISTA_H
#define LISTA_H
struct Celda {
	double dato;
	Celda* siguiente;
};

void imprimirLista(Celda*& lista);

void aniadirLista(Celda*& lista, double valor);
#endif // !LISTA_H
