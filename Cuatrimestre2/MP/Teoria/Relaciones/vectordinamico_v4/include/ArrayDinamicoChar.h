#ifndef VECTORDINAMICOCHAR_H
#define VECTORDINAMICOCHAR_H
#include <iostream>

class VectorDinamicoChar{
private:
    char *arrayChar;
    int nCaracteres;
    int capacidad;
    
    void inicializar();
public:
    VectorDinamicoChar();

    void liberar();

    void mostrar (std::ostream  &flujo) const;

    void redimensionar (int aumento);

    void aniadir (char caracter);

    void leer(std::istream& flujo);
};


#endif
