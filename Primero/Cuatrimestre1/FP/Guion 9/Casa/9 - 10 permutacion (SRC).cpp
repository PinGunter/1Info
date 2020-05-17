/* Programa para representar permutaciones y operar

10/11/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

struct Permutacion{
	int vector[100];
	int longitud;
};

int main(){
	//Declaracion de variables
	Permutacion entrada;
	bool correcto;
	int potencia[100];
	int auxiliar[100];
	int exponente;
	
	//Entrada de datos
	cout << "Introduce la longitud de la permutacion (maximo 100): --> ";
	cin >> entrada.longitud;
	
	cout << "\nIntroduce los elementos de la permutacion:\n";
	
	//Filtro para que la entrada sea correcto
	do{
		for (int i = 0; i < entrada.longitud; i++)
			cin >> entrada.vector[i];	
		
		correcto = true;
		//comprobamos si hay algun elemento repetido
		for (int i=0; i < entrada.longitud; i++){
			for (int j = i+1; j < entrada.longitud; j++)
				if (entrada.vector[i] == entrada.vector[j])
					correcto = false;
		}
		//comprobamos si estan todos los numeros 
		//si no estan repetidos, para que sea valido tendra que estar en [1,entrada.longitud]
		
		for (int i=0;i < entrada.longitud;i++)
			if (!(entrada.vector[i] <= entrada.longitud && entrada.vector[i] >= 1))
				correcto = false;		
				
		if (!correcto)
			cout << "\nEntrada no valida. Vuelve a introducir los elementos de la permutacion:\n";
			
	} while (!correcto);
	
	cout << "\nIntroduce el exponente a elevar la permutacion --> ";
	cin >> exponente;
	
	// Computos -- Potencia enesima de la permutacion
	//permutamos cada posicion el numero de veces de la potencia
	//Creamos un vector auxiliar y copiamos en el la entrada
	for (int i=0; i < entrada.longitud; i++){
		auxiliar[i] = entrada.vector[i];
	}
	
	for (int i=1; i < exponente; i++){
		for (int j=0; j<entrada.longitud; j++){
			potencia[j] = auxiliar[entrada.vector[j]-1];						//Con esto volvemos a la permutacion sin cambios
		}
		for (int k=0;k<entrada.longitud; k++)
			auxiliar[k] = potencia[k];
	}
	//Salida de datos
	cout << "\nLa porencia de la permutacion es: ";
	// Si el exponente es 1 que imprima la misma permutacion , en caso contrario la potencia
	if (exponente==1)
		for (int i=0;i<entrada.longitud;i++)
			cout << entrada.vector[i] << " ";
	else
		for (int i=0;i<entrada.longitud;i++)
			cout << potencia[i] << " ";
	
}
