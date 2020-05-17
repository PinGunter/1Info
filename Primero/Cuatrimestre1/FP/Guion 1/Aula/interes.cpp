//Programa que calcule el inter�s en un a�o
#include <iostream>
using namespace std;

int main(){
	double capital, interes, total; //Declaramos las variables que vamos a usar
	//Pedimos el capital inicial
	cout << "Introduce el capital inicial: ";
	cin >> capital;
	//Ahora pedimos el inter�s
	cout << "Introduce el inter�s: ";
	cin >> interes;
	
	//Ahora realizamos la formula para calcular el total y lo asignamos a la variable total
	total = capital + capital*(interes/100);
	
	//Imprimimos en la pantalla el resultado
	
	cout << "El capital total tras un a�o es: " << total;
	system("pause");
}
