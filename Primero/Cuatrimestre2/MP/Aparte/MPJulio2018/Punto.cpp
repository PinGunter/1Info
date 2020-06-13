/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Punto.h"
using namespace std;

Punto::Punto(){
    x = y = 0.0;
}

double Punto::getX() const{
    return x;
}

double Punto::getY() const{
    return y;
}

double Punto::getDistancia(const Punto& punto) const{
    double distancia = 0.0;
    distancia = sqrt(pow(x - punto.getX(),2)+pow(y-punto.getY(),2));
    return distancia;
}

void Punto::setXY(double newX, double newY){
    x= newX;
    y = newY;
}

ostream & operator<<(ostream &os, const Punto & punto){
    os << punto.getX() <<  " " << punto.getY() << endl;
    return os;
}

istream & operator>>(istream &is, Punto & punto){
    if (is)
        is >> punto.x >> punto.y;
    else {
        std::cerr << "error leyendo Punto " << std::endl;
    }
    return is;
}