/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Diccionario.h
 * Author: salva
 *
 * Created on 25 de abril de 2020, 18:41
 */

#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include <iostream>
#include <cassert>
#include <string>

class Diccionario{
public:
    std::string * lista;
    int n;
    //gestion de memoria
    void inicializar(int entero);
    void liberar();
    void redimensionar(int aumento);

    
public:
    Diccionario();
    Diccionario(int entero);

    //procesamiento de datos
    bool LeerDiccionario(std::istream &is);
    void CrearDiccionario(std::ostream &os) const;
    void Ordenar();
    void aMinuscula();
    bool HayRepetidos() const;
    
    void aniadir(const std::string &palabra);
    void copiar(Diccionario otro);
    std::string get(int p) const;
    inline int size() const { return n; };
    void set(const std::string & palabra, int i);
};


#endif /* DICCIONARIO_H */

