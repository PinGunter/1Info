//Vector dinamico V1

#include <iostream>
#include <fstream> // ifstream
#include "ArrayDinamicoChar.h"
using namespace std;
int main(int argc, char* argv[])
{
	char* arraychar;
	int nCaracteres;
	inicializar(arraychar, nCaracteres);
	
	if (argc==1) //en este caso no hay argumentos
		leer(cin, arraychar, nCaracteres);
	else {		//en este caso si tenemos argumentos en la ejecucion
		ifstream flujo;
                flujo.open(argv[1]);
			
		if (!flujo) {
			cerr << "Error: Fichero " << argv[1] << " no v�alido." << endl;
			return 1;
		}
		
		leer(flujo, arraychar, nCaracteres);
                flujo.close();
	}
	mostrar(cout, arraychar, nCaracteres);
	liberar(arraychar, nCaracteres); // Libera la memoria din�amica reservada
}
