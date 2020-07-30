// Programa para gestionar un campeonato de n equipos
// 10/12/2019
// Salvador Romero Cortes

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;
const int VICTORIA = 3;
const int EMPATE = 1;


class Liga {
private:
	int num_equip = MAX;
	vector<vector<char>> tabla;
public:
	Liga(){
		tabla.resize(MAX);
		for (int i = 0; i < MAX; i++)
			tabla[i].resize(MAX);
	}
	//metodo para introducir el numero de equipos
	void IntroNumEquip(int numero) {
		num_equip = numero;
	}

	//metodo para introducir datos en la matriz
	void IntroDatos(int i,int j, char dato) {
		tabla[i][j] = dato;
	}
	//metodo que devuelve la puntuacion de cada equipo de la liga
	vector<int> ResultadosLiga() {
		vector<int> salida(num_equip);
		for (int i = 0; i < num_equip; i++) {
			for (int j = 0; j < num_equip; j++) {
				if (tabla[i][j] == '1')
					salida[i] = salida[i] + VICTORIA;
				else if (tabla[i][j] == '2')
					salida[j] += VICTORIA;
				else if (tabla[i][j] == 'x' || tabla[i][j] == 'X'){
					salida[i] = salida[i] + EMPATE;
					salida[j] += EMPATE;
				}
			}
		}
		return salida;
	}
};

class GeneradorLiga {
public:
	//metodo que lee una matriz y devuelve un objeto liga
	Liga Lee() {
		int num;
		char dato;
		Liga liga;
		cerr << "Introduce el numero de equipos: ";
		cin >> num;
		liga.IntroNumEquip(num);

		cerr << "Introduce la matriz de la liga:\n";
		for (int i = 0; i < num; i++) {
			cerr << "\nFila " << i + 1 << " : ";
			for (int j = 0; j < num; j++) {
				cin >> dato;
				liga.IntroDatos(i,j, dato);
				if (j == i)
					liga.IntroDatos(i,j, 0);
			}
		}
		return liga;
	}
};

int main() {
	//declaracion de datos
	GeneradorLiga generador;
	Liga liga;
	vector<int> resultados;

	//entrada de datos
	liga = generador.Lee();

	//computos
	resultados = liga.ResultadosLiga();

	//salida de datos
	for (int i = 0; i < resultados.size(); i++) {
		cout << "\nEquipo " << i + 1 << " : ";
		cout << resultados[i];
	}
}
