/*
Mostrar como se comunican los distintos bloques de un programa a traves de variables
que indican lo que ha sucedido en el bloque anterior y destacar la importancia de incluir
un bloque else, para garantizar que siempre se ejecuta el codigo adecuado, en todas las
situaciones posibles

04/10/2019
Salvador Romero Cortes
*/

//Incluimos los recursos necesarios para el programa. De E/S y para trabajar con strings
#include <iostream>
#include <string>

using namespace std;

//Programa principal

int main(){
	
	const int DISTANCIA_MAY_MIN = 'a' - 'A';
	
	char letra_convertida, letra_original;
	
	cout << "\nIntroduzca una letra --> ";
	cin >> letra_original;
	
	// OPCION A

	/*
	if ((letra_original >= ’A’) && (letra_original <= ’Z’)){
		letra_convertida = letra_original + DISTANCIA_MAY_MIN;
		cout << letra_convertida;
	}
	else{
		cout << letra_original << " no es una may´uscula";
	}
	*/

	//OPCION B
		
	/*	
	string tipo_letra;

	if ((letra_original >= 'A') && (letra_original <= 'Z'))
		tipo_letra = "es may´uscula";
		
	if (tipo_letra == "es may´uscula")
		letra_convertida = letra_original + DISTANCIA_MAY_MIN;
	else
		letra_convertida = letra_original;
	cout << "\nEl car´acter " << letra_original <<
		" una vez convertido es: " << letra_convertida;
	*/
	
	/*
	Si se opta por esta alternativa, el suspenso esta garantizado. ¿Por que?´
	Porque la inicializacion de la variable se hace en la estructura condicional, por lo tanto si no se cumple "tipo_letra" no tiene valor propio.
	Y esto puede dar lugar a errores logicos.
 
	*/
	
	//OPCION C
	
	/*	
	
	bool es_mayuscula;
	
	if ((letra_original >= 'A') && (letra_original <= 'Z'))
		es_mayuscula = true;
		
	if (es_mayuscula)
		letra_convertida = letra_original + DISTANCIA_MAY_MIN;
		
	cout << "\nEl car´acter " << letra_original <<
		" una vez convertido es: " << letra_convertida;
	*/
}
