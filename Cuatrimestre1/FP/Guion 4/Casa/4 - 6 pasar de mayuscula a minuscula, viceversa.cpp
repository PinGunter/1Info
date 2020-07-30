/*
	Programa que lee un caracter y lo convierte a minuscula si es mayuscula y viceversa. En caso de que sea un caracter no alfabetico no se convierte
	ENTRADA --> caracter en mayuscula, minuscula o no alfabetico
	SALIDA --> conversion a minuscula o mayuscula segun la entrada
	
05/10/2019
Salvador Romero Cortes	
*/

#include <iostream>					//Incluimos los recursos de E/S

using namespace std;

//Programa principal

int main(){
	
	//Declaro la constante de la distancia entre mayuscula y minuscula
	
	const int DISTANCIA_MAY_MIN = 'A' - 'a';
	
	//Declaramos las variables
	
	char letra_original, letra_convertida;
	bool es_mayuscula, es_minuscula;
	
	//Entrada de datos
	
	cout << "Introduce un caracter --> ";
	cin >> letra_original;
	
	es_mayuscula = (letra_original >= 'A') && (letra_original <= 'Z');
	es_minuscula = (letra_original >= 'a') && (letra_original <= 'z');
	
	
	//Computos
	
	if (es_mayuscula)
		letra_convertida = letra_original - DISTANCIA_MAY_MIN;
	
	else if (es_minuscula)
		letra_convertida = letra_original + DISTANCIA_MAY_MIN;
	
	else
		letra_convertida = letra_original;
		
	//Salida de datos
	
	cout << "\nEl caracter " << letra_original << " convertido es " << letra_convertida << endl;
	
	//Sentencia para detener el programa 
	
	system("pause");
	
}
