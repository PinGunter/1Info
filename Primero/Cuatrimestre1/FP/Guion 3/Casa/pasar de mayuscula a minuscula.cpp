/*
Programa que lee un caracter en mayuscula y devuelve el caracter en minuscula
No se puede utilizar "toupper" ni "tolower"

	Entrada: caracter en mayuscula
	Salida: caracter en minuscula

Salvador Romero Cortes
28/09/2019
*/

#include <iostream>														//Incluimos los recursos de E/S

using namespace std;

int main(){																	//Programa principal
	
	//Declaramos la variable para el caracter que introducira el usuario
	
	char caracter, caracter_min;
	
	//Pedimos al usuario el caracter y lo asignamos a la variable
	cout << "Introduce el caracter (en mayuscula) ---> ";
	cin >> caracter;
	
	/*Ahora lo convertimos a minuscula. Comprando la tabla ASCII se aprecia que 
	entre cada letra y su mayuscula hay una diferencia de 32. Usaremos esto para pasarlo a minuscula
	aprovechando la equivalencia con el tipo entero
	*/
	
	caracter_min = caracter + 32;
	
	//Mostramos el resultado
	
	cout << "El caracter en minuscula es: " << caracter_min << endl;
	
	//Sentencia para que el programa se detenga hasta que el usuario interactue
	system("pause");
	
}
