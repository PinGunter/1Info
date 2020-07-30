/* Programa para implementar una funcion que devuelva si un caracter esta en una cadena
15/11/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int TamanioCadena(const char cadena[]);
bool SeEncuentra(const char cadena[], char caracter);

int main(){
	const int LONG = 150;
	//declaracion de variables
	char caracter;
	char cadena[LONG];
	bool encontrada;
	
	//Entrada de datos
	cout << "Introduce la cadena de caracteres\n";
	cin.getline(cadena, LONG);
	
	cout << "\nIntroduce el caracter que deseas buscar --> ";
	cin >> caracter;
	
	//Computos
	encontrada = SeEncuentra(cadena, caracter);	
	
	//Salida de datos
	if (encontrada)
		cout << "Se ha encontrado " << caracter << " en la cadena \"" << cadena << "\"." << endl;
	else
		cout << "No se ha encontrado " << caracter << " en la cadena \"" << cadena << "\"." << endl;
}

//Funcion para calcular el tamanio de una cadena
int TamanioCadena(const char cadena[]){
	int tamanio = 0;
	int i = 0;
	while (cadena[i] != '\0'){
		tamanio++;
		i++;
	}
	return tamanio;
	
}
//Funcion para realizar una busqueda secuencial del caracter en la cadena
bool SeEncuentra(const char cadena[], char caracter){
	int j = 0, tamanio = TamanioCadena(cadena);
	bool encontrado = false;
	
	while (j < tamanio && !encontrado){
		if (cadena[j] == caracter){
			encontrado = true;
		}
		else
			j++;
	}
	
	return encontrado;
}
