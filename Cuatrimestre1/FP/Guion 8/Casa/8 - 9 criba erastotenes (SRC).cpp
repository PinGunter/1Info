/* Programa para calcular la criba de Erastotenes

	ENTRADA --> numero maximo
	SALIDA --> primos menores al maximo
04/11/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main(){
	//Declaracion de variables
	bool primos[1000];
	int numeros[1000];
	int maximo;
	
	//Entrada de datos
	cout << "Introduce el numero maximo:\n";
	cin >> maximo;
	
	//Computos
	//De primeras consideramos todos los numeros como primos
	for (int i = 0; i < maximo; i++)
		primos[i] = true;
	//Rellenamos un vector con los valores hasta el maximo
	for (int i = 0; i < maximo; i++) 
		numeros[i] = i;
		
	//Ahora marcamos como falsos los multiplos de cada numero que consideremos primo
	//Es decir, calculamos los multiplos de los "true" y los marcamos como "false"
	for (int j=2; j < maximo; j++){
		if (primos[j]){
			for (int k = j+1; k < maximo; k++){
				if (k % j == 0)
					primos[k] = false;
			}
			
		}
	}
	
	//Salida de datos
	cout << "Los numeros primos menores a " << maximo << " son:\n";
	for (int i=0;i<maximo;i++){
		if (primos[i])
			if (numeros[i]!=0)
				cout << numeros[i] << "\n";
	}
	
	system("pause");
}
