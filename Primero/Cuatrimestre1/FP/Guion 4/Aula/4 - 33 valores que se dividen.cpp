/*
    Programa para comprobar si dos numeros introducidos por teclado
    se dividen o no

    ENTRADA --> numeros enteros
    SALIDA --> que numero divide al otro

11/10/2019
Salvador Romero Cortes
*/

#include <iostream>                 //Incluimos los recursos de E/S
#include <string>

using namespace std;

//Programa principal

int main(){
    //Declaracion de variables
    int entero1, entero2;

    /*  APARTADO A  */
    // Mezclando entradas, computos y salidas
    /*
    cout << "Introduce el primer numero: ";
    cin >> entero1;
    cout << "\nIntroduce el segundo numero: ";
    cin >> entero2;

    if (entero1%entero2==0)
        cout << "\nEl segundo numero divide al primero.\n";
    else if(entero2%entero1==0)
        cout << "\nEl primer numero divide al segundo.\n";
    else
        cout << "\nNinguno divide al otro.\n";
    */
   
   /* APARTADO B    */
   //Apartado i)
   /*
   string quien_divide;
    .............
    if (a%b==0)
    quien_divide = "b divide a a" ;
    .............
    if (quien_divide == "b divide a a")
    cout << b << " divide a " << a;
   */
    /* Si se opta por esta solucion el suspenso esta garantizado.¿Por qué?
    Porque no funciona en todos los casos. No funciona si a divide a b. Y ademas no dice quien divide
    a quien, especificado en el enunciado. Por lo tanto no cumple con lo pedido.
    */

   //Apartado ii)
   /*
    bool a_divide_b, b_divide_a;
    .............
    if (a%b==0)
    a_divide_b = true;
    .............
    if (a_divide_b)
    cout << a << "divide a " << b;

    //Apartado iii)
   
    bool se_dividen;
    int Divdo, Divsor;
    .............
    if (a%b==0){
    Divdo = a;
    .............
    if (se_dividen)
    cout << Dvsor << " divide a " << Dvdo;
    */
   
   /*   APARTADO C  */

   //Declaracion de variables
   int Divdo, Divisor;
   bool se_dividen;

   //Entrada de datos

   cout << "Introduce un numero entero --> ";
   cin >> entero1;
   cout << "Introduce otro numero entero --> ";
   cin >> entero2;

   se_dividen = entero1 % entero2 == 0 || entero2 % entero1 == 0;
   
   //Computos
   
   Divdo = entero1;
   Divisor = entero2;

   if (entero2 % entero1 == 0){
      Divdo = entero2;
      Divisor = entero1;
   }
   //Salida
   if (se_dividen){
       cout << Divisor << " divide a " << Divdo << endl;
   }
   else
   	cout << "No se dividen entre ellos" << endl;

   //Sentencia para detener el programa
   system("pause");
   

}
