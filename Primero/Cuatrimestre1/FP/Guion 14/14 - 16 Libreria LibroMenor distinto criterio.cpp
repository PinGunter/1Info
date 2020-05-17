// Programa para gestionar una libreria
// 14/12/2019
// Salvador Romero Cortes

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//clase que representa el identificador de un libro
//contiene metodos de comparacion
class Identificador{
	private:
		string id;
	public:

		/**
		 * @brief constructos sin parametros. Inicializa a "AAAA";
		 */
		Identificador();
		/**
			@brief constructor
			@param cadena string con tamanion maximo de 4 caracteres
		*/
		Identificador(string cadena);

		/**
		 * @brief metodo para introducir un valor al id
		 * @param cadena string con tamanio maximo de 4 caracteres
		 */
		void IntroId(string cadena);

		/**
			@brief metodo para obtener el identificador
			@retval string de 4 caracteres
		*/
		string GetId();

		/**
			@brief metodo que compara dos objetos de la clase identificador
			@param otro el identificador con el que se compara
			@retval devuelve true si son iguales
		*/
		bool EsIgual_a(Identificador otro);

		/**
			@brief metodo que comparar dos objetos de la clase Identificador
			@param otro el identificador con el que se compara
			@retval devuelve true si el primero es menor que el otro
		*/
		bool EsMenor_que(Identificador otro);
};

//clase para representar una fecha
class Fecha{
	private:
		int dia;
		int mes;
		int anio;

		/**
		 * @brief metodo que se asegura de que la fecha sea correcta
		 *	@retval true si es correcta
		 */
		bool FechaValida();
	public:
		/**
		 * @brief constructor predeterminado a 1/1/1
		*/
		Fecha();

		/**
			@brief metodo para establecer una fecha
			@param el_dia establece el dia que se va a establecer
			@param el_mes establece el mes
			@param el_anio establece el anio
		*/
		void SetDiaMesAnio(int el_dia, int el_mes, int el_anio);

		/**
			@brief metodo para obtener el dia de la fecha
			@retval devuelve el dia
		*/
		int Dia();

		/**
			@brief metodo para obtener el mes de la fecha
			@retval devuelve el mes
		*/
		int Mes();

		/**
			@brief metodo para obtener el anio de la fecha
			@retval devuelve el anio
		*/
		int Anio();

		/**
			@brief metodo para obtener un string con la fecha completa
			@retval devuelve string con la fecha
		*/
		string ToString();

		/**
			@brief metodo que compara dos fechas
			@param otro la fecha con la que se compara
			@retval true si la fecha primera es menor que la segunda
		*/
		bool EsMenor_que(Fecha otro);

		/**
			@brief metodo que comparar dos fechas
			@param otro la fecha con la que se compara
			@retval true si las dos fechas son iguales
		*/
		bool EsIgual_a(Fecha otro);

};

//clase para representar un libro, contiene su identificador y la fecha
//contiene metodos de comparacion
class Libro{
	private:
		Identificador identifica;
		Fecha date;
	public:
		/**
		 * @brief constructor predeterminado
		*/
		Libro();

		/**
			@brief constructor con parametros
			@param id el identificador
			@param fecha la fecha del libro
		*/
		Libro(Identificador id, Fecha fecha);

		/**
		 * @brief metodo para introducir los datos de un libro
		 * @param id el identificador
		 * @param fecha la fecha
		 */
		void IntroLibro(Identificador id, Fecha fecha);

		/**
			@brief metodo para comparar dos libros
			@param otro el libro con el que se compara
			@retval devuelve true si son iguales
		*/
		bool EsIgual_a(Libro otro);

		/**
			@brief metodo para comparar dos libros
			@param otro el libro con el que se compara
			@retval devuelve true si el primero es menor que el otro
		*/
		bool EsMenor_que(Libro otro);

		/**
			@brief metodo para obtener el id
			@retval el identificador del libro
		*/
		Identificador GetIdLibro();

		/**
			@brief metodo para obtener la fecha del libro
			@retval la fecha del libro
		*/
		Fecha GetFecha();

		/**
		 * @brief metodo para mostrar por pantalla el libro
		 */
		void Mostrar();
};

//clase para representar un conjunto de libros
class Biblioteca{
	private:
		vector<Libro> biblioteca;
	public:
		/**
			@brief metodo para introducir un libro a la biblioteca
			@param libro el libro que se aniade a la biblioteca
		*/
		void NuevoLibro(Libro libro);

		/**
			@brief metodo para obtener un libro de la biblioteca
			@param i es el indice del libro, la posicion en la biblioteca
			@retval libro i-esimo de la biblioteca
		*/
		Libro GetLibro(int i);

		/**
			@brief metodo para ordenar los libros por fecha de menor a mayor
		*/
		void Ordena();

		/**
		 * @brief metodo para saber el numero de libros
		 * @retval tamanio del vector
		 */
		int GetSize();

		/**
		 * @brief metodo para mostrar por pantalla el libro i-esimo
		 * @param i el indice del vector
		 */
		void MostrarLibro(int i);

};

//clase para leer los datos desde un fichero y crear una biblioteca
class LectorBiblioteca{
	public:
		/**
			@brief metodo para crear una nueva biblioteca a partir de un fichero
			@retval una biblioteca con los datos de entrada
		*/
		Biblioteca NuevaBiblioteca();
};

//clase para imprimir en pantalla todos los libros
class ImpresorBiblioteca{
	public:
		/**
			@brief imprime todos los libros de una biblioteca
			@param biblio biblioteca que se va a imprimir
		*/
		void ImprimeBiblio(Biblioteca biblio);
};


/*-------------------------------------------------*
*																	*
*					PROGRAMA PRINCIPAL						*
*																	*
*--------------------------------------------------*/

int main(){
	//declaracion de objetos
	LectorBiblioteca lector;
	ImpresorBiblioteca impresor;
	Biblioteca biblioteca;

	//entrada de datos
	biblioteca = lector.NuevaBiblioteca();

	//computos
	biblioteca.Ordena();

	//salida de datos
	impresor.ImprimeBiblio(biblioteca);
}



/*-------------------------------------------------*
*																	*
*					METODOS DE LAS CLASES					*
*																	*
*--------------------------------------------------*/


/*********** CLASE IDENTIFICADOR	***************/
Identificador::Identificador(){
	id = "AAAA";
}

Identificador::Identificador(string cadena){
	if (cadena.size() != 4)
		cadena.resize(4);
	id = cadena;
}

void Identificador::IntroId(string cadena){
	if (cadena.size() != 4)
		cadena.resize(4);
	id = cadena;
}

bool Identificador::EsIgual_a(Identificador otro){
	bool iguales = id.compare(otro.id) == 0;
	return iguales;
}

bool Identificador::EsMenor_que(Identificador otro){
	bool menor_que = id.compare(otro.id) < 0;
	return menor_que;
}

string Identificador::GetId(){
	return id;
}

/*********** CLASE FECHA	***************/

Fecha::Fecha(){
	dia = 1;
	mes = 1;
	anio = 1;
}


bool Fecha::FechaValida(){
	bool valida = false;
	bool es_bisiesto;
	bool meses31[12] = {1,0,1,0,1,0,1,1,0,1,0,1};
	
	if (mes >= 1 && mes <= 12){
		if (mes ==2){
			es_bisiesto = (anio%4 == 0) && ((anio%100 !=0) || (anio%400 == 0));
			
			if (es_bisiesto){
				if (dia <= 29 && dia >= 1)
						valida = true;
			}
			else
				if (dia <= 28 && dia >= 1)
					valida = true;
		}
		else if ( meses31[mes-1] ){
			if (dia <= 31 && dia >= 1)
				valida = true;
		}
		else
			if (dia <= 30 && dia>=1)
				valida = true;
	}
	return valida;
}

void Fecha::SetDiaMesAnio(int el_dia, int el_mes, int el_anio){
	dia = el_dia;
	mes = el_mes;
	anio = el_anio;
	if (!FechaValida()){
		dia = 1;
		mes = 1;
		anio = 1;
	}
}

int Fecha::Dia(){
	return dia;
}

int Fecha::Mes(){
	return mes;
}

int Fecha::Anio(){
	return anio;
}

string Fecha::ToString(){
	return to_string(dia) + "/" + to_string(mes) + "/" + to_string(anio);
}

bool Fecha::EsMenor_que(Fecha otro){
	bool menor;

	if (anio < otro.anio)
		menor = true;
	else if (anio > otro.anio)
		menor = false;
	else{
		if (mes < otro.mes)
			menor = true;
		else if (mes > otro.mes)
			menor = false;
		else {
			if (dia < otro.dia)
				menor = true;
			else
				menor = false;
		}
	}

	return menor;
}

bool Fecha::EsIgual_a(Fecha otro){
	bool iguales = dia == otro.Dia() && mes == otro.Mes() && anio == otro.Anio();
	return iguales;
}

/*********** CLASE LIBRO	***************/

Libro::Libro(){
	identifica.IntroId("AAAA");
	date.SetDiaMesAnio(1,1,1);
}

Libro::Libro(Identificador id, Fecha fecha){
	identifica = id;
	date = fecha;
}

void Libro::IntroLibro(Identificador id, Fecha fecha){
	identifica = id;
	date = fecha;
}

Identificador Libro::GetIdLibro(){
	return identifica;
}

Fecha Libro::GetFecha(){
	return date;
}

bool Libro::EsIgual_a(Libro otro){
	bool iguales = identifica.EsIgual_a(otro.GetIdLibro()) && date.EsIgual_a(otro.GetFecha());
	return iguales;
}

bool Libro::EsMenor_que(Libro otro){
	bool menor;
	if (date.EsMenor_que(otro.GetFecha()))
		menor = false;
	else if (otro.GetFecha().EsMenor_que(date))
		menor = true;
	else{
		if (identifica.EsMenor_que(otro.GetIdLibro()))
			menor = true;
		else
			menor = false;
	}
	
	return menor;
}

void Libro::Mostrar(){
	cout << identifica.GetId();
	cout << " ";
	cout << date.ToString();
}

/*********** CLASE BIBLIOTECA	***************/
void Biblioteca::NuevoLibro(Libro libro){
    biblioteca.push_back(libro);
}

Libro Biblioteca::GetLibro(int i){
	return biblioteca[i];
}

void Biblioteca::Ordena(){
	int j;
	Libro a_desplazar;
	for (int i=1; i < biblioteca.size(); i++){
		a_desplazar = biblioteca[i];

		for (j=i; j > 0 && a_desplazar.EsMenor_que(biblioteca[j-1]); j--)
			biblioteca[j] = biblioteca[j-1];
		
		biblioteca[j] = a_desplazar;
	}
}

int Biblioteca::GetSize(){
	return biblioteca.size();
}

void Biblioteca::MostrarLibro(int i){
	biblioteca[i].Mostrar();
}

/*********** CLASE LECTORBIBLIOTECA	***************/
Biblioteca LectorBiblioteca::NuevaBiblioteca(){
	Biblioteca biblio;
	Libro libro;
	Identificador id;
	Fecha date;

	string identifica, terminador = "FFFF";
	int d, m, a;
	do{
		cin >> identifica;
		if (identifica != terminador)
			cin >> d >> m >> a;
		date.SetDiaMesAnio(d,m,a);
		id.IntroId(identifica);
		libro.IntroLibro(id, date);
		if (identifica != terminador){
			biblio.NuevoLibro(libro);
		}
	} while (identifica != terminador);
	return biblio;
}

/*********** CLASE IMPRESORBIBLIOTECA	***************/

void ImpresorBiblioteca::ImprimeBiblio(Biblioteca biblio){
	for (int i=0; i < biblio.GetSize();i++){
		biblio.MostrarLibro(i);
		cout << " ";
	}
}