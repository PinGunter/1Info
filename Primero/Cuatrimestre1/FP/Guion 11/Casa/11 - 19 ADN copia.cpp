/* El Instituto de Investigaciones Biologicas Avanzadas de Guejar Sierra dispone de una base
de datos de ADN de diversas especies biologicas del Parque Nacional de Sierra Nevada codificadas
como secuencias de caracteres (A, T, G y C) de distinta longitud segun la especie.
Esta base de datos se compone de 1000 registros donde cada registro contiene el nombre de
la especie y la secuencia de su ADN, ambas representadas como cadenas de caracteres (tipo
string). Ejemplos de la informacion asociada con distintas especies son:
Nombre: La mosca del Vinagre, ADN: ATAATGGACAAT
Nombre: La lombriz de tierra, ADN: GGATACT
Nombre: La ameba verde, ADN: AGAGAT
El instituto necesita un programa de ordenador que les permita identificar a que especie
pertenece una toma de ADN que se ha recogido en el campo y analizado en el laboratorio.
Teniendo en cuenta que las secuencias de ADN analizadas pueden comenzar en cualquier
posicion de la secuencia. Por ejemplo, las secuencias GGATACT y ACTGGAT pertenecen
a la misma especie (La lombriz de tierra). Observad que la secuencia es la misma, aunque
comienza en un punto distinto. Se pide:
* Disenar las estructuras de datos (tipos de datos, estructuras, clases, vectores, ect.) necesarios para almacenar en memoria principal esta base de datos.
* Disenar una funcioon que, a partir de la base de datos y de una secuencia de ADN especifica nos indique si esta registrada en la base de datos y, en caso afirmativo, cual es el nombre de la especie.

25/11/2019
Salvador Romero Cortes
*/


#include <iostream>
#include <cstring>

using namespace std;

const int LONG = 100;

class CoincidenciasADN{
	public:
		char entrada[LONG];
		bool coincidencia = false;

	private:
		int longitud_entrada;

		//metodo para que la entrada sea correcta
		bool EntradaValida(char cadena[],int longitud_entrada){
			bool valida = false;
			bool valida_expr;
			for (int i=0; i < longitud_entrada && !valida; i++){
				valida = true;
				valida_expr = cadena[i] == 'A' || cadena[i] == 'T' || cadena[i] == 'G' || cadena[i] == 'C';

				if (!valida_expr)
					valida = false;
            }
			return valida;
        }

		void DesplazarVector(char vector[], int &longitud, int posicion, char insercion){
			for(int i=longitud; i > posicion; i--)
				vector[i] = vector[i-1];

			vector[posicion] = insercion;
			longitud++;
		}

	public:
		//creamos un vector de strings, donde tendremos las secuencias de adn.
		//0. Mosca del vinagre, 1. Lombriz de tierra, 2. Ameba Verde
		string secuencias[LONG] = {"ATAATGGACAAT", "GGATACT", "AGAGAT"};
		string nombres[LONG] = {"La mosca del vinagre", "La lombriz de tierra", "La ameba verde"};

		//metodo para comprobar si la entrada esta en la base de datos, si lo esta devuelve un entero con la posicion
		//para ello vamos alterando el vector de manera que el ultimo elemento se convierte en el primero hasta que encuentre coincidencia o acabe con todas las letras
		int EnBaseDeDatos(char entrada[]){
			int posicion;
			for(int i=0; i < longitud_entrada && !coincidencia; i++){
				DesplazarVector(entrada, longitud_entrada, 0, entrada[longitud_entrada]);
				//borramos el ultimo elemento (marcamos como final de cadena)
				entrada[longitud_entrada] = '\0';

				for (int j=0; j < longitud_entrada; j++)
					if (entrada == secuencias[j]){
						coincidencia = true;
						posicion = j;
					}
			}

			if (coincidencia)
				return posicion;
			else
				return -1;
		}

		//metodo para mostrar la coincidencia (si existe) por pantalla
		void MostrarCoincidencias(char entrada[]){
			bool hay_coincidencia = EnBaseDeDatos(entrada) > -1;
			int posicion = EnBaseDeDatos(entrada);

			if (hay_coincidencia)
				cout << "\n\tSe ha encontrado una coincidencia en la base de datos\n";
				cout << "La secuencia introducida corresponde a la secuencia de: "
				 	<< nombres[posicion] << " (" << secuencias[posicion] << ").";

		}

		//metodo para la entrada de datos
		void IntroducirSecuencia(char entrada[]){
			longitud_entrada = strlen(entrada);
			bool valida_intro;

			cout << "Introduce la secuencia a buscar: ";
			do{
				cin.getline(entrada, LONG);
				
				valida_intro = EntradaValida(entrada, longitud_entrada);
				if (!valida_intro)
					cout << "\nLas secuencias solo pueden contener \"A\", \"T\", \"G\" o \"C\". Vuelva a introducirla\n";
			}while (!valida_intro);
		}
};


int main(){
	//declaracion de variables
	class CoincidenciasADN secuencia_adn;

	//entrada de datos
	secuencia_adn.IntroducirSecuencia(secuencia_adn.entrada);

	//computos y salida
	secuencia_adn.MostrarCoincidencias(secuencia_adn.entrada);
}

