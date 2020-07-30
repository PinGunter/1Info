/*
    Programa para calcular numeros triangulares

    ENTRADA -> numero maximo
    SALIDA --> numeros triangulares menores al maximo

27/10/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main (){
    //Declaracion de variables
    int maximo, resultado = 0, n = 1;

    //Entrada de datos
    cout << "Introduce el numero maximo --> ";
    cin >> maximo;

    //Computos
    cout << "Los numeros triangulares menores a " << maximo << " son:\n";
    
    while (resultado < maximo){
		  resultado += n;
        n++;
        
        if (resultado < maximo){			//No queremos que siga evaluando el while cuando el resultado sea igual o mayor que el maximo. Ya que hace la evaluacion resultado < maximo antes de sumarlo.
	         //Imprimimos los numeros
		      cout << resultado << endl;
			}
    } 
	
	//Sentencia para detener el programa
	system("pause");
}
