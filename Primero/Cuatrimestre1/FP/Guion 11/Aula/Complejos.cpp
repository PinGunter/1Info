//Complejos
#include <iostream>

using namespace std;

//clase para representar numeros complejos
class Complejo{
	private:
		double real, imag;
		
	public:
		//constructor
		Complejo(){
			real = 0;
			imag = 0;
		}
		//metodo para introducir valores
		void SetValores(double r, double i);
		
		//metodo para introducir solo la parte real
		void SetReal(double r);
		
		//metodo para introducir solo la parte imaginaria
		void SetImag(double i);
		
		//metodo para sacar la parte real
		double GetReal();
		
		//metodo para sacar la parte imaginaria
		double GetImag();

		//metodo para mostrar los complejos
		void Mostrar();
			
		//metodo para sumar dos complejos
		Complejo Suma(Complejo complejo2);
		
		//metodo para restar dos complejos
		Complejo Resta(Complejo complejo2);
		
		//metodo para multiplicar dos numeros complejos
		Complejo Producto(Complejo complejo2);			
};


Complejo


int main(){
	//declaracion de objetos y variables
	Complejo numero1, numero2, suma, resta, producto;
	double real1, real2, imag1, imag2;
	
	//entrada de datos
	cout << "Introduce el primer numero complejo:\nParte real: ";
	cin >> real1;
	cout << "\nParte imaginaria: ";
	cin >> imag1;
	
	cout << "\nIntroduce el segundo numero complejo:\nParte real: ";
	cin >> real2;
	cout << "\nParte imaginaria: ";
	cin >> imag2;
	
	//pasamos los datos a los objetos
	numero1.SetValores(real1, imag1);
	numero2.SetValores(real2, imag2);
	
	//computos
	suma = numero1.Suma(numero2);
	resta = numero1.Resta(numero2);
	producto = numero1.Producto(numero2);
	
	//salida de datos
	cout << "\nLa suma de los complejos es: ";
	suma.Mostrar();
	cout << "\nLa resta de los numeros complejos es: ";
	resta.Mostrar();
	cout << "\nEl producto de los numeros complejos es: ";
	producto.Mostrar();
	
}

//definimos los metodos

void Complejo::SetValores(double r, double i){
	real = r;
	imag = i;
}

void Complejo::SetReal(double r){
	real = r;
}

void Complejo::SetImag(double i){
	imag = i;
}

double Complejo::GetReal(){
	double r = real;
	return r;
}

double Complejo::GetImag(){
	double i = imag;
	return i;
}

void Complejo::Mostrar(){
	cout << real << " + (" << imag << ")i";
}

Complejo Complejo::Suma(Complejo complejo2){
	Complejo suma;
	suma.real = real + complejo2.real;
	suma.imag = imag + complejo2.imag;
	return suma;	
}

Complejo Complejo::Resta(Complejo complejo2){
	Complejo resta;
	resta.real = real - complejo2.real;
	resta.imag = imag - complejo2.imag;
	return resta;
}

Complejo Complejo::Producto(Complejo complejo2){
	Complejo producto;
	producto.real = real * complejo2.real - (imag * complejo2.imag);
	producto.imag = imag * complejo2.real + real * complejo2.imag;
	return producto;
}




