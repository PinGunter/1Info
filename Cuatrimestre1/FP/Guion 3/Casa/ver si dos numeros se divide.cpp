/* Programa para indicar si dos valores introducidos por el usuario se dividen de forma
entera al otro.

	Entrada --> dos numeros enteros
	Salida --> afirmacion de si son divisores
	
Salvado Romero Cortes
28/09/2019
*/

#include <iostream>										//Incluimos los recursos de E/S

using namespace std;

int main(){													// Programa principal
	
	//Declaramos las variables que vamos a usar para guardar los datos de los enteros
	
	int entero1, entero2;
	
	//Preguntamos al usuario por los valores de los numeros
	
	cout << "Introduce el valor del primer numero entero --> ";
	cin >> entero1;
	
	cout << "\nIntroduce el valor del segundo numero entero --> ";
	cin >> entero2;
	
	//Usamos una estructura condicional para comprobar si son divisores
	
	if (entero1 % entero2 == 0){
		//Si el segundo entero es divisor del primero se ejecutara esta linea
		cout << "\nEl segundo numero entero es divisor del primero.\n";
	} else{
		//Si no es asi comprobamos si el primero es divisor del segundo con otra estructura condicional
			if (entero2 % entero1 == 0){
				//Si se cumple la condicion se ejecutara la siguiente sentencia
				cout << "\nEl primer numero entero es divisor del segundo.\n";
			} else{
				//En caso que ninguno sea divisor se ejecutara esta sentencia
				cout << "\nNinguno de los numeros introducidos son divisores del uno al otro.\n";
			}
	}
	
	//Sentencia para detener el programa hasta que el usuario interactue con el teclado
	system("pause");
}
