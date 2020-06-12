#ifndef LINEA
#define LINEA
#include "InfoParada.h"
#include <cassert>
#include <iostream>

class Linea {
private:
    int num_paradas;
    InfoParada* paradas;
    void reservarMemoria(int n = 0);
    void redimensionar(int n);
    void liberarMemoria();
    void copiar(const Linea& otro);
public:
    int getNumParadas() const;
    InfoParada& operator[](int indice);
    const InfoParada& operator[](int indice) const;

    Linea();
    Linea(const Linea& otro);
    Linea& operator=(const Linea& otro);
    InfoParada& operator+=(const InfoParada& otro);

    friend std::ostream& operator<<(std::ostream& os, const Linea& linea);
    friend std::istream& operator>>(std::istream& is, Linea& linea);
    int estaParada(const InfoParada & parada);

};

std::ostream& operator<<(std::ostream& os, const Linea& linea);
std::istream& operator>>(std::istream& is, Linea& linea);
#endif // !LINEA
