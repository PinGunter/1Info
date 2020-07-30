/* 
 * File:   Cliente.h
 * Author: Salvador Romero Cortés
 *
 * Created on 11 de junio de 2020, 19:17
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
public:
    /**
     * Devuelve el identificador de cliente
     * @return el identificador de cliente
     */
    int getIdCliente() const;
    
    /**
     * Devuelve el descuento que se aplica a este cliente
     * @return el descuento que se aplica a este cliente
     */
    double getDescuento() const;
    
    /**
     * Devuelve el nombre del cliente
     * @return el nombre del cliente
     */
    std::string getNombre() const;
    
    /**
     * Devuelve el NIF del cliente
     * @return el NIF del cliente
     */
    std::string getNIF() const;
    
    /**
     * Devuelve una cadena (string) con los datos de este cliente, separados
     * por espacios en blanco
     * @return una cadena (string) con los datos de este cliente, separados
     * por espacios en blanco
     */
    std::string toString() const;
    
    /*
     * constructor sin argumentos. No sería estrictamente necesario porque no hay memoria dinamica
     * pero tampoco queremos que se inicialicen los datos a datos basura, así que lo implemento.
     */
    Cliente();
    
    /* el destructor no es necesario puesto que no manejamos memoria dinamica en esta clase */

    /* el constructor de copia y el operador de asignacion no son estrictamente necesarios puesto 
     que no hay memoria dinamica y por tanto el que hace el compilador por defecto está bien*/
    

private:
    int idCliente;
    double descuento;
    std::string nombre;
    std::string NIF;
};

#endif /* CLIENTE_H */

