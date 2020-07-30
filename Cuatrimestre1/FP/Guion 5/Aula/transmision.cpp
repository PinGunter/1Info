/*
   Programa que descodifica el mensaje extraterrestre
   El mensaje esta descompuesto en 1 y 0 y siempre acaba con 5 ceros
   Cada cadena de unos indica los factores primos del numero

17/10/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main(){
   
   //Declaracion de variables
   
   int contador0 = 0, contador1 = 0, entrada, factor = 1;
   bool terminador = false;
   
   cout << "Introduce el mensaje extraterrestre (separado por espacios): ";
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
            if (contador1 > 0)
            	factor *= contador1;					//Multiplicamos los factores
            contador1 = 0;
            break;
         default:
            cout << "\nEntrada no valida\n";
            break;
      }
   
     
      
      if (contador0 == 5)
         terminador = true;
     
   } while (!terminador);
   
   cout << "\nEl mensaje es: " << factor << endl;
}
