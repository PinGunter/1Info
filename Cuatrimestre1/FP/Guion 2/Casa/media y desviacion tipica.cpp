/*
Programa para calcular la media y la desviaciÃ³n estandar de la altura de 3 personas
AMPLIACION --> Mostrar si los valores estan por encima o debajo de la media
Por Salvador Romero Cortés
28/09/2019
*/

#include <iostream>																						//Incluimos los rescursos de E/S
#include <cmath>																							//Incluimos los recursos de herramientas matematicas

using namespace std;

int main(){																									//Programa principal

	int altura1, altura2, altura3;
	double media, desviacion, distancia;															//Declaramos las variables que vamos a usar para guardar los datos del usuario y las operaciones aritmeticas
 
	//Preguntamos por los datos y los asignamos a sus correspondientes variables
	
	cout << "Introduce la altura de la primera persona: ";									
	cin >> altura1;
	
   cout << "Introduce la altura de la segunda persona: ";
   cin >> altura2;
   
   cout << "Introduce la altura de la tercera persona: ";
   cin >> altura3;

   //Calculamos la media
   
   media = (altura1+ altura2+ altura3)/3.0;
   
   //Mostramos el resultado de la media
   
   cout << "La media de las 3 alturas es: " << media <<endl;
   
   //Ahora que tenemos la media vamos a calcular paso a paso la desviación	 típica
	//Primero calculamos el numerador. La distancia entre cada valor y la media al cuadrado
  
   distancia = pow(altura1 - media,2) + pow(altura2 - media,2) + pow(altura3 - media,2);
   
   //Finalmente calculamos la desviacion
   
   desviacion = sqrt(distancia/3);
   
   //Imprimimos el resultado de la desviacion
   
   cout << "La desviación típica es: " << desviacion << endl;
   
	//Sentencia para detener el programa hasta que el usuario interactue con el teclado
	system("pause");
}


