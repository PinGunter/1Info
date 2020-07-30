/*
Programa que calcula las horas, minutos y segundos dentro de
su rango correspondiente.
Por Salvador Romero Cort�s
21/09/2019
*/

#include <iostream> 												//Incluimos los recursos de E/S

using namespace std;

int main(){															//Programa principal
	int horas,minutos,segundos,dias;							//Declaramos las variables para guardar cada unidad de tiempo
	
	//Pedimos los datos al usuario y los asignamos a sus variables correspondientes
	
	cout << "Introduce el n�mero de horas, minutos y segundos que quieras convertir\n";
	cout << "Horas: "; cin >> horas;
	cout << "Minutos: "; cin >> minutos;
	cout << "Segundos: "; cin >> segundos;
	
	//Comenzamos a convertir los segundos en minutos
	
	minutos = minutos + segundos/60;							//Los nuevos minutos son los anteriores m�s 60 segundos
	segundos = segundos%60;										//los segundos que quedan son aquellos que no alcanzan 60, el resto.
	
	//El proceso es el mismo para todos los siguientes, variando en los dias que en lugar de 60 son 24
	//Ahora de minutos a horas
	
	horas = horas + minutos/60;
	minutos = minutos%60;
	
	//Ahora de horas a dias
	
	dias = horas/24;
	horas = horas%24;

	//Imprimimos los resultados
	
	cout << "\nUna vez ajustado el rango, las entradas quedan como:\n";
	cout << "D�as: " << dias;
	cout << "\nHoras: " << horas;
	cout << "\nMinutos: " << minutos;
	cout << "\nSegundos: " << segundos << endl;

	system("pause");												//Sentencia para detener el programa hasta que el usuario pulse una tecla
}
