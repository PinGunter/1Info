//Ver si un vector esta dentro de otro
#include <iostream>

using namespace std;

bool EstaContenido(char vector1[], int tamanio1, char vector2[], int tamanio2);

int main() {
	int tamanio1, tamanio2;
	char vector1[100], vector2[100];
	bool contenido;

	cout << "Introduce el tamanio del primer vector: ";
	cin >> tamanio1;
	cout << "Introduce los elementos del vector: ";
	for (int i = 0; i < tamanio1; i++)
		cin >> vector1[i];

	cout << "\nIntroduce el tamanio del segundo vector: ";
	cin >> tamanio2;
	cout << "Introduce los elementos del vector: ";
	for (int i = 0; i < tamanio2; i++)
		cin >> vector2[i];

	//comprobamos si el segundo esta dentro del primero
	contenido = EstaContenido(vector1, tamanio1, vector2, tamanio2);

	//salida
	if (contenido)
		cout << "esta contenido";
	else
		cout << "no esta contenido";
}


bool EstaContenido(char vector1[], int tamanio1, char vector2[], int tamanio2) {
	bool contenido = false;
	bool va_coincidiendo = true;
	for (int i=0; i <= tamanio1 - tamanio2 && !contenido; i++){
		va_coincidiendo = true;
		for (int j=0 ;j < tamanio2 && va_coincidiendo; j++)
			va_coincidiendo = vector1[j+i] == vector2[j];
			
		if (va_coincidiendo)
			contenido = true;
	}
	return contenido;
}
