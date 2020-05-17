//Programa para trabajar con clase de libro
#include <iostream>
#include <string>

using namespace std;

class Libro {
private:
	string titulo, autor, editorial;
	int anio;

	//metodos de comparacion
	bool MismoTitulo(Libro libro2);
	bool MismoAutor(Libro libro2);
	bool MismaEdit(Libro libro2);
	bool MismoAnio(Libro libro2);

public:
	//metodos para asignar los distintos campos
	void SetLibro(string titu, string aut, string edit, int a);
	void SetTitulo(string entrada);
	void SetAutor(string entrada);
	void SetEditorial(string entrada);
	void SetAnio(int entrada);

	//metodos para devolver los campos
	string GetTitulo();
	string GetAutor();
	string GetEditorial();
	int GetAnio();
	string GetTodo();

	//metodos de comparacion
	void ComparaLibro(Libro libro2);
};

bool SwitchOpciones(Libro libro, Libro libro2, int eleccion);

int main() {
	//declaracion de objetos y variables
	Libro libro1, libro2;
	string titu, aut, edit, titu2, aut2, edit2;
	int ano, ano2;
	bool salir = false;
	int eleccion, eleccion_libro;
	string opciones = "\n1)Mostrar todos los datos\n2)Mostrar el titulo\n3)Mostrar el autor\n4)Mostrar la editorial\n5)Mostrar el anio de salida\n6)Comparar con el otro libro\n7)Salir\n";


	//entrada de datos
	cout << "\tLibro 1\n";
	cout << "Introduce el titulo: ";
	getline(cin, titu);
	cout << "\nIntroduce el autor: ";
	getline(cin, aut);
	cout << "\nIntroduce la editorial: ";
	getline(cin, edit);
	cout << "\nIntroduce el anio: ";
	cin >> ano;

	cin.ignore();
	cout << "\tLibro 2\n";
	cout << "Introduce el titulo: ";
	getline(cin, titu2);
	cout << "\nIntroduce el autor: ";
	getline(cin, aut2);
	cout << "\nIntroduce la editorial: ";
	getline(cin, edit2);
	cout << "\nIntroduce el anio: ";
	cin >> ano2;

	//asignamos las variables a las variables de los objetos
	libro1.SetLibro(titu, aut, edit, ano);
	libro2.SetLibro(titu2, aut2, edit2, ano2);

	//hacemos switch para elegir las opciones

	while (!salir) {
		cout << "\nElija el libro sobre el que va a trabajar (1 o 2): ";
		cin >> eleccion_libro;

		salir = false;
		if (eleccion_libro == 1) {
			cout << "\nIntroduce la opcion que desee: ";
			cout << opciones;
			cin >> eleccion;

			salir = SwitchOpciones(libro1, libro2, eleccion);
		}
		else if (eleccion_libro == 2) {
			cout << "\nIntroduce la opcion que desee: ";
			cout << opciones;
			cin >> eleccion;

			salir = SwitchOpciones(libro2, libro1, eleccion);
		}
	}
}

bool SwitchOpciones(Libro libro, Libro libro2, int eleccion) {
	bool exit = false;
	switch (eleccion) {
		case 1:
			cout << "Los datos del libro son:\n";
			cout << libro.GetTodo();
			break;
		case 2:
			cout << "Titulo: " << libro.GetTitulo() << endl;
			break;
		case 3:
			cout << "Autor: " << libro.GetAutor() << endl;
			break;
		case 4:
			cout << "Editorial: " << libro.GetEditorial() << endl;
			break;
		case 5:
			cout << "Anio: " << libro.GetAnio() << endl;
			break;
		case 6:
			cout << "\nComparacion:\n";
			libro.ComparaLibro(libro2);
			break;
		case 7:
			exit = true;
			break;
		default:
			exit = false;
			break;
	}
	return exit;
}

//definicion de metodos

bool Libro::MismoTitulo(Libro libro2) {
	bool iguales = titulo == libro2.titulo;
	return iguales;
}

bool Libro::MismoAutor(Libro libro2) {
	bool iguales = autor == libro2.autor;
	return iguales;
}

bool Libro::MismaEdit(Libro libro2) {
	bool iguales = editorial == libro2.editorial;
	return iguales;
}

bool Libro::MismoAnio(Libro libro2) {
	bool iguales = anio == libro2.anio;
	return iguales;
}

void Libro::SetLibro(string titu, string aut, string edit, int a) {
	titulo = titu;
	autor = aut;
	editorial = edit;
	anio = a;
}

void Libro::SetTitulo(string entrada) {
	titulo = entrada;
}

void Libro::SetAutor(string entrada) {
	autor = entrada;
}

void Libro::SetEditorial(string entrada) {
	editorial = entrada;
}

void Libro::SetAnio(int entrada) {
	anio = entrada;
}

string Libro::GetTitulo() {
	return titulo;
}

string Libro::GetAutor() {
	return autor;
}

string Libro::GetEditorial() {
	return editorial;
}

int Libro::GetAnio() {
	return anio;
}

string Libro::GetTodo() {
	string toda_info = "Titulo: " + titulo + "\nAutor: " + autor + "\nEditorial: " + editorial + "\nAnio: " + to_string(anio);
	return toda_info;
}

void Libro::ComparaLibro(Libro libro2) {
	bool titulos = titulo == libro2.titulo;
	bool autores = autor == libro2.autor;
	bool edits = editorial == libro2.editorial;
	bool anios = anio == libro2.anio;
	bool todo = titulos && autores && edits && anios;

	if (todo)
		cout << "Los libros son iguales.\n";
	else {
		cout << "Los aspectos diferentes son:\n";
		if (!titulos)
			cout << "Titulo 1: " << titulo << " --- Titulo 2: " << libro2.titulo << endl;
		if (!autores)
			cout << "Autor 1: " << autor << " --- Autor 2: " << libro2.autor << endl;
		if (!edits)
			cout << "Editorial 1: " << editorial << " --- Editorial 2: " << libro2.editorial << endl;
		if (!anios)
			cout << "Anio 1: " << anio << " --- Anio 2: " << libro2.anio << endl;
	}
}
