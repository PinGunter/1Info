// Racionales
// 12/12/2019
// Salvador Romero Cortes

#include <iostream>

using namespace std;

class Racional{
	private:
		int numerador;
		int denominador;
		
		//metodo para calcular el mcd de dos numeros
		int MaxComDiv (int numero1, int numero2);
		
		//metodo que compruebe que el racional es valido (el denominador no puede ser 0)
		bool Valido();
	
	public:
		//constructor sin argumentos, inicializa el numero a 1
		Racional(){
			numerador = 1;
			denominador = 1;
		}
		
		//constructor con parametros, inicializa un numero racional segun el numerador y el denominador
		Racional (int num, int den){
			numerador = num;
			denominador = den;
		}
		
		//metodo para transformar una fraccion en la irreducible. Para ello dividimos numerador y denominador por el mcd
		void FraccionIrreducible();
		
		//metodo para comprobar si un numero racional es menor a otro
		//primero calculamos que cual de los dos denominadores es mayor, si son iguales comprobamos el numerador
		bool MenorQue(Racional otro);
		
		//metodo para mostrar con decimales un numero racional.
		//para ello realizamos la division entre el numerador y el numerador de manera "manual" precision veces
		void MostrarRacional(int precision);
		
		//metodo para mostrar la fraccion que representa el numero racional
		void MostrarFraccion();
};

int main(){
	//declaracion de datos
	int num, den, precision;
	bool numero_menor_otro;
	
	cout << "Introduce el numerador y el denominador del numero racional\nNumerador: ";
	cin >> num;
	cout << "\nDenominador: ";
	cin >> den;
	Racional numero(num,den);
	
	cout << "\nIntroduce otro numero racional:\nNumerador: ";
	cin >> num;
	cout  << "\nDenominador: ";
	cin >> den;
	Racional otro(num,den);
	
	cout << "\nIntroduce el numero de digitos de precision para los decimales: ";
	cin >> precision;
	
	//computos
	numero.FraccionIrreducible();
	otro.FraccionIrreducible();
	numero_menor_otro = numero.MenorQue(otro);
	
	//salida de datos
	cout << "\n\nLa fraccion irreducible del primer numero es: ";
	numero.MostrarFraccion();
	cout << " y su equivalente en decimales es: ";
	numero.MostrarRacional(precision);
	
	cout << "\nLa fraccion irreducible del segundo numero es: ";
	otro.MostrarFraccion();
	cout << " y su equivalente en decimales es: ";
	otro.MostrarRacional(precision);
	
	if (numero_menor_otro)
		cout << "\n\nEl primer numero es menor que el segundo.";
	else
		cout << "\n\nEl primer numero es mayor o igual que el segundo.";
		
}

int Racional::MaxComDiv(int numero1, int numero2){
	int mcd = 1;
	int minimo = numero2;
	if (numero1 < minimo)
		minimo = numero1;
		
	for (int i = 1; i <= minimo; i++){
		if (numero1 % i == 0 && numero2 % i == 0)
			mcd = i;
	}
	return mcd;
}

bool Racional::Valido(){
	bool valido = denominador != 0;
	return valido;
}

void Racional::FraccionIrreducible(){
	int mcd = MaxComDiv(numerador,denominador);
	numerador /= mcd;
	denominador /= mcd;
}

bool Racional::MenorQue(Racional otro){
	bool menor;
	if (denominador > otro.denominador)
		menor = true;
	else if (denominador < otro.denominador)
		menor = false;
	else{
		if (numerador < otro.numerador)
			menor = true;
		else
			menor = false;
	}
	return menor;	
}

void Racional::MostrarFraccion(){
	cout << numerador << "/" << denominador; 
}

void Racional::MostrarRacional(int precision){
   int div_entera = numerador / denominador;
   double division = (numerador/1.0)/denominador;
   double decimal = division - div_entera;
   int resto = numerador, division_manual;
   
	if (decimal == 0 && precision > 0){
      cout << div_entera << ",";
      for (int i=0; i < precision; i++)
         cout << "0";
   }
   else{
      cout << div_entera;
      if (precision > 0){
         cout << ",";
         for (int i=0; i < precision; i++){
            resto = (resto%denominador) * 10;
            division_manual = resto/denominador;
            cout << division_manual;
         }
      }
   }      

   
}

