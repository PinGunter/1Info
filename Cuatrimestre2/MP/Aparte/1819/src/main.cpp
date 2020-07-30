/**
 * @author Salva Romero
 * @file main.cpp
 * @brief 
 * Universidad de Granada - DGIM
 * Metodología de la Programación 
 * Examen de laboratorio 2018-2019
 * Por favor, rellene las funciones que se indican.
 * Una vez ejecutado el programa y obtenidos los ficheros de salida,
 * ejecute la script validaFicheros.sh para comprobar que la salida es correcta
 * No olvide pasar valgrind.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;


/**
 * @brief Función que analiza la IP del ordenador de prácticas y genera un número
 * entero asociado a ella
 * @return Un número entero obtenido a partir de la IP del ordenador de prácticas;
 */
int findIP();


/**
 * @brief Clase círculo
 */
class Circulo;

/**
 * @brief Clase punto bidimensional
 */
class Punto {
public:
    double _x, _y;
    /**
     * @brief Constructor que inicializa el punto dependiendo de la IP
     * del ordenador en la que se ejecute
     */
    Punto();
    /**
     * Método que calcula si un punto está dentro de un círculo o no
     * @param c El círculo a comprobar
     * @return @retval true si @a p está dentro del círculo, @retval false en otro caso
     */
    bool estaDentro(Circulo c) const;
};

class Circulo {
public:
    Punto _centro;
    double _radio;
};

void LeerFichero(istream &is, Circulo *&lista, int &n);
void Inicializar(Circulo *&lista, int &n,int valor);
void Liberar(Circulo *&lista, int &n);
void Aniadir(Circulo *&lista, int &n, const Circulo nuevo);
void Redimensionar(Circulo *&lista, int &n, int aumento);
void DentroOFuera(Circulo *&lista, int &n_lista, Circulo *&dentro, int &n_dentro, Circulo *&fuera, int &n_fuera,const Punto P);
void EscribirFichero(ostream &os,Circulo * lista, int n);

/**
@brief Imprime el contenido de un vector de Circulo
@param v 	Vector de Circulo
@param n	Número de elementos que contiene @a v
 */
void imprimirVector(Circulo *, int n);

int main() {
    Punto P; /// Punto. Se inicializa automáticamente según la IP del ordenador
    Circulo *Circulos = nullptr, /// Vector de círculos leídos desde el fichero de entrada
            *Dentro = nullptr, /// Vector de círculos que contienen a Punto
            *Fuera = nullptr; /// Vector de círculos que no contienen a Punto
    int nCirculos = 0, /// Número de elementos de Circulos[]
            nDentro = 0, /// Número de elementos de Dentro[]
            nFuera = 0; /// Número de elementos de Fuera[]
    ifstream fCirculos; /// Fichero de entrada
    ofstream fDentro, fFuera; /// Ficheros de salida
    string sCirculos = "data/datos1.dat", /// Nombre del fichero de entrada
            sDentro = "data/salida_" + to_string(findIP() % 10) + ".in", /// Fichero de salida para Dentro[]
            sFuera = "data/salida_" + to_string(findIP() % 10) + ".out"; /// Fichero de salida para Fuera []   
    istream *entrada;
    ostream *salida_dentro;
    ostream *salida_fuera;
    //abrimos el archivo de entrada
    fCirculos.open(sCirculos);
    if (!fCirculos && fCirculos.eof()){
        cerr << "Error abriendo el archivo. Abortando." << endl;
        return 1;
    }else
        entrada = &fCirculos;
    
    //abrimos los archivos de salida
    fDentro.open(sDentro);
    if (!fDentro && fDentro.eof()){
        cerr << "Error abriendo el archivo de salida. Abortando." << endl;
        return 1;
    } else
        salida_dentro = &fDentro;
    
    fFuera.open(sFuera);
    if (!fFuera && fFuera.eof()){
        cerr << "Error abriendo el archivo de salida. Abortando." << endl;
        return 1;
    } else
        salida_fuera = &fFuera;
       
    
    /// Examen: Leer fichero de datos
//    *entrada >> nCirculos;
//    if (nCirculos > 0){
//        Circulos = new Circulo[nCirculos];
//        for (int i=0; i < nCirculos; i++){
//            *entrada >> Circulos[i]._centro._x >> Circulos[i]._centro._y >> Circulos[i]._radio;
//        } 
//    }
    LeerFichero(*entrada,Circulos,nCirculos);
   
    //LeerFichero(*entrada, Circulos, nCirculos);
    /// Examen: Imprimir los datos leídos
    cout << "Circulos leidos: " << endl;
    imprimirVector(Circulos,nCirculos);
    /// Examen: Calcular resultado
//    for (int i=0; i < nCirculos; i++){
//        if (P.estaDentro(Circulos[i]))
//            nDentro++;
//        else
//            nFuera++;
//    }
//    
//    if (nDentro > 0){
//        Dentro = new Circulo[nDentro];
//    }
    DentroOFuera(Circulos,nCirculos,Dentro,nDentro,Fuera,nFuera,P);
    /// Examen: Mostrar resultado
    cout << "Circulos que contienen al punto: " << endl;
    imprimirVector(Dentro,nDentro);
    cout << "Circulos que NO contienen al punto: " << endl;
    imprimirVector(Fuera,nFuera);
    /// Examen: Guardar resultado en disco
    EscribirFichero(*salida_dentro,Dentro,nDentro);
    EscribirFichero(*salida_fuera,Fuera,nFuera);
    /// Examen: Terminación del programa

    fCirculos.close();
    fDentro.close();
    fFuera.close();
    if (Circulos != nullptr){
        delete [] Circulos;
    }
    if (Fuera != nullptr){
        delete [] Fuera;
    }
    if (Dentro != nullptr){
        delete [] Dentro;
    }
       
     
    return 0;
}

void imprimirVector(Circulo *v, int n) {
    if (n > 0 && v != nullptr) {
        cout << n << " elementos" << endl;
        for (int i = 0; i < n; i++)
            cout << "[" << i << "] = (" << v[i]._centro._x << "-" << v[i]._centro._y << ")-" << v[i]._radio << (i % 5 == 4 ? "\n" : "\t\t");
        cout << endl;
    } else
        cerr << "ERROR el vector está vacío" << endl;
}

bool Punto::estaDentro(Circulo c) const {
    return sqrt(pow(_x - c._centro._x, 2) + pow(_y - c._centro._y, 2)) <= c._radio;
}

Punto::Punto() {
    int IP = findIP();
    srand(IP % 10);
    _x = rand() % 20;
    _y = rand() % 20;
    cout << "PUNTO " << _x << "-" << _y << endl;
}

int findIP() {
    ifstream f;
    string name;
    f.open("/etc/hostname");
    f >> name;
    f.close();
    return name[name.length() - 1] - '0';
}

void LeerFichero(istream &is, Circulo * &lista, int &n){
    int n_elem = 0;
    Circulo aux;
    is >> n_elem;
    for (int i=0; i < n_elem; i++){
        is >> aux._centro._x >> aux._centro._y >> aux._radio;
        Aniadir(lista,n,aux);
    }
}


void Inicializar(Circulo *&lista, int &n, int valor){
    lista = nullptr;
    n = valor;
}


//void Liberar(Circulo *lista, int &n){
//    if (lista != nullptr){
//        delete [] lista;
//        Inicializar(lista, n);
//    }
//}

void Aniadir(Circulo *&lista, int &n, Circulo aniadido){
    Circulo * nuevo = new Circulo[n+1];
    //if (lista != nullptr){
        for (int i=0; i < n; i++){
            nuevo[i]._centro._x = lista[i]._centro._x;
            nuevo[i]._centro._y = lista[i]._centro._y;
            nuevo[i]._radio = lista[i]._radio;
        }
        delete [] lista;
        lista = nuevo;
        n += 1;
        lista [n-1] = aniadido;
    //}
}


void DentroOFuera(Circulo *&lista, int &n_lista, Circulo *&dentro, int &n_dentro, Circulo *&fuera, int &n_fuera, const Punto P){
    for (int i=0; i < n_lista; i++){
        if (P.estaDentro(lista[i])){
            Aniadir(dentro,n_dentro,lista[i]);
        }
        else
            Aniadir(fuera,n_fuera,lista[i]);
    }
    
}


void EscribirFichero(ostream &os,Circulo * lista, int n){
    os << n << endl;
    for (int i=0; i < n; i++)
        os << lista[i]._centro._x << " " << lista[i]._centro._y << " " << lista[i]._radio << endl;
}
