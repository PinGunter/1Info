//VectorParejasCaracterEntero
//08/12/2019
//Salvador Romero Cortes

#include <iostream>
#include <vector>

using namespace std;

struct ParejaCaracterEntero{
	char caracter;
	int entero;
};

class VectorParejasCaracterEntero{
	private:
		vector<ParejaCaracterEntero> conjunto;
	
	public:
		//metodo para inicializar el conjunto
		void Inicializar(int tamanio, char caracter[], int entero[]);
				
		//metodos para tener los distintos datos
		char GetChar(int indice);
		
		int GetInt(int indice);
		
		int GetSize();
		
		vector<ParejaCaracterEntero> GetTodo();
};

class Frase {
private:
	vector<char> frase;
	vector<int> posiciones;
	//metodo para inicializar el vector de posiciones
	void InicializarPosiciones();

public:
	//metodo para inicializar la frase
	void InicializarFrase(const char entrada[]);

	//metodo para localizar la k-esima palabra
	int LocalizarPalabra(int k_esima);

	//metodo para eliminar los blancos finales
	void EliminaBlancosIniciales();

	//metodo para eliminar los blancos finales
	void EliminaBlancosFinales();

	//metodo que devuelve el numero de palabras que hay en una frase
	int NumeroPalabras();

	//metodo para borrar la k-esima palabra
	void BorrarPalabra(int k_esima);

	//metodo para desplazar la palabra k-esima al final de la frase
	void MoverPalabraFinal(int k_esima);

	//metodo para imprimir la frase
	void Imprimir();
	
	//metodo para eliminar un determinado caracter
	void EliminarCaracteres(int posicion);
	
	//metodo para eliminar una pareja de la frase
	Frase EliminarPareja(VectorParejasCaracterEntero pareja);
};

int TamanioCadena(const char cadena[]) {
	int tamanio = 0;
	int i = 0;
	while (cadena[i] != '\0') {
		tamanio++;
		i++;
	}
	return tamanio;
}

int main() {
	const int LONG = 100;
	//declaracion de variables y objetos
	char cadena[LONG];
	Frase entrada, salida;
	VectorParejasCaracterEntero parejas;
	int tamanio, entero[LONG];
	char car [LONG];
	
	//entrada de datos
	cout << "Introduce la frase:\n";
	cin.getline(cadena, LONG);
	
	cout << "\nIntroduce el tamanio del vector de parejas: ";
	cin >> tamanio;
	
	cout << "\nIntroduce los elementos del vector de parejas: ";
	for (int i=0; i < tamanio; i++){
		cout << "\nCaracter: ";
		cin >> car[i];
		cout << "Entero: ";
		cin  >> entero[i];
	}
	
	//Computos
	parejas.Inicializar(tamanio, car, entero);
	entrada.	InicializarFrase(cadena);
	salida = entrada.EliminarPareja(parejas);
	
	//salida
	cout << "La frase con las parejas eliminadas queda como: ";
	salida.Imprimir();
}

//metodo que contiene las posiciones de cada palabra
void Frase::InicializarPosiciones() {
	int i = 0;
	while (i < frase.size()){
		if ((frase[i] != ' ' && frase[i - 1] == ' ') || (i == 0 && frase[i] != ' ')) {
			posiciones.push_back(i);
		}
		i++;
	}
}

void Frase::InicializarFrase(const char entrada[]) {
	int longitud = TamanioCadena(entrada);
	for (int i = 0; i < longitud; i++)
		frase.push_back(entrada[i]);
	InicializarPosiciones();
}

void Frase::Imprimir() {
	for (int i = 0; i < frase.size(); i++)
		cout << frase[i];
}

int Frase::LocalizarPalabra(int k_esima) {
	return posiciones[k_esima - 1];
}

void Frase::EliminaBlancosIniciales() {
	for (int i = 0; i <= posiciones[0]; i++) {
		if (frase[i] == ' ')
			for (int j = 0; j < frase.size()-1; j++)
				frase[j] = frase[j + 1];
	}
}

void Frase::EliminaBlancosFinales() {
	int blancos_finales = 0;
	for (int i = posiciones[posiciones.size()-1]; i < frase.size(); i++){
		if (frase[i] == ' ')
			blancos_finales++;
	}
	
	frase.resize(frase.size()-blancos_finales);
}

int Frase::NumeroPalabras(){
	return posiciones.size();
}

void Frase::BorrarPalabra(int k_esima){
	if (k_esima != posiciones.size()){
		int posicion = posiciones[k_esima-1];
		int ejecucion = posiciones[k_esima] - posicion;
		for (int i=0; i < ejecucion; i++){
			for (int j=posicion; j <= frase.size(); j++)
				frase[j] = frase[j+1];
		}
		frase.resize(frase.size()-ejecucion);
	}
	else{
		for (int i=frase.size(); i > posiciones[k_esima-1];i--)
			if (frase[i] != ' ')
				frase.pop_back();
	}
}

void Frase::MoverPalabraFinal(int k_esima){
	Frase aux;
	aux.frase = frase;
	aux.posiciones = posiciones;
	BorrarPalabra(k_esima);
	int tamanio = 0;
	
	//borramos las palabras anteriores a la k_esima
	for (int i=k_esima-1; i > 0; i--)
		aux.BorrarPalabra(i);
	
	//contamos el tamanio de la palabra k_esima
	for (int i=0; i < aux.frase.size() && aux.frase[i] != ' '; i++)
		if (aux.frase[i] != ' ')
			tamanio++;
	
	aux.frase.resize(tamanio);
	for (int i=0; i < aux.frase.size(); i++)
		frase.push_back(aux.frase[i]);
}

void Frase::EliminarCaracteres(int posicion){
	int total_utilizados = frase.size();
	int tope;
	if (posicion >=0 && posicion < total_utilizados){
		tope = total_utilizados-1;
		
		for (int i=posicion; i < tope; i++){
			frase[i] = frase[i+1];
		}
		total_utilizados--;
		frase.resize(total_utilizados);
	}
}

Frase Frase::EliminarPareja(VectorParejasCaracterEntero pareja){
	Frase resultado;
	resultado.frase = frase;
	resultado.posiciones = posiciones;
	int ejecuciones = pareja.GetSize();
	int entero;
	char caracter;
	bool parar;
	
	for (int i=0; i < ejecuciones; i++){
		entero = pareja.GetInt(i);
		caracter = pareja.GetChar(i);
		for (int k=0; k < entero; k++){
			parar = false;
			for (int j=0; j < resultado.frase.size() && !parar; j++){
				if (resultado.frase[j] == caracter){
					resultado.EliminarCaracteres(j);
					parar = true;
				}
			}
		}
	}
	return resultado;
}

void VectorParejasCaracterEntero::Inicializar(int tamanio, char caracter[], int entero[]){
	conjunto.resize(tamanio);
	for (int i=0; i < tamanio; i++){
		conjunto[i].caracter = caracter[i];
		conjunto[i].entero = entero[i];
	}
}	

char VectorParejasCaracterEntero::GetChar(int indice){
	return conjunto[indice].caracter;
}

int VectorParejasCaracterEntero::GetInt(int indice){
	return conjunto[indice].entero;
}

int VectorParejasCaracterEntero::GetSize(){
	return conjunto.size();
}

vector<ParejaCaracterEntero> VectorParejasCaracterEntero::GetTodo(){
	return conjunto;
}
