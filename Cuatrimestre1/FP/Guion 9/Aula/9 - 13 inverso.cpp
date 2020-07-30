/* Programa para devolver un numero con las cifras invertidas

14/11/2019
Salvador Romero Cortes
*/

#include <iostream>
#include <cmath>

using namespace std;

int CuentaCifras(int numero);
int Inverso(int numero);

int main(){
	//declaracion de variables
	int entrada;
	int resultado;
	
	//Entrada de datos
	do{
		cout << "Introduce un numero entero positivo: ";
		cin >> entrada;
	} while (entrada < 1);
	
	//Computos
	resultado = Inverso(entrada);
	
	//Salida de datos
	cout << "\nEl numero " << entrada << " invertido es " << resultado << endl;
}

//Funcion que cuenta las cifras de un numero. Vamos dividiendo entre multiplos de 10 y haciendo modulo 10. Contamos cada iteracion
int CuentaCifras(int numero){
	int cuenta = 0, resto = 0, divisor = 10;
	while (resto != 0 || cuenta == 0){
		resto = numero / divisor;
		cuenta++;
		divisor *= 10;
	}
	return cuenta;
}

//Funcion para invertir las cifras
//Primero calculamos el numero de cifras que tiene, luego las separamos y finalmente hacemos las operaciones correspondientes para obtener el numero (multiplicar por multiplos de 10)

int Inverso(int numero){
	int cifra, inverso = 0, divisor = 1;
	int cuenta = CuentaCifras(numero);
	do{
		cifra = (numero / divisor) % 10;
		inverso += cifra * pow(10, cuenta - 1);
		divisor *= 10;
		cuenta --;
	} while (cuenta > 0);
	
	return inverso;
}
