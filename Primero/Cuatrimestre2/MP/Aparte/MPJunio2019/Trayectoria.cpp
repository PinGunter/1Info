#include "Trayectoria.h"
#include <cassert>
void Trayectoria::inicializar(int n) {
	if (n > 0) {
		puntos = new Punto3D[n];
		numeroPuntos = n;
	}
	else {
		puntos = nullptr;
		numeroPuntos = 0;
	}
}

void Trayectoria::liberar() {
	if (puntos != nullptr) {
		delete[] puntos;
	}
	puntos = nullptr;
	numeroPuntos = 0;
}

Trayectoria::Trayectoria() {
	inicializar();
}

Trayectoria::Trayectoria(Punto3D* lista, int n) {
	inicializar(n);
	for (int i = 0; i < numeroPuntos; i++) {
		puntos[i] = lista[i];
	}
}

Trayectoria::Trayectoria(const Trayectoria& otro) {
	*this = otro;
}

Trayectoria::~Trayectoria() {
	liberar();
}

Trayectoria& Trayectoria::operator=(const Trayectoria& otro) {
	if (this != &otro) {
		delete[] this->puntos;
		numeroPuntos = otro.numeroPuntos;
		this->puntos = new Punto3D[otro.numeroPuntos];
		for (int i = 0; i < numeroPuntos; i++) 
			puntos[i] = otro.puntos[i];
	}
	return *this;
}

Punto3D Trayectoria::getPunto(int i) const {
	assert(i >= 0 && i < numeroPuntos);
	return puntos[i];
}

void Trayectoria::setPunto(int i, const Punto3D& nuevo){
	assert(i >= 0 && i < numeroPuntos);
	puntos[i] = nuevo;
}

int Trayectoria::getNumeroPuntos()const {
	return numeroPuntos;
}

double Trayectoria::calcularLongitud() const{
	double longitud = 0.0;
	for (int i = 0; i < numeroPuntos - 1; i++) {
		longitud += puntos[i].calcularDistancia(puntos[i + 1]);
	}
	return longitud;
}

void Trayectoria::aniadir(const Punto3D& nuevo) {
	Trayectoria aux(puntos, numeroPuntos + 1);
	aux.setPunto(numeroPuntos, nuevo);
	*this = aux;
}

std::istream& operator>>(std::istream& is, Trayectoria& trayectoria){
	is >> trayectoria.numeroPuntos;
	trayectoria.inicializar(trayectoria.numeroPuntos);
	for (int i = 0; i < trayectoria.getNumeroPuntos(); i++)
		is >> trayectoria.puntos[i];
	return is;
}
