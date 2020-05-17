/*
Programa para calcular que sucursal ha realizado mas ventas

   ENTRADA --> numero de sucursal, codigo de producto y ventas
   SALIDA --> sucursal con mas numero de ventas
12/10/2019
Salvador Romero Cortes
*/

#include <iostream>                 //Incluimos los recursos de E/S

using namespace std;

//Programa principal
int main(){

   //Declaracion de variables

   int sucursal, codigo, ventas;
   int total_ventas1 = 0 , total_ventas2 = 0, total_ventas3 = 0, max_ventas = 0, max_sucursal = 0;
   bool bucle_en_funcionamiento;

   //Computos
   do{
      cout << "Introduce separadadas por un espacio el numero de sucursal, el codigo de producto y el numero de ventas (sucursal: -1 para finalizar):\n";
      cin >> sucursal;

      //Queremos que el programa pare en cuanto se introduca -1
      if (sucursal == -1)
         break;

      cin >> codigo;
      cin >> ventas;
      
      bucle_en_funcionamiento = (sucursal == 1 || sucursal == 2 || sucursal == 3) && (codigo ==1 || codigo == 2 || codigo == 3) && ventas >= 0;
      
      //Vamos sumando las ventas totales de cada sucursal
      if (sucursal == 1){
         total_ventas1 += ventas;
      }
      else if (sucursal == 2){
         total_ventas2 += ventas;
      }
      else if (sucursal == 3){
         total_ventas3 += ventas;
      }

   } while (bucle_en_funcionamiento);

   //Ahora comprobamos cual tiene mas ventas
   
   if (total_ventas1 >= total_ventas2 && total_ventas1 >= total_ventas3){
      max_ventas = total_ventas1;
      max_sucursal = 1;
   }
   else if (total_ventas2 >= total_ventas1 && total_ventas2 >= total_ventas3){
      max_ventas = total_ventas2;
      max_sucursal = 2;
   }
   else if ( total_ventas3 >= total_ventas1 && total_ventas3 >= total_ventas2){
      max_ventas = total_ventas3;
      max_sucursal = 3;
   }

   /* SALIDA   */
   
   cout << "\nSUCURSAL: " << max_sucursal << "\nVENTAS: " << max_ventas << endl;

   //Sentencia para detener el programa
   system("pause");
}
