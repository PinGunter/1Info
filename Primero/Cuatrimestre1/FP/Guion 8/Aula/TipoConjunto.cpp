/*
	Ejercicio 11 Relacion 3
	
07/11/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

//Creamos la estructura del conjunto
struct TipoConjunto{
	int num_elem;
	int elementos[1000];
};

int main(){
	//Declaracion de variables
	TipoConjunto conjunto1, conjunto2, conjunto_union, interseccion;
	int a_insertar;
	int buscado, posicion_encontrada, izda, dcha, centro;
	int n = 0, m = 0, u = 0;
	bool encontrado = false;
	
	//Entrada de datos
	cout << "\t\tENTRADA DE DATOS\n\n";
	//Conjunto1
	cout << "Introduce el numero de elementos que tiene el conjunto 1 --> ";
	cin >> conjunto1.num_elem;
	
	cout << "Introduce los elementos del conjunto:\n";
	for (int i=0;i < conjunto1.num_elem; i++)
		cin >> conjunto1.elementos[i];
	
	//Conjunto2
	cout << "Introduce el numero de elementos que tiene el conjunto 2 --> ";
	cin >> conjunto2.num_elem;
	
	cout << "Introduce los elementos del conjunto (separados por espacios):\n";
	for (int i=0;i < conjunto2.num_elem; i++)
		cin >> conjunto2.elementos[i];
		
	/* 	Apartado A	*/
	cout << "\n\tApartado A\nIntroduce un elemento a buscar en el conjunto 1 --> ";
	cin >> buscado;
	
	/* 	Apartado B */
	cout << "\n\tAparatado B\nIntroduce un elemento a introducir en el conjunto 1 --> ";
	cin >> a_insertar;

	 
	//Computos
	//Ordenamos los dos conjuntos usando un algoritmo de insercion
	//Conjunto1
	char candidato;
	int i;
	for (int izda=1; izda < conjunto1.num_elem; izda++){
		candidato = conjunto1.elementos[izda];
		
		for ( i = izda; i > 0 && candidato < conjunto1.elementos[i-1];i--)
			conjunto1.elementos[i] = conjunto1.elementos[i-1];
			
		conjunto1.elementos[i] = candidato;
		
	}
	
	//Conjunto 2
	for (int izda=1; izda < conjunto2.num_elem; izda++){
		candidato = conjunto2.elementos[izda];
		
		for ( i = izda; i > 0 && candidato < conjunto2.elementos[i-1];i--)
			conjunto2.elementos[i] = conjunto2.elementos[i-1];
			
		conjunto2.elementos[i] = candidato;
		
	}
	
	/* 	APARTADO A
		Buscar un elemento en los conjuntos
		Como se encuentran ordenados utilizamos la busqueda binaria
	*/
	
	//Conjunto 1
	izda = 0;
	dcha = conjunto1.num_elem - 1;
	
	while (!encontrado && izda <= dcha){
		centro = (izda + dcha)/ 2;
		
		if (buscado == conjunto1.elementos[centro]){
			encontrado = true; 
			posicion_encontrada = centro+1;
		}
		else if (buscado < conjunto1.elementos[centro])
			dcha = centro - 1;
		else 
			izda = centro + 1;
	}
	
	
	/* 	APARTADO B 	
		Insertar un elemento en el conjunto
		Hacemos un switch segun el conjunto que se haya elegido
	*/

	i = conjunto1.num_elem - 1;
	while (a_insertar < conjunto1.elementos [i] && i >=0){
		conjunto1.elementos [i+1] = conjunto1.elementos [i];
		i--;
	}
	conjunto1.elementos[i+1] = a_insertar;
	conjunto1.num_elem ++;

	
	
	/* 	APARTADO C 	
		Calcular la union de los dos conjuntos
		La union sera un TipoConjunto que tenga todos los elementos de conjunto 1 y 2
		Insertamos todos los valores de un conjunto en el conjunto union. Luego comprobamos
		los elementos del conjunto 2 y lo insertamos
	*/
	
	
	while (n < conjunto1.num_elem  && m < conjunto2.num_elem){
		if (conjunto1.elementos[n] > conjunto2.elementos[m]){
			conjunto_union.elementos[u] = conjunto2.elementos[m];
			m++;
		}
		else if (conjunto1.elementos[n] < conjunto2.elementos[m]){
			conjunto_union.elementos[u] = conjunto1.elementos[n];
			n++;
		}
		else {
			conjunto_union.elementos[u] = conjunto1.elementos[n];
			n++;
			m++;
		}
				
		u++;
	}

		//En caso de que sean de distinto tamanio, insertamos el resto
		
		while (n < conjunto1.num_elem){
			conjunto_union.elementos[u] = conjunto1.elementos[n++];
			u++;
		}
	
		while (m < conjunto2.num_elem){
			conjunto_union.elementos[u] = conjunto2.elementos[m++];
			u++;
		}
		
	conjunto_union.num_elem = u;
	
	/* 	 APARTADO D 	
		La interseccion son todos los elementos de ambos conjuntos
		Los elementos no pueden estar repetidos y deben estar en orden
*/
	interseccion.num_elem = 0;
	for (int j=0; j < conjunto1.num_elem; j++){
		for (int k=0;k<conjunto2.num_elem; k++){
			if (conjunto1.elementos[j] == conjunto2.elementos[k]){
				interseccion.elementos[interseccion.num_elem] = conjunto1.elementos[j];
				interseccion.num_elem ++;
				}
		}
	}
	
	//Salida de datos
	cout << "\n\n\n\n\n\tSALIDA DE DATOS\n";
	/* Apartado A */
	cout << "\tAPARTADO A\n";
	
	if (encontrado)
		cout << "Se ha encontrado " << buscado << " en el conjunto 1 en la posicion " << posicion_encontrada << endl;
	else
		cout << "No se ha encontrado " << buscado << " en el conjunto" << endl;
		
	/* Apartado B*/
	cout << "\tAPARTADO B\n";

	cout << "El conjunto con el valor " << a_insertar << " insertado queda como:\n";
	for (int i = 0 ; i < conjunto1.num_elem; i++)
		cout << conjunto1.elementos[i] << " ";
	
	/* Apartado C */
	cout << "\n\tAPARTADO C\n";
	cout << "La union de los dos conjuntos es:\n";
	for(int j =0; j < conjunto_union.num_elem; j++)
		cout << conjunto_union.elementos[j] << " ";
		
	/* Apartado D */
	cout << "\n\tAPARTADO D\n";
	cout << "La interseccion de los dos conjuntos es:\n";
	for(int j =0; j < interseccion.num_elem; j++)
		cout << interseccion.elementos[j] << " ";
}
