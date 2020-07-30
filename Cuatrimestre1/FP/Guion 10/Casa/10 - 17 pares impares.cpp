/* Programa para obtener dos vectores a partir de uno inicial
	Los dos vectores resultantes son uno de impares y otro de elementos pares
16/11/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

void ParesImpares(const int vector[], int pares[], int impares[],int tamanio, int &tamanio_par, int &tamanio_impar);

int main(){
	const int LONG = 100;
	//declaracion de variables
	int vector[LONG], impares[LONG], pares[LONG];
	int tamanio, tamanio_par, tamanio_impar;
	tamanio = tamanio_par = tamanio_impar = 0;
	
	//entrada de datos
	cout << "Introduce el tamanio del vector (max. 100) --> ";
	cin >> tamanio;
	
	cout << "Introduce los elementos del vector:\n";
	for(int i=0; i < tamanio; i++)
		cin >> vector[i];
		
	//computos
	ParesImpares(vector, pares, impares, tamanio, tamanio_par, tamanio_impar);
	
	//salida de datos
	cout << "\n\nEl vector {";
	for (int i=0; i < tamanio; i++){
		cout << vector[i];
		if (i < tamanio -1)
			cout << ", ";
	}
	cout << "} se divide en:\nVector de numeros pares: {";
	for (int i=0; i < tamanio_par; i++){
		cout << pares[i];
		if (i < tamanio_par -1)
			cout << ", ";
	}
	cout << "}\nVector de numeros impares: {";
		for (int i=0; i < tamanio_impar; i++){
		cout << impares[i];
		if (i < tamanio_impar -1)
			cout << ", ";
	}
	cout << "}\n";
}

//funcion para calcular los vectores impares y pares de uno de entrada
void ParesImpares(const int vector[], int pares[], int impares[], int tamanio, int &tamanio_par, int &tamanio_impar){
	int contador, contador_pares, contador_impares;
	contador = contador_pares = contador_impares = 0;
	
	while (contador < tamanio){
		if (vector[contador] % 2 == 0){
			pares[contador_pares] = vector[contador];
			contador_pares++;
		}
		else{
			impares[contador_impares] = vector[contador];
			contador_impares++;
		}
		contador++;
	}
	
	tamanio_par = contador_pares;
	tamanio_impar = contador_impares;
}
