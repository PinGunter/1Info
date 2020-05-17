/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <cassert>

#include "VectorDinamicoChar.h"

void VectorDinamicoChar::inicializar(int n) {
    this->capacidad = n;
    this->arrayChar = new char[capacidad];
    this->nCaracteres = 0;
}

VectorDinamicoChar::VectorDinamicoChar(int n) {
    assert(n>0);
    inicializar(n);
}
VectorDinamicoChar::~VectorDinamicoChar(){
    delete [] arrayChar;
}

VectorDinamicoChar::VectorDinamicoChar(const VectorDinamicoChar & otro){
    copiar(otro);
}
void VectorDinamicoChar::copiar(const VectorDinamicoChar& otro){
    inicializar(otro.capacidad);
    nCaracteres = otro.nCaracteres;
    for (int i=0; i < nCaracteres; i++){
        arrayChar[i] = (otro.arrayChar)[i];
    }
}
VectorDinamicoChar& VectorDinamicoChar::operator =(const VectorDinamicoChar& otro){
    if (this != &otro){
        delete [] arrayChar;
        copiar(otro);
    }
    return *this;
}

void VectorDinamicoChar::liberar() {
    if (arrayChar != nullptr) {
        delete[] arrayChar;
        arrayChar = nullptr;
    }
    nCaracteres = 0;
    capacidad = 0;
}

void VectorDinamicoChar::leer(std::istream& flujo) {
    char caracter;
    liberar();
    inicializar();
    while (flujo.get(caracter)) {
        aniadir(caracter);
    }
}

void VectorDinamicoChar::mostrar(std::ostream& flujo) const {
    for (int i = 0; i < nCaracteres; i++) {
        flujo << arrayChar[i];
    }
}

void VectorDinamicoChar::redimensionar(int incremento) {
    if (nCaracteres + incremento > 0) {
        char* nuevoArray = new char[nCaracteres + incremento];
        for (int i = 0; (i < nCaracteres) &&
                (i < nCaracteres + incremento); i++) {
            nuevoArray[i] = arrayChar[i];
        }
        delete[] arrayChar;
        arrayChar = nuevoArray;
        capacidad += incremento; //nchar = nchar + incremento;
    }
}

void VectorDinamicoChar::aniadir(char caracter) {
    //redimensionar(arraychar, capacidad * 2);
    if (capacidad == nCaracteres) {
        char* nuevoArray = new char[capacidad * 2];
        for (int i = 0; (i < nCaracteres); i++) {
            nuevoArray[i] = arrayChar[i];
        }
        delete[] arrayChar;
        arrayChar = nuevoArray;
        capacidad *= 2;
    }
    arrayChar[nCaracteres] = caracter;
    nCaracteres++;
}

int VectorDinamicoChar::numeroCaracteres() const {
    return nCaracteres;
}

char& VectorDinamicoChar::valor(int pos) {
    assert(pos>=0 && pos<nCaracteres);
    return arrayChar[pos];
}

const char& VectorDinamicoChar::valor(int pos) const {
    assert(pos>=0 && pos<nCaracteres);
    return arrayChar[pos];
}

std::ostream& operator <<(std::ostream & flujo, const VectorDinamicoChar & vector){
    for (int i=0; i < vector.nCaracteres; i++){
        flujo << vector.arrayChar[i]; //flujo << vector.valor(i);
    }
    
    return flujo;
}

std::istream& operator << (std::istream &flujo, VectorDinamicoChar &vector){
    char caracter;
    vector.liberar();
    vector.inicializar();
    while (flujo.get(caracter)){
        vector.aniadir(caracter);
    }
    return flujo;
}
