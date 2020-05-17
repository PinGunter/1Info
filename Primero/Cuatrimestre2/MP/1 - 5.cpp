#include <iostream>

const int TAMANIO = 100;

using namespace std;

/**
* @brief funcion que obtiene el minimo de un vector
* @param v array de donde obtiene el minimo
* @param utils entero que indica el numero de elementos el vector
* @retval la posicion del minimo elemento del vector
*/

int buscarMinimoArray(int v[], int utils);

/**
* @brief funcion para mostrar un vector por pantalla
* @param v el vector que vamos a imprimir
* @param utils el numero de componentes utiles
**/
void imprimirArray(int v[], int utils);

/**
* @brief funcion para leer desde el teclado un array
* @param v el vector que vamos a leer
* @param utils el numero de componentes utiles, se pasa por referencia
**/
void leerArray(int v[], int utils);

/**
* @brief funcion que ordena un vector usando el metodo de seleccion
* @param v el vector que va a ser ordenado
* @param utils el numero de componentes utiles del vector
**/
void ordenarporSeleccion(int v[], int utils);


int main(){
    int utiles, array[TAMANIO];

    cout << "Introduce el numero de componentes del vector (max 100): ";
    do{
        cin >> utiles;
        if (utiles <= 0 || utiles > 99)
            cout << "Valor no valido\n";
    } while (utiles <= 0 || utiles > 99);

    //leemos el array
    leerArray(array, utiles);

    //lo ordenamos
    ordenarporSeleccion(array, utiles);

    //lo mostramos por pantalla
    imprimirArray(array, utiles);
}

void ordenarporSeleccion (int v[], int utils){
    int posMin, 
}