/* Programa para calcular la multiplicacion usando el algoritmo ruso
	
	El algoritmo va multiplicando por 2 el multiplicador y dividiendo por dos el multiplicando hasta que este sea 1.
	Finalmente se suman todos los multiplicadores cuyos multiplicandos sean impares
	ENTRADA --> productos
	SALIDA --> resultado de la multiplicacion
	
22/10/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main(){

	//Declaracion de variables
	
	int multiplicando = 0, multiplicador = 0 , suma = 0;
	bool terminador = false;
	
	//Entrada de datos
	cout << "Introduce el multiplicando --> ";
	cin >> multiplicando;
	
	cout << "Introduce el multiplicador --> ";
	cin >> multiplicador;
	
	cout << endl << multiplicando << " * " << multiplicador << " =";				//Esta linea sera la primera de la salida de datos
	//Computos
	
	while (!terminador){
	
		terminador = multiplicando == 1;
		
		//Comprobamos si es impar
		if (multiplicando % 2 == 1){
			suma += multiplicador;
			cout  << " + " << multiplicador;
		}
		multiplicando /= 2;
		multiplicador *= 2;
	
	}
	
	//Salida de datos
	cout << " = " << suma << endl;
	
	//Sentencia para detener el programa
	system("pause");
	
}
