/* 
 * File:   Clientes.h
 * Author: Salvador Romero Cortés
 *
 * Created on 11 de junio de 2020, 19:20
 */

#ifndef CLIENTES_H
#define CLIENTES_H

#include "Cliente.h"
#include <iostream>
#include <fstream>

class Clientes {
public:
    /**
     * Versión de devolución por referencia del operador de acceso a un elemento 
     * de la colección de clientes
     * @param n el número de elemento al que se quiere acceder
     * @return el elemento que hay en la posición n (comienza desde la posición 0)
     */
    Cliente& operator[](int n);

    /**
     * Versión de devolución por referencia constante del operador de acceso 
     * a un elemento de la colección de clientes
     * @param n el número de elemento al que se quiere acceder
     * @return el elemento que hay en la posición n (comienza desde la posición 0)
     */
    const Cliente& operator[](int n) const;

    /**
     * Devuelve el número de clientes en la colección
     * @return el número de clientes en la colección
     */
    int getNumeroClientes() const;

    /*
     * Constructor sin argumentos. Es necesario ya que trabajamos con memoria dinamica y tenemos que 
     * controlar el contenido de esta.
     */
    Clientes();

    ~Clientes();

    Clientes(const Clientes & otro);
    Clientes & operator=(const Clientes & otro);
    bool estaCliente(const Cliente & nuevo);
    Cliente & operator+=(const Cliente & otro);
    friend std::ostream & operator<<(std::ostream & os, const Clientes & clientes);
    void escribirClientes(const std::string &nombre) const;
private:
    void redimensionar(int n);
    void copiar(const Clientes & otro);
    void reservarMemoria(int n = 0);
    void liberar();
    int numClientes;
    Cliente *losClientes;
};

Clientes operator+(const Clientes & uno, const Clientes & otro);
std::ostream & operator<<(std::ostream & os, const Clientes & clientes);


#endif /* CLIENTES_H */

