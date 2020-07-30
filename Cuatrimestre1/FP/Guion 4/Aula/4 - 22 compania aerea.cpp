/* Programa para calcular el precio de los billestes de avion segun unas 
determinadas condiciones.

	ENTRADA --> numero de km, si es cliente previo
	SALIDA --> precio final del billete

10/10/2019
Salvador Romero Cortes
*/

#include <iostream>						//Incluimos los recursos de E/S

using namespace std;

//Programa principal

int main(){
	//Declaracion de constantes
	
	const double PRECIO_POR_KM = 0.1;
	const double DESCUENTO_A = 0.03;
	const double DESCUENTO_B = 0.04;
	const double DESCUENTO_C = 0.05;
	
	//Declaracion de variables
	
	bool cliente_previo;
	int distancia;
	char respuesta;
	double precio_caso1, precio_caso2;					
	
	//Entrada de datos
	
	cout << "Introduce el numero de kilometros del viaje que desea hacer --> ";
	cin >> distancia;
	
	cout << "�Ha sido usted cliente nuestro anteriormente? \"s\" para si y \"n\" para no. --> ";
	cin >> respuesta;
	
	//Convertirmos la entrada del usuario en datos booleanos
	if (respuesta == 's')
		cliente_previo = 1;
	else if (respuesta == 'n')
		cliente_previo = 0;
	else{	
		//En caso de una entrada no valida se cierra el programa
		cout << "\nEntrada no valida. Fin del programa.";
		system("pause");
		return 0;
	}
	
	/*	COMPUTO	*/
	
	// CASO 1. Aplicando c) de forma adicional a los descuentos a) y b)
	
	precio_caso1 = 150;				//Tarifa base de 150 euros
	
	if (distancia >= 200){
		precio_caso1 += PRECIO_POR_KM * (distancia-200);
	}
	if (distancia >= 600 && distancia < 1100){
		precio_caso1 = precio_caso1 - DESCUENTO_A * precio_caso1;
	}
	else if (distancia >= 1100){
		precio_caso1 = precio_caso1 - DESCUENTO_B * precio_caso1;
	}

	
	if (cliente_previo)
		precio_caso1 = precio_caso1 - DESCUENTO_C * precio_caso1;
	
	precio_caso1 -= 15;				//Rebaja global
	
	//CASO 2. Aplicando c) de forma exclusiva con los anteriores.
	
	precio_caso2 = 150;				//Tarifa base de 150 euros

	

	if (distancia >= 200){
		precio_caso2 += PRECIO_POR_KM * (distancia-200);
	}
	if (!cliente_previo){
		if (distancia >= 600 && distancia < 1100){
			precio_caso2 = precio_caso2 - DESCUENTO_A * precio_caso2;
		}
		else if (distancia >= 1100){
			precio_caso2 = precio_caso2 - DESCUENTO_B * precio_caso2;
		}
	}
	else{		
	precio_caso2 = precio_caso2 - DESCUENTO_C * precio_caso2;	
	}
	
	precio_caso2 -= 15;				//Rebaja global
	
	/*	SALIDA DE DATOs	*/
	
	cout << "\nEn el primer caso (todos los descuentos se aplican) el precio del billete seria --> " << precio_caso1 << " euros." << endl;
	cout << "En el segundo caso (descuento c exclusivo) el precio del billete seria --> " << precio_caso2 << " euros." << endl;
	
	//Sentencia para detener el programa
	system("pause");
	
}
