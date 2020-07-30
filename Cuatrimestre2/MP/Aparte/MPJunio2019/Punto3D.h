#ifndef PUNTO3D_H
#define PUNTO3D_H
#include <iostream>
#include <cmath>
/**
* @brief clase que representa las coordenadas de un GPS
* @x longitud
* @y latitud
* @z altura
*/
class Punto3D {
private:
	double x, y, z;
public:
	Punto3D();
	inline double getX() const{ return x; }
	inline double getY() const{ return y; }
	inline double getZ() const { return z; }
	double calcularDistancia(const Punto3D& siguiente);

	friend std::ostream& operator<<(std:: ostream& os, const Punto3D& punto);
	friend std::istream& operator>>(std::istream& is, Punto3D& punto);
};

#endif
