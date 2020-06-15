/* 
 * File:   Venta.h
 * Author: Salvador Romero Cortés
 *
 * Created on 11 de junio de 2020, 20:57
 */

#ifndef VENTA_H
#define VENTA_H

#include <string>

class Venta {
public:

    /**
     * Constructor que crea un objeto Venta leyendo los datos de la cadana (string=
     * proporcionada. Se supone que la cadena contiene los datos de la siguiente
     * forma: idCliente idProducto total
     * @param linea cadena de caracteres (string) que contiene los datos a 
     * partir de los que se va a construir el objeto Venta
     */
    Venta(const std::string &linea);

    /**
     * Devuelve el identificador del cliente de esta venta
     * @return el identificador del cliente de esta venta
     */
    int getIdCliente() const;

    /**
     * Devuelve el identificador del producto de esta venta
     * @return el identificador del producto de esta venta
     */
    int getIdProducto() const;

    /**
     * Devuelve el total del importe de esta venta
     * @return el total del importe de esta venta
     */
    double getTotal() const;

    /**
     * necesario puesto que ya hay otro constructor con argumentos. Debido a esto el compilador no crea
     * un constructor de oficio. Si no existiera el otro no sería necesario porque no tiene memoria dinamica
     */
    Venta();

    /* el destructor no es necesario puesto que no manejamos memoria dinamica en esta clase */

    /* el constructor de copia y el operador de asignacion no son estrictamente necesarios puesto 
    que no hay memoria dinamica y por tanto el que hace el compilador por defecto está bien*/
    
private:
    int idCliente;
    int idProducto;
    double total;
};

#endif /* VENTA_H */

