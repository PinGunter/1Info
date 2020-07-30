#include <iostream>

using namespace std;

const int TAMANIO = 100;
/**
 * @brief funcion que realiza el producto de dos matrices A y B
 * @param A la primera matriz
 * @param B la segunda matriz
 * @param C la matriz resultante del producto A*B
 * @param m numero de filas de A
 * @param n numero de columnas de A == numero de filas de B
 * @param p numero de columnas de B
*/

void ProductoMatriz(int A[][TAMANIO], int B[][TAMANIO], int C[][TAMANIO], int m, int n, int p);

int main(){
	int matrizA[TAMANIO][TAMANIO], matrizB[TAMANIO][TAMANIO], matrizC[TAMANIO][TAMANIO];
	int filasA, filasB, colsA, colsB, filasC, colsC;
	
	cout << "MATRIZ A\nFilas: ";
	cin >> filasA;
	cout << "Columnas: ";
	cin >> colsA;
	
	for (int i=0; i < filasA; i++)
		for (int j=0; j < colsA; j++)
			cin >> matrizA[i][j];
			
				
	cout << "\n\nMATRIZ B\nFilas: ";
	cin >> filasB;
	cout << "Columnas: ";
	cin >> colsB;
	
	for (int i=0; i < filasB; i++)
		for (int j=0; j < colsB; j++)
			cin >> matrizB[i][j];
			
	
	filasC = filasA; 
	colsC = colsB;
	
	if (colsA == filasB){
		ProductoMatriz(matrizA,matrizB,matrizC, filasA, colsA, colsB);
		cout << "\nMATRIZ RESULTANTE:\n";
		for (int i=0; i < filasC; i++){
			for (int j=0;j < colsC; j++){
				cout << matrizC[i][j] << " ";
			}
			cout << endl;	
		}
	}
	else
		cout << "\n*Para poder multiplicarse A deber tener el mismo numero de columnas que B de filas*";	

}

void ProductoMatriz(int A[][TAMANIO], int B[][TAMANIO], int C[][TAMANIO], int m, int n, int p){
	int filas, columnas;
	filas = m;
	columnas = p;
	
	for (int i=0; i < m; i ++){
		for (int j = 0; j < p; j++){
			C[i][j] = 0;
			for (int k=0; k < n; k++){
				C[i][j] += A[i][k]*B[k][j];
			} 
		}
	}
}

