// Salvador Romero Cortes
// Amigos

#include <iostream>

using namespace std;

int main (){
   
   //Declaracion de variables
   
   int entero1, entero2, suma1 = 0, suma2 = 0;
   bool son_amigos;
   
   //Entrada de datos
   
   //Utilizamos un do while para filtrar la entrada
   do{
      cout << "Introduce un numero entero positivo: ";
      cin >> entero1;
      
      if (entero1 <= 0)
         cout << "\n¡Entrada incorrecta!\n";
   
   } while (entero1 <= 0);
   
   //Usamos otro filtro para el segundo numero
   do{
      cout << "Introduce otro numero entero positivo: ";
      cin >> entero2;
      
      if (entero2 <= 0)
         cout << "\n¡Entrada incorrecta!\n";

   } while (entero2 <= 0);
   
   //Computos
   //Primero calculamos los divisores de ambos numeros. Usamos un bucle for
   
   for (int i = 1; i < entero1; i ++){
      if (entero1 % i == 0)                  //En caso de que el modulo sea 0 es un divisor, por lo tanto lo sumamos para posteriormente comprobar si son amigos
         suma1 += i;
   } 
   
   //Comprobamos los divisores del segundo
   
   for (int j = 1; j < entero2; j ++){
      if (entero2 % j == 0)
         suma2 += j;
   }
   
   //Ahora comprobamos si son amigos
   
   son_amigos = suma1 == entero2 && suma2 == entero1;             //Esta variable booleana sera true si son amigos
   
   //Salida de datos
   
   if (son_amigos)
      cout << entero1 << " y " << entero2 << " son amigos.\n";
   else
      cout << entero1 << " y " << entero2 << " no son amigos.\n";
      
   //Sentencia para detener el programa
   system("pause");
}

