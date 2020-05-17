/* Ejercicio 3 Relacion 4A

10/11/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

//Modulo de confirmacion
// Se trata de un filtro que solo permite S o N y devuelve true cuando 
// es S y false cuando es N
bool Confirmacion(){
	char respuesta;
	bool ese, ene;
	cout << "\n¿Confirmar? (S/N)?\n";
	do{
		cin >> respuesta;
		ese = respuesta == 'S' || respuesta == 's';
		ene = respuesta == 'N' || respuesta == 'n';
		
		if (ese)
			return true;
		else if (ene)
			return false;
		else
			cout << "\nEntrada no valida. Introduce S o N\n";
		
	} while (!ese && !ene);
}


int main(){
	//Implementamos el modulo de confirmacion	
	if (Confirmacion())
		cout << "\nHas confirmado\n";
	else
		cout << "\nHas denegado\n";
	
	system("pause");
	
}
