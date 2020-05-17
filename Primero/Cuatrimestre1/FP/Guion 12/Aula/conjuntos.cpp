//Programa para utilizar una clase conjunto
//05/12/2019
//Salvador Romero Cortés

#include <iostream>
#include <vector>

using namespace std;

//clase que representa un conjunto
class Conjunto{
	private:
		vector<int> elementos;
		
		//metodo para ordenar el vector usando insertionsort
		void Ordena();
		
		//metodo para eliminar los repetidos en un vector ordenado
		void EliminaRepes();
		
	public:
		//constructor a 0
		Conjunto(){
			elementos.resize(0); 	
		}
		
		//inicializar a un vector
		void Inicializar(int longitud, vector<int> vector);
		
		//buscar un elemento en el conjunto
		bool EncontrarEntero(int buscado);
		
		//insertar un elemento en el conjunto
		void InsertarElem(int insertar);
		
		//eliminar un elemento del conjunto
		void EliminarElem(int eliminado);
		
		//hacer la union de dos conjuntos
		Conjunto Union(Conjunto otro);
		
		//hacer la interseccion de dos conjuntos
		Conjunto Interseccion (Conjunto otro);
		
		//mostrar en pantalla los resultados
		void Imprimir();
	};
	
	int main(){
		//declaracion de variables y objetos
		Conjunto conjunto1, conjunto2, unido, interseccion;
		int long1 = 0, long2 = 0, long_union = 0, long_inter = 0;
		vector<int> vector1;
		vector<int> vector2;
		int aux, buscado, insertar, eliminado;
		bool encontrado;
		
		//entrada de datos
		cout << "Introduce el tamanio del primer conjunto: ";
		cin >> long1;
		cout << "Introduce los elementos del primer conjunto: ";
		for (int i=0; i < long1; i++){
			cin >> aux;
			vector1.push_back(aux); 
		}
				
		cout << "Introduce un elemento a buscar en el conjunto: ";
		cin >> buscado;
		
		cout << "Introduce el elemento que desea insertar en el conjunto: ";
		cin >> insertar;
		
		cout << "Introduce el elemento que desea eliminar del conjunto: ";
		cin >> eliminado;
		
		cout << "Introduce el tamanio del conjunto con el que desea realizar la union e interseccion: ";
		cin >> long2;
		cout << "Introduce los elementos del segundo conjunto: ";
		for (int i=0; i < long2; i++){
			cin >> aux;
			vector2.push_back(aux); 
		}
		
		//inicializamos los conjuntos
		conjunto1.Inicializar(long1, vector1);
		conjunto2.Inicializar(long2, vector2);
		
		//computos
		encontrado = conjunto1.EncontrarEntero(buscado);
		conjunto1.InsertarElem(insertar);
		conjunto1.EliminarElem(eliminado);
		unido = conjunto1.Union(conjunto2);
		interseccion = conjunto1.Interseccion(conjunto2);
		
		//salida de datos
		if (encontrado)
			cout << buscado << " esta en el conjunto";
		else
			cout << buscado << " no esta en el conjunto";
		
		cout << "\nEl conjunto con el elemento insertado y eliminado queda como: ";
		conjunto1.Imprimir();
		
		cout << "\nLa union de los dos conjuntos es: ";
		unido.Imprimir();
		
		cout << "\nLa interseccion de los dos conjunto es: ";
		interseccion.Imprimir();
}
		
void Conjunto::Ordena(){
	int candidato, i;
	for (int izda = 1; izda < elementos.size(); izda++) {
		candidato = elementos[izda];

		for (i = izda; i > 0 && candidato < elementos[i-1]; i--)
			elementos[i] = elementos[i-1];

		elementos[i] = candidato;
	}
}

void Conjunto::EliminaRepes(){
	int num_elem = elementos.size();
	int i = 1;
	while (i <= num_elem){
		if (elementos[i] == elementos[i-1]){
			i--;
			for (int j=i; j <= num_elem; j++)
				elementos[j] = elementos[j+1];
				num_elem--;
		}
		i++;
	}
	elementos.resize(num_elem);
}

void Conjunto::Inicializar(int longitud, vector<int> vector){
	for (int i=0; i < longitud; i++)
		elementos.push_back(vector[i]);
	Ordena();
	EliminaRepes();
}

void Conjunto::Imprimir(){
	cout << "{";
	for (int i=0; i < elementos.size(); i++){
		cout << elementos[i];
		if (i < elementos.size()-1)
			cout << ", ";
	}
	cout << "}";
}

bool Conjunto::EncontrarEntero(int buscado){
	int izda = 0, dcha = elementos.size() -1, centro;
	bool encontrado = false;
	
	while (izda <= dcha && !encontrado){
		centro = (izda+dcha)/2;
		if (elementos[centro] == buscado)
			encontrado = true;
		else if (elementos[centro] < buscado)
			izda = centro + 1;
		else
			dcha = centro -1;
	}
	return encontrado;
}

void Conjunto::InsertarElem(int insertar){
	bool esta_en_conjunto = EncontrarEntero(insertar);
	int num_elem = elementos.size();
	int i = num_elem - 1;
	if (!esta_en_conjunto) {
		elementos.resize(num_elem+1);
		while (insertar < elementos[i] && i >= 0) {
			elementos[i + 1] = elementos[i];
			i--;
		}
		elementos[i + 1] = insertar;
		num_elem++;
	}
}

void Conjunto::EliminarElem(int eliminado){
	bool esta_en_conjunto = EncontrarEntero(eliminado);
	int num_elem = elementos.size();
	if (!esta_en_conjunto)
		cout << "\nNo se puede eliminar un elemento que no esta en el conjunto.\n";
	else {
		for (int i = 0; i < num_elem; i++) {
			if (elementos[i] == eliminado)
				for (int j = i; j < num_elem; j++)
					elementos[j] = elementos[j + 1];
		}

		num_elem--;
	}
	elementos.resize(num_elem);
}

Conjunto Conjunto::Union(Conjunto otro){
	Conjunto unido;
	unido.elementos = otro.elementos;
	bool encontrado;
	for (int i=0; i < elementos.size(); i++){
		encontrado = unido.EncontrarEntero(elementos[i]);
		if (!encontrado)
			unido.elementos.push_back(elementos[i]);	
	}
	unido.elementos.shrink_to_fit();
	unido.Ordena();
	return unido;
}

Conjunto Conjunto::Interseccion(Conjunto otro){
	Conjunto interseccion;
	bool esta_en_otro;
	
	for (int i=0; i < elementos.size(); i++){
		esta_en_otro = otro.EncontrarEntero(elementos[i]);
		if (esta_en_otro)
			interseccion.elementos.push_back(elementos[i]);
	}
	interseccion.Ordena();
	return interseccion;
}

