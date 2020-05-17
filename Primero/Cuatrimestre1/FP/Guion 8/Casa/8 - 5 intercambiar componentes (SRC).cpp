/* Programa para intercambiar dos componentes de un vector

   ENTRADA --> posiciones a intercambiar
   SALIDA --> vector cambiado
02/11/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main(){
   //Declaracion de variables
   int vector [4] = {1,2,5,3};
   int variable_intercambio_aux, intercambio1, intercambio2;

   //Entrada de datos
   do{
      cout << "Introduce las posiciones que quieres cambiar del vector  {";
      for (int i = 0; i <= 3; i++){
      	cout << vector[i];
      	if (i < 3)
      		cout << ", ";
   	}
      cout << "} (separadas por espacios)\n";
      
      cin >> intercambio1 >> intercambio2;

      //Como las posiciones empiezan desde el 0 le restamos uno
      intercambio1 -= 1;
      intercambio2 -= 1;

      if (intercambio1 > 3 || intercambio2 > 3 || intercambio1 < 0 || intercambio2 < 0)
         cout << "\nEntrada no valida. Debe ser un valor entre 1 y 4\n";
   
   }while(intercambio1 > 3 || intercambio2 > 3 || intercambio1 < 0 || intercambio2 < 0);

   //Computos
   variable_intercambio_aux = vector[intercambio1];
   vector[intercambio1] = vector[intercambio2];
   vector[intercambio2] = variable_intercambio_aux;

   //Salida de datos
   cout << "Tras el intercambio el vector queda como: {";
	for (int i = 0; i <= 3; i++){
      cout << vector[i];
      if (i < 3)
      	cout << ", ";
   }
   cout << "}\n";
	system("pause");

}
