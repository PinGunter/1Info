//Programa para implementar una clase Conjunto que representa un conjunto de numeros enteros
// Salvador Romero Cort�s
// 30/11/2019

#include <iostream>

using namespace std;

const int MAX_ELEM = 100;

class Conjunto {
private:
	int num_elem;
	int elementos[MAX_ELEM];

	void OrdenarConjunto();
	void EliminarRepes();

public:
	//constructor para inicializarlo a 0
	Conjunto();

	//metodo para inicializarlo a un vector	
	void Inicializar(int longitud, int vector[]);

	//metodo para buscar un entero dentro del conjunto
	bool EncontrarEntero(int buscado);

	//metodo para insertar un elemento en el conjunto
	void InsertarElem(int elemento);

	//metodo para eliminar un elemento del conjunto
	void EliminarElem(int elemento);

	//metodo que devuelve la union de dos conjuntos
	Conjunto Union(Conjunto conjunto2);

	//metodo que devuelve la interseccion de dos conjuntos
	Conjunto Interseccion(Conjunto conjunto2);

	//metodo para mostrar los conjuntos
	void Mostrar();
};

void IntroducirDatos(int vector[], int longitud);

int main() {
	//declaracion de variables y objetos
	Conjunto conjunto1, conjunto2, conjunto_union, interseccion;

	int longitud1, longitud2, long_union, long_inters, inserta, elimina, busca;
	longitud1 = longitud2 = long_union = long_inters = 0;
	int vector1[MAX_ELEM], vector2[MAX_ELEM], vector_union[MAX_ELEM], vector_inters[MAX_ELEM];
	bool encontrado = false;

	//Entrada de datos
	cout << "Introduce el tamanio del primer conjunto --> ";
	cin >> longitud1;
	cout << "\nIntroduce el tamanio del segundo conjunto --> ";
	cin >> longitud2;

	//introducimos los datos de los vectores
	cout << "\nIntroduce los elementos del conjunto 1:\n";
	IntroducirDatos(vector1, longitud1);
	cout << "\nIntroduce los elementos del conjunto 2:\n";
	IntroducirDatos(vector2, longitud2);

	//los pasamos al objeto
	conjunto1.Inicializar(longitud1, vector1);
	conjunto2.Inicializar(longitud2, vector2);

	cout << "\nIntroduce el entero que quieres buscar en el primer conjunto (recuerda que no hay repetidos en un conjunto) --> ";
	cin >> busca;

	cout << "\nIntroduce el elemento que quiere introducir en el primer conjunto --> ";
	cin >> inserta;

	cout << "\nIntroduce el elemento que quieres eliminar del primer conjunto --> ";
	cin >> elimina;


	//computos
	encontrado = conjunto1.EncontrarEntero(busca);
	conjunto1.InsertarElem(inserta);
	conjunto1.EliminarElem(elimina);
	conjunto_union = conjunto1.Union(conjunto2);
	interseccion = conjunto1.Interseccion(conjunto2);

	//salida de datos

	if (encontrado)
		cout << endl << busca << " esta en el conjunto 1.\n";
	else
		cout << endl << busca << " no esta en el conjunto 1.\n";

	cout << "\nEl conjunto 1 con las debidas inserciones y eliminaciones queda como:\n";
	conjunto1.Mostrar();

	cout << "\nLa union de los dos conjuntos es:\n";
	conjunto_union.Mostrar();

	cout << "\nLa interseccion de los dos conjuntos es:\n";
	interseccion.Mostrar();
}

void IntroducirDatos(int vector[], int longitud) {
	for (int i = 0; i < longitud; i++)
		cin >> vector[i];
}
//constructor
Conjunto::Conjunto() {
	num_elem = 0;
}

//metodo para ordenar los vectores --> InsertionSort
void Conjunto::OrdenarConjunto() {
	char candidato;
	int i;
	for (int izda = 1; izda < num_elem; izda++) {
		candidato = elementos[izda];

		for (i = izda; i > 0 && candidato < elementos[i-1]; i--)
			elementos[i] = elementos[i-1];

		elementos[i] = candidato;
	}
}

//metodo para eliminar repetidos en un conjunto ordenado
//compara el elemento con su anterior, si son iguales borra el elemento
//y desplaza el resto del vector a la izquierda
void Conjunto::EliminarRepes() {
	int repetido;
	for (int i = 1; i < num_elem; i++) {
		if (elementos[i] == elementos[i - 1]) {
			for (int j = i; j < num_elem; j++)
				elementos[j] = elementos[j + 1];
			num_elem--;
		}
	}
}

//metodo para inicializar el conjunto a un vector, tras la asignacion, lo ordenamos
void Conjunto::Inicializar(int longitud, int vector[]) {
	num_elem = longitud;
	for (int i = 0; i < num_elem; i++)
		elementos[i] = vector[i];

	//lo ordenamos
	OrdenarConjunto();
	//eliminamos repetidos
	EliminarRepes();
}

//metodo para encontrar un elemento en el conjunto. Como estan ordenados podemos utilizar una busqueda binaria
bool Conjunto::EncontrarEntero(int buscado) {
	int izda = 0;
	int dcha = num_elem - 1;
	int centro;
	bool encontrado = false;
	while (!encontrado && izda <= dcha) {
		centro = (izda + dcha) / 2;

		if (buscado == elementos[centro])
			encontrado = true;
		else if (buscado < elementos[centro])
			dcha = centro - 1;
		else if (buscado > elementos[centro])
			izda = centro + 1;
	}
	return encontrado;
}
//metodo para introducir un elemento y que siga ordenado
//primero buscamos si ese elemento esta en el conjunto y asi no tenemos que insertarlo
void Conjunto::InsertarElem(int elemento) {
	bool esta_en_conjunto = EncontrarEntero(elemento);
	int i = num_elem - 1;
	if (!esta_en_conjunto) {
		while (elemento < elementos[i] && i >= 0) {
			elementos[i + 1] = elementos[i];
			i--;
		}
		elementos[i + 1] = elemento;
		num_elem++;
	}
}

//metodo para eliminar un elemento del conjunto
//primero buscamos si esta en el conjunto y en caso positivo lo eliminamos
//en caso contrario avisamos de error
void Conjunto::EliminarElem(int elemento) {
	bool esta_en_conjunto = EncontrarEntero(elemento);
	if (!esta_en_conjunto)
		cout << "\nNo se puede eliminar un elemento que no esta en el conjunto.\n";
	else {
		for (int i = 0; i < num_elem; i++) {
			if (elementos[i] == elemento)
				for (int j = i; j < num_elem; j++)
					elementos[j] = elementos[j + 1];
		}

		num_elem--;
	}
}

//metodo para realizar la union de dos conjuntos
Conjunto Conjunto::Union(Conjunto conjunto2) {
	Conjunto unido;
	int count1 = 0, count2 = 0, count0 = 0;

	while (count1 < num_elem && count2 < conjunto2.num_elem) {
		if (elementos[count1] < conjunto2.elementos[count2]) {
			unido.elementos[count0] = elementos[count1];
			count1++;
		}

		else if (elementos[count1] > conjunto2.elementos[count2]){
			unido.elementos[count0] = conjunto2.elementos[count2];
			count2++;
		}

		else {
			unido.elementos[count0] = elementos[count1];
			count1++;
			count2++;
		}
		count0++;
	}

	//ahora introducimos el resto de elementos
	while (count1 < num_elem) {
		unido.elementos[count0] = elementos[count1++];
		count0++;
	}
	while (count2 < conjunto2.num_elem) {
		unido.elementos[count0] = conjunto2.elementos[count2++];
		count0++;
	}

	//asignamos el num elem al nuevo conjunto
	unido.num_elem = count0;
	return unido;
}

//metodo para realizar la interseccion de dos conjuntos
Conjunto Conjunto::Interseccion(Conjunto conjunto2) {
	Conjunto intersectado;
	for (int i = 0; i < num_elem; i++)
		for (int j = 0; j < conjunto2.num_elem; j++) {
			if (elementos[i] == conjunto2.elementos[j]) {
				intersectado.elementos[intersectado.num_elem] = elementos[i];
				intersectado.num_elem++;
			}
		}
	return intersectado;
}

//metodo para mostrar el conjunto
void Conjunto::Mostrar() {
	cout << "{";
	for (int i = 0; i < num_elem; i++) {
		if (i < num_elem - 1)
			cout << elementos[i] << ", ";
		else
			cout << elementos[i] << "}";
	}
}

