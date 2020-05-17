//Aumentar constraste

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
void Contraste(Imagen &imagen);

//funcion principal
int main(){
   //declaracion de variables
   Imagen imagen;

   //entrada de datos
   Entrada(imagen);

   //computos
   Contraste(imagen);

   //salida de datos
   Salida(imagen);
}

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

//funcion para aumentar el contraste de las imagenes
//en caso de que el color sea <125 lo ponemos negro
//en caso de que sea >= 125 lo ponemos blanco
//recorremos la matriz y aplicamos las condiciones
void Contraste(Imagen &imagen){
   for (int i=0; i < imagen.filas; i++)
      for (int j=0; j <imagen.columnas; j++){
         if (imagen.matriz[i][j] < 125)
            imagen.matriz[i][j] = NEGRO;
         else
            imagen.matriz[i][j] = BLANCO;
      }
}

