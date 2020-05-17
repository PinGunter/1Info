/*
Programa que convierte un caracter en un numero entero
Si por ejemplo introducimos como caracter '7' nos devuelve
el entero 7.

	Entrada: caracter numerico entre 0 y 9
	Salida: el numero entero correspondiente
	
Salvador Romero Cortes
28/09/2019
*/

#include <iostream>														//Incluimos los recursos de E/S

using namespace std;

int main() {
	
	//Declaramos las variables que vamos a utilizar
	
	char car;
	int entero;
	
	//Pedimos al usuario el caracter entre 0 y 9
	
	cout << "Introduce un numero entre 0 y 9 --> ";
	cin >> car;
	
	//En la tabla ASCII podemos ver que entre cada numero entero y su caracter hay una diferencia de 48
	//Por lo tanto basta con restarsela para obtener el entero correspondiente
	
	entero = car - 48;
	
	cout << "El numero entero que has introducido es --> " << entero << endl;
	
	//Sentencia para detener el programa hasta que el usuario interactue
	system("pause");
	
}
