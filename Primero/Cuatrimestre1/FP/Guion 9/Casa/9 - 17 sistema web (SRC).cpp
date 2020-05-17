/* Programa para sugerir un nombre de usuario en funcion del nombre y los apellidos

12/11/2019
Salvador Romero Cortes
*/

#include <iostream>
#include <cstring>

using namespace std;

int main(){
	//Declaracion de variables y constantes
	const int LONG = 1000;
	char nombre_entrada [LONG];
	string login;
	int tamanio, contador = 0;

	//Entrada de datos
	cout << "Introduce tu nombre y apellidos:\n";
	cin.getline(nombre_entrada,LONG);

	cout << "Introduce un numero entero --> ";
	cin >> tamanio;
	
	//Computos
	//La primera palabra la hacemos fuera de bucle
	for (int i=0; i <tamanio; i++){
		login+= nombre_entrada[contador];
		contador++;
	}
	//Cuando se encuentre un espacio en blanco aniade los caracteres tamanio veces
	while (contador < strlen(nombre_entrada)){
		if (nombre_entrada[contador] == ' '){
			for (int i=0; i < tamanio; i++){
				contador++;
				if (nombre_entrada[contador] != ' ')
					login += nombre_entrada[contador];

			}
		} else
			contador++;
	}

	//Ahora pasamos todos a minusculas
	for(int i=0; i < contador; i++)
		if (login[i] <= 'Z' && login[i] >= 'A')
			login[i] = login[i] + ('a'-'A');
	
	
			
	cout <<"\nEl nombre de usuario sugerido es: " << login;
}
