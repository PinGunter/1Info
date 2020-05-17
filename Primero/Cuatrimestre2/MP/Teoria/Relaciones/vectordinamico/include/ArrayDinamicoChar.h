#ifndef VECTORDINAMICOCHAR_H
#define VECTORDINAMICOCHAR_H
#include <iostream>
void inicializar(char * &array, int &nchar);

void liberar(char * &array, int &nchar);

void mostrar (std::ostream  &flujo, char * array, int nchar);

void redimensionar (char * &array, int &nchar, int aumento);

void aniadir (char * &array, int &nchar, char caracter);

void leer(std::istream& flujo, char* &array, int& nchar);
#endif
