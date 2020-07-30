/*
	Programa que indica si un anio introducido es bisiesto o no
	
	ENTRADA --> anio cualquiera
	SALIDAD --> el anio es bisiesto o no

05/10/2019
Salvador Romero Cortes
*/

#include <iostream>				//Incluimos los recursos de E/S

using namespace std;

//Programa principal

int main(){
	
	//Declaramos las variables que vamos a usar para almacenar los datos
	
	int anio;
	bool es_bisiesto;
	
	//Entrada de datos
	
	cout << "Introduce un anio --> ";
	cin >> anio;
	
	//Computos
	
	/*Establecemos el valor de la variable es bisiesto
	Para que sea bisiesto tiene que cumplir:
		1. Sea divisible entre 4
		2. No sea divisible entre 100
		3. Excepcion si es divisible entre 400
	*/
	
	es_bisiesto = (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0;
	
	//Salida
	
	if (es_bisiesto)
		cout << "El anio introducido es bisiesto.\n";
	else
		cout << "El anio introducido no es bisiesto.\n";
		
	//Sentencia para detener el programa
	
	system("pause");
		
	
	
}
