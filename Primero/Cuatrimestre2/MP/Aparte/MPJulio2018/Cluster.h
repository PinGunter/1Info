/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cluster.h
 * Author: salva
 *
 * Created on 13 de junio de 2020, 19:55
 */

#ifndef CLUSTER_H
#define CLUSTER_H
#include "VectorPuntos.h"
#include <cassert>
class Cluster{
private:
    Punto centroide;
    VectorPuntos puntos;
public:
    Punto getCentroide() const;
    Punto getPunto(int n) const;
    int size() const;
    
    void setCentroide(const Punto& punto);
    void add(const Punto &otro);
    void calcularCentroide();
    
    friend std::ostream & operator<<(std::ostream & os, const Cluster & cluster);
    friend std::istream & operator>>(std::istream &is, Cluster & cluster);
};
std::ostream & operator<<(std::ostream & os, const Cluster & cluster);
std::istream & operator>>(std::istream &is, Cluster & cluster);


#endif /* CLUSTER_H */

