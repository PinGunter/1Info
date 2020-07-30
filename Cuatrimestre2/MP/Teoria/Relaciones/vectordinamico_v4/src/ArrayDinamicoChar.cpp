#include "ArrayDinamicoChar.h"

void VectorDinamicoChar::inicializar() {
    capacidad = 10;
    arrayChar = new char [capacidad];
    nCaracteres = 0;
}

VectorDinamicoChar::VectorDinamicoChar() {
    inicializar();
}

void VectorDinamicoChar::liberar() {
    if (arrayChar != nullptr) {
        delete [] arrayChar;
        arrayChar = nullptr;
    }
    nCaracteres = 0;
    capacidad = 0;
}

void VectorDinamicoChar::mostrar(std::ostream& flujo) const {
    for (int i = 0; i < nCaracteres; i++) {
        flujo << arrayChar[i];
    }
}

void VectorDinamicoChar::redimensionar(int aumento) {
    //solo ejecutaremos la redimension si el tamaño neto es positivoi
    if (nCaracteres + aumento > 0) {
        char * array_nuevo = new char [nCaracteres + aumento];

        //ahora copiamos los antiguos elementos en el nuevo
        for (int i = 0; (i < nCaracteres) && (i < nCaracteres + aumento); i++) {
            array_nuevo[i] = arrayChar[i];
        }
        delete [] arrayChar;
        arrayChar = array_nuevo;
        nCaracteres = nCaracteres + aumento;
    }
}

void VectorDinamicoChar::aniadir(char caracter) {
    //tmb se podria hacer una llamada a redimensionar, modificando previamente el redimensionar
    if (nCaracteres == capacidad) {
        char * nuevoArray = new char[capacidad * 2];
        for (int i = 0; i < nCaracteres; i++)
            nuevoArray[i] = arrayChar[i];
        delete [] arrayChar;
        arrayChar = nuevoArray;
        capacidad = 2 * capacidad;
    }
    //y ahora le asignamos el nuevo caracter en la posicion nchar
    arrayChar[nCaracteres] = caracter;
    nCaracteres++;
}

void VectorDinamicoChar::leer(std::istream& flujo) {
    char caracter;
    liberar(); //Liberamos para borrar el contenido anterior
    inicializar(); //Inicializar para crear un array de un tamaño != 0
    while (flujo.get(caracter)) {
        aniadir(caracter);
    }
}
