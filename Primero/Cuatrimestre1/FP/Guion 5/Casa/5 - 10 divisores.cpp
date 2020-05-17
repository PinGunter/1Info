/*
	Programa que imprime todos los divisores de un entero
	
	ENTRADA --> entero positivo
	SALIDA --> todos sus divisores
	
11/10/2019
Salvador Romero Cortes
*/

//Incluimos los recursos de E/S
#include <iostream>

using namespace std;

int main(){
	
	//Declaracion de variables
	
	int entero;
		
	//Entrada de datos con filtro para que sea positivo
	
	do{
		cout << "\nIntroduce un numero entero positivo --> ";
		cin >> entero;
		
	} while (entero <= 0);
	
	//Computos y salida
	
	//Usamos un bucle for para comprobar los divisores
	
	for (int i = 1; i <= entero; i++){
		if (entero % i == 0)
			cout << "\t" << i << " es divisor de " << entero << endl;
	}
	
	//Sentencia para detener el programa
	system("pause");
	
}
