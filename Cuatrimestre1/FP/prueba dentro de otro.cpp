#include <iostream>
#include <cstring>
using namespace std;

struct Vector {
	int limite;
	char array[100];
};


bool VectorDentroDeOtro(Vector dentro, Vector otro){
	bool va_coincidiendo;
	bool encontrado = false;
	for (int i=0; i <= otro.limite - dentro.limite && !encontrado; i++){
		va_coincidiendo = true;
		for (int j = 0; j < dentro.limite; j++)
			va_coincidiendo = dentro.array[i+j] == otro.array[j];

		if (va_coincidiendo){
			encontrado = true;
		}
	}
	return encontrado;
}

int main(){
	Vector dentro, otro;
	cout << "Introduce el vector1: ";
	cin.getline(dentro.array,100);
	dentro.limite = strlen(dentro.array);
	cout << "Introduce el vector2: ";
	cin.getline(otro.array,100);
	otro.limite = strlen(otro.array);
	cout << endl << endl << VectorDentroDeOtro(dentro,otro);
}
