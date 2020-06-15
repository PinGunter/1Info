/* 
 * File:   Ventas.cpp
 * Author: Salvador Romero Cortés
 * 
 * Created on 11 de junio de 2020, 20:58
 */

#include "Ventas.h"

void Ventas::reservarMemoria(int n){
    if (n>0){
        numVentas = n;
        lasVentas = new Venta[n];
    } else {
        numVentas = 0;
        lasVentas = nullptr;
    }
}

void Ventas::liberar(){
    if (lasVentas != nullptr)
        delete [] lasVentas;
    lasVentas = nullptr;
    numVentas = 0;
}

Ventas::Ventas(){
    reservarMemoria();
}

Ventas::~Ventas(){
    liberar();
}

void Ventas::copiar(const Ventas& otro){
    numVentas = otro.numVentas;
    for (int i=0; i < numVentas; i++)
        lasVentas[i] = otro.lasVentas[i];
}

Ventas & Ventas::operator =(const Ventas& otro){
    if (this != &otro){
        liberar();
        reservarMemoria(otro.numVentas);
        copiar(otro);
    }
    
    return *this;
}

Ventas::Ventas(const Ventas& otro){
    reservarMemoria(otro.numVentas);
    copiar(otro);
}

void Ventas::redimensionar(int n){
    Venta *nueva = new Venta[n];
    for (int i=0; i < n && i < numVentas; i++)
        nueva[i] = lasVentas[i];
    liberar();
    lasVentas = nueva;
    numVentas = n;
}

Venta & Ventas::operator +=(const Venta& otro){
    redimensionar(numVentas+1);
    lasVentas[numVentas-1] = otro;
    return *this->lasVentas;
}
std::istream & operator>>(std::istream &is, Ventas & ventas){
    std::string flujoVenta;
    ventas.liberar();
    while (is){
        getline(is,flujoVenta);
        if (is){
            Venta aux(flujoVenta);
            ventas += aux;
        }
    }
    return is;
}

Ventas::Ventas(std::string archivo){
    std::ifstream fichero(archivo);
    std::string cadena;
    reservarMemoria();  //hacemos esto para no tener punteros salvajes
    getline(fichero,cadena);
    if (cadena == "FICHEROVENTAS"){
        fichero >> *this;
    } else {
        std:: cerr << "el fichero: " << archivo << " no contiene cadena magica, valores inicializados por defecto " << std::endl;
    }
}

double Ventas::getVentaMedia() const{
    double media = 0.0;
    for (int i=0; i < numVentas; i++)
        media += lasVentas[i].getTotal();
    media = (media*1.0)/numVentas;
    return media;
}

bool operator>(const Ventas & uno, const Ventas & otro){
    return uno.getVentaMedia() > otro.getVentaMedia();
}

bool operator==(const Ventas & uno, const Ventas & otro){
    return uno.getVentaMedia() == otro.getVentaMedia();
}