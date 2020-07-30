#include <iostream>
#include <iomanip>

using namespace std;

void FrecuenciasDeChar(const char entrada[],int utiles, int salida[]);

void AMinuscula(char vector[],int utiles);

const char TERMINADOR = '#';
const int TAMANIO = 2000;
const char ABC[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
const int DISTANCIA = 'a' - 'A';

int main() {
	char texto[TAMANIO], aux;
	int frecuencias[TAMANIO], utiles = 0;

	do {
		cin >> aux;
		if (aux != TERMINADOR) {
			texto[utiles] = aux;
			utiles++;
		}
	} while (aux != TERMINADOR);

	//computos
	AMinuscula(texto, utiles);
	FrecuenciasDeChar(texto, utiles, frecuencias);
	
	//salida de datos
	cout << "CARACTER" << setw(18) << "FRECUENCIAS" << endl;
	for (int i=0; i < 26; i++){
		cout << setw(4) << ABC[i] << setw(17) << frecuencias[i] << endl;
	}


}

void AMinuscula(char vector[], int utiles) {
	for (int i=0; i < utiles; i++) {
		if (vector[i] >= 'A' && vector[i] <= 'Z') {
			vector[i] = vector[i] + DISTANCIA;
		}
	}
}

void FrecuenciasDeChar(const char entrada[], int utiles, int salida[]){
	int contador;
	
	for (int i=0; i < 26; i++){
		contador = 0;
		for (int j=0; j < utiles; j++){
			if (ABC[i] == entrada[j])
				contador++;
		}
		salida[i] = contador;
	}
}
