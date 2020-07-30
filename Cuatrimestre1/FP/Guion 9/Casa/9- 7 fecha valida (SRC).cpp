/* Programa con un modulo que indica si la fecha introducida es correcta o no

10/11/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

/*Modulo para comprobar si la fecha es valida
 * Creamos un vector booleano indicando si los meses son de 31 dias o no
 * Los anios siempre son validos
 * Comprobamos que el mes este entre 1 y 12
 * Si es febrero comprobamos si es bisiesto
 	*Si es bisiesto el dia entre 1 y 29
 	*Si no entre 1 y 28
 * Miramos si es de 31 o 30 dias y que este entre 1 y 31 o 30 respectivamente
*/
bool FechaValida(int d, int m, int a){
	bool valida = false, bisiesto;
	bool meses31[12] = {1,0,1,0,1,0,1,1,0,1,0,1};
	
	if (m >= 1 && m <= 12){
		if (m ==2){
			bisiesto = (a%4 == 0) && ((a%100 !=0) || (a%400 == 0));
			
			if (bisiesto)
				if (d <= 29 && d >= 1)
					valida = true;
		}
		else if ( meses31[m-1] ){
			if (d <= 31 && d >= 1)
				valida = true;
		}
		else
			if (d <= 30 && d>=1)
				valida = true;
	}
	
	return valida;
}

int main(){
	//Declaracion de variables
	int dia, mes, anio;
	
	//Entrada de datos
	cout << "Introduce la fecha:\nDia: ";
	cin >> dia;
	cout << "\nMes: ";
	cin >> mes;
	cout << "\nAnio: ";
	cin >> anio;
	
	//Salida de datos
	
	if (FechaValida(dia,mes,anio))
		cout << "\nLa fecha introducida es valida\n";
	else
		cout << "\nLa fecha introducida no es valida\n";
		
	system("pause");
}
