//Programa para realizar operaciones con numeros enteros largos usando clases con un vector para representarlo
//1/12/2019
//Salvador Romero Cort�s

#include <iostream>

using namespace std;

const int LONG = 30;

//clase que representa un entero largo usando un vector cuyos elementos son las cifras del numero
class EnteroLargo {
private:
	int longitud = 0;
	int numero[LONG] = { 0 };
	int acarreo = 0;

public:
	//metodo para asignar un vector a un entero largo
	void Asignar(int tamanio, int vector[]);

	//metodo para comprobar si uno es menor que otro
	bool EsMenor(EnteroLargo numero2);

	//metodo para comprobar si uno es mayor que otro
	bool EsMayor(EnteroLargo numero2);

	//metodo para comprobar si son iguales
	bool SonIguales(EnteroLargo numero2);

	//metodo para saber si son uno es menor igual
	bool MenorOIgual(EnteroLargo numero2);

	//metodo para saber si uno es mayor o igual
	bool MayorOIgual(EnteroLargo numero2);

	//metodo para sumar dos numeros
	EnteroLargo Suma(EnteroLargo numero2);

	//metodo para restar dos numeros
	EnteroLargo Resta(EnteroLargo numero2);

	//metodo para mostrar un numero
	void Mostrar();
};

//funcion para filtrar
int Filtro(int minimo, int maximo);

//funcion para introducir valores del vector
void IntroducirVector(int vector[], int tamanio);

//funcion para el switch
bool SwitchOpciones(EnteroLargo entero1, EnteroLargo entero2, EnteroLargo suma, EnteroLargo resta, int entrada);

int main() {
	//declaracion de objetos y variables
	EnteroLargo numero1, numero2, suma, resta;
	int tamanio1, tamanio2, entrada;
	int vector1[LONG], vector2[LONG];
	bool salir = false;
	string opciones = "\n1)Comprobar si numero1 es menor que numero2\n2)Comprobar si numero1 es mayor que numero2\n3)Comprobar si son iguales\n4)Comprobar si numero1 es menor o igual que numero2\n5)Comprobar si numero1 es mayor o igual a numero2\n6)Sumar los numeros\n7)Restar numero2-numero1\n8)Salir\n";


	//entrada de datos
	cout << "\nIntroduce el tamanio del entero largo (max. 30) --> ";
	tamanio1 = Filtro(1, 30);
	cout << "\nIntroduce las cifras del entero largo:\n";
	IntroducirVector(vector1, tamanio1);

	cout << "\nIntroduce el tamanio del segundo entero largo (max. 30) --> ";
	tamanio2 = Filtro(1, 30);
	cout << "\nIntroduce las cifras del segundo entero largo:\n";
	IntroducirVector(vector2, tamanio2);

	//asignamos los datos a los objetos
	numero1.Asignar(tamanio1, vector1);
	numero2.Asignar(tamanio2, vector2);

	//computos y salidas
	while (!salir) {
		cout << "\n\nElije la opcion deseada:";
		cout << opciones;

		cin >> entrada;
		salir = SwitchOpciones(numero1, numero2, suma, resta, entrada);
	}
}

int Filtro(int minimo, int maximo) {
	int resultado;
	do {
		cin >> resultado;

		if (resultado < minimo || resultado > maximo)
			cout << "---Entrada no valida---\nVuelve a introducir el dato:\n";

	} while (resultado < minimo || resultado > maximo);
	return resultado;
}

void IntroducirVector(int vector[], int tamanio) {
	int numero;
	for (int i = 0; i < tamanio; i++) {
		numero = Filtro(0, 9);
		vector[i] = numero;
	}
}

bool SwitchOpciones(EnteroLargo entero1, EnteroLargo entero2, EnteroLargo suma, EnteroLargo resta, int entrada) {
	bool salir = false;
	bool es_menor, es_mayor, iguales, menorigual, mayorigual;

	switch (entrada) {
	case 1:
		es_menor = entero1.EsMenor(entero2);
		if (es_menor)
			cout << "\nEl numero1 es menor que el numero2\n";
		else
			cout << "\nEl numero1 no es menor que el numero2\n";
		break;
	case 2:
		es_mayor = entero1.EsMayor(entero2);
		if (es_mayor)
			cout << "\nEl numero1 es mayor que el numero2\n";
		else
			cout << "\nEl numero1 no es mayor que el numero2\n";
		break;
	case 3:
		iguales = entero1.SonIguales(entero2);
		if (iguales)
			cout << "\nLos numeros son iguales\n";
		else
			cout << "\nLos numeros son distintos\n";
		break;
	case 4:
		menorigual = entero1.MenorOIgual(entero2);
		if (menorigual)
			cout << "\nEl numero1 es menor o igual que el numero2\n";
		else
			cout << "\nEl numero1 no es menor o igual que el numero2\n";
		break;
	case 5:
		mayorigual = entero1.MayorOIgual(entero2);
		if (mayorigual)
			cout << "\nEl numero1 es mayor o igual que el numero2\n";
		else
			cout << "\nEl numero1 no es mayor o igual que el numero2\n";
		break;
	case 6:
		suma = entero1.Suma(entero2);
		cout << "\nEl resultado de la suma es:\n";
		suma.Mostrar();
		break;
	case 7:
		resta = entero1.Resta(entero2);
		cout << "El resultado de la resta es:\n";
		//comprobamos si sera un resultado negativo
		if (entero1.EsMenor(entero2))
			cout << "-";
		resta.Mostrar();
		break;
	case 8:
		salir = true;
		break;
	}
	return salir;
}
//metodo para asignar las cifras del numero
void EnteroLargo::Asignar(int tamanio, int vector[]) {
	longitud = tamanio;
	int i = LONG - longitud;
	int j = 0;
	while (i < LONG) {
		numero[i] = vector[j];
		j++;
		i++;
	}
}

//metodo para comprobar si el primero es menor que el segundo
//primero comprobamos si el tamanio es igual, si uno es menor ya lo tenemos
bool EnteroLargo::EsMenor(EnteroLargo numero2) {
	bool menor = false, stop = false;
	if (longitud < numero2.longitud)
		menor = true;
	else if (longitud > numero2.longitud)
		menor = false;
	else {
		for (int i = LONG - longitud; i < LONG && !stop; i++) {
			if (numero[i] > numero2.numero[i]) {
				menor = false;
				stop = true;
			}
			else if (numero[i] < numero2.numero[i]) {
				menor = true;
				stop = true;
			}
		}
	}
	return menor;

}
//metodo para comprobar si el primero es mayor que el segundo
//primero comprobamos si el tamanio es igual, si uno es menor ya lo tenemos
bool EnteroLargo::EsMayor(EnteroLargo numero2) {
	bool mayor = false, stop = false;
	if (longitud < numero2.longitud)
		mayor = false;
	else if (longitud > numero2.longitud)
		mayor = true;
	else {
		for (int i = LONG - longitud; i < LONG && !stop; i++) {
			if (numero[i] > numero2.numero[i]) {
				mayor = true;
				stop = true;
			}
			else if (numero[i] < numero2.numero[i]) {
				mayor = false;
				stop = true;
			}
		}
	}
	return mayor;
}

//metodo para ver si son iguales. se tiene que cumplir que las longitudes sean iguales
//y cada elemento en orden tambien
bool EnteroLargo::SonIguales(EnteroLargo numero2) {
	bool iguales = true;
	if (longitud == numero2.longitud) {
		for (int i = LONG - longitud; i < LONG && iguales; i++) {
			if (numero[i] != numero2.numero[i])
				iguales = false;
		}
	}
	else
		iguales = false;

	return iguales;
}

//llamamos a las funciones anteriores para ver si se cumplen
bool EnteroLargo::MenorOIgual(EnteroLargo numero2) {
	bool menor_o_igual = SonIguales(numero2) || EsMenor(numero2);
	return menor_o_igual;
}

//llamamos a las funciones anteriores para ver si se cumplen
bool EnteroLargo::MayorOIgual(EnteroLargo numero2) {
	bool mayor_o_igual = SonIguales(numero2) || EsMayor(numero2);
	return mayor_o_igual;
}

//usaremos un acarreo para hacer la suma
//sumamos cifra a cifra desde el final
EnteroLargo EnteroLargo::Suma(EnteroLargo numero2) {
	EnteroLargo suma;
	int final = LONG;
	int max = longitud;
	if (numero2.longitud > longitud)
		max = numero2.longitud;
	int inicio = LONG - max -1;

	for (int i = final; i >= inicio; i--) {
		suma.numero[i] = numero[i] + numero2.numero[i] + suma.acarreo;
		if (suma.numero[i] > 9) {
			suma.numero[i] -= 10;
			suma.acarreo = 1;
		}
		else
			suma.acarreo = 0;
	}
	suma.longitud = LONG - inicio;
	if (suma.numero[inicio] == 0)
		suma.longitud--;
	return suma;
}


//metodo para restar los numeros. Se hace cifra a cifra con acarreo
EnteroLargo EnteroLargo::Resta(EnteroLargo numero2) {
	EnteroLargo resta;
	int final = LONG;
	int max = longitud;
	if (numero2.longitud > longitud)
		max = numero2.longitud;
	int inicio = LONG - max;
	int eliminar0 = inicio;
	
	if (EsMayor(numero2)){
		for (int i = final; i >= inicio; i--) {
			resta.numero[i] = numero[i] - (numero2.numero[i] + resta.acarreo);
			if (resta.numero[i] < 0) {
				resta.numero[i] = 10 + resta.numero[i];
				resta.acarreo = 1;
			}
			else
				resta.acarreo = 0;
		}
	}
	else{
		for (int i = final; i >= inicio; i--) {
			resta.numero[i] = numero2.numero[i] - (numero[i] + resta.acarreo);
			if (resta.numero[i] < 0) {
				resta.numero[i] = 10 + resta.numero[i];
				resta.acarreo = 1;
			}
			else
				resta.acarreo = 0;
		}
	}
	resta.longitud = max;
	while (resta.numero[eliminar0] == 0) {
		resta.longitud--;
		eliminar0++;
	}
	return resta;
}

void EnteroLargo::Mostrar() {
	for (int i = LONG - longitud; i < LONG; i++)
		cout << numero[i];
}
