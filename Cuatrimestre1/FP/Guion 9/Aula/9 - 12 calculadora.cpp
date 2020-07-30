/* Calculadora 
14/11/2019
Salvador Romero Cortes
*/

#include <iostream>

using namespace std;

int Calculadora(int a, int b, char o);
int MCD(int a, int b);
int MCM(int a, int b);
void FiltroOperacion(char &o);

int main(){
   //Declaracion de variables
   int numero1, numero2, resultado;
   char operacion;
   
   //Entrada de datos
   cout << "Introduce un numero entero --> ";
   cin >> numero1;
   cout << "Introduce otro numero entero --> ";
   cin >> numero2;
   cout << "\nIntroduce la operacion que desea realizar:\n\"m\" para el MCM\n\"d\" para el MCD\n\"+\", \"-\", \"*\", \"/\" para la operacion correspondiente.";
   cout << "\nOperacion --> ";
   FiltroOperacion(operacion);
   
   //Computos
   resultado = Calculadora(numero1,numero2,operacion);
   
   //Salida de datos
   cout << "\n\nEl resultado de la operacion es --> " << resultado << endl;
}

//Filtro para que el caracter introducido sea correcto
void FiltroOperacion(char &operacion){
   bool valido = operacion == 'm' || operacion == 'd' || operacion == '+' || operacion == '-' || operacion == '*' || operacion == '/';
   do{
      cin >> operacion;
      valido = operacion == 'm' || operacion == 'd' || operacion == '+' || operacion == '-' || operacion == '*' || operacion == '/';
      
      if (!valido)
         cout << "\nCaracter introducido no valido. Vuelva a introducir un caracter correcto:\n";
   }while(!valido);
}

//Funcion para calcular el MCD. Obtenemos los divisores y nos quedamos con el comun mayor
int MCD (int numero1, int numero2){
   int mcd = 1;
   for (int i=1; i < numero1 && i < numero2; i++){
      if (numero1 % i == 0 && numero2 % i == 0)
         mcd = i;
   }
	
	return mcd;
}

//Funcion para calcular el MCM. Este sera simplemente el cociente entre el producto de los numeros y el MCD 
int MCM (int numero1, int numero2){
	int mcm = 0;
	//Comprobamos que no sean 0, en caso de que lo sean no haremos calculos puesto que sera 0
	if (numero1!= 0 && numero2 != 0)
		mcm = (numero1*numero2)/MCD(numero1,numero2);
	
	return mcm;
}

//Funcion que hace la operacion en funcion del caracter introducido
//Usamos un switch para ir cambiando entre las posibles opciones
int Calculadora (int numero1, int numero2, char operacion){
	int resultado;
   switch (operacion){
   	case '+':
   		resultado = numero1 + numero2;
   		break;
   	
   	case '-':
   		resultado = numero1 - numero2;
   		break;
   	
   	case '*':
   		resultado = numero1 * numero2;
   		break;
   	
   	case '/':
   		resultado = numero1 / numero2;
   		break;
   		
   	case 'm':
   		resultado = MCM(numero1,numero2);
   		break;
   	
   	case 'd':
   		resultado = MCD(numero1,numero2);
   		break;
	}
	
	return resultado;
}
