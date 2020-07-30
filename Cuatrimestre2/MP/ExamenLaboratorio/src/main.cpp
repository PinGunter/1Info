/**
 * @file main.cpp
 * @brief Examen de laboratorio 
 * Universidad de Granada
 * Metodología de la Programación 
 * @nombre_del_alumno:  Salvador Romero Cortés
 * 
 * @warning Por favor, rellene las funciones que se indican
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/**
@brief Imprime el contenido de un vector de string
@param v 	Vector de string
@param n	Número de elementos que contiene @a v
 */
void imprimirVector(const string *v, const int n) {
    if (v != nullptr && n > 0) {
        cout << n << " elementos" << endl;
        for (int i = 0; i < n; i++)
            cout << "[" << i << "] = " << v[i] << endl;
    } else
        cerr << "ERROR: Vector de datos vacío" << endl;
}

//funcion que saca el error y cierra el problema
void error(const string & mensaje) {
    cerr << "ERROR: " + mensaje << endl;
    exit(1);
}

//funcion para añadir elementos a un vector dinamico.
/*
 * crea un vector dinamico con el tamaño anterior más uno.
 * copia los elementos que teniamos en el vector
 * liberamos la memoria del original
 * copiamos el auxiliar al nuevo y le añadimos el elemento
 */
void aniadir(string *& lista, int &n, const string &nuevo) {
    string * nuevostr = new string [n + 1];
    for (int i = 0; i < n; i++)
        nuevostr[i] = lista[i];
    delete [] lista;
    n += 1;
    lista = nuevostr;
    lista[n - 1] = nuevo;
}

//funcion para crear un fichero con los datos de un vector
void crearFichero(ostream &os, const string * lista, int n) {
    if (lista != nullptr) {
        os << n << " ";
        for (int i = 0; i < n; i++)
            os << lista[i] << " ";
    }
}

//funcion para liberar la memoria de un vector dinamico
void liberar(string *& lista, int &n) {
    if (lista != nullptr)
        delete [] lista;
    n = 0;
}

/**
 * @brief Implementa la función del enunciado 
 * @param v1 Primer vector
 * @param nv1 Número de elementos de @a v1
 * @param v2 Segundo vector
 * @param nv2 Número de elementos de @a v2
 * @param v3 Vector resultado. Debe reservarse memoria dentro de la función
 * @param nv3 Número de elementos de @a v3
 */
void funcion(string const *v1, int nv1, string *v2, int nv2, string * &v3, int &nv3) {
    //tenemos que hacer la interseccion
    //recorremos cada vector y si son iguales los añadimos usando la funcion aniadir
    for (int i = 0; i < nv1; i++) {
        for (int j = 0; j < nv2; j++) {
            if (v1[i] == v2[j])
                aniadir(v3, nv3, v1[i]);
        }
    }
}

int main() {
    int nv1 = 0, nv2 = 0, nv3 = 0;
    string *v1 = nullptr, *v2 = nullptr, *v3 = nullptr;
    string nombre_archivo = "data/Laboratorio.dat", archivo_salida = "data/salida.dat";
    ifstream entrada;
    ofstream salida;
    string palabra;
    int nleido1 = 0, nleido2 = 0;

    //comprobamos el archivo de entrada
    entrada.open(nombre_archivo);
    if (!entrada || entrada.eof())
        error("No se ha podido leer el archivo de entrada.");
    else {
        //leemos el primer vector
        entrada >> nleido1;
        if (nleido1 < 0){
            entrada.close();
            error("Numero de elementos del primer vector inválido");
        }

        for (int i = 0; i < nleido1; i++) {
            if (entrada.eof()){
                liberar(v1,nv1);
                entrada.close();
                error("Se ha llegado al final del archivo antes de leer todos los elementos");
            }else{
                entrada >> palabra;
                aniadir(v1, nv1, palabra);
            }
        }
        //leemos el segundo vector
        entrada >> nleido2;
        if (nleido2 < 0){
            liberar(v1,nv1);
            entrada.close();
            error("Numero de elementos del segundo vector inválido");
        }

        for (int i = 0; i < nleido2; i++) {
            if (entrada.eof()){
                liberar(v1,nv1);
                liberar(v2,nv2);
                entrada.close();
                error("Se ha llegado al final del archivo antes de leer todos los elementos");
            }else{
                entrada >> palabra;
                aniadir(v2, nv2, palabra);
            }
        }
        entrada.close();
    }

    //comprobamos el archivo de salida
    salida.open(archivo_salida);
    if (!salida){
        liberar(v1,nv1);
        liberar(v2,nv2);
        error("No se ha podido crear o abrir el archivo de salida.");
    }

    // Examen: Leer vector v1
    // ...
    imprimirVector(v1, nv1);

    // Examen: Leer vector B
    // ...
    imprimirVector(v2, nv2);

    // Examen: Calcular resultado
    funcion(v1, nv1, v2, nv2, v3, nv3);

    // Examen: Mostrar resultado
    imprimirVector(v3, nv3);
    crearFichero(salida, v3, nv3);
    salida.close();
    // Examen: Terminación del programa
    // ...
    liberar(v1,nv1);
    liberar(v2,nv2);
    liberar(v3,nv3);

    return 0;
}

