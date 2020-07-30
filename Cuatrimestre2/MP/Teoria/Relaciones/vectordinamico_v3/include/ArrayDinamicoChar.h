#ifndef VECTORDINAMICOCHAR_H
#define VECTORDINAMICOCHAR_H
#include <iostream>

struct VectorDinamicoChar{
    char *arrayChar;
    int nCaracteres;
    int capacidad;
};

void inicializar(VectorDinamicoChar &arraychar);

void liberar(VectorDinamicoChar &arraychar);

void mostrar (std::ostream  &flujo, const VectorDinamicoChar &arraychar);

void redimensionar (VectorDinamicoChar &arraychar, int aumento);

void aniadir (VectorDinamicoChar &arraychar, char caracter);

void leer(std::istream& flujo, VectorDinamicoChar &arraychar);
#endif
