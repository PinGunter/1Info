/* Programa para calcular el numero de secuencias ascendentes de un vector

	ENTRADA --> vector
	SALIDA --> numero de secuencias ordenadas
05/11/2019
Salvador Romero Cortes
*/
#include <iostream>

using namespace std;

int main(){
	//Declaracion de variables
	int vector [7];
	int contador = 1, anterior = -100000;
	
	//Entrada de datos
	cout << "Introduce los valores del vector entero de 7 elementos:\n";
	
	for (int i = 0; i < 7; i++)
		cin >> vector[i];
	
	cout << "Vector: {";
	for (int j = 0; j < 7; j++){
		cout << vector[j];
		if (j < 6)
			cout << ", ";
	}
	cout << "}\n";

	//Computos
	//como las secuencias individuales tambien cuentan, solo aumentaremos el contador cuando no sea ascendente
	for (int k = 0; k < 7; k++){
		if (vector[k] < anterior)
			contador++;
		anterior = vector[k];
	}
	
	//Salida de datos
	cout << "\nHay " << contador << " secuencias.\n";
	system("pause");
}
