#ifndef REDCIUDADES_H
#define REDCIUDADES_H
#include <iostream>
#include <cassert>
#include <fstream>
struct InfoCiudad{
    char * nombre;
    int poblacion;
};

class RedCiudades{
private:
    int num_ciudades;
    InfoCiudad * info;
    double **distancia;
    void reservarMemoria(int n=0);
    void liberar();
    void copiar(const RedCiudades &otro);
public:
    int NumCiudades() const;
    double Distancia(int ciudad1, int ciudad2) const;
    char * NombreCiudad(int indice) const;
    int PoblacionCiudad(int indice) const;
    
    RedCiudades();
    ~RedCiudades();
    bool EstaVacia() const;
    RedCiudades(const RedCiudades & otro);
    RedCiudades & operator=(const RedCiudades & otro);
    friend std::ostream & operator<< (std::ostream & os, const RedCiudades & red);
    friend std::istream & operator>>(std::istream & is, RedCiudades & red);
    RedCiudades(std::string archivo);
    bool LeerRedCiudades(std::string archivo);
    bool EscribirCiudades(std::string archivo) const;
    int CiudadMejorConectada() const;
    int MejorEscalaEntre(int i,int j) const;
};

std::ostream & operator<< (std::ostream & os, const RedCiudades & red);
std::istream & operator>>(std::istream & is, RedCiudades & red);
int estaEn(double n, double *lista, int tam);
#endif //RedCiudades
