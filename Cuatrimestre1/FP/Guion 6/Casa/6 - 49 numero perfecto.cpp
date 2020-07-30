/* Programa para calcular numeros perfectos
	ENTRADA --> numero
	SALIDA --> mayor numero perfecto menor al introducido
	
22/10/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main(){

	//Declaracion de variables
	int entero, perfecto= 0, max_perfecto = 0;	
	//Entrada de datos
	cout << "Introduce un numero --> ";
	
	cin >> entero;

	//Computos
	
	for (int i = 1; i<=entero; i++){ 
		
		for (int j = 1; j<i; j++){
			
			if (i % j == 0)					//encontramos los divisores y los vamos sumando (sin contar el numero en si)
				perfecto += j;	
		}
		if (perfecto==i){
			if (perfecto > max_perfecto)	//Comprobamos cual de ellos es el mayor
				max_perfecto = perfecto;
		}
		perfecto = 0;						//Reseteamos la suma con cada iteracion del primer bucle for
	
	}
	
	//Salida
	
	if (max_perfecto > 0)
		cout << "\nEl numero perfecto mas grande menor a " << entero << " es " << max_perfecto << endl;
	else
		cout << "\nNo existe un numero perfecto menor al numero introducido" << endl;

	//Sentencia para detener el programa
	system("pause");
}
