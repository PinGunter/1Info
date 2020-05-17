/* Programa para calcular si dos palabras son iguales
	el criterio es:
		La primera letra y la ultima son la misma
		Las letras entre la primera y la ultima tienen que ser las mismas pero no en el mismo orden
	25/11/2019
	Salvador Romero Cortes
*/

#include <iostream>
#include <cstring>

using namespace std;

const int LONG = 100;
const char TERMINADOR = '\0';

struct FrecuenciaCaracter{
	char caracter;
	int frecuencia;
};

class PalabrasIguales{
	public:
		char palabra1[LONG], palabra2[LONG];
	private:
		//metodo para calcular el tamanio de la cadena
		int Longitud(char cadena[]){
			int longitud = 0;
			for (int i=0; cadena[i] != '\0'; i++){
				longitud++;
			}
			return longitud;
		}
		
		int longitud1 = Longitud(palabra1);
		int longitud2 = Longitud(palabra2);
		int final1 = palabra1[longitud1];
		int final2 = palabra2[longitud2];


		void CharAFrecuenciaCaracter(char cadena[], FrecuenciaCaracter vector_frecuencia[], int final){
			//copiamos la cadena en el vector frecuencias
			int contador_fr = 0, contador_ch = 1;

			while (contador_ch < final){
				vector_frecuencia[contador_fr].caracter = cadena[contador_ch];
				contador_fr++;
				contador_ch++;
			}
		}
		//metodo para calcular las repeticiones de un caracter en una cadena
		bool IntermedioBien(char palabra1[], char palabra2[]){
			FrecuenciaCaracter vector_frecuencias1[LONG], vector_frecuencias2[LONG];
			bool correcto;
			
			CharAFrecuenciaCaracter(palabra1, vector_frecuencias1, final1);
			CharAFrecuenciaCaracter(palabra2, vector_frecuencias2, final2);

			//contamos los caracteres
			for (int i=0; i < longitud1; i++)
				for (int j=0; j < longitud2; j++)
					if (vector_frecuencias1[i].caracter == vector_frecuencias2[j].caracter){
						vector_frecuencias1[i].frecuencia ++;
						vector_frecuencias2[j].frecuencia ++;
					}

			//asumimos que son iguales
			correcto = true;
			for (int i=0; i < longitud1; i ++)
				for (int j=0; j < longitud2; j++)
					if ((vector_frecuencias1[i].caracter != vector_frecuencias2[j].caracter) && (vector_frecuencias1[i].frecuencia != vector_frecuencias2[j].frecuencia))
						correcto = false;

			return correcto;
		}
		
		
		
		//metodo para comprobar si la primera y ultima letra son iguales
		bool ExtremosBien(char palabra1[], char palabra2[]){
			char inicio1, inicio2;
			bool correcto;
			
			inicio1 = palabra1[0];
			inicio2 = palabra2[0];
	
			
			correcto = inicio1 == inicio2 && final1 == final2;
			return correcto;
		}
		
		//metodo para comprobar si la parte intermedia es igual segun el criterio, para ello contamos el numero de caracteres que tiene esa parte

		
	public:
		//metodo para comprobar que se cumplen las condiciones
		
		void IntroducirDatos(char palabra1[], char palabra2[]){
			cout << "Introduce la palabra 1 --> ";
			cin.getline(palabra1,LONG);

			cout << "Introduce la palabra 2 --> ";
			cin.getline(palabra2,LONG);
		}

		bool SonIguales(char palabra1[], char palabra2[]){
			bool son_iguales = ExtremosBien(palabra1, palabra2) && IntermedioBien(palabra1, palabra2);
			
			return son_iguales;
		}
};

int main(){
	//declaracion de variables
	PalabrasIguales palabra;
	bool iguales;

	//entrada de datos
	palabra.IntroducirDatos(palabra.palabra1, palabra.palabra2);

	//computos
	iguales = palabra.SonIguales(palabra.palabra1, palabra.palabra2);

	//salida de datos
	if (iguales)
		cout << "Las palabras introducidas son iguales.";
	else
		cout << "Las palabras introducidas no son iguales";




}
