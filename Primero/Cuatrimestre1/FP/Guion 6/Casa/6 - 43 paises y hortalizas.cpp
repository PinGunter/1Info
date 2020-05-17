/*
	Programa que calcula que pais exporta mas hortalizas
	ENTRADA --> pais, tipo de hortaliza y toneladadas vendidas
	SALIDA --> el que mas exporta

22/10/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main(){
	
	//Declaracion de variables
	char pais, hortaliza;
	string max_pais;
	double exportaciones, suma_esp = 0, suma_fr = 0, suma_de = 0, max_exportaciones;
	bool terminador = false;
	
	//Entrada de datos y computos con bucle do while
	cout << "Introduce el caracter del pais, el identificador de hortaliza y toneladas vendidas:\n";
	cout << "Introduce \"@\" para finalizar\n";
	
	while (!terminador){
	
		cin >> pais;
		
		//Comprobamos si va a terminar con @
		if (pais == '@')
			terminador = true;
		
		//Entrada del resto de datos
		
		cin >> hortaliza >> exportaciones;
		
		//Vamos aniadiendo los valores de las exportaciones de cada pais
		
		if (pais == 'E')
			suma_esp += exportaciones;
		
		else if (pais == 'F')
			suma_fr += exportaciones;
		
		else if (pais == 'A')
			suma_de += exportaciones;
		
		//Comprobamos que el valor introducido sea correcto
		
		if (!(hortaliza == 'T' || hortaliza == 'P' || hortaliza == 'E'))
			cout <<"\nValor h no valido\n";	
	}
	
	//Ahora comprobamos cual es el mayor exportador
	if (suma_esp > suma_fr && suma_esp > suma_de){
		max_exportaciones = suma_esp;
		max_pais = "Espania";
	}
	
	else if (suma_fr > suma_esp && suma_fr > suma_de){
		max_exportaciones = suma_fr;
		max_pais = "Francia";
	}
	
	else if (suma_de > suma_esp && suma_de > suma_fr){
		max_exportaciones = suma_de;
		max_pais = "Alemania";
	}
	
	//Salida de datos
	
	cout << "El pais que mas vende es " << max_pais << " con un total de " << max_exportaciones << " toneladas.\n";
	
	//Sentencia para detener el programa
	system("pause");
}
