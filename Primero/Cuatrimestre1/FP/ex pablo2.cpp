//Ejercicio 2
#include <iostream>

using namespace std;

int main(){
	int v[5];
	int w[5];
	cout << "Introduce los valores del vector:\n";
	for (int i=0; i <5; i++)
		cin >> v[i];
	for (int i=0; i < 5; i++)
		w[v[i]] = i;

	for (int i=0; i < 5; i++)
		cout << "El valor de " << i << " esta en la posicion " << w[i] << endl;

}
