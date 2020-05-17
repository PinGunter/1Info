//Programa para ver si una matriz es un cuadrado magico
//Un cuadrado magico es una matriz cuadrada en la que todas las filas, columnas y diagonales suman lo mismo
// 24/11/2019
//Salvador Romero Cortes
#include <iostream>

using namespace std;

const int LONG = 10;

class CuadradoMagico{

	private:
		int suma_hor = 0, suma_ver = 0, suma_diag1 = 0, suma_diag2 = 0;
		
		//metodo para comprobar si la matriz introducida es impar
		bool EsImpar(int orden){
			bool valido = true;
			if (orden % 2 ==0)
				valido = false;
			
			return valido;
		}
		
	public:
		int orden;
		int matriz[LONG][LONG];
		
		void IntroducirDatos(int matriz[][LONG], int &orden){
			//orden de la matriz
				do{
				cout << "\nIntroduce el orden de la matriz(tiene que ser impar): ";
				cin >> orden;
			}while (!EsImpar(orden));
			
			//elementos de la matriz
			for (int i=0; i < orden; i++){
				cout << "\nFila " << i+1 << " --> ";
				for (int j=0; j < orden; j++)
					cin >> matriz[i][j];
			}
		}
		
		bool EsCuadradoMagico(int matriz[][LONG], int &orden){
			//para que sea un cuadrado magico, las sumas de diagonales, filas y columnas debe ser igual
			//para simplifica los calculos podemos sumar todos los elementos de cada fila y luego dividir entre el orden. Lo mismo para las columnas
			
			//sumamos filas
			for(int i=0; i < orden; i++){
				for (int j=0; j < orden; j++)
					suma_hor += matriz[i][j];
			}
			suma_hor /= orden;
			
			//sumamos columnas
			for(int i=0; i < orden; i++)
				for (int j=0; j <orden; j++)
					suma_ver += matriz[j][i];
			
			suma_ver /= orden;
			
			// hay dos diagonales principales
			// la primera se da cuando la posicion de la columna y fila es la misma
			// la segunda se da cuando se asciende y deciende del orden al 0 en las filas y columnas. 
			// del tipo matriz[0][orden], matriz [1][orden-1]...
			
			for (int i=0; i < orden; i++)
				suma_diag1 += matriz[i][i];
				
			for (int i=0; i < orden; i++)
				suma_diag2 += matriz[i][orden-i-1];
			
			//comprobamos si es un cuadrado magico
			if (suma_hor == suma_ver && suma_hor == suma_diag1 && suma_hor == suma_diag2)
				return true;
			else
				return false;
		}	
};



int main(){
	//declaracion de variables
	CuadradoMagico cuadrado;
	bool cuadrado_magico;
	
	//entrada de datos
	cuadrado.IntroducirDatos(cuadrado.matriz, cuadrado.orden);
	
	//computos
	cuadrado_magico = cuadrado.EsCuadradoMagico(cuadrado.matriz, cuadrado.orden);
	
	//salida de datos
	if (cuadrado_magico)
		cout << "\nLa matriz introducida es un cuadrado magico";
	else
		cout << "\nLa matriz introducida no es un cuadrado magico";
}

