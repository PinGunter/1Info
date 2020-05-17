/* Programa qe dada una cadena de caracteres y dos posiciones dentro de la cadena,
x e y, devuelva otra cadena con los caracteres comprendidos entre las componentes x e y 

07/11/2019
Salvador Romero Cortes
*/

#include <iostream>
#include <cstring>

using namespace std;

int main(){
   //Declaracion de variables
   char cadena[101];
   int x, y;
   
   //Entrada de datos
   cout << "Introduce la cadena de caracteres (maximo 100 caracteres):\n";
   cin.getline(cadena,100);
   cadena[101]= '\0';
     
   cout << "Introduce la posicion inicial --> ";
   cin >> x;
   cout << "Introduce la posicion final --> ";
   cin >> y;

   //Salida de datos
   for (int i = x-1; i < y; i++)
      cout << cadena[i];
   
   cout << "\n";
   system("pause");

}

