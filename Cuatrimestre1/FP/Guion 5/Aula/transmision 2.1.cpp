/*
   Programa que descodifica el mensaje extraterrestre
   El mensaje esta descompuesto en 1 y 0 y siempre acaba con 5 ceros
   Cada cadena de unos indica los factores primos del numero
   Parte 1 --> imprime los factores cuyo producto es el numero

18/10/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main(){
   
   //Declaracion de variables
   
   int contador0 = 0, contador1 = 0, entrada;
   bool terminador = false;
   int stop = 0 ;			//numero que impriremos cuando acabe el bucle para indicar el fin de los factores para el siguiente programa
   
   cerr << "Introduce el mensaje extraterrestre (separado por espacios): ";
   do{
      cin >> entrada;

      //Aumentamos los contadores con cada entrada

      switch(entrada){
         case 1:
            contador1 ++;
            contador0 = 0;
            break;
         case 0:
            contador0 ++;
            if (contador1 > 0){
            	cerr << "\t";
      	      cout << contador1 << endl;					//Imprimos los contadores para que el segundo programa los recoja
					}
					
            contador1 = 0;
            break;
         default:
            cerr << "\nEntrada no valida\n";
            break;
      }
   
     
      
      if (contador0 == 5)
         terminador = true;
     
   } while (!terminador);
   cout << stop;
}
