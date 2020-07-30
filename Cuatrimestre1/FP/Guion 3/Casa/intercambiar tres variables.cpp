/*
Programa para intercambiar los valores entre tres variables utilizando el menor 
numero posible de variables auxiliares.

Salvador Romero Cortes
28/09/2019

*/

#include <iostream>													//Incluimos los recursos de entrada y salida

using namespace std;

int main(){																//Programa principal
	
	//Declaramos las variables que vamos a usar para almacenar los datos
	
	int x = 10;
	int y = 20;
	int z = 30;
	int variable_de_cambio;
	
	//Comenzamos a cambiar los valores
	
	variable_de_cambio = x;
	x = z;
	z = y;
	y = variable_de_cambio;
	
	//Imprimimos los resultados
	
	cout << "La variable x ahora vale: " << x << endl;
	cout << "La variable y ahora vale: " << y << endl;
	cout << "La variable z ahora vale: " << z << endl;
	
	system("pause");													//Sentencia para detener el programa hasta la interaccion del ususario
}
