/* Programa para calcular una subsecuencia de numeros ordenada

    ENTRADA --> secuencia de numeros
    SALIDA --> posicion donde comienza la subsecuencia y su longitud
22/10/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int main(){

    //Declaracion de variables

    int entrada, anterior = 0 , longitud = 0, contador = 1, max_long = 0, max_pos = 0;
    
    //Entrada de datos

    cout << "Introduce la secuencia de numeros entre 0 y 100 (numero menor a 0 o mayor a 100 para parar):\n";

    do{
        cin >> entrada;
		  contador++;
		  
        if (entrada >= anterior){				//Comprobamos si el numero introducido es mayor o igual al anterior
			longitud ++;						//En caso positivo aumentamos la longitud de la subsecuencia
	        	
			if (longitud > max_long){	    	//Comprobamos que la actual longitud sea la maxima
                max_long = longitud;				
                max_pos = contador - longitud;	//La maxima posicion sera la diferencia entre el contador y la longitud de la actual subsecuencia
			}
     	}
     		
        else									//Cuando el valor introducido sea menor reseteamos la variable
         	longitud = 1;
				
        anterior = entrada;						//Para la proxima iteracion, el actual es el anterior
    } while (entrada >= 0 && entrada <= 100);

	//Salida de datos
    cout << "La subsecuecia mas grande comienza en la posicion " << max_pos << " y tiene longitud " << max_long << endl;
    
    //Sentencia para detener el programa
    system("pause");
}
