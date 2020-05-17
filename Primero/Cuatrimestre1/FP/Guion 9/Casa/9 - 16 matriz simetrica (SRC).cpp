/* Programa para calcular el vector que representa la mitad de una matriz cuadrada.
	Tambien calula la matriz a partir del vector
	
11/11/2019
Salvador Romero Cortes
*/
#include <iostream>

using namespace std;

int main(){
	//Declaracion de variables y constantes
	const int TAMANIO_MAX = 100;
	int matriz[TAMANIO_MAX][TAMANIO_MAX];
	int vector[TAMANIO_MAX];
	int vector_input[TAMANIO_MAX];
	int matriz_creada[TAMANIO_MAX][TAMANIO_MAX];
	int tamanio1, tamanio2, tamanio_vector1 = 0, tamanio_vector2 = 0;
	int contador_vector = 0;
	bool filtro = true;
	
	//Entrada de datos
	//Primera parte
	cout << "Introduce el tamanio de la matriz cuadrada --> ";
	cin >> tamanio1;
	
	//Bucle para introducir los datos de la matriz
	cout << "Introduce los valores de la matriz cuadrada:\n";
	do{
		filtro = true;
		
		for(int i=0; i < tamanio1; i++){
			cout << "Fila " << i+1 << ": ";
			for (int j=0; j < tamanio1; j++)
				cin >> matriz[i][j];
		}
		
		for(int i=0; i < tamanio1; i++)
			for (int j=0; j < tamanio1; j++)
				if (matriz[i][j] != matriz [j][i])
					filtro = false;
					
		if (!filtro)
			cout << "\nLa matriz introducida no es simetrica. Vuelve a introducir los valores:\n";
			
	} while (!filtro);
	
	//Segunda parte
	cout << "\tApartado 2\nIntroduce el tamanio de la matriz cuadrada que se va a crear a partir de un vector --> ";
	cin >> tamanio2;
	
	//Calculamos el tamanio que tendra el vector, puesto que lo necesitamos para introducir los datos
	//Esto lo calcularemos sumando el tamanio de la matriz a si misma menos 1 en cada iteracion
	for(int i=tamanio2; i>0;i--)
		tamanio_vector2 += i;
	
	cout << "Introduce los elementos del vector:\n";
	for (int i=0;i<tamanio_vector2;i++)
		cin >> vector_input[i];
		
	//Computos
	//Primera parte
	//Primero calculamos el tamanio del vector
	for (int i=tamanio1; i > 0; i--)
		tamanio_vector1 += i;
		
	//Ahora creamos el vector. Este tendra los valores de la matriz en posiciones 0,0-1,0-1,1-1,0-1,1...
	//Por lo tanto usamos dos bucles anidados
	
	for (int i=0; i < tamanio1; i++)
		for (int j=0; j <= i; j++){
			vector[contador_vector] = matriz[i][j];
			contador_vector++;
		}
	
	//Segunda parte
	//En la matriz que creamos se cumple que
	//Cada elemento en la posicion x,y tambien lo esta en la y,x
	
	//Creamos la mitad de la matriz
	contador_vector = 0;
	for (int i=0; i < tamanio2; i++)
		for (int j=0; j <=i; j++){
			matriz_creada[i][j] = vector_input[contador_vector];
			contador_vector++;
		}
	
	//Ahora aplicamos la propiedad anterior para hacer la otra mitad
	for (int i=0; i < tamanio2; i++)
		for(int j=0; j <=i; j++)
			matriz_creada[j][i] = matriz_creada[i][j];
			
	//Salida de datos
	cout << "\nEl vector de la matriz introducida es:\n{";
	for (int i=0; i < tamanio_vector1; i++){
		cout << vector[i];
		if (i < tamanio_vector1 -1)
			cout << ", ";
	}
	cout << "}\n";
	
	cout << "\nLa matriz creada por el vector introducido es:";
	for (int i=0; i <tamanio2; i++){
		cout << "\n";
		for (int j=0; j < tamanio2; j++)
			cout << matriz_creada[i][j] << " ";
	}
}
