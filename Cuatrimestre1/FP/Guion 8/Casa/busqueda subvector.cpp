//////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
//////////////////////////////////////////////////////////////////////////

// Recorridos sobre principales: Búsqueda de un vector dentro de otro

// Suponemos que no dejamos huecos en el vector y no hay un dato destacado
// que podamos usar como "señal" de componente no usada, es decir:

// total_utilizados = 5
// XXXXX????...???

// En cualquier caso, en este ejemplo concreto vamos a leer datos desde
// teclado hasta que se introduzca un carácter "terminador"

// aaabcddddefg#ddddefg#
// aaabcddddefg#aaab#
// aaabcddddefg#dddefg#


#include <iostream>
using namespace std;

int main(){
   const char TERMINADOR_ENTRADA_DATOS = '#';
   const int TAMANIO = 100;
   char componente;
   char principal[TAMANIO], a_buscar[TAMANIO];
   int total_utilizados, total_utilizados_a_buscar, pos_encontrado;
   bool encontrado, va_coincidiendo;

   cout << "Búsqueda de un vector dentro de otro\n\n";
   
   cout << "Introduzca caracteres. Para terminar introduzca #\n";
   
   cin >> componente;
   total_utilizados = 0;
   
   while (componente != TERMINADOR_ENTRADA_DATOS && total_utilizados < TAMANIO){
      principal[total_utilizados] = componente;
      total_utilizados++;
      cin >> componente;
   }
   
   cout << "Introduzca caracteres. Para terminar introduzca #\n";

   cin >> componente;
   total_utilizados_a_buscar = 0;

   while (componente != TERMINADOR_ENTRADA_DATOS && total_utilizados_a_buscar < TAMANIO){
      a_buscar[total_utilizados_a_buscar] = componente;
      total_utilizados_a_buscar++;
      cin >> componente;
   }
   
   encontrado = false;

   for (int inicio = 0;
        inicio + total_utilizados_a_buscar <= total_utilizados
        &&
        !encontrado;
        inicio++){

      va_coincidiendo = true;

      for (int i = 0; i < total_utilizados_a_buscar && va_coincidiendo; i++)
         va_coincidiendo = principal[inicio + i] == a_buscar[i];

      if (va_coincidiendo){
         encontrado = true;
         pos_encontrado = inicio;
      }
   }

   if (encontrado)
      cout << "\nEncontrado en la posición " << pos_encontrado;
   else
      cout << "\nNo encontrado";
}
