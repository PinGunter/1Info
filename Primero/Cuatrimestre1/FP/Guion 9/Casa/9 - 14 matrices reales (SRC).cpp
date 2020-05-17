/* Programa que devuelve un vector con la suma de los elementos de las columnas y de las filas de una matriz

11/11/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main(){
	const int FILAS = 100;
	const int COLUM = 100;
	
	//Declaracion de variables
	int matriz[FILAS][COLUM];
	int columnas[COLUM] = {0};
	int filas[FILAS] = {0};
	int filas_utiles, colum_utiles;
	
	//Entrada de datos
	cout << "Introduce el numero de filas de la matriz (maximo 100) --> ";
	do{
		cin >> filas_utiles;
		
		if (filas_utiles > FILAS || filas_utiles < 0)
			cout << "\nEntrada no valida. Escribe un numero entre 0 y 100 --> ";
		
	} while (filas_utiles > FILAS && filas_utiles < 0);
	
	cout << "Introduce el numero de columnas de la matriz (maximo 100) --> ";
	do{
		cin >> colum_utiles;
		
		if (colum_utiles < 0 || colum_utiles > COLUM)
			cout << "\nEntrada no valida. Escribe un numero entre 0 y 100 --> ";
		
	} while (colum_utiles > COLUM && filas_utiles < 0);
	
	
	cout << "Introduce los valores de la fila separados por espacios:\n";
	for(int i=0; i < filas_utiles; i++){
		cout << "Fila " << i+1 << ": ";
		for(int j=0; j < colum_utiles; j++){
			cin >> matriz[i][j];
		}
	}
		
	//Computos
	//Sumamos los elementos de cada fila
	for(int i=0; i < filas_utiles; i++){
		for(int j=0; j < colum_utiles; j++){
			filas[i] += matriz[i][j];
		}
	}
	
	//Sumamos los elementos de cada columna
	for(int i=0; i < colum_utiles; i++){
		for(int j=0; j < filas_utiles; j++){
			columnas[i] += matriz[j][i];
		}
	}
	
	//Salida de datos
	cout << "\nEl vector con la suma de los elementos de las filas queda como:\n";
	for(int i=0; i < filas_utiles; i++)
		cout << filas[i] << " ";
	
	cout << "\nEl vector con la suma de los elementos de las columnas queda como:\n";
	for(int i=0; i < colum_utiles; i++)
		cout << columnas[i] << " ";
	
	cout << endl;
}
