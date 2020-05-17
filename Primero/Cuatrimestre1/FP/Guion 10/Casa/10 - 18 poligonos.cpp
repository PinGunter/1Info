/* Pograma para calcular el area de un poligono de n lados
17/11/2019
Salvador Romero Cortes
*/

#include <iostream>
#include <cmath>

using namespace std;

struct TipoPunto{
	double abscisa;
	double ordenada;
};

struct TipoPoligono{
	TipoPunto puntos[100];
	int num_puntos;
};


double AreaTriangulo(TipoPunto punto1, TipoPunto punto2, TipoPunto punto3);
double AreaPoligono (TipoPoligono poligono);

//Funcion principal
int main(){
	//declaracion de variables
	TipoPoligono poligono;
	double area_final;
	
	//entrada de datos
	cout << "Introduce el numero de vertices del poligono (min. 3 max. 100)\n";
	do{
		cin >> poligono.num_puntos;
	
		if (poligono.num_puntos < 3 || poligono.num_puntos > 100)
			cout << "El numero de vertices debe ser un numero entero en el rango [3,100]. Introduce un numero correcto\n";
	} while (poligono.num_puntos < 3 || poligono.num_puntos > 100);
	
	
	for (int i=0; i < poligono.num_puntos; i++){
		cout << "Introduce las coordenadas del vertice " << i+1 << ":\n";
		cin >> poligono.puntos[i].abscisa >> poligono.puntos[i].ordenada;
	}
	
	//computos
	area_final = AreaPoligono(poligono);
	
	//salida de datos
	cout << "\nEl area del poligono es: " << area_final << endl;
}

//Funcion para calcular el area de los triangulos que formemos
/* Para calcular el area de un triangulo
	Area = sqrt(F(F-S1)(F-S2)(F-S3))
	F = (S1+S2+S3)/2;
	Donde S1, S2 y S3 son las longitudes de los lados de los triangulos
*/
double AreaTriangulo(TipoPunto punto1, TipoPunto punto2, TipoPunto punto3){
	double lado1, lado2, lado3;
	double f;
	double area_triangulo;
	
	//Primero calculamos los lados, esto es restar los dos puntos y hacer la raiz cuadrada de la suma de los cuadrados
	lado1 = sqrt(((punto2.abscisa-punto1.abscisa)*(punto2.abscisa-punto1.abscisa))
				+((punto2.ordenada-punto1.ordenada)*(punto2.ordenada-punto1.ordenada)));
	
	lado2 = sqrt(((punto3.abscisa-punto2.abscisa)*(punto3.abscisa-punto2.abscisa))
				+((punto3.ordenada-punto2.ordenada)*(punto3.ordenada-punto2.ordenada)));
				
	lado3 = sqrt(((punto1.abscisa-punto3.abscisa)*(punto1.abscisa-punto3.abscisa))
				+((punto1.ordenada-punto3.ordenada)*(punto1.ordenada-punto3.ordenada)));
				
	f = (lado1+lado2+lado3)/2;
	area_triangulo = sqrt(f*(f-lado1)*(f-lado2)*(f-lado3));
	
	return area_triangulo;
}

//Funcion para calcular el area del poligono, esto es sumar todas las ares de los triangulos que forman el poligono
//Para ello cogemos 3 vertices consecutivos, fijamos el primero y vamos modificando los otros dos. De esta manera conseguimos triangulizar el poligono
//en varios triangulos.
double AreaPoligono (TipoPoligono poligono){
	double area = 0;
	
	for (int i=1; i < poligono.num_puntos-1; i++){
		area += AreaTriangulo(poligono.puntos[0], poligono.puntos[i], poligono.puntos[i+1]);
	}

	return area;
}
 


