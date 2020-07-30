/*
	Programa que lee enteros desde el teclado y calcula cuantos se han introducido 
	y cual es el minimo de dichos valores. Se para de introducir datos cuando se introduzca
	0. 
	ENTRADA --> numeros enteros
	SALIDA --> minimo de ellos y cuantos se han introducido
	
11/10/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main(){
	
	//Declaracion de variables
	
	int entero, contador, minimo;
	contador = 0;
	bool bucle_en_funcionamiento;
	
	//Entrada de datos y computo
	
	do{
		cout << "\nIntroduce un numero entero (0 para parar) --> ";
		cin >> entero;
		contador++;								//Contamos el numero de iteraciones
		
		//Comprobamos si el numero introducido es minimo
		
		if (contador == 1 || entero < minimo)
			minimo = entero;

		bucle_en_funcionamiento = true;

		//Caso extremo de que el primer numero sea 0
		if (contador == 1 && entero == 0){
			cout << "No has introducido ningun numero\n";
			contador--;															//No queremos que cuente el 0 ya que es el terminador
			continue;
		}
		else if(entero == 0){
			bucle_en_funcionamiento = false;
			contador--;															//No queremos que cuente el 0 ya que es el terminador
		}
	}while (bucle_en_funcionamiento); 

	
	//Salida de datos

	cout << "Has introducido " << contador << " numeros. Y el minimo de ellos es: " << minimo <<endl;

	//Sentencia para detener el programa
	system("pause");
}

