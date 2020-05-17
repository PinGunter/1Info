/*
	Programa para representar un numero racional usando una estructura.
	Funciones
		a. Inicializar un numero racional
		b. Simplificar un numero racional a su fraccion irreducible
		c. Sumar dos numeros racionales
		d. Multiplicar dos numeros racionales
		e. "Evaluar" un numero racional. 
	
	ENTRADA --> dos numeros enteros para representar un numero racional
	SALIDA --> funciones mencionadas anteriormente
	
Salvador Romero Cortés
10/10/2019
*/

#include <iostream>					//Incluimos los recursos de E/S
#include <algorithm>					//Incluimos la biblioteca para calcular el MCD
using namespace std;

//Creamos la estructura "racional"

struct racional{
	int numerador;
	int denominador;
	int mcd;	
};


int main(){
	
	//Declaramos las variables
	
	racional numero1, numero2, suma, producto, simplificada1, simplificada2, suma_simplificada, producto_simplificado;
	float evaluado1, evaluado2;

	//Entrada de datos
	
	cout << "Introduce el numerador del primer numero racional --> ";
	cin >> numero1.numerador;
	cout << "\nIntroduce el denominador del primer numero racional --> ";
	cin >> numero1.denominador;
	
	cout << "\nIntroduce el numerador del segundo numero racional --> ";
	cin >> numero2.numerador;
	cout << "\nIntroduce el denominador del segundo numero racional --> ";
	cin >> numero2.denominador;
	
	/* 	COMPUTO 		*/
	//Comprobamos si la entrada es correcta --> ningun denominador puede ser 0
	
	if (numero1.denominador==0|| numero2.denominador==0){
		cout << "\nLos valores introducidos no son correctos.\nNo se puede dividir entre 0\n";
		system("pause");
		return 0;
		}
		
	//Calculamos el MCD para simplificar la fraccion
	
	numero1.mcd = __gcd(numero1.numerador, numero1.denominador);
	numero2.mcd = __gcd(numero2.numerador, numero2.denominador);
	
	//Simplificar la fraccion consiste en dividir numerador y denominador por el MCD
	
	simplificada1 = {numero1.numerador/numero1.mcd, numero1.denominador/numero1.mcd};
	simplificada2 = {numero2.numerador/numero2.mcd, numero2.denominador/numero2.mcd};
	
	//Para sumar dos numeros multiplicamos los denominadores, multiplicamos en cruz y sumamos
	
	suma = {simplificada1.numerador*simplificada2.denominador + simplificada1.denominador*simplificada2.numerador
			, simplificada1.denominador * simplificada2.denominador};
	
	//Ahora simplificamos el resultado
	
	suma.mcd = __gcd(suma.numerador, suma.denominador);
	suma_simplificada = {suma.numerador/suma.mcd, suma.denominador/suma.mcd};
	
	//Producto de fracciones
	
	producto = {simplificada1.numerador * simplificada2.numerador, simplificada1.denominador * simplificada2.denominador};
	
	//Lo simplificamos
	
	producto.mcd = __gcd(producto.numerador, producto.denominador);
	producto_simplificado = {producto.numerador/producto.mcd, producto.denominador/producto.mcd};
	
	//"Evaluacion de la fraccion"
	
	evaluado1 = (float)simplificada1.numerador/(float)simplificada1.denominador;
	evaluado2 = (float)simplificada2.numerador/(float)simplificada2.denominador;
	
	
	/*		SALIDA DE DATOS	*/
	
	//Apartado A
	cout << "\n\tApartado A\nEl numero racional 1 es --> " << numero1.numerador << "/" << numero1.denominador << endl;
	cout << "El numero racional 2 es --> " << numero2.numerador << "/" << numero2.denominador << endl;
	
	//Apartado B
	cout << "\n\tApartado B\nEl primer numero simplificado es --> " << simplificada1.numerador << "/" << simplificada1.denominador << endl;
	cout << "El segundo numero simplificado es --> " << simplificada2.numerador << "/" << simplificada2.denominador << endl;
	
	//Apartado C
	cout << "\n\tApartado C\nLa suma de los dos numeros es --> " << suma_simplificada.numerador << "/" << suma_simplificada.denominador << endl;
	
	//Apartado D
	cout << "\n\tApartado D\nEl producto de los dos numeros es --> " << producto_simplificado.numerador << "/" << producto_simplificado.denominador << endl;
	
	//Apartado E
	cout << "\n\tApartado E\nEl primer numero \"evaluado\" es --> " << evaluado1;
	cout << "\nEl segundo numero \"evaluado\" es --> " << evaluado2 << endl;
	
	
	//Sentencia para detener el programa
	system("pause");
}
