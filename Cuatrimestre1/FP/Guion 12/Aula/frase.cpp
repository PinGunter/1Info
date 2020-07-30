//Programa para operar con una frase
// 07/12/2019
// Salvador Romero Cortes

#include <iostream>
#include <vector>

using namespace std;

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
	char entrada[LONG];
	int localizador, borrador, mover, localizado, numero_palabras;
	Frase enunciado, sin_b_iniciales, sin_b_finales, borrada, movida;

	//Entrada de datos
	cout << "Introduce la frase:\n";
	cin.getline(entrada, LONG);

	cout << "Introduce el numero de la palabra cuya posicion quieres conocer: ";
	cin >> localizador;
	
	cout << "Introduce el numero de la palabra que quieres borrar: ";
	cin >> borrador;
	
	cout << "Introduce el numero de la palabra que quieres mover al final: ";
	cin >> mover;

	//computos
	//inicializamos frases
	enunciado.InicializarFrase(entrada);
	sin_b_iniciales.InicializarFrase(entrada);
	sin_b_finales.InicializarFrase(entrada);
	borrada.InicializarFrase(entrada);
	movida.InicializarFrase(entrada);

	localizado = enunciado.LocalizarPalabra(localizador);

	//borramos los espacios iniciales y los finales
	sin_b_iniciales.EliminaBlancosIniciales();
	sin_b_finales.EliminaBlancosFinales();

	numero_palabras = enunciado.NumeroPalabras();
	
	borrada.BorrarPalabra(borrador);
	
	movida.MoverPalabraFinal(mover);

	//salida de datos
	cout << "\nLa frase que has introducido es: ";
	enunciado.Imprimir();
	cout << "\nLa posicion de la palabra " << localizador << " es " << localizado << endl;
	cout << "\nLa frase sin los blancos iniciales queda como: |";
	sin_b_iniciales.Imprimir();
	cout << "|";
	cout << "\nLa frase sin los blancos finales queda como: |";
	sin_b_finales.Imprimir();
	cout << "|";
	cout << "\nEn la frase hay " << numero_palabras << " palabras";
	cout << "\nLa frase con la palabra " << borrador << " borrada queda como: ";
	borrada.Imprimir();
	cout << "\nLa frase con la palabra movida es: ";
	movida.Imprimir();	
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
