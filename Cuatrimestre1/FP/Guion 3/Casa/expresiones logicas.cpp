/*
Indicar el valor que devuelven las siguientes expresiones y de que tipo de dato se trata
Indicar tambien si esta mal formulada y el motivo
	
Salvador Romero Cortes
28/09/2019

*/

#include <iostream>												//Incluimos los recursos de E/S

using namespace std;

int main(){															//Programa principal

	//Declaramos constantes los separadores visuales entre apartados
	const string separadorA = "============== A ==============\n\n";
	const string separadorB = "\n\n============== B ==============\n\n";
	const string separadorC = "\n\n============== C ==============\n\n";
	const string separadorD = "\n\n============== D ==============\n\n";
	const string separadorE = "\n\n============== E ==============\n\n";
	const string separadorF = "\n\n============== F ==============\n\n";
	const string separadorG = "\n\n============== G ==============\n\n";
	
	//Declaramos las variables de cada apartado
	
	bool apartadoA, apartadoB, apartadoD, apartadoE, apartadoF, apartadoG;
	double apartadoC;

	cout << separadorA;
	
	//
	//Apartado A
	//
	apartadoA = 2 + 3 < 5 + 8;
	
   if (apartadoA){
    	
   	cout << "Se trata de una expresión booleana y su valor es true (1)";
    	
	}else{
	 	
		cout << "Se trata de una expresion booleana y su valor es false (0)";
	 }
    
    /* Se trata de una expresion booleana y se evalua a true.*/
    
    
	 cout << separadorB;
    
    
   //
	//Apartado B
	//
	apartadoB = 2 < 3 < 8;
	
	if (apartadoB){
		
   	cout << "Se trata de una expresión booleana y su valor es true (1)";
    	
	}else{
	 	
	 	cout << "Se trata de una expresion booleana y su valor es false (0)";
	 }
    
	 /* Se trata de una expresion booleana y se evalua a true. Sin embargo no 
	 tiene significado matematico. Habria que especificar parentesis*/
	 
	
	cout << separadorC;
	
	//
	//Apartado C
	//
	apartadoC = 7/3 + 4.0;
	cout << "Se trata de una expresión real. 7/3 es un numero entero que al sumarle el real 4.0 lo convierte en una expresión real\nSu resultado es: " << apartadoC; 
	
	
	cout << separadorD;
	
	//
	//Apartado D
	//
	int x = 4;
	int y = 4;
	int z = 4;
	apartadoD = x == 4&&y == 3||z != 2 == 1 != 2;
	
   if (apartadoD){
    	
   	cout << "Se trata de una expresión booleana y su valor es true (1)";
    	
	}else{
	 	
		cout << "Se trata de una expresion booleana y su valor es false (0)";
	}
    
    /* Se trata de una expresion booleana y esta mal formulada. Hacen falta parentesis
	 para indicar bien el orden de las comparaciones booleanas. Por ejemplo, un parentesis
	 para cada miembro del "&&" . Tambien para la comparacion ||. 
	 Quedaria mejor asi
	((x == 4)&& (y == 3)) || ((z != 2) == (1 !=2))  
	 */
   cout << separadorE;
	
	//
	//Apartado E
	//
	
	x = 4;
	apartadoE = x <=4||x>=4;
	
	if (apartadoE){
		
		cout << "Se trata de una expresion booleana y su valor es true (1)";
	} else{
		
		cout << "Se trata de una expresion booleana y su valor es false (0)";
	}
	
	/*Se trata de una expresion booleana con valor true. Esta expresion siempre sera verdadera
	puesto que pone las condiciones opuestas en un "or" por lo que siempre se cumplira. Seria mas
	sencillo poner simplemente "if (true)" o almacenar la variable como "apartadoE = true"*/
	
	
	cout << separadorF;
	
	
	//
	//Apartado F
	//
	
	apartadoF = x < 4 && x > 4;
	
	if (apartadoF){
		
		cout << "Se trata de una expresion booleana y su valor es true (1)";
	} else{
		
		cout << "Se trata de una expresion booleana y su valor es false (0)";
	}
	
	/*Se trata de una expresion booleana cuyo valor sera siempre falso (0). Esto se debe a que 
	se utiliza el operador booleano "&&" y para que sea verdadero se tienen que evaluar las dos opciones
	que en este caso son opuestas. No es posible cumplir una cosa y la contraria al mismo tiempo.
	Seria mas sencillo usar "if (false)" o "apartadoF = false"*/

	cout << separadorG;
	
	
	//
	//Apartado G
	//
	char a;
	apartadoG = z > 6 || a < 'z' && a > 'a' || z < 6;

	if (apartadoG){
		
		cout << "Se trata de una expresion booleana y su valor es true (1)";
	} else {
		
		cout << "Se trata de una expresion booleana y su valor es false (0)";
	}
	/* Se trata de una expresion booleana y su valor depende de la entrada de z y a.
	Se deberia usar parentesis para evitar confusiones con la expresion. Tal que asi
	((z > 6) || (a < 'z')) && ((a >'a') || (z < 6))*/
	
	
	//Sentencia para detener el programa hasta que el usuario interactue
	system("pause");
}
