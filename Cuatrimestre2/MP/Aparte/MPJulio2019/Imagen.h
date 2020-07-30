#ifndef IMAGEN_H
#define IMAGEN_H
#include "Comentarios.h"

class Imagen {
private:
    int filas, columnas;
    int **valores;
    Comentarios comentarios;
    void liberarMemoria();
    void reservarMemoria(int f, int c);
    double ValorMedio() const;	

public:
    Imagen(const Imagen & otro);
    int getNumFilas() const;
    int getNumColumnas() const;
    friend std::ostream & operator<<(std::ostream & out, const Imagen & img);
    const Comentarios & getComentarios(void) const;

    Imagen();
    Imagen(int f, int c, int v = 0);
    Imagen(const std::string & fichero);
    Imagen & operator=(const Imagen &otro);
    ~Imagen();
    void set(int f, int c, int v);
    friend std::istream & operator>>(std::istream & is, Imagen & img);
    int & operator()(int f, int c); //version lvalue
    const int & operator()(int f, int c) const; // version constante
    void setComentarios(const Comentarios & coments);
    Imagen SubImagen(int f, int c, int h, int w) const;
    bool operator>(const Imagen & otro) const;
    bool guardar(const char* nombreFichero) const;
};

Imagen operator*(const Imagen & uno, const Imagen & otro) ;



#endif
