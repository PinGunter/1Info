/* 
 * File:   Cliente.cpp
 * Author: Salvador Romero Cortés
 * 
 * Created on 11 de junio de 2020, 19:17
 */
#include <string>
#include <iostream>

#include "Cliente.h"

using namespace std;


int Cliente::getIdCliente() const{
    return idCliente;
}

double Cliente::getDescuento() const{
    return descuento;
}

std::string Cliente::getNombre() const{
    return nombre;
}

string Cliente::getNIF() const {
    return NIF;
}

std::string Cliente::toString() const {
    string cadena = to_string(idCliente) + " " + to_string(descuento) + " " + 
            nombre + " " + NIF;
    return cadena;
}

Cliente::Cliente(){
    idCliente = 0;
    descuento = 0.0;
    nombre = "";
    NIF = "";
}