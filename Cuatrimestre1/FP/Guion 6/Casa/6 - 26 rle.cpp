/*
	Programa que codifica una entrada segun el metodo RLE
	
	ENTRADA --> secuancia de numeros naturales 
	SALIDA --> secuencia codificada segun RLE
19/10/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main(){
	
	//Declaracion de variables
	int entrada, suma, contador,numero;
	entrada = suma = contador = numero = 0;
	
	cout << "Introduce la secuencia separado por espacios (numero negativo para parar): ";
	
	//Bucle de entrada y computo de datos
	
	/*Calcularemos los numeros introducidos sumandolos y luego dividiendo
	esa suma entre el contador*/
	
	do{
		cin >> entrada;

		/*En cuanto la entrada sea distinta del numero anterior calcularemos el RLE del anterior
		y reseteamos la suma y el contador*/
		
		if (numero!= entrada && contador>0){
			numero = suma / contador;
			cout << contador << " " << numero << " ";
			suma = 0;
			contador = 0;
		}
		suma+=entrada;
		contador++;
		numero = entrada;			

	} while (entrada>0);
	
	//Sentencia para detener el programa
	cout << endl << endl;
	system("pause");
}
