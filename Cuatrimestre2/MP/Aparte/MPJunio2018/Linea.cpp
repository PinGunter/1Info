#include "Linea.h"

void Linea::copiar(const Linea& otro) {
    this->num_paradas = otro.num_paradas;
    for (int i = 0; i < num_paradas; i++)
        paradas[i] = otro[i + 1];
}

void Linea::reservarMemoria(int n) {
    if (n > 0) {
        num_paradas = n;
        paradas = new InfoParada[n];
    } else {
        num_paradas = 0;
        paradas = nullptr;
    }
}

void Linea::redimensionar(int n) {
    InfoParada* nueva = new InfoParada[n];
    for (int i = 0; i < num_paradas && i < n; i++)
        nueva[i] = paradas[i];
    delete[] paradas;
    paradas = nueva;
    num_paradas = n;

}

void Linea::liberarMemoria() {
    if (paradas != nullptr)
        delete[] paradas;
    paradas = nullptr;
    num_paradas = 0;
}

int Linea::getNumParadas() const {
    return num_paradas;
}

InfoParada& Linea::operator[](int indice) {
    assert(indice >= 1 && indice <= num_paradas);
    return paradas[indice - 1];
}

const InfoParada& Linea::operator[](int indice) const {
    assert(indice >= 1 && indice <= num_paradas);
    return paradas[indice - 1];
}

Linea::Linea() {
    reservarMemoria();
}

Linea::Linea(const Linea& otro) {
    reservarMemoria(otro.getNumParadas());
    copiar(otro);
}

Linea& Linea::operator=(const Linea& otro) {
    if (this != &otro) {
        liberarMemoria();
        reservarMemoria(otro.getNumParadas());
        for (int i = 0; i < otro.getNumParadas(); i++)
            paradas[i] = otro[i + 1];
    }
    return *this;
}

InfoParada& Linea::operator+=(const InfoParada& otro) {
    redimensionar(getNumParadas() + 1);
    paradas[getNumParadas() - 1] = otro;
    return *this->paradas;
}

std::ostream& operator<<(std::ostream& os, const Linea& linea) {
    os << linea.getNumParadas() << std::endl;
    for (int i = 1; i <= linea.getNumParadas(); i++) {
        char caracter = (linea[i].estaActiva()) ? 'S' : 'N';
        os << i << "\t" << caracter << std::endl;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Linea& linea) {
    int n_paradas;
    is >> n_paradas;
    linea.redimensionar(n_paradas);
    for (int i = 0; i < linea.num_paradas; i++)
        is >> linea.paradas[i];
    return is;
}

int Linea::estaParada(const InfoParada & parada) {
    int posicion = -1;
    for (int i = 0; i < num_paradas && posicion == -1; i++)
        if (paradas[i].getIndice() == parada.getIndice())
            posicion = i;

    return posicion;
}
