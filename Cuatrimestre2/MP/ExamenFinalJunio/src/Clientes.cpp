/* 
 * File:   Clientes.cpp
 * Author: Salvador Romero Cortés
 * 
 * Created on 11 de junio de 2020, 19:20
 */

#include "Clientes.h"
#include "Cliente.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Cliente& Clientes::operator[](int n) {
    return losClientes[n];

}

const Cliente& Clientes::operator[](int n) const {
    return losClientes[n];
}

int Clientes::getNumeroClientes() const {
    return numClientes;
};

void Clientes::reservarMemoria(int n) {
    if (n > 0) {
        losClientes = new Cliente[n];
        numClientes = n;
    } else {
        losClientes = nullptr;
        numClientes = 0;
    }
}

void Clientes::liberar() {
    if (losClientes != nullptr)
        delete [] losClientes;
    losClientes = nullptr;
    numClientes = 0;
}

Clientes::Clientes() {
    reservarMemoria();
}

Clientes::~Clientes() {
    liberar();
}

void Clientes::copiar(const Clientes& otro) {
    numClientes = otro.numClientes;
    for (int i = 0; i < numClientes; i++)
        losClientes[i] = otro.losClientes[i];

}

Clientes & Clientes::operator=(const Clientes& otro) {
    if (this != &otro) {
        liberar();
        reservarMemoria(otro.numClientes);
        copiar(otro);
    }
    return *this;
}

Clientes::Clientes(const Clientes& otro) {
    reservarMemoria(otro.numClientes);
    copiar(otro);
}

void Clientes::redimensionar(int n) {
    Cliente * nuevo = new Cliente [n];
    for (int i = 0; i < n && i < numClientes; i++)
        nuevo[i] = losClientes[i];
    delete [] losClientes;
    losClientes = nuevo;
    numClientes = n;
}

Cliente & Clientes::operator+=(const Cliente& otro) {
    if (!estaCliente(otro)) {
        redimensionar(numClientes + 1);
        losClientes[numClientes - 1] = otro;
    }
    return *this->losClientes;
}

bool Clientes::estaCliente(const Cliente& nuevo) {
    bool esta = false;
    for (int i = 0; i < numClientes && !esta; i++) {
        if (nuevo.getNIF() == losClientes[i].getNIF())
            esta = true;
    }
    return esta;
}

Clientes operator+(const Clientes & uno, const Clientes & otro){
    Clientes nuevo(uno);
    for (int i=0; i < nuevo.getNumeroClientes(); i++){
        if (!nuevo.estaCliente(otro[i]))
            nuevo+= otro[i];
    }
    return nuevo;
}

std::ostream & operator<<(std::ostream & os, const Clientes & clientes){
    for (int i=0; i < clientes.getNumeroClientes(); i++){
        os << clientes[i].toString() << std::endl;
    }
    
    return os;
}

void Clientes::escribirClientes(const std::string& nombre) const{
    ofstream fichero(nombre);
    fichero << "FICHEROCLIENTES" << endl;
    fichero << (*this);
}

