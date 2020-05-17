#include <iostream>

using namespace std;

typedef short int color;

const int FILAS = 400;
const int COLUM = 400;
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

//funcion para rotar la imagen 90º a la derecha
//esto lo podemos conseguir con una matriz con el tamanio de filas y columnas intercambiadas
//a esta nueva matriz le asignamos los valores de la original, las filas en orden y las columnas desde tamanio_columna hasta 0
Imagen RotarDerecha(Imagen imagen){
	Imagen girada;
	girada.cadena_magica = imagen.cadena_magica;
	girada.filas = imagen.columnas;
	girada.columnas = imagen.filas;
	girada.max_color = imagen.max_color;
	
	for (int i=0; i < girada.filas; i++)
		for (int j=0; j < girada.columnas; j++){
			girada.matriz[i][j] = imagen.matriz[imagen.filas-j][i];
		}
	return girada;
}


int main(){
	Imagen entrada, girada;
	
	Entrada(entrada);
	
	girada = RotarDerecha(entrada);
	
	Salida(girada);
}
