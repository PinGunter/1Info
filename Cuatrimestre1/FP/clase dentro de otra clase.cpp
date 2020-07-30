#include <iostream>

using namespace std;

class Dentro{
	private:
		int numero1;
		int numero2;
	public:
		Dentro(int uno, int dos){
			numero1 = uno;
			numero2 = dos;
		}
		
		int GetUno(){
			return numero1;
		}
		
		int GetDos(){
			return numero2;
		}
};

class Fuera{
	private:
		Dentro numeros;
	public:
		Fuera(int uno,int dos):numeros(uno,dos){};
		
		void Mostrar(){
			cout << numeros.GetUno() << " " << numeros.GetDos();
		}
};

int main(){
	int numero1, numero2;
	cout << "Introduce los dos numeros: ";
	cin >> numero1 >> numero2;
	
	Fuera prueba(numero1,numero2);
	prueba.Mostrar();
	
}
