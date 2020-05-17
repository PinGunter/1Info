/*
Comprobar varios apartados, decir el tipo de dato y si es erroneo

03/10/2019
Salvador Romero Cortés 
*/

#include <iostream>                    //Incluimos los recursos de E/S

using namespace std;

//Declaramos la siguiente estructura
struct CuentaCD {
   double saldo;
   double tasa_de_interes;
   int plazo;
   char inicial1;
   char inicial2;
};

//Programa principal

int main(){
   
   //Declaracion de variables
   
   CuentaCD cuenta;
   
   // Apartado A
   
   cout << "\tApartado A\ncuenta.saldo es de tipo double\n\n";
   
   // Apartado B
   
   cout << "\tApartado B\ncuenta.tasa_de_interes es de tipo double\n\n";
   
   // Apartado C
   
   cout << "\tApartado C\nCuentaCD.plazo es erroneo. Para que funcione bien deberia ser cuenta.plazo y seria de tipo entero\n\n";
   
   // Apartado D
   
   cout << "\tApartado D\ncuenta_ahorros.inicial1 es erroneo porque \"cuenta_ahorros\" no esta declarada. Para que funcione en la situacion actual deberia ser cuenta.inicial1 y seria de tipo caracter\n\n";
   
   // Apartado E
   
   cout << "\tApartado E\ncuenta.inicial2 es de tipo caracter\n\n";
   
   // Apartado F

   cout << "\tApartado E\ncuenta es de tipo CuentaCD\n\n";
   
   
   //Sentencia para detener el programa
   
   system("pause");


}
