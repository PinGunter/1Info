#include <iostream>
#include "InfoParada.h"
#include "Linea.h"
#include "RedMetro.h"

using namespace std;

int main(int argc, char * args[]){
    if (argc != 3){
        cerr << "error de parametros. Se necesitan dos ficheros " << endl;
        return 1;
    }
    
    RedMetro red1(args[1]), red2(args[2]);
    if (red1 > red2){
        cout << "La red 1 es de mejor calidad que la red 2 " << endl;
        cout << "La parada mejor conectada es la parada con id: " << red1.MejorConectada() << endl;
    }
    else if (red1 == red2)        
        cout << "Las redes son de igual calidad" << endl;
    else{
        cout << "La red 2 es de mejor calidad que la red 1" << endl;
        cout << "La parada mejor conectada es la parada con id: " << red2.MejorConectada() << endl;
    }
    
    if (red1.estaTotalmenteOperativa())
        cout << "La red 1 esta completamente operativa" << endl;
    else
        cout << "La red 1 no esta completamente operativa" << endl;
    
    if (red2.estaTotalmenteOperativa())
        cout << "La red 2 esta completamente operativa" << endl;
    else
        cout << "La red 2 no esta completamente operativa" << endl;

    
}