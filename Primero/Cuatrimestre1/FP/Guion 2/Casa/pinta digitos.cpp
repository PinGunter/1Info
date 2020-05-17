/*
Programa que separa los dígitos de un numero de 3 cifras introducido por el usuario
Por Salvador Romero Cortés
21/09/2019
*/

#include <iostream>											//Incluimos los recursos de E/S

using namespace std;

int main(){														//Programa principal

	const char spa = ' ';									//Declaramos la variable de un espacio para que sea más como al imprimir el resultado. Es constante

	int numero, cifra1, cifra2, cifra3;					//Declaramos las variables para guardar el numero introducido y cada una de las cifras
	
	cout << "Introduce el número de 3 dígitos:\n";	//Preguntamos al usuario por el número
	cin >> numero;
	
	cifra1 = numero/100; 									//Así truncamos el primer digito
	
	cifra2 = numero/10 - cifra1*10; 						//Así el segundo
	
	cifra3 = numero - cifra1*100 - cifra2*10; 		//El ultimo digito será la resta de la centena y decena
	
	//Imprimimos el resultado
	
	cout << "El número separado es:\n" << cifra1 << spa << cifra2 << spa << cifra3 << endl;
	
	system("pause");											//Sentencia para detener el programa
	
}
