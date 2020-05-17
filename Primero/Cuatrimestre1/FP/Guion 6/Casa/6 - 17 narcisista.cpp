/* 
	Programa que calcula si un numero es narcisista o no
	
	ENTRADA --> numero entero
	SALIDA --> indica si es narcisista o no
	
19/10/2019
Salvador Romero Cortes
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	
	//Declaracion de variables
	
	int numero, divisor = 10, suma = 0, contador, resto, numero_copia,numero_de_cifras,base;
	
	//Entrada de datos
	
	cout << "Introduce un numero entero --> ";
	cin >> numero;
	numero_copia = numero;
	
	//Computos
	
	do{									//Usamos este bucle para calcular cuantas cifras tiene el numero
		resto = numero % divisor;
		contador++;
		divisor*=10;
	} while (resto < numero);
	
	//Ahora que tenemos el numero de cifras calculamos si es narcisista o no
	
	//Copiamos el valor del contador en otra variable para poder modificar el contador sin problemas, restablecemos al divisor como 1
	numero_de_cifras = contador;
	divisor = 1;
	
	while (contador>0){
		base = (numero_copia/divisor)%10;
		suma += pow(base, numero_de_cifras);
		contador --;
		divisor*=10;
	}		
	
	//Salida 
	
	if (suma == numero)
		cout << numero << " es narcisista.\n";
	
	else
		cout << numero << " no es narcisista.\n";
		
	system("pause");
}
