#include <iostream>

using namespace std;

int TamanioCadena(char cadena[]){
   int tamanio, i;
   tamanio = i = 0;
   while (cadena[i] != '\0'){
      tamanio++;
      i++;
   }
   return tamanio;
}

void BorrarPosicionEn(char cadena[], int indice){
   int tamanio = TamanioCadena(cadena);
   for (int i=indice; i < tamanio;i++)
      cadena[i] = cadena[i+1];
}

void InsertarCadenaEnCadenaEnPosicion(char cadena2[], char cadena1[], int posicion){
   int final = posicion + TamanioCadena(cadena2);

   for (int i=0; i < TamanioCadena(cadena2);i++){
      for (int j=final; j>posicion;j++)
         cadena1[j] = cadena1[j-1];
      cadena1[posicion+i] = cadena2[i];
   }
}

void Remplazar(char cadena[], int posicion, int n, char cadena2[]){
   for (int i=posicion; i < posicion+n;i++)
      BorrarPosicionEn(cadena,i);

   InsertarCadenaEnCadenaEnPosicion(cadena2,cadena,posicion);

}

int main(){
   char cadena[100];
   char remplazo[10];
   int posicion, n;

   cout << "Introduce la cadena: ";
   cin.getline(cadena,100);
   cout << "Introduce el remplazo: ";
   cin.getline(remplazo,10);
   cin.ignore();
   cout << "Introduce la posision: ";
   cin >> posicion;
   cout << "Introduce la n: ";
   cin >> n;

   Remplazar(cadena,posicion,n,remplazo);

   for (int i=0; i < TamanioCadena(cadena);i++)
      cout << cadena[i];

}