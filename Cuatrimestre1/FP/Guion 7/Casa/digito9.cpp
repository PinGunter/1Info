/*
	Programa para calcular el numero de veces que aparece una cifra en un intervalo
	ENTRADA --> minimo y maximo del intervalo
	SALIDA --> numero de repeticiones de la cifra en el intervalo
26/10/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main(){

   //Declaracion de variables
   int min, max, cifra, izquierda, contador = 0, divisor = 1, contador_de_cifra = 0;
   
   //Entrada de datos
   //Bucle do while para comprobar que las entradas son correctas
   do{
      cout << "Introduce el valor minimo del intervalo: ";
      cin >> min;
      
      cout << "\nIntroduce el valor maximo del intervalo: ";
      cin >> max;
      
      if (min > max)
         cout << "\nEl minimo debe ser menor al maximo!\n";
         
   } while (min > max);
   
   do{
      cout << "\nIntroduce un numero entero entre 0 y 9: ";
      cin >> cifra;
      
      if (cifra > 9 || cifra < 0)
         cout << "\nLa cifra deber ser un numero entre 0 y 9\n";
         
   }while (cifra > 9 || cifra < 0);
   
   //Computos
   //Vamos a hacer un bucle para ir separando los digitos de los numeros de [a,b], si ese numero es k lo contamos
   
   while (izquierda > 0 || contador == 0){    //Ponemos la condicion asi para que entre al bucle ya que sino como no hemos inicializado "izquierda" no entraria.
      for (int i = min; i <= max; i++){
         izquierda = i / divisor;
         if (izquierda % 10 == cifra)
            contador_de_cifra ++;
      }
      divisor *= 10;
      contador++;
   }
   
   //Salida de datos
   
   cout << cifra << " aparece " << contador_de_cifra << " veces." << endl;
   
   cout << 1%10;
   //Sentencia para detener el programa
   system("pause");
}
