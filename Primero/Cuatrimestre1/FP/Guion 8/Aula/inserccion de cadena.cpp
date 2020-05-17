/* Programa para insertar una cadena de caracteres dentro de otra

07/11/2019
Salvador Romero Cortes*/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){
	const int LONGITUD = 101;
	
	//Declaracion de variables
	char cadena_grande[LONGITUD];
	char cadena_pequenia[LONGITUD];
	int posicion;
		
	//Entrada de datos
	cout << "Introduce la cadena a la que se aniade la segunda cadena (maximo 50 caracteres):\n";
	cin.getline(cadena_grande, 50);
	
	cout << "Introduce la cadena que se introduce en la primera:\n";
	cin.getline(cadena_pequenia, 50);

	cout << "Introduce la posicion en la que quieres que se inserte la cadena --> ";
	cin >> posicion;
	
	//Computos
	//El algoritmo consistira en mover los valores de la cadena grande a la derecha a partir de "posicion"
	//En esos vacios que se han creado insertamos la segunda cadena

	for (int i = LONGITUD; i > posicion; i--){
		cadena_grande[i] = cadena_grande[i-strlen(cadena_pequenia)];	
	}
	
	for (int j=0; j < strlen(cadena_pequenia); j++){
			cadena_grande[posicion+j] = cadena_pequenia[j];
		}
	
	//Salida de datos
	cout <<"\nLa cadena final queda como:\n" << cadena_grande << endl << endl;
	system("pause");
	
}
