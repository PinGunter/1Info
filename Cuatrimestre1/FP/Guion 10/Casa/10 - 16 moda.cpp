/* Programa para calcular la moda de una cadena de caracateres
16/11/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

struct FrecuenciaCaracter{
	char caracter;
	int frecuencia;
};

int TamanioCadena(const char cadena[]);
void CalcularFrecuencia(const char cadena[], FrecuenciaCaracter vector_frecuencias[],int &tamanio);
FrecuenciaCaracter CalcularModa(FrecuenciaCaracter lista_caracteres[], int tamanio);

int main(){
	const int LONG = 150;
	//declaracion de variables
	FrecuenciaCaracter vector_frecuencias [LONG], moda;
	char cadena[LONG];
	int tamanio;
	
	//Entrada de datos
	cout << "Introduce la cadena de caracteres:\n";
	cin.getline(cadena, LONG);
	
	//Computos
	CalcularFrecuencia(cadena, vector_frecuencias, tamanio);
	moda = CalcularModa(vector_frecuencias, tamanio);
	
	//Salida de datos
	cout << "El caracter que mas se repite es: " << moda.caracter << " con una frecuencia de " << moda.frecuencia << endl;
}

//Funcion para obtener el tamanio de una cadena de caracteres
int TamanioCadena(const char cadena[]){
	int i = 0, tamanio = 0;
	while (cadena[i] != '\0'){
		tamanio++;
		i++;
	}
	return tamanio;
}

//Funcion para obtener las frecuencias de cada caracter en la cadena
//Comprobamos si dos caracteres son iguales y aumentamos su frecuencia
//Para ello debemos establecer todas las frecuecias como 0 para que no haya problemas de sumar "basura"
void CalcularFrecuencia(const char cadena[], FrecuenciaCaracter vector_frecuencias[],int &tamanio){
	tamanio = TamanioCadena(cadena);
	
	for (int i=0; i < tamanio; i++)
		vector_frecuencias[i].frecuencia = 0;
	
	for (int i=0; i < tamanio; i++)
		for (int j = 0; j < tamanio; j++)
			if (cadena[i] == cadena[j]){
				vector_frecuencias[i].caracter = cadena[i];
				vector_frecuencias[i].frecuencia++;
			}
}

FrecuenciaCaracter CalcularModa(FrecuenciaCaracter lista_caracteres[], int tamanio){
	FrecuenciaCaracter maximo;
	int i = 0;
	maximo = lista_caracteres[i];
	
	for (int i = 0; i < tamanio; i++){
		if (lista_caracteres[i].frecuencia >= maximo.frecuencia)
			maximo = lista_caracteres[i];
	}
	
	return maximo;
}
