/* Programa que lee los datos fiscales de una persona y reajusta su renta bruta 
segun una serie de criterios e imprime su renta neta final. La expresion es

	RentaNeta = RentaBruta - RentaBruta * Retencion/100

Los criterios son:
	Si es autonomo o no
	Si es pensionista o no
	Estado civil
	Renta bruta
	
Modificaciones:
	-3% si es autonomo
	Si no es autonomo
		+1% a todos los pensionistas
		+2% al resto
			+6% si renta bruta <20 000
			+8% si renta bruta >20 000 
			+10% si es soltero y renta bruta >20 000
			
NOTA
	NuevaRetencion = AntiguaRetencion + AntiguaRetencion * x/100
	
	ENTRADA --> criterios anteriores
	SALIDA --> renta neta
	
06/10/2019
Salvador Romero Cortes
*/

//Programa principal

#include <iostream>

using namespace std;

int main(){
	
	//Declaramos las constantes (los porcentajes de retencion)
	
	const double RETENCION1 = 1.0/100;
	const double RETENCION2 = 2.0/100;
	const double RETENCION3 = 3.0/100;
	const double RETENCION6 = 6.0/100;
	const double RETENCION8 = 8.0/100;
	const double RETENCION10 = 1.0/10; 
	
	//Declaracion de variables
	
	double rentaBruta, rentaNeta, retencion;
	bool autonomo, casado, pensionista;
	int respuesta;
	
	//Entrada de datos
		
	cout << "�Es usted autonomo?\nPulse \"1\" en caso positivo y \"0\" en caso contrario.\n";
	cin >> respuesta;
	if (respuesta == 1)
		autonomo=true;
	else
		autonomo=false;
	
	cout << "�Es pensionista?\n\"1\" para si, \"0\" para no.\n";
	cin >> respuesta;
	if (respuesta == 1)
		pensionista=true;
	else
		pensionista=false;
		
	cout << "�Est� casado?\n\"1\" para si, \"0\" para no.\n";
	cin >> respuesta;
	if (respuesta == 1)
		casado=true;
	else
		casado=false;
	
	cout << "Introduzca su renta bruta:\n";
	cin >> rentaBruta;
	
	cout << "Introduzca su retencion inicial:\n";
	cin >> retencion;
	retencion = retencion;
	//Computos
	
	//Calculo de la retencion
	
	if (autonomo){
		retencion = retencion - retencion * RETENCION3;
	}
	
	else if (pensionista){
		retencion = retencion + retencion * RETENCION1;
	}
	
	else {
		retencion = retencion + retencion * RETENCION2;
		
		if (rentaBruta < 20000){
			retencion = retencion + retencion * RETENCION6;
		}
		else if(rentaBruta >= 20000){
			
			if (casado)
				retencion = retencion + retencion * RETENCION8;

			else if (!casado)
				retencion = retencion + retencion * RETENCION10;

		}
//		else if (casado && rentaBruta > 20000){
//			retencion = retencion + retencion * RETENCION8;
//		}
//		
//		else if (!casado && rentaBruta > 20000){
//			retencion = retencion + retencion * RETENCION10;
//		}
	}
	
	//Ahora calculamos la renta neta
	
	rentaNeta = rentaBruta - rentaBruta * retencion/100;
	
	//Salida de datos
	
	cout << "La renta neta es: " << rentaNeta << endl;
	
	//Sentecia para detener el programa
	
	system("pause");
}

