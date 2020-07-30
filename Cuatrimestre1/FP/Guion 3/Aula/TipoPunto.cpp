/*
Programa que pide el nombre y localizacion de dos ciudades y crea una nueva
cuyo nombre es la concatenacion de ambas y su localizacion el producto de las anteriores.

   ENTRADA: nombres de ciudades, localizacion (coordenadas)
   SALIDA: nueva ciudad creadad resultante de la concatenacion y producto de las introducidasç

03/10/2019
Salvador Romero Cortes
*/

#include <iostream>                                         //Incluimos los recursos de E/S
#include <string>                                           //Incluimos la biblioteca string para poder hacer operaciones con strings

using namespace std;

//Definimos la estructura "TipoPunto" y "TipoCiudad"

struct TipoPunto{
   double abscisa;
   double ordenada;
};

struct TipoCiudad{
   TipoPunto situacion;
   string nombre;
};

//Programa principal

int main(){
   
   //Declaramos las variables que vamos a utlizar para almacenar los datos de las ciudades
   
   TipoPunto coordenadas_ciudad1;
   TipoPunto coordenadas_ciudad2;
   TipoPunto coordenadas_ciudad3;
   TipoCiudad ciudad1;
   TipoCiudad ciudad2;
   TipoCiudad ciudad3;
   
   //Pedimos al usuario por los datos de las ciudades
   
   cout << "Introduce el nombre de la primera ciudad:\n";
   cin >> ciudad1.nombre;

   cout << "Introduce las coordenadas de " << ciudad1.nombre << " (separadas por un espacio):\n";
   cin >> coordenadas_ciudad1.abscisa;
   cin >> coordenadas_ciudad1.ordenada;
   ciudad1.situacion = coordenadas_ciudad1;
   
   cout << "Introduce el nombre de la segunda ciudad:\n";
   cin >> ciudad2.nombre;

   cout << "Introduce las coordenadas de " << ciudad2.nombre << " (separadas por un espacio):\n";
   cin >> coordenadas_ciudad2.abscisa;
   cin >> coordenadas_ciudad2.ordenada;
   ciudad2.situacion = coordenadas_ciudad2;



   //Computo de datos
   
   //1. El nombre de la ciudad nueva es la concatenacion
   
   ciudad3.nombre = ciudad1.nombre + ciudad2.nombre;
   
   //2. Su situacion es el produtcto
   coordenadas_ciudad3 = {coordenadas_ciudad1.abscisa * coordenadas_ciudad2.abscisa, coordenadas_ciudad1.ordenada * coordenadas_ciudad2.ordenada};
   ciudad3.situacion = coordenadas_ciudad3;
   
   
   //Salida de resultados
   
   cout << "La nueva ciudad es: " << ciudad3.nombre << " y su situacion es : " << ciudad3.situacion.abscisa << ", " << ciudad3.situacion.ordenada <<endl;
      
   //Sentencia para detener el programa
   system("pause");
}
