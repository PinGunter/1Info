#include <iostream>

using namespace std;

int main(){
	int beta[100][100];
	bool salida[100][100];
	bool columns[100];
	int posx,posy;
	int filas, columnas, suma, minimo = 100;
	cout << "Introduce las dimensiones de la matriz: ";
	cin >> filas >> columnas;

	cout << "Introduce los elementos de la matriz:\n";
	for (int i=0; i < filas; i++)
		for (int j=0; j < columnas; j++)
			cin >> beta[i][j];

	for (int i=0; i < columnas; i++)
		columns[i] = true;
		
	for (int i=0; i < filas; i++)
		for (int j=0; j < columnas; j++)
			salida[i][j] = 0;

	for (int i=0; i < filas; i++){
		minimo = 100;
		for (int j=0; j < columnas; j++){
			if (columns[j]){
				if (beta[i][j] <= minimo){
					minimo = beta[i][j];
					posx = i;
					posy = j;
				}
			}
		}
		columns[posy] = false;
		salida[posx][posy] = true;
	}

	for (int i=0; i < filas; i++)
		for (int j=0; j < columnas;j++)
			if (salida[i][j])
				suma += beta[i][j];


	cout << "La matriz X queda como:\n";
	for (int i=0; i < filas; i++){
		for (int j=0; j < columnas;j++)
			cout << salida[i][j] << " ";
		cout << endl;
	}
	cout << "El precio es: " << suma << endl;
}
