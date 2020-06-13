/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "VectorPuntos.h"
using namespace std;

void VectorPuntos::reservar(int n) {
    if (n > 0) {
        puntos = new Punto[n];
        nPuntos = 0;
        reservados = n;
    } else {
        puntos = nullptr;
        nPuntos = 0;
        reservados = 0;
    }
}

void VectorPuntos::copiar(const VectorPuntos& otro) {
    nPuntos = otro.size();
    for (int i = 0; i < nPuntos; i++) {
        puntos[i] = otro.puntos[i];
    }
}

void VectorPuntos::liberar() {
    if (puntos != nullptr)
        delete [] puntos;
    puntos = nullptr;
    nPuntos = 0;
    reservados = 0;
}

void VectorPuntos::redimensionar(int n) {
    if (n > reservados) {
        Punto *nuevo = new Punto[n];
        for (int i = 0; i < nPuntos; i++)
            nuevo[i] = puntos[i];
        delete [] puntos;
        puntos = nuevo;
        nPuntos = n;
    }
}

int VectorPuntos::size() const {
    return nPuntos;
}

Punto VectorPuntos::getPunto(int n) const {
    assert(n >= 0 && n < nPuntos);
    return puntos[n];
}

std::ostream &operator<<(std::ostream & os, const VectorPuntos & vector) {
    os << vector.size() << endl;
    for (int i = 0; i < vector.size(); i++)
        os << vector.puntos[i] << endl;
    return os;
}

std::istream & operator>>(std::istream & is, VectorPuntos & vector) {
    int n;
    is >> n;
    if (is) {
        vector.reservar(n);
        for (int i = 0; i < n; i++) {
            is >> vector.puntos[i];
        }
    }else {
        std::cerr << "error leyendo VectorPuntos " << std::endl;
    }
    return is;
}

VectorPuntos::VectorPuntos() {
    reservar(10);
}

VectorPuntos::VectorPuntos(const VectorPuntos & otro) {
    reservar(otro.reservados);
    copiar(otro);
}

VectorPuntos::~VectorPuntos() {
    liberar();
}

VectorPuntos & VectorPuntos::operator=(const VectorPuntos & otro) {
    if (this != &otro) {
        liberar();
        reservar(otro.reservados);
        copiar(otro);
    }
}

void VectorPuntos::add(const Punto& otro) {
    if (reservados <= nPuntos + 1) {
        redimensionar(reservados * 2);
    }
    puntos[nPuntos] = otro;
    nPuntos++;
}

Punto & VectorPuntos::operator[](int n) {
    assert(n >= 0 && n < nPuntos);
    return puntos[n];
}

const Punto & VectorPuntos::operator[](int n) const {
    assert(n >= 0 && n < nPuntos);
    return puntos[n];
}

