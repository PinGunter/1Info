/* Programa para saber si un numero entero es desgarrable
   ENTRADA --> numero entero
   SALIDA --> si es desgarrable o no
11/10/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main(){

   //Declaracion de variables
   int entero, izquierda, derecha;
   bool es_desgarrable = 0;
   int separador = 10;
   //Entrada de datos

   cout << "Introduce un numero entero --> ";
   cin >> entero;

   //Computo
   do {
      izquierda = entero / separador;
      derecha = entero % separador;

      es_desgarrable = ((izquierda + derecha) * (izquierda + derecha)) == entero;
      separador *= 10;
      
   }while (!es_desgarrable && izquierda!= 0);


   //Salida de datos
   if (es_desgarrable)
      cout << "\nEl numero " << entero << " es desgarrable.\n";
   else
      cout <<"\nEl numero " << entero << " no es desgarrable.\n";

   //Sentencia para detener el programa
   system("pause");    

}
