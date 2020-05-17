/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "Point2D.h"
using namespace std;

 Point2D::Point2D() {
        px = py = 0;
    }
 
Point2D::Point2D(int x, int y) {
        px = x;
        py = y;
    }

void Point2D::setX(int px) {
        this->px = px;
    }

void Point2D::setY(int py) {
        this->py = py;
    }

int Point2D::getX() const {
        return px;
    }

int Point2D::getY() const {
        return py;
    }

void Point2D::read() {
        cin >> px >> py;
    }

void Point2D::print() const {
        cout << "("<<px << "," << py<<")";
    }

