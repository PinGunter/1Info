#include "Punto3D.h"

Punto3D::Punto3D() {
	x = y = z = 0;
}

double Punto3D::calcularDistancia(const Punto3D& siguiente){
	double distancia = 0.0;
	distancia = sqrt(pow(getX() - siguiente.getX(), 2) + 
					pow(getY() - siguiente.getY(), 2) + 
					pow(getZ() - siguiente.getZ(), 2));
	return distancia;
}

std::ostream& operator<<(std::ostream& os, const Punto3D& punto) {
	os << punto.getX() << " " << punto.getY() << " " << punto.getZ() << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Punto3D& punto){
	is >> punto.x >> punto.y >> punto.z;
	return is;
}
