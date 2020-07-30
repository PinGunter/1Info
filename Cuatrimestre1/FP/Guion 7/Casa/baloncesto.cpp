/*
   Programa para calcular el ganador de baloncesto

   ENTRADA --> dorsal y puntos introducidos
   SALIDA --> equipo ganador
   
   El equipo 1 lo forman los dorsales 1, 2, 3
   El equipo 2 lo forman los dorsales 4, 5, 6

26/10/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main(){
   //Declaracion de variables
   int dorsal, puntos, equipo1 = 0, equipo2 = 0;
   bool terminador = false;
   
   //Entrada de datos
   cout << "Introduce la secuencia separado por espacios:\n";
   
   //Bucle para la entrada de datos y el computos de puntos
   do{
		cin >> dorsal;
		
		if (dorsal == -1)
			terminador = true;
			
		else{
			
			cin >> puntos;
			if (dorsal == 1 || dorsal == 2 || dorsal == 3)
				equipo1 += puntos;
			
			else if (dorsal == 4 || dorsal == 5 || dorsal == 6)
				equipo2 += puntos;
				
			else
			cout << "\nEntrada incorrecta\n";
		}

		
	} while (!terminador);
	
	//Ahora comprobamos cual tiene mas puntos para la salida de datos
	if  (equipo1 >  equipo2)
		cout << "\nEl equipo 1 ha ganado.\n";
	
	else if (equipo2 > equipo1)
		cout << "\nEl equipo 2 ha ganado.\n";
	
	else
		cout << "\nLos equipos han empatado.\n";
		
	//Sentencia para detener el programa
	system("pause");
	

}
