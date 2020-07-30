#include "Imagen.h"
#include <cassert>
#include <fstream>
void Imagen::liberarMemoria() {
    if (valores != nullptr) {
        for (int i = 0; i < filas; i++)
            delete [] valores[i];
        delete [] valores;
    }
    valores = nullptr;
    filas = columnas = 0;
}

void Imagen::reservarMemoria(int f, int c) {
    if (f > 0 && c > 0) {
        filas = f;
        columnas = c;
        valores = new int* [filas];
        for (int i = 0; i < filas; i++)
            valores[i] = new int [columnas];
    } else {
        valores = nullptr;
        filas = columnas = 0;
    }
}

Imagen::Imagen(const Imagen &otro) {
    reservarMemoria(otro.filas, otro.columnas);
    comentarios = otro.comentarios;
    for (int i=0; i < filas; i++)
        for (int j=0; j < columnas; j++)
            valores[i][j] = otro(i,j);
}

int Imagen::getNumFilas() const {
    return filas;
}

int Imagen::getNumColumnas() const {
    return columnas;
}

std::ostream & operator<<(std::ostream & out, const Imagen & img) {
    out << img.comentarios;
    out << img.columnas << " " << img.filas << " " << std::endl << 255 << std::endl;

    for (int fil = 0; fil < img.filas; fil++) {
        for (int col = 0; col < img.columnas; col++) {
            out << img.valores[fil][col] << " ";
        }
        out << std::endl;
    }

    return out;
}

const Comentarios & Imagen::getComentarios(void) const {
    return comentarios;
}

Imagen::Imagen() {
    if (valores != nullptr)
        reservarMemoria(0, 0);
    else
        valores = nullptr;
    filas = columnas = 0;
    comentarios += "# Creada vacía";
}

Imagen::Imagen(int f, int c, int v) {
    reservarMemoria(f, c);
    for (int i = 0; i < f; i++)
        for (int j = 0; j < c; j++)
            valores[i][j] = v;
    comentarios += "# Creada " + std::to_string(f) + " x " + std::to_string(c) + " a valor " + std::to_string(v);
}

Imagen & Imagen::operator=(const Imagen &otro) {
    if (this != &otro) {
        liberarMemoria();
        reservarMemoria(otro.filas, otro.columnas);
        for (int i = 0; i < filas; i++)
            for (int j = 0; j < columnas; j++)
                valores[i][j] = otro.valores[i][j];
        comentarios = otro.comentarios;
    }
    return *this;
}

Imagen::~Imagen() {
    liberarMemoria();
}


void Imagen::set(int f, int c, int v){
    assert(f >= 0 && f < getNumFilas() && c >= 0 && c < getNumColumnas());
    valores[f][c] = v;
}

std::istream & operator>>(std::istream & is, Imagen & img) {
    int luminosidad, f, c, pixel;
    is >> img.comentarios;
    is >> c >> f;
    is >> luminosidad;
    img.reservarMemoria(f,c);
    for (int i=0; i < img.getNumFilas(); i++)
        for (int j=0; j < img.getNumColumnas(); j++){
            is >> img.valores[i][j];
        }
    return is;
}

Imagen::Imagen(const std::string & fichero){
    std::ifstream flujo;
    std::string cadena;
    flujo.open(fichero);
    if (flujo) {
        getline(flujo, cadena); // Leer P2 //flujo >> cadena; no sirve pues queda el \n sin leer
        if (cadena == "P2") {
            flujo >> *this;
        }
        flujo.close();
    } else {
        std::cerr << "Error, fichero " << fichero << " no ha podido ser abierto" << std::endl;
    }
}

int & Imagen::operator()(int f, int c){ //version lvalue
    assert(f >= 0 && f < getNumFilas() && c >= 0 && c < getNumColumnas());
    return valores[f][c];    
} 
const int & Imagen::operator()(int f, int c) const{ // version constante
    assert(f >= 0 && f < getNumFilas() && c >= 0 && c < getNumColumnas());
    return valores[f][c];    
}

void Imagen::setComentarios(const Comentarios& coments){
    comentarios = coments;
}

Imagen operator *(const Imagen& uno, const Imagen & otro) {
    //pixeles
    Imagen nueva;
    if (uno.getNumColumnas() == otro.getNumColumnas() && uno.getNumFilas() == otro.getNumFilas()){
        for (int i=0; i < uno.getNumFilas(); i++){
            for (int j=0; j < uno.getNumColumnas(); j++){
                if (otro(i,j) == 0)
                    nueva(i,j) = uno(i,j);
                else
                    nueva(i,j) = otro(i,j);
            }
        }
    }
    //comentarios
    Comentarios nuevos_coments(uno.getComentarios());
    nuevos_coments += "#-----------------------";
    for (int i=0; i < otro.getComentarios().getNumComentarios(); i++){
        nuevos_coments += otro.getComentarios()[i];
    }
    nuevos_coments += "#-----------------------";
    nuevos_coments += "#Creada por: ENMASCARAMIENTO";
    nueva.setComentarios(nuevos_coments);
    return nueva;
}

Imagen Imagen::SubImagen(int f, int c, int h, int w) const{
    Imagen subimg (h,w);
    //comentarios
    Comentarios nuevos (getComentarios());
    nuevos += "#-----------------------";
    nuevos += "#Subimagen desde " + std::to_string(f) + ", " + 
            std::to_string(c) + " de dimensiones " + std::to_string(h) + 
            " x " + std::to_string(w);
    subimg.setComentarios(nuevos);
    
    //pixeles
    for (int i=f; i < f+h && i < getNumFilas(); i++)
        for (int j=c; j < c+w && j < getNumColumnas(); j++)
            subimg(i,j) = valores[i][j];
    
    return subimg;
}

double Imagen::ValorMedio() const{
    double media = 0;
    for (int i=0; i < getNumFilas(); i++)
        for (int j=0; j < getNumColumnas();j++)
            media += valores[i][j];
    media /= (filas*columnas);
    return media;
}

bool Imagen::operator >(const Imagen& otro) const{
    if (ValorMedio() > otro.ValorMedio())
        return true;
    else
        return false;
}

bool Imagen::guardar(const char* nombreFichero) const { // EXAMEN 3.3 y examen prácticas
    std::ofstream flujo;
    flujo.open(nombreFichero);
    if (flujo) {
        flujo << "P2" << std::endl;
        flujo << *this;
        flujo.close();
        return true;
    }
    return false;
}