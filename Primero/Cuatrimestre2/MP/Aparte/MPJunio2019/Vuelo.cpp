#include "Vuelo.h"
#include <iostream>
Vuelo::Vuelo(){
	idVuelo = -1;
}

Vuelo::Vuelo(int idVuelo, Trayectoria rutaOptima) {
	this->idVuelo = idVuelo;
	this->rutaOptima = rutaOptima;
}

Vuelo::Vuelo(std::string nombre){
	std::ifstream fichero(nombre);
	fichero >> idVuelo;
	fichero >> rutaOptima;
	fichero >> rutaReal;
	fichero.close();
}

int Vuelo::getId() const
{
	return idVuelo;
}

Vuelo& Vuelo::operator+=(const Punto3D& otro) {
	if (rutaReal.getNumeroPuntos() == 0)
		rutaReal.aniadir(rutaOptima.getPunto(0));
	rutaReal.aniadir(otro);
	return *this;
}

double Vuelo::calcularLongitudOptima() const {
	return rutaOptima.calcularLongitud();
}

double Vuelo::calcularLongitudReal() const {
	return rutaReal.calcularLongitud();
}

double Vuelo::calcularDistanciaMediaTrayectorias()const{
	double distancia_media = 0.0;
	double min, distancia;
	for (int i = 0; i < rutaReal.getNumeroPuntos(); i++) {
		min = rutaReal.getPunto(i).calcularDistancia(rutaOptima.getPunto(0));
		for (int j = 1; j < rutaOptima.getNumeroPuntos(); j++) {
			distancia = rutaReal.getPunto(i).calcularDistancia(rutaOptima.getPunto(j));
			min = (distancia < min) ? distancia : min;
		}
		distancia_media += min;
	}

	return distancia_media/rutaReal.getNumeroPuntos();
}

bool operator<(const Vuelo& uno, const Vuelo & otro){
	bool menor = (uno.calcularDistanciaMediaTrayectorias() < otro.calcularDistanciaMediaTrayectorias()) ? true : false;
	return menor;
}

std::ostream& operator<<(std::ostream& os, const Vuelo& vuelo){
	os << vuelo.idVuelo << std::endl;
	os << vuelo.rutaOptima.getNumeroPuntos() << std::endl;
	for (int i = 0; i < vuelo.rutaOptima.getNumeroPuntos(); i++) 
		os << vuelo.rutaOptima.getPunto(i);
	os << vuelo.rutaReal.getNumeroPuntos() << std::endl;
	for (int i = 0; i < vuelo.rutaReal.getNumeroPuntos(); i++)
		os << vuelo.rutaReal.getPunto(i);

	return os;
}
