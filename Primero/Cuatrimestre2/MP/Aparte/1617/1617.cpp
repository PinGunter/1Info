#include <iostream>
#include <fstream>

using namespace std;

void Inicializar(string * & lista, int &n);
void Liberar(string *& lista, int &n);
void Aniadir(string *& lista, int &n , const string &nuevo);
bool EstaAniadido(const string *lista,int n, const string &comprobado);
void LeerFichero(istream &is, string *&lista, int &n);
void Union(const string * lista1, int n1, const string *lista2, int n2, string *&resul, int &nr);

int main(int nargs, char * args[]){
    string * listaA = nullptr;
    string * listaB = nullptr;
    string * resultado = nullptr;
    int nA = 0, nB = 0, nR = 0;
    ifstream ficheroA, ficheroB;
    string nombreA, nombreB;
    istream *entradaA, *entradaB;

    //procesamos los argumentos
    if (nargs != 5){
        cerr << "Numero de parametros incorrectos" << endl;
        return 1;
    }

    for (int i=1; i < nargs;){
        string param = args[i++];
        if (param == "-a")
            nombreA = args[i++];
        else if (param == "-b")
            nombreB = args[i++];
        else{
            cerr << "Parámetros incorrecots" << endl;
            return 1;
        }
    }

    //abrimos los ficheros
    ficheroA.open(nombreA);
    if (!ficheroA){
        cerr << "Error al abrir el primer archivo" << endl;
        return 1;
    } else{
        entradaA = &ficheroA;
        LeerFichero(*entradaA,listaA,nA);
        ficheroA.close();
    }
    
    ficheroB.open(nombreB);
    if (!ficheroB){
        cerr << "Error al abrir el segundo archivo" << endl;
        return 1;
    } else{
        entradaB = &ficheroB;
        LeerFichero(*entradaB,listaB,nB);
        ficheroB.close();
    }

    //Hacemos la union
    Union(listaA, nA, listaB, nB, resultado,nR);

    //Mostramos por pantalla la union
    cout << "Resultado:" << endl;
    for (int i=0; i < nR; i++){
        cout << resultado[i] << " " << endl;
    }

    if (resultado != nullptr)
        delete [] resultado;
    if (listaA != nullptr)
        delete [] listaA;
    if (listaB != nullptr)
        delete [] listaB;

    return 0;
}

void Inicializar(string * & lista, int &n);
void Liberar(string *& lista, int &n);

void Aniadir(string *& lista, int &n , const string &nuevo){
    string *nuevoptr = new string [n+1];
    for(int i=0; i < n; i++)
        nuevoptr[i] = lista[i];
    
    delete [] lista;
    lista = nuevoptr;
    n ++;
    lista[n-1] = nuevo;
}

bool EstaAniadido(const string *lista,int n, const string &comprobado){
    bool esta = false;
    for (int i=0; i < n && !esta; i++){
        if (lista [i] == comprobado)
            esta = true;
    }
    return esta;
}

void LeerFichero(istream &is, string *&lista, int &n){
    int num_elems = 0;
    string aux;
    is >> num_elems;
    for (int i=0; i < num_elems; i++){
        is >> aux;
        Aniadir(lista,n,aux);
    }
}

void Union(const string * lista1, int n1, const string *lista2, int n2, string *&resul, int &nr){
    for (int i=0; i < n1; i++){
        Aniadir(resul, nr, lista1[i]);
    }

    for (int i=0; i < n2; i++){
        if (!EstaAniadido(resul,nr,lista2[i]))
            Aniadir(resul,nr,lista2[i]);
    }
}