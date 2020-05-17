// Tres en raya
// 12/12/2019
// Salvador Romero Cortes

#include <iostream>

using namespace std;

const int LONG = 100;
const int JUGADOR1 = 1;
const int JUGADOR2 = 2;

class MEnRaya{
   private:
      int orden;
      int raya;
      int tablero[LONG][LONG];
      
      /**
      	@brief metodo para saber si la entrada es correcta
      	@return devuelve true si es valida y false en caso contrario
      **/
      bool EntradaValida(int x);
      
      /*
      	@brief metodo que comprueba si hay una ficha en el tablero
      	@return true si hay, false si no
      */
      bool HayFicha(int x, int y);
   public:
      MEnRaya(int tamanio, int linea){
      	raya = linea;
      	orden = tamanio;
         for (int i=0; i < orden; i++)
            for (int j = 0; j < orden; j++)
               tablero[i][j] = 0;
      }
      
      /*
         @brief metodo que muestra el tablero por pantalla
      */
      void MostrarTablero();
      
      /*
         @brief metodo que coloca la ficha del jugador en una posicion del tablero
         @param jugador indica el jugador que coloca la ficha en este turno
         @param x indica la fila del tablero donde se va a colocar
         @param y indica la columna
         @return no devuelve nada, llama a MostrarTablero() con cada ejecucion
      */
      void ColocarFicha(int jugador, int x, int y);
      
      /*
      	@brief metodo que pregunta donde colocar las fichas
      */
      void PreguntaLocalizacion(int jugador);
      
      /*
         @brief metodo que comprueba si ha ganado un jugador. Comprobamos todas las filas, columnas y diagonales. Las diagonales son tablero[i][j] +- un contador para ir desplzando la diagonal
         @param jugador comprobara si ese jugador ha ganado
         @return true si ha ganado y false si debe seguir en juego
      */
      bool HaGanado(int jugador);
      
      /*
         @brief metodo que comprueba si esta todo el tablero lleno
         @return true si es empate, false si debe seguir en juego
      */
      bool HayEmpate();
      
      /*
         @brief metodo que compruebas las condiciones anteriores
         @return true si hay que seguir con la partida y false si hay que parar
      */
      bool SigueJuego();
      
      /*
      	@brief metodo que muestra el ganador del juego
      */
      void FinJuego();
};

/*
	@brief funcion que borra la pantalla, la usaremos para mostrar el tablero y que no quede muy saturada la pantalla
*/
void BorrarPantalla();

int main(){
	int orden, raya;
	int ronda = 1;
	bool jugando = true;
	int ganador;
	
	cout << "Introduce el tamanio del tablero: ";
	cin >> orden;
	cout << "Introduce el numero de elementos en raya necesarios para ganar: ";
	cin >> raya;
	
	BorrarPantalla();
	MEnRaya juego(orden,raya);		
	juego.MostrarTablero();
	while (jugando){
		cout << "\n\n\t --- RONDA " << ronda << " ---\n";	
		juego.PreguntaLocalizacion(JUGADOR1);
		jugando = juego.SigueJuego();
		if (jugando){
			juego.PreguntaLocalizacion(JUGADOR2);
			jugando = juego.SigueJuego();
		}
		ronda++;
	}
	juego.FinJuego();
}

void BorrarPantalla(){
	system("cls");
}

void MEnRaya::MostrarTablero(){
	for (int i=0; i < orden;i++){
		cout << "\t";
		for (int k=0; k < orden; k++)
			cout << "----";
		cout << "\n\t|";
		for (int j=0; j < orden; j++)
			cout << tablero[i][j] << " | ";

		cout << "\n";
	}
}

void MEnRaya::ColocarFicha(int jugador, int x, int y){
	if (jugador == JUGADOR1)
		tablero[x-1][y-1] = JUGADOR1;
	else if (jugador == JUGADOR2)
		tablero[x-1][y-1] = JUGADOR2;
}

void MEnRaya::PreguntaLocalizacion(int jugador){
	int x,y;
	bool valido, existe;
	do{
		cout << "\nJugador " << jugador << ":\n";
		do{
			cout << "Introduce la fila donde quieres colocar la ficha: ";
			cin >> x;
			valido = EntradaValida(x);
			if (!valido)
				cout << "\n--Entrada no valida--\n";
		} while (!valido);
		do{
			cout << "Introduce la columna donde quieres colocar la ficha: ";
			cin >> y;
			valido = EntradaValida(y);
			if (!valido)
				cout << "\n--Entrada no valida--";
		} while (!valido);
		
		existe = HayFicha(x,y);
		if (existe)
			cout << "\n-- Ya hay una ficha colocada en esa posicion -- ";
	} while (existe);
	ColocarFicha(jugador,x,y);
	BorrarPantalla();
	MostrarTablero();
}

bool MEnRaya::HaGanado(int jugador){
		bool ha_ganado;
		bool columna = false;
		bool fila = false;
		bool diag_izq = false;
		bool diag_dcha = false;
		int contador = 0;
		
		//filas
		for (int i=0; i < orden; i++){
			contador = 0;
			for (int j=0; j < orden; j++){
				if (tablero[i][j] == jugador)
					contador++;
				if (tablero[i][j] != jugador)
						contador = 0;
			}
				if (contador == raya)
					fila = true;
		}
		
		//columnas
		for (int i=0; i < orden; i++){
			contador = 0;
			for (int j=0; j < orden; j++){
				if (tablero[j][i] == jugador)
					contador++;
				if (tablero[j][i] != jugador)
					contador = 0;
			}
				if (contador == raya)
					columna = true;
		}
		
		//diagonal derecha arriba
		for (int i=0; i < orden; i++){
			contador = 0;
			for (int j=0; j < orden-i;j++){
				if (tablero[j][j+i] == jugador)
					contador ++;
				if (tablero[j][j+i] != jugador)
						contador = 0;
				if (contador == raya)
					diag_dcha = true;
			}
		}
		
		//diagonal derecha abajo
		for (int i=0; i < orden; i++){
			contador = 0;
			for (int j=0; j < orden-i;j++){
				if (tablero[j+i][j] == jugador)
					contador ++;
				if (tablero[j+i][j] != jugador)
						contador = 0;
				if (contador == raya)
					diag_dcha = true;
			}
		}
		
		//diagonal izquierda arriba
		for (int i=0; i < orden; i++){
			contador = 0;
			for (int j=0 ; j < orden-i; j++){
				if (tablero[j][orden-j-i-1] == jugador)
					contador++;
				if (tablero[j][orden-j-i-1] != jugador)
					contador = 0;
				if (contador == raya)
					diag_izq = true;
			}
		}
		
		//diagonal izquierda abajo
		for (int i=0; i < orden; i++){
			contador = 0;
			for (int j=i ; j < orden; j++){
				if (tablero[orden-j][j] == jugador)
					contador++;
				if (tablero[orden-j][j] != jugador)
						contador = 0;
				if (contador == raya)
					diag_izq = true;
			}
		}
	
	ha_ganado = diag_izq || diag_dcha || fila || columna;
	return ha_ganado;
}

bool MEnRaya::HayEmpate(){
	bool empate = true;
	for (int i=0; i < orden;i++)
		for (int j=0; j < orden;j++)
			if (tablero[i][j] ==0)
				empate = false;
				
	return empate;				
}

bool MEnRaya::SigueJuego(){
	bool en_curso = !HayEmpate() && !HaGanado(JUGADOR1) && !HaGanado(JUGADOR2);
	return en_curso;
}

void MEnRaya::FinJuego(){
	int ganador;
	if (HaGanado(JUGADOR1) || HaGanado(JUGADOR2)){
		if (HaGanado(JUGADOR1))
			ganador = JUGADOR1;
		else 
			ganador = JUGADOR2;
		
		cout << "\n\n---  HA GANADO EL JUGADOR " << ganador << " --- ";
	}
	
	if (HayEmpate())
		cout << " --- EMPATE --- ";

}

bool MEnRaya::EntradaValida(int x){
	bool valido = x <= orden && x > 0;
	return valido;
}

bool MEnRaya::HayFicha(int x, int y){
	bool existe = tablero[x-1][y-1] != 0;
	return existe;
}
