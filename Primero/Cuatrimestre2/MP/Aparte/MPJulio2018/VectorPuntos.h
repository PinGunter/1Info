/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VectorPuntos.h
 * Author: salva
 *
 * Created on 13 de junio de 2020, 19:55
 */

#ifndef VECTORPUNTOS_H
#define VECTORPUNTOS_H
#include "Punto.h"
#include <iostream>
#include <cassert>
class VectorPuntos{
private:
    Punto *puntos;
    int nPuntos;
    int reservados;
    void reservar(int n=0);
    void liberar();
    void copiar(const VectorPuntos &otro);
    void redimensionar(int n);
public:
    VectorPuntos();
    VectorPuntos(const VectorPuntos & otro);
    ~VectorPuntos();
    VectorPuntos & operator=(const VectorPuntos & otro);
    Punto & operator[](int n);
    const Punto & operator[](int n) const;
 
    
    
    void add(const Punto& otro);
    int size() const;
    Punto getPunto(int n) const;
    friend std::ostream &operator<<(std::ostream & os, const VectorPuntos & vector);
    friend std::istream & operator>>(std::istream & is, VectorPuntos & vector);
    friend class Cluster;
};

std::ostream &operator<<(std::ostream & os, const VectorPuntos & vector);
std::istream & operator>>(std::istream & is, VectorPuntos & vector);

#endif /* VECTORPUNTOS_H */

