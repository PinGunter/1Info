/*
Programa para calcular el reparto de ganancias entre el diseñador y los fabricantes
Por Salvador Romero Cortés
21/08/2019
*/

#include <iostream>																		//Incluimos los recursos de E/S

using namespace std;

int main(){																					//Programa principal

	const double porcentajedis = 0.4;												//El porcentaje de ganancia del diseñador. Es un valor constante. 
																								//Como el diseñador cobra el doble que cada fabricante, pues su porcenteja es 40%. (2/5)
																								
	const double porcentajefab = 0.2;												//Las ganancias de los fabricantes ambién son un valor constante. 
																								//Los 3 fabricantes se reparten el dinero. 20% cada uno. De esta manera se cumplen las condiciones (1/5 cada uno)
	
	double ganancias, disenador, fabricante;										//Declaramos las variables que vamos a usar para guardar los datos de las ganancias totales y de cada parte
	
	//Pedimos los ingresos y asignamos el valor introducido por el usuario a la variable correpsondiente
	
	cout << "Introduce las ganancias totales de la empresa: ";
	cin >> ganancias;
	
	//Calculamos las ganancias de cada parte
	
	disenador = porcentajedis * ganancias;
	fabricante = porcentajefab * ganancias;
	
	//Imprimimos los resultados
	
	cout << "El diseñador cobra: " << disenador << " euros.\n";
	cout << "Cada fabricante cobra: " << fabricante << " euros.\n";
	
	system("pause");																		//Sentencia para detener el programa hasta que el usuario pulse una tecla
}
