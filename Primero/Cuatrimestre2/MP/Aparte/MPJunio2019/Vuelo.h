#ifndef VUELO_H
#define VUELO_H
#include "Trayectoria.h"
#include <iostream>
#include <fstream>
class Vuelo {
private:
	int idVuelo;
	Trayectoria rutaOptima;
	Trayectoria rutaReal;
public:
	Vuelo();
	Vuelo(int idVuelo, Trayectoria rutaOptima);
	Vuelo(std::string nombre);

	int getId() const;
	Vuelo& operator+= (const Punto3D& otro);
	double calcularLongitudOptima() const;
	double calcularLongitudReal() const ;
	double calcularDistanciaMediaTrayectorias() const;
	
	friend std::ostream& operator<<(std::ostream & os, const Vuelo& vuelo);
};
	bool operator<(const Vuelo& uno, const Vuelo & otro);

#endif
