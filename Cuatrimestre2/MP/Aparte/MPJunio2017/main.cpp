#include "RedCiudades.h"
#include <iostream>

using namespace std;

int main(int argc, char * args[]) {
    if (argc != 2) {
        cerr << "error de argumentos" << endl;
        return 1;
    }
    RedCiudades red(args[1]);
    for (int i = 1; i <= red.NumCiudades(); i++) {
        for (int j = 1; j <= red.NumCiudades(); j++)
            cout << red.Distancia(i, j) << " ";
        cout << endl;
    }
    for (int i = 1; i <= red.NumCiudades(); i++) {
        for (int j = 1; j <= red.NumCiudades(); j++) {
            if (red.Distancia(i, j) == 0) {
                if (red.MejorEscalaEntre(i, j) != -1)
                    cout << "La mejor escala entre la ciudad " << i << " y la ciudad " << j << " es la ciudad " << red.MejorEscalaEntre(i, j) << endl;
                //                } else{
                //                    cout << "No hay escala entre la ciudad " << i << " y la ciudad " << j << endl;
                //                }
            }
        }
    }
    // cout << red;
}