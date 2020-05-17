#include <iostream>

using namespace std;

int MCDRecursivo(int entero, int otro){
	int mcd;
	if (otro == 0)
		mcd = entero;
	else
		mcd = MCDRecursivo(otro, entero%otro);

	return mcd;
}

int main(){
	int a,b;
	cout << "Introduce los numeros que quieres calcular el MCD:\n";
	cin >> a >> b;

	cout << "\nEl MCD de los dos numeros es " << MCDRecursivo(a,b) << endl;
}
