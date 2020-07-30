/* 
 * File:   Ventas.h
 * Author: Salvador Romero Cortés
 *
 * Created on 11 de junio de 2020, 20:58
 */

#ifndef VENTAS_H
#define VENTAS_H

#include "Venta.h"
#include <iostream>
#include <fstream>

class Ventas {
public:
    /* constructor sin argumentos. Es necesario puesto que tenemos memoria dinamica 
     * y debemos manejar el contenido de esta*/
    Ventas();
    
    ~Ventas();
    
    Ventas(const Ventas & otro);
    Ventas & operator=(const Ventas & otro);
    Venta & operator+= (const Venta & otro);
    friend std::istream & operator>>(std::istream &is, Ventas & ventas);
    Ventas(std::string archivo);
    double getVentaMedia() const;
private:
    void redimensionar(int n);
    void copiar(const Ventas & otro);
    void reservarMemoria(int n=0);
    void liberar();
    int numVentas;
    Venta *lasVentas;
};
std::istream & operator>>(std::istream &is, Ventas & ventas);
bool operator>(const Ventas & uno, const Ventas & otro);
bool operator==(const Ventas & uno, const Ventas & otro);

#endif /* VENTAS_H */

