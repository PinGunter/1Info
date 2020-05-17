/* Programa para eliminar mayusculas de un vector. 2 parte.

	ENTRADA  --> vector con mayusculas y minusculas
	SALIDA --> vector con minusculas unicamente

05/11/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main(){
	//Declaracion de variables
	char vector_entrada[5];
	int posicion_lectura = 0, posicion_escritura = 0;
	char vector_minusculas[5] = {'\0', '\0', '\0', '\0', '\0'};
	bool es_mayuscula;
	
	//Entrada de datos
	cout << "Introduce el vector de caracteres de 5 elementos. Se eliminaran las mayusculas:\n";
	for (int i=0; i < 5; i++){
		cin >> vector_entrada[i];
	}
	
	//Computo
	//El contador de lectura avanza siempre, el de escritura solo cuando se encuentra una minuscula
	
	while (posicion_lectura < 5){
		es_mayuscula = vector_entrada[posicion_lectura] >= 'A' && vector_entrada[posicion_lectura] <= 'Z';
		
		if (!es_mayuscula){
			posicion_escritura++;
			vector_minusculas[posicion_escritura] = vector_entrada[posicion_lectura];
		}
		
		posicion_lectura++;
	}
	
	//Salida de datos
	cout << "\nEl vector sin las letras mayusculas es:\n{";
	for (int j = 0; j < 5; j++){
		if (vector_minusculas[j] != '\0'){
			cout << vector_minusculas[j];
			
			if (j < 4)
				cout << ", ";
		}
	}
	cout << "}\n";
	
	system("pause");
	
}
