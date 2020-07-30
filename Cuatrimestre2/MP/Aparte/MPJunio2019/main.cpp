/* EXAMEN JUNIO 2019 - MP */
#include <iostream>
#include "Punto3D.h"
#include "Trayectoria.h"
#include "Vuelo.h"

using namespace std;

int main(int argc, char* args[]) {
	string archivo1, archivo2, umbral;
	double umbral_distancia = 0.0;
	Vuelo* menor;
	//comprobacion de argumentos
	if (argc != 4) {
		cerr << "Error en los argumentos" << std::endl;
		return 1;
	} 
	//procesamos los argumentos
	archivo1 = args[1];
	archivo2 = args[2];
	umbral = args[3];
	umbral_distancia = atof(umbral.c_str());
	Vuelo vuelo1(archivo1), vuelo2(archivo2);

	menor = (vuelo1 < vuelo2) ? &vuelo1 : &vuelo2; 
	cout << "El vuelo menor es el de id: " << (*menor).getId() << std::endl;
	cout << "Su longitud real es: " << (*menor).calcularLongitudReal() << " metros." << std::endl;
	cout << "Su longitud optima es: " << (*menor).calcularLongitudOptima() << " metros." << std::endl;
        cout << "Su media de distancias mínimas es: " << (*menor).calcularDistanciaMediaTrayectorias() << std::endl;
	cout << "Información del vuelo " << std::endl << (*menor);

	if ((*menor).calcularDistanciaMediaTrayectorias() < umbral_distancia) 
		cout << "La distancia media de las tratyectorias es menor a la umbral" << std::endl;
	else
		cout << "La distancia media de las tratyectorias no es menor a la umbral" << std::endl;


	
}