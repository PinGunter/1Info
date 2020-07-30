//Programa para leer una serie de cambios en los piniones y cadena de la bici y diga la situacion final
// 09/12/2019
// Salvador Romero Cortes

#include <iostream>

using namespace std;

class Bicicleta{
	private:
		static const int MAX_PINON = 7;
		static const int MAX_EST = 3;
		static const int MIN = 1;
		
		int pinon;
		int estrella;
		
		//metodo para asegurarse de que estan en intervalos correctos
		bool PinonCorrecto(char entrada);
		bool EstrellaCorrecta(char entrada);
		
		//metodo para comprobar que la entrada que cambia las posiciones es correcta
		bool EntradaCorrecta(char entrada, int objeto);
		
		//metodo para que comprueba que la cadena no se pueda romper
		bool NoRomperCadena();

	public:
		//constructor que incializa las posiciones a 1
		Bicicleta(){
			pinon = MIN;
			estrella = MIN;
		}	
		
		//metodo para cambiar en pinon
		void CambioPinon(char entrada);
		
		//metodo para cambiar la estrella
		void CambioEstrella(char entrada);
		
		//metodo para mostrar los cambios
		void Mostrar();
};

int main(){
	//declaracion de variables y de objetos
	const char TERMINADOR = '#';
	Bicicleta bici;
	char seleccion, movimiento;
	
	//entrada de datos y computos
	cerr << "Introduce los datos de cambio (# para terminar): ";
	do{
		cin >> seleccion;
		if (seleccion != TERMINADOR)
			cin >> movimiento;
		seleccion = toupper(seleccion); movimiento = toupper(movimiento);
		
		switch (seleccion){
			case 'E':
				bici.CambioEstrella(movimiento);
				break;
			case 'P':
				bici.CambioPinon(movimiento);
				break;
			default:
				break;			
		}
		
	}while (seleccion != TERMINADOR);
	
	//salida de datos
	bici.Mostrar();
}

bool Bicicleta::PinonCorrecto(char entrada){
	bool valido = true;
	if (pinon == MAX_PINON && (entrada == 'S' || entrada == 'T'))
		valido = false;
	else if (pinon == MAX_PINON-1 && entrada == 'T')
		valido = false;
	else if (pinon == MIN && (entrada == 'B' || entrada == 'C'))
		valido = false;
	else if (pinon == MIN +1 && entrada == 'C')
		valido = false;
	
	return valido;		
}

bool Bicicleta::EstrellaCorrecta(char entrada){
	bool valido = true;
	if (estrella == MAX_EST && entrada == 'S')
		valido = false;
	else if (estrella == MIN && entrada == 'B')
		valido = false;
	
	return valido;
}

bool Bicicleta::EntradaCorrecta(char entrada, int objeto){
	bool valido;
	if (objeto == 1)
		valido = entrada == 'S' || entrada == 'B' || entrada == 'C' || entrada == 'T';
	else if (objeto == 2)
		valido = entrada == 'S' || entrada == 'B';
	
	return valido;
}

//cambio de marcha del pinon
//primero nos aseguramos de que la entrada sea correcta y que no vaya a pasarse de los limites
//si es todo valido subimos o bajamos
void Bicicleta::CambioPinon(char entrada){
	bool entrada_valida = EntradaCorrecta(entrada,1);
	bool movimiento_valido = PinonCorrecto(entrada);
	bool situacion_valida = NoRomperCadena();
	
	if (entrada_valida && movimiento_valido && situacion_valida){
		if (entrada == 'S')
			pinon++;
		else if (entrada == 'T')
			pinon += 2;
		else if (entrada == 'B')
			pinon--;
		else if (entrada == 'C')
			pinon -= 2;
	}
}

//cambio de marcha de la estrella
// primero nos aseguramos de que la entrada y el intervalo de cambio sea correcto y si es asi subimos o bajamos
void Bicicleta::CambioEstrella(char entrada){
	bool entrada_valida = EntradaCorrecta(entrada,2);
	bool movimiento_valido = EstrellaCorrecta(entrada);
	bool situacion_valida = NoRomperCadena();
	
	if (entrada_valida && movimiento_valido && situacion_valida){
		if (entrada == 'S')
			estrella++;
		else if (entrada == 'B')
			estrella--;
	}
}

//mostramos el estado de la estrella y pinon
void Bicicleta::Mostrar(){
	cout << "\nEstrella: " << estrella;
	cout << "\nPinon: " << pinon;
}

bool Bicicleta::NoRomperCadena(){
	bool valido;
	bool situacion1 = estrella == 1 && pinon >= 5;
	bool situacion2 = estrella == 2 && (pinon == 1 || pinon == 7);
	bool situacion3 = estrella == 3 && pinon <= 3;
	valido = !(situacion1 || situacion2 || situacion3);
	
	return valido;
}
