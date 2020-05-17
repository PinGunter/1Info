#include <iostream>
using namespace std;

int main(){
	int edad_Pedro, edad_Juan, temporal; //Declaramos las variables
	cout << "Introduce la edad de Pedro:\n";
	cin >> edad_Pedro;
	cout << "Introduce la edad de Juan\n";
	cin >> edad_Juan;
	
	//Ahora intercambiamos los valores usando la variable auxiliar "temporal"
	temporal = edad_Pedro;
	edad_Pedro = edad_Juan;
	edad_Juan = temporal;
	
	//Imprimimos los resultados
	cout << "La edad de Pedro es: " << edad_Pedro << " años.\nLa edad de Juan es: " << edad_Juan << " años.";
	system("pause");
	
	
}
