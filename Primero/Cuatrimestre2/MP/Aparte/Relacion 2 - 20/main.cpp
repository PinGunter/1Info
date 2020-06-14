#include <iostream>
#include "Lista.h"

using namespace std;

int main()
{
	double array[] = { 1,2,3,4,5,6,7,8,9,10 };
	Lista lista;

	for (int i = 0; i < 10; i++)
	{
		lista.aniadir(array[i]);
	}
	cout << "Lista: " << endl;
	lista.imprimir();

	lista.eliminarUltimo();
	cout << "Lista despues de eliminarFinal(): " << endl;
	lista.imprimir();

	Celda* pos = lista.getCelda(2);
	lista.eliminar(pos);
	cout << "Lista despues de eliminar posición 2: " << endl;
	lista.imprimir();

	pos = lista.getCelda(0);
	lista.eliminar(pos);
	cout << "Lista despues de eliminar posición 0: " << endl;
	lista.imprimir();

	pos = lista.getCelda(0);
	lista.insertarTras(pos, 3);
	cout << "Lista despues de insertar 3 en posición siguiente a 0: " << endl;
	lista.imprimir();

	lista.insertarTras(0, 1);
	cout << "Lista despues de insertar 1 al principio: " << endl;
	lista.imprimir();

	lista.liberar();
}