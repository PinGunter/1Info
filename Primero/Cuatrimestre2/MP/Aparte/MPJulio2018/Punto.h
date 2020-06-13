/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Punto.h
 * Author: salva
 *
 * Created on 13 de junio de 2020, 19:55
 */

#ifndef PUNTO_H
#define PUNTO_H
#include <iostream>
#include <cmath>
class Punto{
private:
    double x;
    double y;
public:
    Punto();
    double getX() const;
    double getY() const;
    double getDistancia(const Punto & punto) const;
    void setXY(double newX, double newY);
    friend std::ostream & operator<<(std::ostream & os, const Punto & punto);
    friend std::istream & operator>>(std::istream & is, Punto & punto);
};
std::ostream & operator<<(std::ostream & os, const Punto & punto);
std::istream & operator>>(std::istream & is, Punto & punto);


#endif /* PUNTO_H */

