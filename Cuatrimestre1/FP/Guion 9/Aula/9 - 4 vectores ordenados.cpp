/* Programa que calcula un vector con las componentes de otros dos
14/11/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;
void FiltroTamanio(int &tamanio){
   do{
      cin >> tamanio;
      if (tamanio < 1 || tamanio > 50)
         cout << "\nTamanio invalido. Debe ser entre 0 y 50. Vuelve a introducir un tamanio:\n";
      }while (tamanio < 1 || tamanio > 50);
}

int main(){
   const int LONG = 100;
   //Declaracion de variables
   int vector1[LONG/2];
   int vector2[LONG/2];
   int resultado[LONG];
   int tamanio1 = 0, tamanio2 = 0, tamanio_resultado = 0;
   int contador1 = 0, contador2 = 0, contador_resultado = 0;
   
   //Entrada de datos
   cout << "Introduce el tamanio del primer vector (max. 50) --> ";
   FiltroTamanio(tamanio1);
   cout << "\nIntroduce las componentes del vector:\n";
   for (int i=0; i < tamanio1; i++)
      cin >> vector1[i];
      
   cout << "\nIntroduce el tamanio del segundo vector (max. 50) --> ";
   FiltroTamanio(tamanio2);
   cout << "\nIntroduce las componentes del vector:\n";
   for (int i=0; i < tamanio2; i++)
      cin >> vector2[i];
   
   //Computos
   //Iremos comparando uno a uno los elementos de cada vector. Los insertamos en el vector resultado de manera ordenada
   //Se inserta el valor menor y su contador aumenta, si son iguales aumentan los dos contadores
   while (contador1 < tamanio1 && contador2 < tamanio2){
      if (vector1[contador1] > vector2[contador2])
         resultado[contador_resultado++] = vector2[contador2++];
   
      else if (vector1[contador1] < vector2[contador2])
         resultado[contador_resultado++] = vector1[contador1++];
      
      else{
         resultado[contador_resultado++] = vector1[contador1++];
         resultado[contador_resultado++] = vector2[contador2++];
      }
   }
   
   //En caso de que tengan un numero distinto de elementos imprimimos los que quedan
   if (tamanio1 > tamanio2){
      while (contador1 <= tamanio1)
         resultado[contador_resultado++] = vector1[contador1++];
   }
   else if (tamanio2 > tamanio1){
      while (contador2 <= tamanio2)
         resultado[contador_resultado++] = vector2[contador2++];
   }
      
   tamanio_resultado = contador_resultado -1;            //Ponemos menos porque sino, en  resultado[tamanio_resultado] tendriamos un valor basura
   //Salida de datos
   cout << "\nEl vector resultante es:\n";
   for (int i=0; i < tamanio_resultado; i++)
      cout << resultado[i] << " ";
}
