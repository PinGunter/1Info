#include <iostream>
using namespace std;

int main(){
	const double PI = 3.141619; //Declaramos la constante PI
	double radio, longitud, area; //Declaramos las variables
	
	//Preguntamos por los datos
	cout << "Introduce el valor de la longitud del radio:\n";
	cin >> radio;
	
	//Calculamos la longitud y el area y las asignamos a sus respectivas variables
	longitud = 2*PI*radio;
	area = PI*radio*radio;
	
	//Imprimimos los resultados
	
	cout << "La longitud del círculo es: " << longitud << " y su área es: " << area << endl;
	system("pause");
}
