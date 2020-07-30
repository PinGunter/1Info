//Funciones generales
#include <iostream>

using namespace std;

typedef short int color;

const int FILAS = 650;
const int COLUM = 650;
const color BLANCO = 255;
const color NEGRO = 0;


struct Imagen{
	string cadena_magica;
	int filas,columnas,max_color;
	color matriz[FILAS][COLUM];
};

//funcion de entrada
void Entrada(Imagen &imagen){
	cin >> imagen.cadena_magica;
	cin >> imagen.columnas >> imagen.filas;
	cin >> imagen.max_color;
	
	for (int i=0; i < imagen.filas; i++)
		for (int j=0; j < imagen.columnas; j++)
			cin >> imagen.matriz[i][j];
}

//funciones de salida
void Salida(Imagen imagen){
	cout << imagen.cadena_magica << endl;
	cout << imagen.columnas << " " << imagen.filas << endl;
	cout << imagen.max_color;
	for (int i=0; i < imagen.filas; i++){
		cout << endl;
		for (int j=0; j < imagen.columnas; j++)
			cout << imagen.matriz[i][j] << " ";
	}
}


int main(){
	Imagen imagen_entrada;
	Entrada(imagen_entrada);
	Salida (imagen_entrada);
}
	
	

