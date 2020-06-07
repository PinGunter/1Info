#ifndef TRAYECTORIA_H
#define TRAYECTORIA_H
#include "Punto3D.h"
#include <cmath>
class Trayectoria {
private:
	Punto3D* puntos;
	int numeroPuntos;
	void inicializar(int n = 0);
	void liberar();
public:
	Trayectoria();
	Trayectoria(Punto3D* lista, int n);
	Trayectoria(const Trayectoria& otro);
	~Trayectoria();

	void aniadir(const Punto3D& nuevo);
	Trayectoria& operator=(const Trayectoria& otro);
	Punto3D getPunto(int i) const;
	void setPunto(int i, const Punto3D& nuevo);
	int getNumeroPuntos() const ;
	double calcularLongitud() const;
	friend std::istream& operator>>(std::istream& is, Trayectoria& trayectoria);
};

#endif
