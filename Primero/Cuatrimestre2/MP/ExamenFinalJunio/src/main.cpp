/* 
 * File:   main.cpp
 * Author: Salvador Romero Cortés
 *
 * Created on 11 de junio de 2020, 19:16
 */

#include <iostream>
#include "Cliente.h"
#include "Clientes.h"
#include "Venta.h"
#include "Ventas.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2){
        cerr << "no se han proporcionado ficheros de venta. Saliendo... " << endl;
        return 1;
    }
    //hacemos un vector de Ventas y vamos añadiendo cada una al vector
    int n_ventas = argc-1;
    Ventas * ventas = new Ventas[n_ventas];
    Ventas * mejor;
    string mejor_fich;  
    
    for (int i=0; i < argc-1; i++){
        ventas[i] = Ventas(argv[i+1]);
    }
    mejor = &ventas[0];
    //vemos cual de los ficheros de Ventas tiene mejor media

    
    for (int i = 0; i < n_ventas; i++){
        if (ventas[i] > (*mejor)){
            mejor = &ventas[i];
            mejor_fich = argv[i+1];
        }
    }
    
    //mostramos el valor de la mejor Ventas
    cout << "El fichero que contiene las mejores ventas es el fichero: " << mejor_fich << endl;
    cout << "El valor de la venta media del fichero es " << (*mejor).getVentaMedia() << endl;
    
    //ahora comprobamos cuales del resto de ficheros tienen las mismas medias
    for (int i=0; i < n_ventas; i++)
        if (ventas[i] == (*mejor) && mejor != &ventas[i])
            cout << "El fichero " << argv[i+1] << " tambíen tiene la misma venta media que el mejor." << endl;
    
    
    delete [] ventas;
    return 0;
}

