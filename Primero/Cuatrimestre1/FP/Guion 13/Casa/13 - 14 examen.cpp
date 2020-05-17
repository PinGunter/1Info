// Programa para automatizar la realizacion de examenes tipo test
// 10/12/2019
// Salvador Romero Cortes

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int LONG = 100;

class Examen{
	private:
		string asignatura;
		vector <string> preguntas;
		vector <char> respuestas;
	public:
		Examen(string nombre){
			asignatura = nombre;
		}
		
		// metodo para insertar una nueva pregunta y su respuesta correcta
		void NuevaPregunta(string enunciado, char respuesta);
		
		//metodo que devuelve el numero de preguntas que hay
		int NumPreguntas();
		
		//metodo que devuelve el enunciado de una pregunta i-esima
		string GetEnunciado (int i);
		
		//metodo que devuelve la respuesta de una pregunta i-esima
		char GetRespuesta(int i);		
};

int PuntuacionExamen(int alumno);

int main(){
	//declaracion de objetos y variables
	string asignatura, pregunta;
	int num_alum, num_preguntas;
	double puntos = 0;
	char eleccion, respuesta, respuesta_correcta;
	bool bucle = true;
	
	//entrada de datos
	cout << "Introduce el nombre de la asignatura: ";
	getline(cin,asignatura);
	Examen examen(asignatura);
	
	do{
		cout << "Desea aniadir una pregunta? (S/N): ";
		cin >> eleccion;
		cin.ignore();
		if (eleccion == 'S' || eleccion == 's'){
			cout << "Pregunta:\n";
			getline(cin,pregunta);
			cout << "Respuesta: ";
			cin >> respuesta;
			examen.NuevaPregunta(pregunta,respuesta);
		}
		else if (eleccion == 'N' || eleccion == 'n')
			bucle = false;
	} while (bucle);
	
	num_preguntas = examen.NumPreguntas();
	
	//examinacion
	cout << "Introduce el numero de alumnos que realizaran la prueba: ";
	cin >> num_alum;
	
	for (int i=0; i < num_alum; i++){
		cout << "\tALUMNO " << i+1 << endl;
		for (int j=0; j < num_preguntas; j++){
			pregunta = examen.GetEnunciado(j);
			respuesta_correcta= examen.GetRespuesta(j);
			cout << pregunta << "('#' para no responder)\n";
			cin >> respuesta;
			if (respuesta == respuesta_correcta)
				puntos++;
			else if (respuesta == '#')
				puntos +=0;
			else 
				puntos--;

		}		
		//calculamos la nota sobre 10
		puntos = puntos/num_preguntas * 10;
		if (puntos < 0)
			puntos = 0;
		//mostramos la puntuacion
		cout << "\n --- La puntutacion del alumno es: " << puntos << " --- \n\n\n";
		puntos = 0;
	}
}

//definimos los metodos
//metodo para insertar nuevas preguntas y respuestas. Usamos un push back

void Examen::NuevaPregunta(string enunciado, char respuesta){
	preguntas.push_back(enunciado);
	respuestas.push_back(respuesta);
}

//devuelve el numero de preguntas
int Examen::NumPreguntas(){
	return preguntas.size();
}

//devuelve el enunciado i-esimo
string Examen::GetEnunciado(int i){
	return preguntas[i];
}

//devuelve la respuesta correcta 
char Examen::GetRespuesta(int i){
	return respuestas[i];
}
