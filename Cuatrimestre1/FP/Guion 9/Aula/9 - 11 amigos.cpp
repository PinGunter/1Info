/* Programa para calcular todos los numeros amigos en un intervalo

14/11/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

void Amigos(int a, int b);

int main(){
   //Declaracion de variables
   int numero1, numero2;
   
   //Entrada de datos
   cout << "Introduce el intervalo en el que quieres calcular los numeros amigos.\nPrimero: ";
   cin >> numero1;
   cout << "\nFinal: ";
   cin >> numero2;
   
   //Computos y salida de datos
   for (int i=numero1; i < numero2; i++)
      for (int j=i+1 ; j < numero2; j++)
         Amigos(i,j);
}

/* Funcion para calcular los numeros amigos 
Esto es que la suma de los divisores de uno sea igual al otro y viceversa*/

void Amigos(int a, int b){
   int suma_numero1 = 0;
   int suma_numero2 = 0;
   //obtenemos la suma de los divisores de cada numero
   for(int i=1; i < a; i++)
      if (a % i == 0)
         suma_numero1 += i;
         
   for (int i=1; i < b; i++)
      if (b % i == 0)
         suma_numero2 += i;
         
   //Comprobamos si son amigos
   if (suma_numero1 == b && suma_numero2 == a)
      cout << a << " y " << b << " son amigos\n";
}
