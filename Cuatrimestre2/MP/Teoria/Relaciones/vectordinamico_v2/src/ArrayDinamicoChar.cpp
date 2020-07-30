#include "ArrayDinamicoChar.h"


void inicializar(VectorDinamicoChar &arraychar){
        arraychar.arrayChar = nullptr;	
        arraychar.nCaracteres = 0;
	
}

void liberar(VectorDinamicoChar &arraychar){
    if (arraychar.arrayChar != nullptr){
	delete [] arraychar.arrayChar;
	inicializar(arraychar);
    }
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
	//primero redimensionamos el vector en 1 espacio
	redimensionar (arraychar, 1);
	//y ahora le asignamos el nuevo caracter en la posicion nchar -1
	arraychar.arrayChar[arraychar.nCaracteres-1] = caracter;
}


void leer(std::istream& flujo, VectorDinamicoChar &arraychar){
	char caracter;
        liberar(arraychar);
	while(flujo.get(caracter)){
		aniadir(arraychar, caracter);
	}
}
