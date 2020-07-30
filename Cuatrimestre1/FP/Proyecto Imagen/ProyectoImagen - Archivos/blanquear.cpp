//Primera parte de Proyecto Imagen
//Blanquear. Convertir la imagen a blanco

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

void Entrada(Imagen &imagen);
void Salida(Imagen imagen);
void Blanquear(Imagen &imagen);

int main(){
	//declaracion de variables
	Imagen imagen;
	
	//entrada de datos
	Entrada(imagen);
	//computos
	
	Blanquear(imagen);
	//salida de datos
	Salida (imagen);

}

//funcion para introducir los datos de entrada en la memoria
void Entrada(Imagen &imagen){
	cin >> imagen.cadena_magica;
	cin >> imagen.columnas >> imagen.filas;
	cin >> imagen.max_color;
	
	for (int i=0; i < imagen.filas; i++)
		for (int j=0; j < imagen.columnas; j++)
			cin >> imagen.matriz[i][j];
}


//funcion para sacar la imagen. Se realizan distintos cout con saltos de linea o espacios en blanco para el correcto formato de la imagen PGM
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

//funcion para blanquear la imagen
//recorremos cada pixel de la imagen y lo ponemos en el valor 255(blanco)
void Blanquear (Imagen &imagen){
	
	for (int i=0; i < imagen.filas; i++)
		for(int j=0; j < imagen.columnas; j++)
			imagen.matriz[i][j] = BLANCO;

}
