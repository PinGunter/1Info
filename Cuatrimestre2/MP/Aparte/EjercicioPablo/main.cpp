/*
 * Se hace lectura del numero de elementos
 * Se tiene devolver un diccionario.
 * Condiciones del diccionario:
    * Ordenado alfabeticamente -- entrada
    * No puede haber palabras repetidas -- entrada
    * No puede haber caracteres no alfabeticos -- entrada
    * Todo en minuscula 
 */

#include <iostream>
#include <fstream>
#include "Diccionario.h"
using namespace std;

int main(int argc, char** argv) {
    //variables
    Diccionario dic;
    string archivo_entrada, archivo_salida;
    ifstream entrada;
    ofstream salida;
    istream *input; ostream *output;    
    bool abrir_ok, cerrar_ok, leer_ok;
    
    //procesar los argumentos
    if (argc != 2){
        cout << "Número de parámetros incorrecto." << endl;
        return 1;
    }
    
    
    archivo_entrada = argv[1];
    entrada.open(archivo_entrada);
    input = &entrada;
    
    cout << "Introduce el nombre del archivo de salida: " << endl;
    cin >> archivo_salida;
    salida.open(archivo_salida);
    output = &salida;
    
    if (!entrada || !salida){
        cout << "Error abriendo el archivo." << endl;
        return 1;
        
    } else{
        leer_ok = dic.LeerDiccionario(*input);
        if (!dic.HayRepetidos() && leer_ok)
            dic.CrearDiccionario(*output);
        else{
            cout << "Diccionario inválido" << endl;
            return 1;
        }
    }
    
    if (abrir_ok)
        entrada.close();

    if (cerrar_ok)
        salida.close();

    return 0;
}
