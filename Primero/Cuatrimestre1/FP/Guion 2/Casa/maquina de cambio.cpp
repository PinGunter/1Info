/*
Programa para calcular las monedas de cambio de moneda
Por Salvador Romero Cortés
21/09/2019
*/

#include <iostream>																											//Incluimos los recursos de E/S

using namespace std;
	
int main(){																														//Programa principal

	int precio, pagado, euro, cambio, cincuentaCent, veinteCent, diezCent, cincoCent;					//Declaramos las variables que vamos a usar a lo largo del programa para almacenar los datos de las monedas
	
	//Preguntamos por las cantidades y las asignamos a variables
	
	cout << "Introduce el precio del producto (en céntimos): "; cin >> precio;
	cout << "\nIntroduce la cantidad pagada (en céntimos): "; cin >> pagado;							
	
	//Primero comprobamos si el precio es igual o inferior a lo pagado. En estos casos el programa acabaría aquí
	
	if (precio > pagado){																									//Si se cumple que el precio a pagar es superior al pagado
		cout << "La cantidad introducida es inferior al precio del producto.\n";							//Imprimimos mensaje de error
		return 0;																												//Y acabamos el programa
	}
	else{																															
		if (precio == pagado){																								//Por otra parte, si el precio a pagar es el mismo que el pagado,	
			cout << "No es necesario cambio.";																			//no hay cambio que dar	
			return 0;																											//Y tambíen acabamos el programa
		}
	}
	
	/*
	En caso de que no se cumplan ninguna de las condiciones anteriores quiere decir que ha pagado más de lo que cuesta 
	por lo tanto el cambio sera necesario.
	Comezamos a calcular cuantas monedas de cada tipo seran necesarias. De mayor a menor.
	*/
	
	
	cambio = pagado - precio;																								//Calculamos el cambio total que habrá que dar al usuario
	
	//Monedas de Euro
	
	euro = cambio/100;																										//Los euros seran los centimos divididos por 100
	cambio %= 100;																												//El modulo será el resto de centimos que no han sido suficientes para una moneda de euro
																																	//Este proceso será el mismo para el resto de monedas 
	
	//50 Cent
	
	cincuentaCent = cambio/50;
	cambio %= 50;
	
	//20 Cent
	
	veinteCent = cambio/20;
	cambio %= 20;
	
	//10 Cent
	
	diezCent = cambio/10;
	cambio %= 10;
	
	//5 Cent
	
	cincoCent = (cambio)/5;
	cambio %= 5;																												//Puede que sea necesario cambio en monedas de 1 centimo puesto que son multiplos de 5
	
	//Establecemos una situacion condicional
	
	if (cambio !=0){																											//Si queda cambio despues de convertirlo a monedas de 5 cent, imprimos el resultado con monedas de centimo
		cout << "El cambio es:\n" 
		<< euro << " monedas de euro\n" 
		<< cincuentaCent << " monedas de 50 Cent\n" 
		<< veinteCent << " monedas de 20 Cent\n" 
		<< diezCent << " monedas de 10 Cent\n" 
		<< cincoCent << " monedas de 5 Cent\n"
		<< cambio << " monedas de 1 Cent\n";
		
	}
	else{																															//En caso contrario no serán necesarias y por tanto no habrá que imprimir en la pantalla monedas de 1 cent
		cout << "El cambio es:\n" 
		<< euro << " monedas de euro\n" 
		<< cincuentaCent << " monedas de 50 Cent\n" 
		<< veinteCent << " monedas de 20 Cent\n" 
		<< diezCent << " monedas de 10 Cent\n" 
		<< cincoCent << " monedas de 5 Cent\n";
	}
	system("pause");																											//Sentencia para detener el programa hasta pulsar una tecla
}
