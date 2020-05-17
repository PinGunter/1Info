//Vector dinamico V1

#include <iostream>
#include <fstream> // ifstream
#include "ArrayDinamicoChar.h"
using namespace std;

int main(int argc, char* argv[])
{
        VectorDinamicoChar arraychar;
	inicializar(arraychar);
	
	if (argc==1) //en este caso no hay argumentos
		leer(cin, arraychar);
	else {		//en este caso si tenemos argumentos en la ejecucion
		ifstream flujo;
                flujo.open(argv[1]);
			
		if (!flujo) {
			cerr << "Error: Fichero " << argv[1] << " no v�alido." << endl;
			return 1;
		}
		
		leer(flujo, arraychar);
                flujo.close();
	}
	mostrar(cout, arraychar);
	liberar(arraychar); // Libera la memoria din�amica reservada
}
