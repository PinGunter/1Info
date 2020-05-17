//Vector dinamico V1

#include <iostream>
#include <fstream> // ifstream
#include "ArrayDinamicoChar.h"
using namespace std;

int main(int argc, char* argv[])
{
        VectorDinamicoChar arraychar;

        if (argc==1) //en este caso no hay argumentos
                arraychar.leer(cin);
        else {		//en este caso si tenemos argumentos en la ejecución
                ifstream flujo;
                flujo.open(argv[1]);

                if (!flujo) {
                        cerr << "Error: Fichero " << argv[1] << " no válido." << endl;
                        return 1;
                }

                arraychar.leer(flujo);
                flujo.close();
        }
        arraychar.mostrar(cout);
        arraychar.liberar(); // Libera la memoria din�amica reservada
}
