//Salvador Romero Cortes
//Cifra

#include <iostream>

using namespace std;

int main(){

   //Declaracion de variables
   int a, b, k, izquierda, contador = 0, divisor = 1, contadorK = 0;
   
   //Entrada de datos
   //Bucle do while para comprobar que las entradas son correctas
   do{
      cout << "Introduce un numero entero, a: ";
      cin >> a;
      
      cout << "\nIntroduce un numero entero, b: ";
      cin >> b;
      
      if (a > b)
         cout << "\na debe ser menor a b!\n";
         
   } while (a > b);
   
   do{
      cout << "\nIntroduce un numero entero entre 0 y 9, k: ";
      cin >> k;
      
      if (k > 9 || k < 0)
         cout << "\nk deber ser un numero entre 0 y 9\n";
         
   }while (k > 9 || k < 0);
   
   //Computos
   //Vamos a hacer un bucle para ir separando los digitos de los numeros de [a,b], si ese numero es k lo contamos
   
   while (izquierda > 0 || contador == 0){    //Ponemos la condicion asi para que entre al bucle ya que sino como no hemos inicializado "izquierda" no entraria.
      for (int i = a; i <= b; i++){
         izquierda = i / divisor;
         if (izquierda % 10 == k)
            contadorK ++;
      }
      divisor *= 10;
      contador++;
   }
   
   //Salida de datos
   
   cout << k << " aparece " << contadorK << " veces." << endl;
   
   //Sentencia para detener el programa
   system("pause");
}
