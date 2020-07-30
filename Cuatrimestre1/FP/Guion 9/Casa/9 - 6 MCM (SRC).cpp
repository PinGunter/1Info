/* Programa para calcular el MCM usando un modulo

10/11/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

//Para calcular el MCM podemos utilizar el MCD.
//De manera que MCM(a,b) = a*b / MCD(a,b)

int MCM(int a, int b){
	int mcd, mcm;
	//Calculamos el MCD
	if (a!=0 || b!=0){
		for (int i = 1; i <= a && i <= b; i++){
			if (a % i == 0 && b % i == 0)
				mcd = i;
		}
		//Calculamos el mcm
		mcm = (a*b) /mcd;
	}
	else							//En caso de que sean alguno sea 0, no hace falta hacer calculos, el mcm es 0
		mcm = 0;
	
	return mcm;
}

int main(){
	//Declaracion de variables
	int num1, num2, resultado;
	
	//Entrada de datos
	cout << "Introduce los numeros a los que se calcularan su MCM:\n";
	cin >> num1 >> num2;
	
	//Computos
	resultado = MCM(num1,num2);
	
	//Salida de datos
	cout << "\nEl MCM de los numeros introducidos es: " << resultado << endl;
	
	system("pause");
}
