#include "Frecuencias.h"

void Frecuencias::reservarMemoria(int n){
	if (n > 0) {
		pareja = new Pareja[n];
		npares = n;
	}
	else {
		pareja = nullptr;
		npares = 0;
	}
}

void Frecuencias::liberar(){
	if (pareja != nullptr)
		delete[] pareja;
	pareja = nullptr;
	npares = 0;
}

void Frecuencias::copiar(const Frecuencias& otro) {
	for (int i = 0; i < otro.getNumPares();i++) {
		pareja[i] = otro.getPareja(i);
	}
	npares = otro.getNumPares();
}

void Frecuencias::redimensionar(int n) {
	if (n > 0) {
		Pareja* aux = new Pareja[n];
		for (int i = 0; i < npares; i++)
			aux[i] = getPareja(i);
		delete[] pareja;
		pareja = aux;
		npares = n;
	}
	else {
		pareja = nullptr;
		npares = 0;
	}
}

int Frecuencias::buscarEntero(int n)
{
	int posicion = -1;
	for (int i = 0; i < getNumPares() && posicion == -1; i++) {
		if (pareja[i].dato == n)
			posicion = i;
	}
	return posicion;
}

void Frecuencias::ordenar(){
	int j = 0; 
	Pareja a_desplazar;
	for (int i = 1; i < getNumPares(); i++) {
		a_desplazar = pareja[i];
		for (j = i; j > 0 && a_desplazar.dato < pareja[i - 1].dato; j--)
			pareja[j] = pareja[j - 1];
		pareja[j] = a_desplazar;
	}
}

Frecuencias::Frecuencias(){
	reservarMemoria();
}

Frecuencias::Frecuencias(const Frecuencias& otro){
	reservarMemoria(otro.getNumPares());
	copiar(otro);
}

Frecuencias::~Frecuencias(){
	liberar();
}

Frecuencias& Frecuencias::operator=(const Frecuencias& otro){
	reservarMemoria(otro.getNumPares());
	copiar(otro);
	return *this;
}

void Frecuencias::Add(int n){
	int pos = buscarEntero(n);
	if (pos == -1) {
		redimensionar(getNumPares() + 1);
		pareja[getNumPares() - 1].dato = n;
		pareja[getNumPares() - 1].nveces = 1;
		ordenar();
	}
	else {
		pareja[pos].nveces++;
	}
}

Frecuencias& Frecuencias::operator+=(int n){
	Add(n);
	return *this;
}

std::ostream& operator<<(std::ostream& os, Frecuencias& fr)
{
	for (int i = 0; i < fr.getNumPares(); i++)
		os << fr.getPareja(i).dato << " " << fr.getPareja(i).nveces << std::endl;
	return os;
}

