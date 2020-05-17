#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int main(){
    //Declaramos las variables de esperanza/media, desviación típica y la abscisa
    double esperanza, desviaciont,x;
    //Preguntamos al usuario por los datos
    cout << "Introduce el valor de la media o esperanza:\n";
    cin >> esperanza;
    cout << "Introduce el valor de la desviación típica:\n";
    cin >> desviaciont;
    cout << "Introduce el valor de la abscisa x:\n";
    cin >> x;
    //Ahora necesitaremos escribir la función Gaussiana
    //Gaussiana(x) = (1/(desviaciont*sqrt(2pi))*exp(pow((-1/2)*((x-esperanza)/desviaciont)),2)
    double primeraParteGaussiana = (1/(desviaciont*sqrt(2*M_PI)));
    double segundaParteGaussiana = exp((-1/2)*((x-esperanza)/desviaciont));
    double segundaParteGaussianaCuadrada = pow(segundaParteGaussiana, 2);
	 cout << "El valor de la funcion gaussiana en x = " << x << " es "<<primeraParteGaussiana*segundaParteGaussianaCuadrada << endl;
    system("pause");
}
