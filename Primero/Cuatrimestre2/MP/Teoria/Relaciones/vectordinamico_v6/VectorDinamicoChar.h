/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VectorDinamicoChar.h
 * Author: acu
 *
 * Created on 24 de marzo de 2020, 15:42
 */

#ifndef VECTORDINAMICOCHAR_H
#define VECTORDINAMICOCHAR_H
#include <iostream>

class VectorDinamicoChar {
    char* arrayChar; // array dinámico de char
    int nCaracteres; // no de caracteres actualmente en el array
    int capacidad;
    
    void inicializar(int n=10);
    void copiar(const VectorDinamicoChar &otro);
public:
    VectorDinamicoChar(int n=10);
    ~VectorDinamicoChar();
    VectorDinamicoChar(const VectorDinamicoChar & otro);
    VectorDinamicoChar& operator=(const VectorDinamicoChar & otro);
    void liberar();
    void leer(std::istream& flujo);
    void mostrar(std::ostream& flujo) const;
    void redimensionar(int incremento);
    void aniadir(char caracter);
    int numeroCaracteres() const;
    char& valor(int pos);
    const char& valor(int pos) const;
    
    friend std::ostream& operator <<(std::ostream & flujo, const VectorDinamicoChar & vector);
    friend std::istream& operator << (std::istream &flujo, VectorDinamicoChar &vector);

};

    std::ostream& operator <<(std::ostream & flujo, const VectorDinamicoChar & vector);
    std::istream& operator << (std::istream &flujo, VectorDinamicoChar &vector);


#endif /* VECTORDINAMICOCHAR_H */

