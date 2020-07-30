#include "Diccionario.h"
#include <cassert>

using namespace std;

Diccionario::Diccionario() {
    n = 0; 
    lista = nullptr;
}

Diccionario::Diccionario(int entero){
    inicializar(entero);
}

void Diccionario::inicializar(int entero) {
    if (lista != nullptr)
        liberar();
    n = entero;
    lista = new string[entero];
}

void Diccionario::liberar() {
    if (lista != nullptr) {
        delete [] lista;
        lista = nullptr;
    }
    n = 0;
}

void Diccionario::copiar(Diccionario otro) {
    liberar();
    for (int i = 0; i < otro.size(); i++)
        aniadir(otro.get(i));
}

void Diccionario::aniadir(const std::string &palabra) {
    Diccionario aux(size()+1);
    for (int i = 0; i < size(); i++)
        aux.set(get(i), i);
    inicializar(aux.size());
    for (int i = 0; i < aux.size(); i++)
        set(aux.get(i), i);

    set(palabra, size() - 1);
}

void Diccionario::redimensionar(int aumento) {
    Diccionario aux;
    aux.inicializar(size() + aumento);
    aux.copiar((*this));
    inicializar(aux.size() + aumento);
    copiar(aux);
    aux.liberar();
}

void Diccionario::set(const std::string &palabra, int i) {
    assert(i >= 0 && i < size());
    lista[i] = palabra;
}

bool Diccionario::LeerDiccionario(std::istream &is) {
    int n_palabras;
    is >> n_palabras;
    string palabra;
    bool es_palabra = true;
    for (int i=0; i < n_palabras; i++){
        is >> palabra;
        for (int j=0; j < palabra.size(); j++)
            if (!(palabra.at(j) >= 'A' && palabra.at(j) <= 'z') && es_palabra)
                es_palabra = false;
        if (es_palabra)
            aniadir(palabra);
    }
   aMinuscula();
   Ordenar();
   return es_palabra;
}

void Diccionario::Ordenar(){
    int j;
    string movimiento;
    for (int i=1;i < size(); i++){
        movimiento = get(i);
        for (j=i; j > 0 && movimiento < lista[j-1]; j--)
            lista[j] = lista[j-1];
        lista[j] = movimiento;
    }
}

void Diccionario::aMinuscula(){
    for (int i=0; i < size(); i++){
        for (int j=0; j < get(i).size(); j++)
            if (get(i).at(j) >= 'A' && get(i).at(j) <= 'Z')
                lista[i][j] -= 'Z' - 'z';
    }
}

bool Diccionario::HayRepetidos() const{
    bool repetido = false;
    for (int i=0; i < size(); i++){
        for (int j=0; j < size(); j++)
            if (i!=j)
                if (get(i) == get(j))
                    repetido = true;
    }
    return repetido;
}

void Diccionario::CrearDiccionario(std::ostream& os) const{
    for (int i = 0; i < size(); i++){
        os << i+1 << ".- " << get(i) << endl;
    }
}

string Diccionario::get(int p) const{
    assert(p >= 0 && p < size());
    return lista[p];
}