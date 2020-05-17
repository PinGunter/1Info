/*
	Programa para jugar a adivinar un numero
	Opcion para jugar cuantas veces se desee

27/10/2019
Salvador Romero Cortes
*/

#include <iostream>
#include <string>

using namespace std;

int main (){
	//Declaracion de variables
	int numero;
	char repetir;
	bool fin_de_bucle = false, jugar_de_nuevo = false;
	string entrada;
	
	//Entrada de datos

	do {
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
		
		cout <<"\nFin del juego\n";
		
		cout <<"\nQuieres volver a jugar? (s para si y n para terminar)\n";
		cin >> repetir;
		
		jugar_de_nuevo = repetir == 's';		
		
	} while (jugar_de_nuevo);
	//Sentencia para detener el programa
	system("pause");
	
}
