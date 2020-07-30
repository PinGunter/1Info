#ifndef FRECUENCIAS_H
#define FRECUENCIAS_H
#include <cassert>
#include <iostream>

struct Pareja {
	int dato; 
	int nveces;
};

class Frecuencias {
	Pareja* pareja;
	int npares;
	
	void reservarMemoria(int n=0);
	void liberar();
	void copiar(const Frecuencias& otro);
	void redimensionar(int n);
	int buscarEntero(int n);
	void ordenar();
public:
	/*
	* @brief contructor basico de la clase
	*/
	Frecuencias();

	/*
	* @brief contructor de copia
	*/
	Frecuencias(const Frecuencias & otro);

	/*
	*@brief destructor de la clase
	*/
	~Frecuencias();

	/*
	* @brief operador de asignacion
	*/
	Frecuencias& operator=(const Frecuencias& otro);

	inline Pareja getPareja(int n)const { assert(n >= 0 && n < npares); return pareja[n]; }
	inline int getNumPares() const { return npares; };

	void Add(int n);

	Frecuencias& operator+= (int n);
	friend std::ostream& operator<<(std::ostream &os, Frecuencias& fr);
};

std::ostream& operator<<(std::ostream& is, Frecuencias& fr);


#endif