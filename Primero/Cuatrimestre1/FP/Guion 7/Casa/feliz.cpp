/*
	Programa que calcula si un numero es feliz
	ENTRADA --> numero entero
	SALIDA --> si es feliz o no
	
26/10/2019
Salvador Romero Cortes
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	//Declaracion de variables
	int numero, grado, divisor = 1, izquierda, digito, suma = 0, numero_iterado;
	bool feliz;
	
	//Entrada de datos
	cout << "Introduce un numero que quieras saber si es feliz --> ";
	cin >> numero;
	cout << "Introduce el grado del numero feliz que quieres comprobar --> ";
	cin >> grado;
	
	//Computos
	
	//Para calcular si el numero es feliz, tenemos que separar los digitos del numero y sumar sus cuadrados
	//Vamos dividiendo por multiplos de 10 y haciendo modulo 10 para sacar los digitos
	//Repetimos el proceso segun el grado introducido
	
	numero_iterado = numero;
	
	for (int j = 1; j <= grado; j++){
		do{
			izquierda = numero_iterado/divisor;
			digito = izquierda % 10;
			suma += digito * digito;
			divisor *= 10;	
		} while (izquierda != 0);	
		
		if (suma == 1)
			feliz = true;
			
		numero_iterado = suma;
		suma = 0;
		divisor = 1;
	}
	
	//Salida de datos
	if (feliz)
		cout << numero << " es un numero feliz\n";
	else
		cout << numero << " no es un numero feliz\n";
		
	//Sentencia para detener el programa
	system("pause");

	




}
