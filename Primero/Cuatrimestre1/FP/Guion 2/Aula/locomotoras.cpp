/*
Programa para conocer las distancias que habran recorrido
dos locomotoras antes de que choquen	

Salvador Romero Cortés
25/09/2019
*/

#include <iostream>									//Incluimos los recursos de E/S

using namespace std;

int main(){												//Programa principal
	
	//Declaramos las variables para guardar los datos
	
	double distancia_inicial, velocidad_locomotora1, velocidad_locomotora2;		//Datos que introducira el usuario
	double tiempo, distancia_locomotora1, distancia_locomotora2;					//Datos que calcularemos
	
	//Bloque que muestra en pantalla mensajes para que el usuario introduzca los datos y se guarden en su respectivas variables
	
	cout << "Introduce la distancia inicial (en metros) --> ";
	cin >> distancia_inicial;
	cout << "\nIntroduce la velocidad inicial de la primera locomotora (en m/s) --> ";
	cin >> velocidad_locomotora1;
	cout << "\nIntroduce la velocidad inicial de la segunda locomotora (en m/s) --> ";
	cin >> velocidad_locomotora2;
	
	//Primero calculamos el tiempo que tardaran en chocarse 
	
	tiempo = distancia_inicial / (velocidad_locomotora1 + velocidad_locomotora2);
	
	
	//Una vez tenemos el tiempo calculamos las distancias que han recorrido cada una
	
	distancia_locomotora1 = velocidad_locomotora1 * tiempo;
	
	distancia_locomotora2 = velocidad_locomotora2 * tiempo;
	
	
	//Finalmente sacamos a la pantalla los resultados
	
	cout << "\n\nLa primera locomotora recorre " << distancia_locomotora1 << " m antes de chocar.\n";
	cout << "La segunda locomotora recorre " << distancia_locomotora2 << " m antes de chocar.\n";
	
	//Sentencia final para detener el programa hasta que el usuario pulse una tecla
	system("pause");
}
