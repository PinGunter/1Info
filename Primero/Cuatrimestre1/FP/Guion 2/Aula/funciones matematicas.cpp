/*
Programa para expresiones matematicas
Salvador Romero Cortés
25/09/2019
*/

#include <iostream>																	//Incluimos los recursos de E/S
#include <cmath>																		//Incluimos los recursos matematicos
using namespace std;

int main(){																				//Programa principal													
	double x, y, h, resultado_exp1, resultado_exp2, resultado_exp3;		//Declaramos las variables que vamos a usar para almacenar los datos
	
	string expresion1, expresion2, expresion3;								//Declaramos las variables donde vamos a guardadt la traduccion literal
	
	
	cout << "Introduce el valor de x:\n";										//Mostramos un mensaje en pantalla para que el usuario introduzca los datos
	cin >> x;																			//Asignamos la entrada a la variable correspondiente
	
	cout << "Introduce el valor de y:\n";										
	cin >> y;
	
	cout << "Introduce el valor de h:\n";
	cin >> h;
	
	//Traducimos la primera expresión matemática
	
	resultado_exp1 = ( 1+(( pow(x,2) )/ y )) / (( pow(x,3) ) / (1 + y));
	expresion1 = "( 1 + (( pow(x,2) )/ y )) / (( pow(x,3) )/( 1 + y ))";
	
	//Imprimimos la primera expresion
	
	cout << "\n\nLa expresion a) se traduce a C++ como:\n\n" << expresion1 << "\n\ny su resultado para los valores introducidos es: " << resultado_exp1;
	
	//Traducimos la segunda expresion
	
	resultado_exp2 = ( 1 + (1.0/3.0)  * sin(h)  -(1.0/7.0) * cos(h)) / (2*h);
	expresion2 = "( 1 + (1.0/3.0)  * sin(h)  -(1.0/7.0) * cos(h)) / (2*h)";
	
	//La imprimimos
	
	cout << "\n\n\nLa expresion b) se traduce a C++ como:\n\n" << expresion2 << "\n\ny su resultado para los valores introducidos es: " << resultado_exp2;
	
	//Por ultimo traducimos y calculamos la tercera expresion
	
	resultado_exp3 = sqrt( 1 + ((exp(x) / (pow(x,2) )) * (exp(x) / (pow(x,2) ))));
	expresion3 = "sqrt( 1 + ((exp(x) / (pow(x,2) )) * (exp(x) / (pow(x,2) ))))";
	
	//Imprimimos el ultimo resultado

	cout << "\n\n\nLa expresion c) se traduce a C++ como:\n\n" << expresion3 << "\n\ny su resultado para los valores introducidos es: " << resultado_exp3 << endl;

	system("pause");																		//Sentencia para detener el programa hasta que el usuario pulse una tecla
}

