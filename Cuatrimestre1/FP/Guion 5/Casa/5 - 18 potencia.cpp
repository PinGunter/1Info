/* Programa para calcular las funciones x^n y n!
   ENTRADA --> numero entero y real
   SALIDA --> funcion x^n y n!
11/10/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main(){

   //Declaracion de variables
   int n,factorial;
   double x, potencia;

   //Entrada de datos
   cout << "Introduce un numero entero, n --> "; 
   cin >> n;
   cout << "\nIntroduce un numero real, x --> ";
   cin >> x;

   /* COMPUTOS */

   //Potencia
   potencia = 1;
   //Bucle en el que vamos multiplicando por si misma la base n veces
   for (int i = 1; i <= n; i++){
      potencia = potencia * x;
   }

   //Factorial
   factorial = x;
   //Bucle en el que vamos multiplicando x por uno menor en cada iteracion
   for (int f = x - 1; f > 0; f--){
      factorial = factorial * f;
   }  

   /* SALIDA DE DATOS   */
   cout << "El resultado de " << x << "^" << n << " es --> " << potencia << endl;
   cout << "El resultado de " << x << "!" << " es --> " << factorial << endl;

   //Sentencia para detener el programa
   system("pause");
}
