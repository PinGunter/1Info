#include "RedMetro.h"
#include <fstream>

using namespace std;

void RedMetro::crearRedVacia() {
    lineas = nullptr;
    num_lineas = 0;
}

bool RedMetro::estaVacia() {
    return num_lineas == 0;
}

void RedMetro::liberarMemoria() {
    if (lineas != nullptr)
        delete[] lineas;
    lineas = nullptr;
    num_lineas = 0;
}

void RedMetro::reservarMemoria(int n) {
    if (n > 0) {
        num_lineas = n;
        lineas = new Linea[n];
    } else
        liberarMemoria();
}

void RedMetro::redimensionar(int n) {
    Linea* nueva = new Linea[n];
    for (int i = 0; i < getNumLineas(); i++)
        nueva[i] = lineas[i];
    delete[] lineas;
    lineas = nueva;
    num_lineas = n;
}

int RedMetro::getNumLineas() const {
    return num_lineas;
}

int RedMetro::getNumeroTotalParadas() const {
    int total = 0;
    for (int i = 0; i < num_lineas; i++)
        total += lineas[i].getNumParadas();
    return total;
}

Linea& RedMetro::operator[](int indice) {
    assert(indice >= 1 && indice <= num_lineas);
    return lineas[indice - 1];
}

const Linea& RedMetro::operator[](int indice) const {
    assert(indice >= 1 && indice <= num_lineas);
    return lineas[indice - 1];
}

RedMetro::RedMetro() {
    crearRedVacia();
}

RedMetro::RedMetro(const RedMetro& otro) {
    reservarMemoria(otro.getNumLineas());
    copiar(otro);
}

RedMetro::RedMetro(std::string fichero) {
    ifstream archivo(fichero);
    if (!archivo) {
        cerr << "error abriendo el fichero " << fichero << endl;
        exit(1);
    } else {
        string cadena;
        std::getline(archivo, cadena);
        if (cadena != "METRO") {
            cerr << "error abriendo " << fichero << endl;
            exit(1);
        }
        archivo >> *this;
    }
}

RedMetro& RedMetro::operator=(const RedMetro& otro) {
    if (this != &otro) {
        liberarMemoria();
        reservarMemoria(otro.getNumLineas());
        for (int i = 0; i < getNumLineas(); i++)
            lineas[i] = otro[i + 1];
    }
    return *this;

}

Linea& RedMetro::operator+=(const Linea& otro) {
    redimensionar(getNumLineas() + 1);
    lineas[getNumLineas() - 1] = otro;
    return *this->lineas;
}

RedMetro::~RedMetro() {
    liberarMemoria();
}

void RedMetro::copiar(const RedMetro& otro) {
    num_lineas = otro.getNumLineas();
    for (int i = 0; i < num_lineas; i++) {
        lineas[i] = otro[i + 1];
    }
}

std::ostream& operator<<(std::ostream& os, RedMetro& red) {
    os << red.getNumLineas() << std::endl;
    for (int i = 1; i <= red.getNumLineas(); i++) {
        os << red[i];
    }
    return os;
}

std::istream& operator>>(std::istream& is, RedMetro& red) {
    if (is) {
        int n_lineas;
        is >> n_lineas;
        if (is) {
            red.reservarMemoria(n_lineas);
            for (int i = 0; i < red.num_lineas; i++)
                is >> red.lineas[i];
        }
    }
    return is;
}

bool operator==(const RedMetro & uno, const RedMetro & otro) {
    bool resultado;
    double calidad1, calidad2;
    calidad1 = uno.getNumLineas()*0.3 + uno.numParadasActivas()*0.7;
    calidad2 = otro.getNumLineas()*0.3 + otro.numParadasActivas()*0.7;
    resultado = calidad1 == calidad2;
    return resultado;
}

bool operator!=(const RedMetro & uno, const RedMetro & otro) {
    bool resultado;
    double calidad1, calidad2;
    calidad1 = uno.getNumLineas()*0.3 + uno.numParadasActivas()*0.7;
    calidad2 = otro.getNumLineas()*0.3 + otro.numParadasActivas()*0.7;
    resultado = calidad1 != calidad2;

    return resultado;
}

bool operator>(const RedMetro & uno, const RedMetro & otro) {
    bool resultado;
    double calidad1, calidad2;
    calidad1 = uno.getNumLineas()*0.3 + uno.numParadasActivas()*0.7;
    calidad2 = otro.getNumLineas()*0.3 + otro.numParadasActivas()*0.7;
    resultado = calidad1 > calidad2;
    return resultado;
}

int RedMetro::numParadasActivas() const {
    int activas = 0;
    for (int i = 0; i < getNumLineas(); i++) {
        for (int j = 0; j < lineas[i].getNumParadas(); j++)
            if (lineas[i][j + 1].estaActiva())
                activas++;
    }
    return activas;
}

int RedMetro::MejorConectada() const {
    int *ids = new int [getNumeroTotalParadas()];
    int *fr = new int [getNumeroTotalParadas()];
    int pos = 0;
    int k=0;
    for (int i = 0; i < getNumeroTotalParadas(); i++) {
        ids[i] = fr[i] = 0;
    }

    for (int i = 0; i < num_lineas; i++) {
        for (int j = 0; j < lineas[i].getNumParadas(); j++) {
            pos = estaNumeroEnVector(lineas[i][j + 1].getIndice(), ids, getNumeroTotalParadas());
            if (pos != -1) {
                fr[pos]++;
            } else {
                k = 0;
                while (ids[k] != 0){
                    k++;
                }
                ids[k] = lineas[i][j + 1].getIndice();
                fr[k] = 1;
            }

        }
    }
    int mayor_id = 0, mayor_fr = 0;
    for (int i = 0; i < getNumeroTotalParadas(); i++)
        if (fr[i] > mayor_fr){
            mayor_id = ids[i];
            mayor_fr = fr[i];
        }
    return mayor_id;
}

bool RedMetro::estaTotalmenteOperativa() {
    bool operativa = true;
    for (int i = 0; i < num_lineas && operativa; i++) {
        for (int j = 0; j < lineas[i].getNumParadas() && operativa; j++)
            operativa = lineas[i][j + 1].estaActiva();
    }
    return operativa;
}

int estaNumeroEnVector(int numero, int*vector, int tamano) {
    int pos = -1;
    for (int i = 0; i < tamano && pos == -1; i++)
        if (vector[i] == numero)
            pos = i;
    return pos;
}
