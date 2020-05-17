/* Programa que calcula las veces que aparece un segundo vector en el primero 

02/11/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main(){
   //Declaracion de variables
   int vector1 [9];
   int vector2 [3];
   int posicion[9] = {0,0,0,0,0,0,0,0,0}; 					
   int contador = 0, contador_posicion = 0, contador_aux = 0;

   //Entrada de datos
   cout << "Introduce los valores del primer vector (9 elementos separados por espacios)\n";
	for (int i=0; i < 9; i++){
		cin >> vector1[i];	
	}
	
	cout << "Introduce los valores del segundo vector (3 elementos separados por espacios)\n";
	for (int j=0; j < 3; j++){
		cin >> vector2[j];	
	}
	
	cout << "Vector 1: ";
	for (int i = 0; i < 9; i++){
		cout << vector1[i];
		if (i < 8 )
			cout << ", ";
	}
	
	cout << "\nVector 2: ";
	for (int j = 0; j < 3; j++){
		cout << vector2[j];
		if (j < 2 )
			cout << ", ";
	}
	
	//Computos
	//Si 3 numeros consecutivos son iguales a las componentes del vector2, esta contenido
	int i = 0;
	while (i < 9){
		if (vector1[i] == vector2[0] && vector1[i+1] == vector2[1] && vector1[i+2] == vector2[2]){
			contador ++;
			if (contador_posicion == 0){
				posicion [contador_aux] = i + 1;
				contador_aux++;
			}
			contador_posicion++;
		}
		else{
			contador_posicion = 0;
		}
		
	i++;
		
	}
	contador_aux = 0;
	//Salida
	
	cout << "\nEl vector 2 aparece " << contador << " veces en el vector 1\nEn las posiciones: ";
	
	//No queremos que imprima las posiciones repetidas, solo una vez
	for (int j = 0; j < 9; j++){
		if (posicion[j] != 0)
			cout << posicion[j] << " ";
	}
		
	cout << endl;		
	system("pause");
}
	
	
	


