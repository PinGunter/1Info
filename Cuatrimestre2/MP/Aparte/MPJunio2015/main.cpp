#include <iostream>
#include <fstream>
#include "Lista.h"
#include "Frecuencias.h"
using namespace std;

int main(int argc, char *args[]) {
	std::cout << "EJERCICIO 1\n";
	Celda* lista = nullptr;
	for (int i = 1; i <= 10; i++)
		aniadirLista(lista, i);
	imprimirLista(lista);
	
	std::cout << "EJERCICIO 2, 3, 4, 5\n";
	int aux;
	Frecuencias fr;
	istream* input;
	ifstream fichero;
	if (argc == 1)
		input = &cin;
	else {
		fichero.open(args[1]);
		if (!fichero) {
			cerr << "Error al abrir el archivo" << endl;
			return 1;
		}
		input = &fichero;
	}
	while (*input && (*input).peek() != '#') {
		(*input) >> aux;
		if ((char) aux != '#' && (*input))
			fr += aux;
	}
	std::cout << "n fr" << endl;
	std::cout << fr;


}