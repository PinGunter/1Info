/*
Programa para calcular el área de un triángulo
Datos de entrada: lados del triangulo (en cm) y ángulo que forman (en grados)
Datos de salida: área del triangulo
Salvador Romero Cortés
*/

#include <iostream>												//Incluimos los recursos de E/S
#include <cmath>													//Incluimos los recursos de las herramientas matemáticas. Lo necesitaremos para el seno

using namespace std;

int main(){															//Programa principal

	const double PI = 3.1415927;								//Declaramos la constante PI
	
	//Bloque de declaración de variables
	
	double lado1, lado2, angulo;								//Datos que pedimos al usuario
	double area, angulo_radianes;								//Dato que calculamos
	
	//En este bloque imprimimos un mensaje en la pantalla pidiento los datos al usuario
	
	cout << "Introduce el valor de un lado (en cm) --> ";
	cin >> lado1;
	
	cout << "Introduce el valor de otro lado (en cm) --> ";
	cin >> lado2;
	
	cout << "Introduce el ángulo que forman los dos lados (en grados sexagesimales) --> ";
	cin >> angulo;
	
	
	//Primero pasamos los grados sexagesimales a radianes
	
	angulo_radianes = angulo * (PI / 180);
	
	//Ahora calculamos el area 
	
	area = (1.0/2.0) * lado1 * lado2 * sin (angulo_radianes);
	
	//Finalmente mostramos por pantalla el resultado
	
	cout << "\n\nEl área del triangulo es: " << area << " cm^2.\n\n";
	
	//Sentencia final para detener el programa hasta que el usuario pulse una tecla
	
	system("pause");
	
	

}
