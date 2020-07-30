/*
	Programa para jugar a adivinar un numero
	Apartados a) y b)
	Apartados a) y b)
27/10/2019
Salvador Romero Cortes
*/

#include <iostream>
#include <string>

using namespace std;

int main (){
	//Declaracion de variables
	int numero;
	bool fin_de_bucle = false;
	string entrada;
	
	//Entrada de datos
	
	cout << "Introduce el numero a adivinar: ";
	cin >> numero;
	
	
	//Computos
	do{
		cout << "Introduce un numero (Escribe \"@\" para parar):\n";
		cin >> entrada;
		
		if (entrada == "@")
			fin_de_bucle = true;
		
		//Usamos stoi pra convertir la entrada de tipo string en un entero
		else if (stoi(entrada) > numero)
			cout << "\nEl numero introducido es mayor.\n";
		
		else if (stoi(entrada) < numero)
			cout << "\nEl numero introducido es menor.\n";
			
		else{
			cout << "\nHas acertado!!\n";
			fin_de_bucle = true;
		}
		
	}while (!fin_de_bucle);
	
	//Salida
	cout <<"\nFin del juego\n";
}
