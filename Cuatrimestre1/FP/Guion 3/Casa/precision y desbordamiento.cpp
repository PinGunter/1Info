/* 
Comprobar si se produce un problema de precisiï¿½n o de desbordamiento
en los ejemplos
Salvador Romero Cortï¿½s
27/09/2019
*/

#include <iostream>																										//Incluimos los recursos de E/S
#include <limits>	
using namespace std;

int main(){																													//Programa principal

	const string separadorA = "======================= A ========================\n\n";				//Constantes que usaremos para separar visualmente los resultados
	const string separadorB = "======================= B ========================\n\n";
	const string separadorC = "======================= C ========================\n\n";
	const string separadorD = "======================= D ========================\n\n";
	const string separadorE = "======================= E ========================\n\n";
	const string separadorF = "======================= F ========================\n\n";
	const string separadorG = "======================= G ========================\n\n";
	
	
	
	cout << separadorA;
	
	//
	//Ejemplo 1
	//
	
	int chico, chico1, chico2; chico1 = 123456789;
	chico2 = 123456780;
	chico = chico1 * chico2;
	
	cout << "El resultado de las operaciones del apartado a es: " << chico << endl; 		
	cout << "Se produce error de desbordamiento, el resultado del programa es: " << chico << " y deberia ser 1.5241578e+16\n\n";
	
	/*
	En este caso se ha producido un ERROR DE DESBORDAMIENTO, 
	el resultado de la operacion necesita un numero de bits superior al reservado por el tipo int. 
	Por lo tanto se produce un error de desbordamiento y da un resultado erroneo
	*/
	
	cout << separadorB;
	
	//
	//Ejemplo 2
	//
	
	
	long grande;
	//int chico1, chico1, chico2; chico1 = 123456789;		Lo comentamos porque ya estaban declaradas antes
	chico = 123456780;
	grande = chico1 * chico2;
			
	cout << "El resultado de las operaciones del apartado b es: " << grande << endl;					
	cout << "Se produce un erro de desbordamiento, el resultado del programa es: " << grande << " y deberia ser 1.5241578e+16\n\n";
	
	/*
	En este caso ocurre como en el anterior, un ERROR DE DESBORDAMIENTO. Este ocurre debido a que el compilador primero evalua la
	expresion de la derecha "chico1 * chico2" como ambas son de tipo entero el resultado tambien lo es. Luego ese resultado se le asigna a la variable de tipo long
	Por lo tanto se le asigna el valor erroneo de la operacion puesto que el desbordamiento ocurre antes de que se le asigne la variable
	*/
		
	cout << separadorC;
	
	//
	//Ejemplo 3
	//
	
	
	double resultado, real1, real2; real1 = 123.1;
	real2 = 124.2;
	resultado = real1 * real2;
	
	cout.precision(10);																									//Establecemos la precisiï¿½n de los numeros decimales de los reales
	
	cout << "El resultado de las operaciones del apartado c es: " << resultado << endl;				
	cout << "No se produce un error de desbordamiento pero si de precision.\nComo se trata de un numero real nunca va a ser completamente exacto y asumimos una aproximacion\n\n";


	/*Se produce un ERROR DE PRECISION. Cuando c++ trabaja con numeros reales aproxima los valores y esto da lugar a un error de precision.
	Con la sentencia "cout.precision(10)" estamos indicando que represente 10 numeros decimales. Sin embargo tenemos que asumir que se trata 
	de una aproximacion y no es exacta. Por lo tanto se trata de un error de precision" Si no hubiesemos escrito esa sentencia también habría 
	un error de precisoón al no mostrar los correctos decimales.
	
	*/
	
	cout << separadorD;
	
	//
	//Ejemplo 4
	//
	
	
	//double resultado, real1 , real2; real1 = 123.1;		Lo comentamos porque ya estaban declaradas antes
	real2 = 123456789.2;
	resultado = real1 * real2;
	
	cout << "El resultado de las operaciones del apartado d es: " << resultado << endl;
	cout << "No se produce error de desbordamiento pero si de precision.\nAl igual que antes al tratar con numeros reales el resultado sera una aproximacion\n\n";
	
	
	/*
	Al igual que antes se produce un ERROR DE PRECISION por la aproximacion que se realiza al trabajar con numeros reales.
	*/
	
	cout << separadorE;
	
	
	//
	//Ejemplo 5
	//
	
	double real, otro_real; real = 2e34;
	otro_real = real + 1; otro_real = otro_real - real;

	cout << "El resultado de la operacion del apartado e es: " << otro_real << endl;
	cout << "Se produce un error de desbordamiento. El resultado es: " << otro_real << " y deberia ser 1.\n\n";

	/*
	Se produce un ERROR DE DESBORDAMIENTO. Cuando añadimos 1 a "real" superamos el limite de memoria que estaba reservada. 
	De esta manera se produce un ERROR DE DESBORDAMIENTO y se le asigna el valor mas bajo, lo que causa que cuando se le reste la variable "real"
	no salga 1 como se esperaria.
	Podemos considerar tambien un ERROR DE PRECISION debido a tratarse de numeros reales
	*/
	
	cout << separadorF;


	//
	//Ejemplo 6
	//

	//double real, otro_real;		Lo comentamos porque ya estaban declaradas
	real = 1e+300; otro_real = 1e+200;
	otro_real = otro_real * real;
	
	cout << "El resultado de la operacion del apartado f es: " << otro_real << endl;
	cout << "Se produce un error de precisión. El resultado es infinito.\n\n";
	
	/*
	En este caso se produce un ERROR DE PRECISION. La multiplicación de numeros tan enormes hace que el programa de 
	como resultado inifinito en lugar de ese numero tan grande.
	*/
	
	cout << separadorG;
	
	//
	//Ejemplo 7
	//
	
	//En este caso cambio el nombre de las variables para que no haya problemas con las declaradas anteriormente

	float chicoG; double grandeG;																						
	
	grandeG = 2e+150; chicoG = grandeG;
	
	cout << "El resultado de la operacion del apartado g es: " << chicoG << endl;
	cout << "Vuelve a producirse un error de precisión con infinito como resultado\n";	
	
	/*
	En este caso pasa como el apartado anterior donde un número muy grande es almacenado como infinito. Se produce un ERROR DE PRECISION. Ocurrre 
	porque en la variable grandeG se utiliza más bits para la representación de los numeros y por tanto tiene un limite superior mayor al de chicoG que es de tipo float.
	Al pasar un numero superior al limite de bits lo considera infinito y no como ese numero grande.
	*/
	
	system("pause");				//Sentencia para detener el usuario hasta que interactue										

}
