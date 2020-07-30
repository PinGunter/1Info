/* Programa para calcular los numeros perfectos hasta un determinado numero
14/11/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

bool EsPerfecto(int numero);

int main(){
	//Declaracion de variables
	int maximo;
	
	//Entrada de datos
	cout << "Introduce el numero maximo --> ";
	cin >> maximo;
	
	//Computos y Salida de datos
	for (int i=1; i < maximo; i++){
		if (EsPerfecto(i))
			cout << i << " es perfecto.\n";
	}
}
//Funcion para comprobar si es perfecto o no. Obtenemos los divisores, los sumamos y comprobamos si es igual al numero
bool EsPerfecto(int numero){
	bool perfecto = false;
	int suma = 0;
	
	//Sumamos los divisores
	for (int i=1; i < numero; i++){
		if (numero % i == 0)
			suma += i;
	}
	
	//Comprobamos si es igual al numero
	if (suma == numero)
		perfecto = true;
		
	return perfecto;	
}
