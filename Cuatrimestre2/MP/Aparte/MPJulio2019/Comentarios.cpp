#include "Comentarios.h"

/* Ya implementadas */
Comentarios::Comentarios(const Comentarios & otro) {
    reservarMemoria(otro.numComentarios);
    *this = otro;
}

int Comentarios::getNumComentarios() const {
    return numComentarios;
}

Comentarios & Comentarios::operator=(const Comentarios & otro) {
    if (this != &otro) {
        liberarMemoria();
        reservarMemoria(otro.getNumComentarios());
        for (int i = 0; i < numComentarios; i++)
            losComentarios[i] = otro.losComentarios[i];
    }
    return *this;
}

const std::string& Comentarios::operator[](int index) const { // Se supone implementado
    return losComentarios[index];
}

std::string& Comentarios::operator[](int index) { // Se supone implementado
    return losComentarios[index];
}

void Comentarios::redimensionar(int n) {
    std::string * aux = new std::string [n];
    for (int i = 0; i < numComentarios; i++)
        aux[i] = losComentarios[i];
    delete [] losComentarios;
    losComentarios = aux;
    numComentarios = n;
}

std::istream & operator>>(std::istream & in, Comentarios & c) {
    char primerCaracter;
    int i = 0;

    c.liberarMemoria();
    while (in && (primerCaracter = in.peek()) == '#') {
        c.redimensionar(c.numComentarios + 1);
        getline(in, c[i]); 
        //in >> c[i];
        i++;
    }

    return in;
}

std::ostream & operator<<(std::ostream & out, const Comentarios &c) {
    for (int i = 0; i < c.getNumComentarios(); i++) {
        out << c[i] << std::endl;
    }
    return out;
}

/* implementacin propia */

void Comentarios::reservarMemoria(int n) {
    if (n > 0) {
        numComentarios = n;
        losComentarios = new std::string [n];
    } else {
        numComentarios = 0;
        losComentarios = nullptr;
    }
}

void Comentarios::liberarMemoria() {
    if (losComentarios != nullptr)
        delete [] losComentarios;

    losComentarios = nullptr;
    numComentarios = 0;
}

Comentarios::Comentarios() {
    reservarMemoria(0);
}

Comentarios::~Comentarios() {
    liberarMemoria();
}

Comentarios & Comentarios::operator+=(const std::string& cadena) {
    redimensionar(numComentarios + 1);
    std::string comentario_nuevo = cadena;
    if (comentario_nuevo.length() > 0) {
        if (comentario_nuevo.at(0) != '#')
            comentario_nuevo = '#' + comentario_nuevo;
    } else {
        comentario_nuevo[0] = '#';
    }
    losComentarios[numComentarios - 1] = comentario_nuevo;

    return *this;
}

