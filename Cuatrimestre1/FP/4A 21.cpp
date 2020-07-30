#include <iostream>
using namespace std;

const int LONG = 100;

struct FrecuenciaCaracter {
	char caracter;
	int frecuencia = 0;
};

class Palabra {
private:
	char cadena[LONG] = {0};

	//metodo para calcular si los extremos estan bien
	bool ExtremosBien(Palabra otra);

	//metodo para comprobar si la parte intermedia de la palabra cumple las condiciones
	bool IntermedioBien(Palabra otra);

public:
	//constructor con parametros
	Palabra(char entrada[]);

	//metodo para obtener la longitud de la cadena
	int LongitudCadena();

	//metodo para calcular las frecuencias de los caracteres de una palabra desde una posicion y hasta un final concretos
	void CalcularFrecuencias(FrecuenciaCaracter vector[], int inicio, int final);

	//metodo para obtener un caracter iesimo de la cadena
	char GetChar(int i);

	//metodo para saber si son iguales
	bool SonIguales(Palabra otro);
};

int main() {
	//declaracion de variables y objetos
	char cadena[LONG], cadena2[LONG];
	bool iguales;
	//entrada de datos
	cout << "Introduce la primera palabra: ";
	cin.getline(cadena, LONG);
	Palabra primera(cadena);

	cout << "Introduce la segunda palabra: ";
	cin.getline(cadena2, LONG);
	Palabra segunda(cadena2);

	//computos
	iguales = primera.SonIguales(segunda);

	//salida de datos
	if (iguales)
		cout << "Las palabras son iguales.";
	else
		cout << "Las palabras no son iguales.";

}

int Palabra::LongitudCadena() {
	int i = 0;
	while (cadena[i] != '\0')
		i++;

	return i;
}

void Palabra::CalcularFrecuencias(FrecuenciaCaracter vector[], int inicio, int final) {
	for (int i = inicio; i < final; i++) {
		for (int j = inicio; j < final; j++) {
			if (cadena[i] == cadena[j]) {
				vector[i-1].caracter = cadena[i];
				vector[i-1].frecuencia++;
			}
		}
	}
	vector[final-1].caracter = '\0';
	vector[final-1].frecuencia = 0;
}

bool Palabra::ExtremosBien(Palabra otra) {
	char inicio1 = cadena[0];
	char inicio2 = otra.GetChar(0);
	char final1 = cadena[LongitudCadena() - 1];
	char final2 = otra.GetChar(otra.LongitudCadena() - 1);

	bool bien = inicio1 == inicio2 && final1 == final2;
	return bien;
}

bool Palabra::IntermedioBien(Palabra otra) {
	FrecuenciaCaracter vector1[LONG], vector2[LONG];
	int longitud = LongitudCadena();
	bool bien[LONG] = { 0 };
	bool intermedio_bien = true;

	CalcularFrecuencias(vector1, 1, longitud - 1);
	otra.CalcularFrecuencias(vector2, 1, longitud - 1);

	for (int i = 0; i < longitud-2; i++) {
		for (int j = 0; j < longitud && !bien[i]; j++) {
			if (vector1[i].caracter == vector2[j].caracter && vector1[i].frecuencia == vector2[j].frecuencia)
				bien[i] = true;
			else
				bien[i] = false;

		}
	}
	for (int i = 0; i < longitud-2; i++)
		if (!bien[i])
			intermedio_bien = false;


	return intermedio_bien;
}

Palabra::Palabra(char entrada[]) {
	int i = 0;
	while (entrada[i] != '\0') {
		cadena[i] = entrada[i];
		i++;
	}
}

char Palabra::GetChar(int i) {
	return cadena[i];
}

bool Palabra::SonIguales(Palabra otro) {
	int longitud1 = LongitudCadena();
	int longitud2 = otro.LongitudCadena();
	bool iguales;
	bool extremos = ExtremosBien(otro);
	bool intermedio = IntermedioBien(otro);
	if (longitud1 == longitud2)
		iguales = extremos && intermedio;
	else
		iguales = false;

	return iguales;
}
