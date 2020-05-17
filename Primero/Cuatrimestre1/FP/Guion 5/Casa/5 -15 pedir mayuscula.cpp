/* Programa que convierte una letra mayuscula a minuscula

   ENTRADA --> cualquier caracter
   SALIDA --> minuscula correspondiente
11/10/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main(){
   //Declaro la constante de la distancia entra mayuscula y minuscula
   const int DISTANCIA_MAY_MIN = 'A' - 'a';

   //Declaracion de variables
   char caracter_usuario, minuscula;
   bool es_mayuscula;

   //Entrada de datos con filtro para ver si es mayuscula
   do{
      cout << "Introduce un caracter en mayuscula --> ";
      cin >> caracter_usuario;

      es_mayuscula = caracter_usuario >= 'A' && caracter_usuario <= 'Z';

   }while (!es_mayuscula);

   //Computos

   minuscula = caracter_usuario - DISTANCIA_MAY_MIN;
   //Salida de datos

   cout << "El caracter '" << caracter_usuario << "' en minuscula es --> " << minuscula << endl;

   //Sentencia para detener el programa
   system("pause");
   
}
