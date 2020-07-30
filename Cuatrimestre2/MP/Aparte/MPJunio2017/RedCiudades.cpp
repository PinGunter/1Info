#include "RedCiudades.h"
#include <cstring>
using namespace std;

int RedCiudades::NumCiudades() const {
    return num_ciudades;
}

double RedCiudades::Distancia(int ciudad1, int ciudad2) const {
    assert(ciudad1 >= 1 && ciudad1 <= num_ciudades && ciudad2 >= 1 && ciudad2 <= num_ciudades);
    return distancia[ciudad1-1][ciudad2-1];
}

char * RedCiudades::NombreCiudad(int indice) const {
    assert(indice >= 0 && indice < num_ciudades);
    return info[indice].nombre;
}

int RedCiudades::PoblacionCiudad(int indice) const {
    assert(indice >= 0 && indice < num_ciudades);
    return info[indice].poblacion;
}

void RedCiudades::reservarMemoria(int n) {
    if (n > 0) {
        num_ciudades = n;
        info = new InfoCiudad[n];
        distancia = new double *[n];
        for (int i = 0; i < n; i++)
            distancia[i] = new double[n];

        for (int i = 0; i < n; i++) {
            info[i].nombre = 0;
            info[i].poblacion = 0;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                distancia[i][j] = 0;
    } else {
        num_ciudades = 0;
        info = nullptr;
        distancia = nullptr;
    }
}

RedCiudades::RedCiudades() {
    reservarMemoria();
}

void RedCiudades::liberar() {
    //liberamos el vector con la info
    if (info != nullptr) {
        for (int i = 0; i < num_ciudades; i++)
            delete [] info[i].nombre;
        delete [] info;

    }
    info = nullptr;
    //liberamos la matrix
    if (distancia != nullptr) {
        for (int i = 0; i < num_ciudades; i++)
            delete [] distancia[i];
        delete [] distancia;
    }
    distancia = nullptr;
    num_ciudades = 0;
}

RedCiudades::~RedCiudades() {
    liberar();
}

bool RedCiudades::EstaVacia() const {
    return num_ciudades == 0;
}

void RedCiudades::copiar(const RedCiudades& otro) {
    num_ciudades = otro.num_ciudades;
    for (int i = 0; i < num_ciudades; i++) {
        info[i].poblacion = otro.info[i].poblacion;
        info[i].nombre = new char [strlen(otro.info[i].nombre + 1)];
        strcpy(info[i].nombre, otro.info[i].nombre);
    }

    for (int i = 0; i < num_ciudades; i++)
        for (int j = 0; j < num_ciudades; i++)
            distancia[i][j] = otro.distancia[i][j];
}

RedCiudades::RedCiudades(const RedCiudades & otro) {
    reservarMemoria(otro.num_ciudades);
    copiar(otro);
}

RedCiudades & RedCiudades::operator=(const RedCiudades& otro) {
    if (this != &otro) {
        liberar();
        reservarMemoria(otro.num_ciudades);
        copiar(otro);
    }
    return *this;
}

ostream & operator<<(ostream & os, const RedCiudades & red) {
    os << red.NumCiudades() << endl;
    for (int i = 0; i < red.NumCiudades(); i++) {
        os << i << " " << red.NombreCiudad(i) << " " << red.PoblacionCiudad(i) << endl;
    }
    //imprimos las distancias
    for (int i = 1; i <= red.NumCiudades(); i++) {
        for (int j = 1; j <= i; j++) {
            if (red.Distancia(i,j) != 0)
            os << i  << " " << j << " " << red.Distancia(i, j) << endl;
        }
    }
    return os;
}

istream & operator>>(istream & is, RedCiudades & red) {
    int nciudades;
    int indice, indice2, poblacion;
    double dist;
    string nombre;
  //  red.liberar();
    if (is) {
        is >> nciudades;
        if (!is) {
            cerr << "error leyendo" << endl;
            exit(1);
        }

        red.reservarMemoria(nciudades);
        //nombres y poblaciones
        for (int i = 0; i < nciudades; i++) {
            is >> indice >> nombre >> poblacion;
            if (is) {
                red.info[indice - 1].nombre = new char [nombre.length() + 1];
                strcpy(red.info[indice - 1].nombre, nombre.c_str());
                red.info[indice - 1].poblacion = poblacion;
            }
        }
        //distancias
        while (is >> indice) {
            is >> indice2;
            is >> dist;
            red.distancia[indice - 1][indice2 - 1] = red.distancia[indice2 - 1][indice - 1] = dist;
        }

    } else {
        cerr << "error leyendo" << endl;
        exit(1);
    }


    return is;
}

RedCiudades::RedCiudades(std::string archivo) {
    if (!LeerRedCiudades(archivo)) {
        cerr << "error leyendo el archivo" << endl;
        exit(1);
    }
}

bool RedCiudades::LeerRedCiudades(std::string archivo) {
    ifstream fichero(archivo);
    if (fichero) {
        string cadena;
        getline(fichero, cadena);
        if (cadena == "RED") {
            fichero >> (*this);
        } else {
            return false;
        }
    } else {
        return false;
    }
    fichero.close();
    return true;
}

bool RedCiudades::EscribirCiudades(std::string archivo)const {
    ofstream fichero(archivo);
    if (fichero) {
        fichero << "RED" << endl;
        fichero << (*this);
    } else {
        cerr << "error con " << archivo << endl;
        return false;
    }
    fichero.close();
    return true;
}

int RedCiudades::CiudadMejorConectada() const {
    int mejor = 0;
    int mayor = 0;
    for (int i = 0; i < num_ciudades; i++) {
        int cont = 0;
        for (int j = 0; j < num_ciudades; j++) {
            if (distancia[i][j] != 0.0)
                cont++;
        }
        if (cont > mayor) {
            mayor = cont;
            mejor = i;
        }
    }

    return mejor;
}

int estaEn(double n, double *lista, int tam) {
    int pos = -1;
    for (int i = 0; i < tam && pos == -1; i++) {
        if (n == lista[i])
            pos = i;
    }
    return pos;
}

int RedCiudades::MejorEscalaEntre(int i, int j) const {
    int indice = -1;
    //primero comprobamos que no haya escala directa
    if (distancia[i-1][j-1] == 0.0 && i != j) {
        double menordist = -1;
        double dist = -1;
        //recorremos la matriz en vertical y comprobamos que haya ciudaddes en comuin
        for (int k = 0; k < num_ciudades; k++) {
            if (distancia[i - 1][k] != 0 && distancia[j - 1][k] != 0) {
                dist = distancia[i - 1][k] + distancia[j - 1][k];

                if (dist < menordist || menordist < 0) {
                    menordist = dist;
                    indice = k;
                }
            }
        }
    }
    indice = (indice == -1) ? -1 : indice+1;
    return indice;
}