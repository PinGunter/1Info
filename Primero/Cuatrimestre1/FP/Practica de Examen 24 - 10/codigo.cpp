//Salvador Romero Cortes
//Codigo

#include <iostream>

using namespace std;

int main(){

   //Declaracion de variables
   char entrada;
   int contador_hash = 0, contadorA = 0, contadorE = 0, contadorI = 0, contadorO = 0, contadorU = 0;
   bool fin = false;
   
   //Entrada de datos
   
   cout << "Introduce la secuencia codificada:\n";
   
   //Usaremos un do while para la ejecucion de los computos y la entrada reiterada de la secuencia
   do{
      cin >> entrada;
      
      if (entrada == '#')
         contador_hash += 1;                 //Queremos que cuente los # que hay en la secuencia, como el codigo se encuentra entre el primer y segundo #
                                             //los computos los haremos cuando el contador sea 1
      if (contador_hash == 1){
         //Creamos una estructura switch para ir viendo si es una vocal
         
         switch (entrada){
            case 'a':
               contadorA += 1;      
               break;
            
            case 'e':
               contadorE += 1;
               break;
             
            case 'i':
               contadorI += 1;
               break;
             
            case 'o':
               contadorO += 1;
               break;
            
            case 'u':
               contadorU += 1;
               break;
         }
      }
      fin = entrada == '@' && contador_hash == 2;
   } while (!fin);
   
   //Salida de datos
   cout << "ID: " << contadorA << contadorE << contadorI << contadorO << contadorU << endl;
   
   //Sentencia para detener el programa
   system("pause");
}
