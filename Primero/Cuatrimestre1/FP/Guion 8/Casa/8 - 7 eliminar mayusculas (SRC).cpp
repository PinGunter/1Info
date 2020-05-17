/* Programa para eliminar las mayusculas de un vector

05/11/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main(){
	//Declaracion de variables
	char vector [5] = {'\0','\0','\0','\0','\0'};
	char vector_sin_mayuscula [5] = {'\0','\0','\0','\0','\0'};
	int fin = 'Z';
	//Entrada de datos
	cout << "Introduce los caracteres del vector de tamanio 5. Se eliminaran las mayusculas\n";
	
	for (int i = 0; i < 5; i++){
		cin >> vector[i];
	}
	
	//Computos
	for (int i = 0; i < 5; i++)
		vector_sin_mayuscula [i] = vector[i];
		
	for (int j=0; j<5; j++){
		if (vector_sin_mayuscula[j] >= 'A' && vector_sin_mayuscula[j] <= 'Z'){
			int tope = fin -1;
			
			for (int i=vector_sin_mayuscula[j]; i<tope; i++){
				vector_sin_mayuscula[j] = vector_sin_mayuscula[i+1];
			}
		
			fin --;
		}
	}
	

	//Salida de datos
	cout << "\nEl vector sin mayusculas es:\n";
	for (int k=0;k<5;k++)
		if (vector_sin_mayuscula[k] != '~')
			cout << vector_sin_mayuscula[k] << " ";

}
