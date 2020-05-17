//Extraordinario 2019
#include <iostream>

using namespace std;

class SecuenciaCaracteres{
private:
   static const int TAMANIO = 50;
   char vector_privado[TAMANIO];
   int total_utilizados;

public:
   SecuenciaCaracteres()
      :total_utilizados(0) {
   }

   int TotalUtilizados(){
      return total_utilizados;
   }

   int Capacidad(){
      return TAMANIO;
   }

   void Aniade(char nuevo){
      if (total_utilizados < TAMANIO){
         vector_privado[total_utilizados] = nuevo;
         total_utilizados++;
      }
   }

   char Elemento(int indice){
      return vector_privado[indice];
    }

	bool ContieneCaracter(char buscado){
		bool encontrado = false;
		for (int i = 0; i <total_utilizados; i++)
			if (vector_privado[i] == buscado)
				encontrado = true;
		return encontrado;
	}

	int ContieneAEnIntervalo(SecuenciaCaracteres contenido, int inicio, int final){
		int posicion = -1;
		int counter = 0, indice = 0;
		bool encontrado = false;

		for (int i=inicio; i < final-contenido.TotalUtilizados() && !encontrado;i++){
			for (int j=i; j < final;j++){
				if (contenido.Elemento(indice++) == vector_privado[j])
					counter++;
				else{
					counter = 0;
					indice = 0;
				}
				if (counter == contenido.TotalUtilizados()){
					encontrado = true;
					posicion = i;
				}
			}
		}
		return posicion;
	}

	bool Contiguo(char izda, SecuenciaCaracteres dcha){
		bool contiguo = true;
		int posicion_busqueda =0;

		contiguo = !dcha.ContieneCaracter(izda);

		for (int i=0; i <total_utilizados && contiguo;i++){
			if (vector_privado[i] == izda){
				if (posicion_busqueda == 0)
					posicion_busqueda = ContieneAEnIntervalo(dcha,i+1,total_utilizados);
				else
					posicion_busqueda = ContieneAEnIntervalo(dcha,posicion_busqueda+1, total_utilizados);

				if (posicion_busqueda != -1)
					posicion_busqueda += dcha.TotalUtilizados();
				else
					contiguo = false;
			}
		}
		return contiguo;
	}

};


int main(){
	SecuenciaCaracteres frase, dcha;
	char izda, caracter;
	int numero;
	
	cout << "Introduce el numero de caracteres: ";
	cin >> numero;
	
	cout << "Introduce los caracteres: ";
	for (int i=0; i < numero; i++){
		cin >> caracter;
		frase.Aniade(caracter);
	}
	
	cout << "Introduce la izda: ";
	cin >> izda;
	cout << "Introduce el numero de caracteres de dcha: ";
	cin >> numero;
	cout << "Introduce los caracteres de dcha:";
	for (int i=0; i < numero; i++){
		cin >> caracter;
		dcha.Aniade(caracter);
	}
	
	bool contiguo = frase.Contiguo(izda,dcha);
	
	cout << "\n\n\n" << contiguo;
}
