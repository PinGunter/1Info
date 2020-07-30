#include <iostream>

using namespace std;

struct Vector {
	int limite;
	char array[100];
};

Vector Copia(Vector array);

Vector Ascendente(Vector array);

Vector Descendente(Vector array);

Vector Reverse(Vector array);

void Imprimir(Vector array);

int BusquedaNormal(Vector array, int buscado);

int BusquedaBinaria(Vector array, int buscado);

Vector Insertar(Vector array, int insertado, int posicion);

Vector InsertarOrdenado(Vector array, int insertado);

Vector EliminarPosicion(Vector array, int posicion);

Vector EliminarElemento(Vector array, int elemento);

Vector EliminarRepetidos(Vector array);




int main() {
	Vector entrada, ascendente, descendente, reverse, insertado, insertado_orden, eliminado_pos, eliminado_elem, eliminado_repes;
	int buscado, insertar, eliminar, posicion;
	cout << "Introduce el tamanio del vector: ";
	cin >> entrada.limite;

	ascendente.limite = descendente.limite = reverse.limite = entrada.limite;

	cout << "Introduce los elementos del vector:\n";
	for (int i = 0; i < entrada.limite; i++)
		cin >> entrada.array[i];

	cout << "Introduce un elemento a buscar, insertar y eliminar. Posicion as well bro: ";
	cin >> buscado >> insertar >> eliminar >> posicion;

	// computos
	ascendente = Ascendente(entrada);
	descendente = Descendente(entrada);
	reverse = Reverse(entrada);
	insertado = Insertar(entrada, insertar,posicion);
	insertado_orden = InsertarOrdenado(entrada, insertar);
	eliminado_pos = EliminarPosicion(entrada, posicion);
	eliminado_elem = EliminarElemento(entrada, eliminar);
	eliminado_repes = EliminarRepetidos(entrada);

	// salida
	Imprimir(ascendente);
	Imprimir(descendente);
	Imprimir(reverse);
	Imprimir(insertado);
	Imprimir(insertado_orden);
	Imprimir(eliminado_elem);
	Imprimir(eliminado_pos);
	Imprimir(eliminado_repes);
	cout << "\nBusqueda normal\n";
	if (BusquedaNormal(entrada, buscado) != -1)
		cout << "Se ha encontrado en la posicion " << BusquedaNormal(entrada, buscado) + 1;
	else
		cout << "No se ha encontrado.";

	cout << "\nBusqueda binaria\n";
	if (BusquedaBinaria(entrada, buscado) != -1)
		cout << "Se ha encontrado en la posicion " << BusquedaBinaria(entrada, buscado) + 1;
	else
		cout << "No se ha encontrado.";

}

Vector Copia(Vector array) {
	Vector copia;
	copia.limite = array.limite;
	for (int i = 0; i < array.limite; i++)
		copia.array[i] = array.array[i];

	return copia;
}

Vector Ascendente(Vector array) {
	Vector ascendente = Copia(array);
	int j;
	int a_desplazar;
	for (int i = 1; i < ascendente.limite; i++) {
		a_desplazar = ascendente.array[i];

		for (j = i; j > 0 && a_desplazar < ascendente.array[j - 1]; j--)
			ascendente.array[j] = ascendente.array[j - 1];

		ascendente.array[j] = a_desplazar;
	}

	return ascendente;
}

Vector Descendente(Vector array) {
	Vector descendente = Copia(array);

	int j;
	int a_desplazar;
	for (int i = 1; i < descendente.limite; i++) {
		a_desplazar = descendente.array[i];
		for (j = i; j > 0 && a_desplazar > descendente.array[j - 1]; j--)
			descendente.array[j] = descendente.array[j - 1];

		descendente.array[j] = a_desplazar;
	}
	return descendente;
}

Vector Reverse(Vector array) {
	Vector reverse = Copia(array);
	int aux;

	for (int i = 0; i < reverse.limite / 2; i++) {
		aux = reverse.array[i];
		reverse.array[i] = reverse.array[reverse.limite - i - 1];
		reverse.array[reverse.limite - i - 1] = aux;
	}
	return reverse;
}

void Imprimir(Vector array) {
	for (int i = 0; i < array.limite; i++)
		cout << array.array[i] << " ";
	cout << "\n";
}


int BusquedaNormal(Vector array, int buscado) {
	int posicion = -1;
	for (int i = 0; i < array.limite; i++)
		if (array.array[i] == buscado)
			posicion = i;
	return posicion;
}

int BusquedaBinaria(Vector array, int buscado) {
	Vector aux = Ascendente(array);
	array = Copia(aux);
	int izda = 0, dcha = array.limite - 1, centro;
	int posicion = -1;
	bool encontrado = false;
	while (izda <= dcha && !encontrado) {
		centro = (izda + dcha) / 2;
		if (array.array[centro] == buscado) {
			posicion = centro;
			encontrado = true;
		}
		else if (array.array[centro] < buscado)
			izda = centro + 1;
		else
			dcha = centro - 1;

	}
	return posicion;
}

Vector Insertar(Vector array, int insertar, int posicion) {
	Vector insertado = Copia(array);
	for (int i = insertado.limite; i > posicion; i--)
		insertado.array[i] = insertado.array[i - 1];
	insertado.array[posicion] = insertar;
	insertado.limite++;
	return insertado;
}

Vector InsertarOrdenado(Vector array, int insertar) {
	bool insert = false;
	Vector insertado = Ascendente(array);
	for (int i = 0; i <= insertado.limite && !insert ; i++)
		if (insertar < insertado.array[i]|| i == insertado.limite) {
			for (int j = insertado.limite; j > i; j--)
				insertado.array[j] = insertado.array[j - 1];
			insertado.array[i] = insertar;
			insert = true;
		}
	insertado.limite++;
	return insertado;
}


Vector EliminarPosicion(Vector array, int posicion) {
	Vector eliminado = Copia(array);
	for (int i = posicion; i < eliminado.limite; i++)
		eliminado.array[i] = eliminado.array[i + 1];
	eliminado.limite--;
	return eliminado;
}

Vector EliminarElemento(Vector array, int elemento) {
	Vector eliminado = Copia(array);
	for (int i = 0; i < eliminado.limite; i++)
		if (eliminado.array[i] == elemento)
			eliminado = EliminarPosicion(eliminado,i);
	return eliminado;
}

Vector EliminarRepetidos(Vector array) {
	Vector eliminado = Ascendente(array);
	int i = 1;
	while (i <= eliminado.limite){
		if (eliminado.array[i] == eliminado.array[i - 1]) {
			i--;
			for (int j = i; j <= eliminado.limite; j++)
				eliminado.array[j] = eliminado.array[j + 1];
				eliminado.limite--;
		}
		i++;
	}
	return eliminado;
}

int VectorDentroDeOtro(Vector dentro, Vector otro){
	int posicion = -1;
	bool va_coincidiendo;
	bool encontrado = false;
	for (int i=0; i <= dentro.limite + otro.limite; i++){
		va_coincidiendo = true;
		for (int j = 0; j < dentro.limite; j++)
			va_coincidiendo = dentro.array[i+j] == otro.array[j];

		if (va_coincidiendo){
			encontrado = true;
			posicion = i;
		}
	}
}
