//Ejercicio 1
#include <iostream>

using namespace std;

int main(){
	int n;
	do{
		cout << "\nIntroduce un numero, n, entre 1 y 9: ";
		cin >> n;
	} while (n < 1 || n > 9);

	for (int i=1; i <= n; i++){
		for (int j = i; j > 0; j--)
			cout << i;
		for (int k = n-i; k > 0; k--)
			cout << "_";
		cout << " = " << i * i << endl;
	}
}
