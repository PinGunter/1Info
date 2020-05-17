/**
 * @file main.cpp
 * @author DECSAI
 * @note Revisar el uso de punteros y memoria dinámica. Introducir el uso de valgrind
 * @warning Compilar en "Project - Properties - Configuration DEBUG"
 * Llamada a valgrind
 *
   valgrind --leak-check=full dist/Debug/GNU-Linux/mp1920punteros
 * 
 */

#include <iostream>
using namespace std;

/**
 * @brief Imprime el contenido de un vector de enteros en pantalla
 * @param v El vector
 * @param n El tamaño del vector
 */
void printVector(int *v, int n) {
    cout << "Memory address: "<<v<<endl;
    for (int i=0; i<n; i++)
        cout << "["<<i<<"]= "<< v[i] << endl;
}

/**
 * @brief Uso básico de punteros
 */
void basicUSeStatic() {
   int array[5]={1,2,3,4,5}; 
   int *ptr = array;
   
   printVector(ptr,5);
}

/**
 * @brief Declara un vector y lo imprime en pantalla
 * @warning ERROR "UNINITIALIZED USE OF MEMORY"
==XXXXX==    by 0x4F493F9: std::ostream& std::ostream::_M_insert<long>(long) (in /usr/lib/x86_64-linux-gnu/libstdc++.so.6.0.21)                                                             
==XXXXX==    by 0x400B00: printVector(int*, int) (main.cpp:XX)                                                                                                                              
==XXXXX==    by 0x400BAC: nonInitialized() (main.cpp:XX)                                                                                                                                    
==XXXXX==    by 0x400EF7: main (main.cpp:XX)
 *                 
 */
void nonInitialized() {
   int array[5]; 
   printVector(array,1);
}


/**
 * @warning beware of wild pointers, that is, non-initialized pointers
 */
void wildPointer() {
   int array[5]={1,2,3,4,5}; 
  // int *ptr; 
   int *ptr=nullptr; 
   
   printVector(ptr,5);
}

/**
 * @brief Uso básico de memoria dinámica
 * 1. Pedir memoria al sistema operativo
 * 2. Usar la memoria
 * 3. Liberar la memoria
 */

void basicUseDynamic() {
    // 1. Pedir memoria al sistema operativo
    int *p = new int;
    
    // 2. Usar la memoria
    *p = 13; 

    // Se copia el valor en c
    int c = *p; 

    // Se muestra
    cout << "Valor de c: " << c<<endl; 

    // 3. Liberar la memoria
    delete p;
}

/**
 * @warning Lee varias posiciones fuera del vector
==2209== Invalid read of size 4
==2209==    at 0x400AF7: printVector(int*, int) (main.cpp:23)
==2209==    by 0x400CE4: invalidRead() (main.cpp:91)
==2209==    by 0x400EA1: main (main.cpp:150)

 */
void invalidRead() {
   int *array=new int[5];
    printVector(array,7);
    delete[]array;
    array=nullptr;
}

/**
 * @warning Escribe ilegalmente en memoria
==2611== Invalid write of size 4
==2611==    at 0x400D22: invalidWrite() (main.cpp:103)
==2611==    by 0x400E7B: main (main.cpp:156)
==2611==  Address 0x5ab70d4 is 0 bytes after a block of size 20 alloc'd
==2611==    at 0x4C2E80F: operator new[](unsigned long) (vg_replace_malloc.c:422)
==2611==    by 0x400CF9: invalidWrite() (main.cpp:101)
==2611==    by 0x400E7B: main (main.cpp:156)

 */
void invalidWrite() {
   int *array=new int[5];
   for(int i=0; i <= 5; i++){
      array[i]=i;  
   }      
   delete []array;
   array=nullptr;
}

/**
 * @warning memoria reservada y no liberada
 ==3052== 20 bytes in 1 blocks are definitely lost in loss record 1 of 2
==3052==    at 0x4C2E80F: operator new[](unsigned long) (vg_replace_malloc.c:422)
==3052==    by 0x400D74: memoryLoss() (main.cpp:123)
==3052==    by 0x400EA7: main (main.cpp:172)

 */
void memoryLoss() {
   int *array=new int[5];
   for(int i=0; i < 5; i++){
      array[i]=i;
   }
   printVector(array,5);
//   delete [] array; 
//   array = nullptr;   
}

/**
 * @warning delete incorrecto
 */
void invalidDelete() {
   int *array=new int[5];
   for(int i=0; i < 5; i++){
      array[i]=i;
   }
   printVector(array,5);
   delete array; 
   array=nullptr;
}

/**
 * @warning delete incorrecto
 */
void doubleDelete() {
   int *array=new int[5];
   for(int i=0; i < 5; i++){
      array[i]=i;
   }
   printVector(array,5);
   delete array; 
   //array=nullptr;
   delete array;
}

int main() {
    
    cout << "USO DE PUNTEROS & MEMORIA DINÁMICA"<<endl;
    //basicUSeStatic();
    //nonInitialized();
     wildPointer();
    //basicUseDynamic();
    //invalidRead();
    //invalidWrite();
    // memoryLoss();
    // invalidDelete();
    //doubleDelete();
return 0;
}