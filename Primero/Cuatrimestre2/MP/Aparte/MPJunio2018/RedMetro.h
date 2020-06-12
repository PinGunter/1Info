#ifndef REDMETRO
#define REDMETRO
#include "Linea.h"
#include <cassert>
#include <iostream>

class RedMetro {
private:
    int num_lineas;
    Linea* lineas;
    void crearRedVacia();
    bool estaVacia();
    void liberarMemoria();
    void reservarMemoria(int n);
    void redimensionar(int n);
    void copiar(const RedMetro& otro);

public:
    int getNumLineas() const;
    int getNumeroTotalParadas() const;
    Linea& operator[](int indice);
    const Linea& operator[](int indice) const;

    RedMetro();
    RedMetro(const RedMetro& otro);
    RedMetro(std::string fichero);
    ~RedMetro();
    RedMetro& operator=(const RedMetro& otro);
    Linea& operator+=(const Linea& otro);
    int numParadasActivas() const;
    int MejorConectada() const;
    
    bool estaTotalmenteOperativa();
    friend std::ostream& operator<<(std::ostream &os, RedMetro& red);
    friend std::istream& operator>>(std::istream& is, RedMetro& red);
    friend bool operator==(const RedMetro & uno, const RedMetro & otro);
    friend bool operator!=(const RedMetro & uno, const RedMetro & otro);
    friend bool operator>(const RedMetro & uno, const RedMetro & otro);
    
};

std::ostream& operator<<(std::ostream& os, RedMetro& red);
std::istream& operator>>(std::istream& is, RedMetro& red);
bool operator==(const RedMetro & uno, const RedMetro & otro);
bool operator!=(const RedMetro & uno, const RedMetro & otro);
bool operator>(const RedMetro & uno, const RedMetro & otro);
int estaNumeroEnVector(int numero, int*vector, int tamano);
#endif