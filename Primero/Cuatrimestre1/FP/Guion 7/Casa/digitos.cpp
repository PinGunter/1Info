/* Programa que separa un numero entero arbitrario en sus cifras

	ENTRADA --> numero entero cualquiera
	SALIDA --> sus digitos separados por espacios
	
26/10/2019
Salvador Romero Cortes
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	//Declaracion de variables
	int contador = 0, numero, divisor = 1, modulo, izquierda, digito;
	
	//Entrada de datos
	cout << "Introduce un numero entero --> ";
	cin >> numero;
	
	//Computos
	//Primero contamos cuantas cifras tiene el numero
	//Para ello lo dividimos en cifras y contamos cuantas hay
	
	do{
		izquierda = numero / divisor;
		contador ++;
		divisor *= 10;
	}while (izquierda != 0);
	
	
	//Ahora separamos los digitos y los imprimimos por pantalla
	//Para separarlos en orden hacemos modulo de 10^(contador-1) y luego dividimos el resultado entre una potencia menos de 10
	for (int j = contador - 1; j >= 1 ; j --){
		modulo = (int)pow(10.0, j);
		divisor = modulo / 10;
		digito = (numero % modulo) / divisor;
		cout << digito << " ";	
	}
	
	//Sentencia para detener el programa
	cout << "\n";
	system("pause");
}
