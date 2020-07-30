#include <iostream>

using namespace std;

bool EstaOrdenado(int vector[], int longitud);

class SecuenciaCaracteres{
	private:
	   static const int TAMANIO = 50;
	   char vector_privado[TAMANIO];
	   int total_utilizados;
	
	public:
	   SecuenciaCaracteres()
	      :total_utilizados(0) {
	   }
	   
	   void SetTotal(int numero){
			total_utilizados = numero;
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
	
		int ContieneCaracter(char elemento, int comienzo){
			int posicion = -1;
			for (int i=comienzo; i < total_utilizados; i++){
				if (elemento == vector_privado[i])
					posicion = i;
			}
			return posicion;
		}
		
		bool ContieneDebilmenteA(SecuenciaCaracteres otra){
			bool contiene_debil;
			const int LONGITUD = otra.TotalUtilizados();
			int posiciones[LONGITUD];
			int inicio = 0;
			bool romper = false;
			
			for (int i=0; i < LONGITUD && !romper; i++){
				posiciones[i] = ContieneCaracter(otra.Elemento(i), inicio);
				inicio = posiciones[i]+1;
				if (inicio == 0)
					romper = true;			
			}
			if (romper) contiene_debil = false; 
			else	contiene_debil = EstaOrdenado(posiciones, otra.TotalUtilizados());
		
			return contiene_debil;
		}
};

bool EstaOrdenado(int vector[], int longitud){
	bool ordenado = true;
	for (int i=1; i < longitud; i++)
		if (vector[i] < vector[i-1])
			ordenado = false;
	return ordenado;
}

int main(){
	SecuenciaCaracteres p,q;
	int total1, total2;
	char aux;
	bool contiene;
	cout << "Introduce el tamanio de la primera cadena: ";
	cin >> total1;
	for (int i=0; i < total1; i++){
		cin >> aux;
		p.Aniade(aux);
	}
	
	cout << "Introduce el tamanio de la segunda cadena: ";
	cin >> total2;
	for (int i=0; i < total2; i++){
		cin >> aux;
		q.Aniade(aux);
	}
	
	contiene = p.ContieneDebilmenteA(q);
	
	if (contiene) cout << "CONTIENE" <<endl;
	else cout << "NO" << endl;
}
