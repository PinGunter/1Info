#include <iostream>

using namespace std;

struct Partido{
	string local;
	string visitante;
};

int Emparejamientos (Partido emparejamientos[], string equipos[], int n_equipos){
	int numero_emparejamientos = 0;
	for (int i=0; i < n_equipos; i++){
		for (int j=i+1; j < n_equipos; j++){
			emparejamientos[numero_emparejamientos].local = equipos[i];
			emparejamientos[numero_emparejamientos].visitante = equipos[j];
			numero_emparejamientos++;
		}
	}
	return numero_emparejamientos;
}

void MostrarPartido(Partido partido){
	cout << "(" << partido.local << " - " << partido.visitante << ")" << endl;
}
int main(){
	string equipos[100];
	int n_equipos;
	Partido liga[100];
	cout << "Introduce el numero de equipos: ";
	cin >> n_equipos;
	for (int i=0; i < n_equipos; i++)
		cin >> equipos[i];
	int n_emparejamientos = Emparejamientos(liga, equipos, n_equipos);
	for (int i=0; i < n_emparejamientos; i++)
		MostrarPartido(liga[i]);
}
