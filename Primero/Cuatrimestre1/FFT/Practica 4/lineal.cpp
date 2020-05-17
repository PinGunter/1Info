#include <iostream>
#include <cmath>
using namespace std;
int main(){
	double vi,vo1,vo2;
	double k = 0.00095;
	double vt = 1.12;
	double r = 2150.0;
	
	do{
		cin >> vi;
		if (vi !=-1){
			for (double i = 2.85; i < 3.5; i+=0.01){
				vo1 = 5.0-r*(k/2.0) * pow(i-vt,2.0);
				vo2 = (2.0*i-1.26081-sqrt(pow(2.0*i-1.26081,2.0)-19.58384333))/(2.0);
				cout << "INDICE: " << i << "\t" << vo1 << " " << vo2 << endl;
				if (vo1 == 1.76427)
					cout << "encontrado: " << i;
			}
		}
	} while (vi != -1);
}
