#include <iostream>
#include <fstream>

using namespace std;

void Aniadir(string *& lista, int &n, const string &nuevo);
void Interseccion(const string * lista1, int n1, const string * lista2, int n2, string *& interseccion, int &ni);


int main(int nargs, char * args[]) {
    string *lista1, *lista2, *interseccion;
    int n1 = 0, n2 = 0, ni = 0;
    lista1 = lista2 = interseccion = nullptr;
    ifstream archivo;
    istream *entrada;
    string nombre_archivo;

    if (nargs != 2) {
        cerr << "Número de argumnetos incorrecto." << endl;
        return 1;
    }

    nombre_archivo = args[1];

    archivo.open(nombre_archivo);
    if (!archivo) {
        cerr << "No se puede abrir el fichero." << endl;
        return 1;
    } else {
        entrada = &archivo;
        *entrada >> n1;
        lista1 = new string[n1];
        for (int i = 0; i < n1; i++)
            *entrada >> lista1[i];

        *entrada >> n2;
        lista2 = new string[n2];
        for (int i = 0; i < n2; i++)
            *entrada >> lista2[i];

        archivo.close();
    }
    
    Interseccion(lista1, n1, lista2, n2, interseccion, ni);
    for (int i=0; i < n1; i++)
        cout << lista1[i] << " ";
    cout << endl;
    for (int i=0; i < n2; i++)
        cout << lista2[i] << " ";
    
    cout << endl << "Resultado:" << endl;
    for (int i = 0; i < ni; i++)
        cout << interseccion[i] << endl;

    if (lista1 != nullptr)
        delete [] lista1;
    if (lista2 != nullptr)
        delete [] lista2;
    if (interseccion != nullptr)
        delete [] interseccion;
}

void Aniadir(string *& lista, int &n, const string &nuevo){
    string *nuevostr = new string [n+1];
    for (int i=0 ; i < n; i++)
        nuevostr[i] = lista[i];
    delete [] lista;
    lista = nuevostr;
    n += 1;
    lista[n-1] = nuevo;
}
void Interseccion(const string * lista1, int n1, const string *lista2, int n2, string *& interseccion, int &ni){
    for (int i=0; i < n1; i++){
        for (int j=0; j < n2; j++){
            if (lista1[i] == lista2[j])
                Aniadir(interseccion,ni,lista2[j]);   
        }
    }
}


