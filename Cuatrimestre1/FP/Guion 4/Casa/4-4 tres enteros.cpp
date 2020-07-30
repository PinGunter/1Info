/*
Programa que lea tres valores enteros desde teclado y diga si estan ordenados o no
	ENTRADA --> dos enteros
	SALIDA --> decir si estan ordenados o no
	
04/10/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

//Programa principal 

int main(){
	
	//Declaracion de variables
	
	int entero1;
	int entero2;
	int entero3;
	
	//Entrada de datos
	
	cout << "Introduce el primer numero entero --> ";
	cin >> entero1;
	
	cout << "\nIntroduce el segundo numero entero --> ";
	cin >> entero2;
	
	cout << "\nIntroduce el tercer numero entero --> ";
	cin >> entero3;
	
	//Declaracion de variables booleanas y computo
	
	bool ascendente = entero1 < entero2 && entero2 < entero3;
	bool descendente = entero1 > entero2 && entero2 > entero3;
	
	//Salida
	
	if (ascendente)
		cout << "\nLos numeros estan ordenados de forma ascendente.\n";
	else if (descendente){
		cout << "\nLos numeros estan ordenados de forma descendente.\n";
	}
	else
		cout << "\nNo estan ordenados.\n";
	
	//Sentencia para detener el programa
	
	system("pause");
}
