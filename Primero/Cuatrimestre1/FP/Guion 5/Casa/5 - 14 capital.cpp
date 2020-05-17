/*Programa que calcule el inter�s en un a�o

   ACTUALIZACION: Calcular cuantos años han de pasar hasta que el capital final
   sea al menos el doble del inicial.

11/10/2019
Salvador Romero Cortes
*/

#include <iostream>
using namespace std;

int main(){
	double capital, interes, capital_final; //Declaramos las variables que vamos a usar
	int anio = 0;
   //Pedimos el capital inicial
	cout << "Introduce el capital inicial: ";
	cin >> capital;
	//Ahora pedimos el interes
	cout << "Introduce el interes: ";
	cin >> interes;

//Computos
   capital_final = capital;
   do{
      capital_final = capital_final + capital_final*(interes/100);
      anio++;

   } while (!(capital_final>=2*capital));

//Salida de datos

cout << "Se han necesitado " << anio << " anios para que el capital final (" << capital_final <<
 ") sea igual o superior al doble del capital inicial (" << capital << ").\n";

//Sentencia para detener el programa
system("pause");
}
