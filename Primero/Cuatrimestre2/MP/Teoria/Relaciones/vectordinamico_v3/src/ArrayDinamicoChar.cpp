#include "ArrayDinamicoChar.h"


void inicializar(VectorDinamicoChar &arraychar){
    arraychar.capacidad = 10;
    arraychar.arrayChar = new char [arraychar.capacidad];	
    arraychar.nCaracteres = 0;

}

void liberar(VectorDinamicoChar &arraychar){
    if (arraychar.arrayChar != nullptr){
        delete [] arraychar.arrayChar;
        arraychar.arrayChar = nullptr;
    }
    arraychar.nCaracteres = 0;
    arraychar.capacidad = 0;
}

void mostrar (std::ostream  &flujo, const VectorDinamicoChar &arraychar){
    for (int i=0; i < arraychar.nCaracteres; i++){
            flujo << arraychar.arrayChar[i];
    }
}

void redimensionar (VectorDinamicoChar &arraychar, int aumento){
    //solo ejecutaremos la redimension si el tamaño neto es positivoi
    if (arraychar.nCaracteres+aumento > 0){
            char * array_nuevo = new char [arraychar.nCaracteres+aumento];

            //ahora copiamos los antiguos elementos en el nuevo
            for (int i=0; (i < arraychar.nCaracteres) && (i < arraychar.nCaracteres+aumento);i++){
                    array_nuevo[i] = arraychar.arrayChar[i];
            }
            delete [] arraychar.arrayChar;
            arraychar.arrayChar = array_nuevo;
            arraychar.nCaracteres = arraychar.nCaracteres + aumento;
    }
}

void aniadir (VectorDinamicoChar &arraychar, char caracter){
    //tmb se podria hacer una llamada a redimensionar, modificando previamente el redimensionar
    if (arraychar.nCaracteres = arraychar.capacidad){
        char * nuevoArray = new char[arraychar.capacidad*2];
        for (int i=0; i < arraychar.nCaracteres; i++)
            nuevoArray[i] = arraychar.arrayChar[i];
        delete [] arraychar.arrayChar;
        arraychar.arrayChar = nuevoArray;
    }
    //y ahora le asignamos el nuevo caracter en la posicion nchar
    arraychar.arrayChar[arraychar.nCaracteres] = caracter;
    arraychar.nCaracteres++;
}


void leer(std::istream& flujo, VectorDinamicoChar &arraychar){
    char caracter;
    liberar(arraychar); //Liberamos para borrar el contenido anterior
    inicializar(arraychar);  //Inicializar para crear un array de un tamaño != 0
    while(flujo.get(caracter)){
            aniadir(arraychar, caracter);
    }
}
