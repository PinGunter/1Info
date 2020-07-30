#include "ArrayDinamicoChar.h"
void inicializar(char * &array, int &nchar){
        array = nullptr;	
        nchar = 0;
	
}

void liberar(char * &array, int &nchar){
    if (array != nullptr){
	delete [] array;
	inicializar(array, nchar);
    }
}

void mostrar (std::ostream &flujo, char * array, int nchar){
	for (int i=0; i < nchar; i++){
		flujo << array[i];
	}
}

void redimensionar (char * &array, int &nchar, int aumento){
	//solo ejecutaremos la redimension si el tamaño neto es positivoi
	if (nchar+aumento > 0){
		char * array_nuevo = new char [nchar+aumento];
		
		//ahora copiamos los antiguos elementos en el nuevo
		for (int i=0; (i < nchar) && (i < nchar+aumento);i++){
			array_nuevo[i] = array[i];
		}
		delete [] array;
                array = array_nuevo;
		nchar = nchar + aumento;
	}
}

void aniadir (char * &array, int &nchar, char caracter){
	//primero redimensionamos el vector en 1 espacio
	redimensionar (array, nchar, 1);
	//y ahora le asignamos el nuevo caracter en la posicion nchar -1
	array[nchar-1] = caracter;
}


void leer(std::istream & flujo, char* &array, int& nchar){
	char caracter;
        liberar(array,nchar);
	while(flujo.get(caracter)){
		aniadir(array, nchar, caracter);
	}
}
