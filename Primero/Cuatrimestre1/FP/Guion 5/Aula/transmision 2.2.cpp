/*
   Programa que descodifica el mensaje extraterrestre
   El mensaje esta descompuesto en 1 y 0 y siempre acaba con 5 ceros
   Cada cadena de unos indica los factores primos del numero
   Parte 2 --> entrada de datos desde la parte 1. Calcula numero total.

18/10/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main(){
	
	//Declaracion de variables
	
	int factor, numero = 1 ;
	bool final = false;
	
	//Computos --> bucle para multiplicar los factores
	
	do{
		cin >> factor;
			
		if (factor == 0)					//No queremos multiplicar el ultimo 0 que finaliza
			final = true;
			
		else
			numero *= factor;				//Multiplicamos los factores

		
	} while (!final);
	
	//Salida de datos
	
	cout << "El numero descodificado es: " << numero << endl;

}
