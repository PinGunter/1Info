/*
Programa para representar polinomios de grado maximo 3.
Funciones
    1. Inicializar un polinomio
    2. Sumar dos polinomios
    3. Evaluar un polinomio en un punto x

ENTRADA --> coeficientes de polinomios
SALIDA --> polinomio inicializado, suma de dos polinomios y la evaluacion en un punto x

06/10/2019
Salvador Romero Cortes
*/

#include <iostream>         //Incluimos los recursos de E/S

using namespace std;

//Creamos la estructura polinomio
struct polinomio
{
    // Declaramos los coeficientes del polinomio

    double a;
    double b;
    double c;
    double d;
};

//Programa principal

int main(){

    //Declaramos las variables

    polinomio polinomio1, polinomio2, suma;
    double x, evaluacion;
    string mas = " + ";
    
    //Entrada de datos

    cout << "Introduce los coeficientes del primer polinomio separados por un espacio:\n";
    cin >> polinomio1.a >> polinomio1.b >> polinomio1.c >> polinomio1.d;

    cout << "\nIntroduce los coeficientes del segundo polinomio separados por un espacio:\n";
    cin >> polinomio2.a >> polinomio2.b >> polinomio2.c >> polinomio2.d;

    cout << "Introduce un punto x donde se evalue el primer polinomio:\n";
    cin >> x;

    // Computos
    //Suma de polinomios

    suma = {polinomio1.a + polinomio2.a,
            polinomio1.b + polinomio2.b,
            polinomio1.c + polinomio2.c,
            polinomio1.d + polinomio2.d};
    

    //Evaluacion en x

    evaluacion = polinomio1.a * x*x*x + polinomio1.b * x*x + polinomio1.c * x + polinomio1.d;    
    //Salida de datos

    //Inicializacion de polinomios
    cout << "\tApartado A\nEl primer polinomio inicializado es: " << polinomio1.a << "x^3" << mas
    << polinomio1.b << "x^2" << mas << polinomio1.c << "x" << mas << polinomio1.d << endl;

    cout << "El segundo polinomio inicializado es: " << polinomio2.a << "x^3" << mas << polinomio2.b << "x^2"  
    << mas << polinomio2.c << "x" << mas << polinomio2.d << endl;

    //Resultado de la suma
    cout << "\tApartado B\nEl resultado de la suma es: " << suma.a << "x^3" << mas << suma.b << "x^2" << mas << suma.c << "x" << mas << suma.d << endl;

    //Resultado de la evaluacion en x
    cout << "\tApartado C\nEl primer polinomio evaluado en x es: " << evaluacion << endl;

    //Sentencia para detener el programa
    system("pause");




}