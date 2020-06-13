/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>

#include "Cluster.h"

using namespace std;

Punto Cluster::getCentroide() const{
    return centroide;
}

Punto Cluster::getPunto(int n) const{
    assert(n >= 0 && n < puntos.size());
    return puntos.getPunto(n);
}

void Cluster::setCentroide(const Punto& punto){
    centroide.setXY(punto.getX(),punto.getY());
}

int Cluster::size() const{
    return puntos.size();
}

void Cluster::add(const Punto& otro){
    puntos.add(otro);
}

std::ostream & operator<<(std::ostream & os, const Cluster & cluster){
    os << cluster.centroide.getX() << " " << cluster.centroide.getY() << std::endl;
    os << cluster.puntos;
    return os;
}

std::istream & operator>>(std::istream &is, Cluster & cluster){
    double ix,iy;
    is >> ix >> iy;
    if (is){
        Punto aux;
        aux.setXY(ix,iy);
        cluster.setCentroide(aux);
        is >> cluster.puntos;  
    }else {
        std::cerr << "error leyendo cluster " << std::endl;
    }
    return is;
}

void Cluster::calcularCentroide(){
    double cord_x = 0.0, cord_y = 0.0;
    for (int i=0; i < puntos.size(); i++){
        cord_x += puntos[i].getX();
        cord_y += puntos[i].getY();
    }
    cord_x /= puntos.size();
    cord_y /= puntos.size();
    centroide.setXY(cord_x,cord_y);
}