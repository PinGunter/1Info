// PROYECTO IMAGEN: 

#include <iostream>

using namespace std;

typedef short int color;

const int FILAS = 650;
const int COLUM = 650;
const color BLANCO = 255;
const color NEGRO = 0;

struct Imagen{
	string cadena_magica;
	int filas, columnas, max_color;
	color matriz[FILAS][COLUM];
};

void Entrada(Imagen&imagen){
	
	cin >> imagen.cadena_magica;
	cin >> imagen.columnas;
	cin >> imagen.filas;
	cin >> imagen.max_color;
	
	for(int i = 0; i < imagen.filas; i++){
		for(int j = 0; j < imagen.columnas; j++)
			cin >> imagen.matriz[i][j];
	}
};

void Salida(Imagen imagen){
	
	cout << imagen.cadena_magica << endl;
	cout << imagen.columnas << " " ;
	cout << imagen.filas << endl;
	cout << imagen.max_color;
	
	for(int i = 0; i < imagen.filas; i++){
		cout << endl;
		
		for(int j = 0; j < imagen.columnas; j++)
			cout << imagen.matriz[i][j] << " ";	
	}	
};

void Negativo(Imagen&imagen){
	
	for(int i = 0; i < imagen.filas; i++){
		for(int j = 0; j < imagen.columnas; j++){
			
			if(imagen.matriz[i][j] == NEGRO)
				imagen.matriz[i][j] = BLANCO;	
			else
				imagen.matriz[i][j] = BLANCO - imagen.matriz[i][j];
		}
	}
};

int main(){
	
	Imagen imagen;
	Entrada(imagen);
	Negativo(imagen);	
	Salida(imagen);
	
}
