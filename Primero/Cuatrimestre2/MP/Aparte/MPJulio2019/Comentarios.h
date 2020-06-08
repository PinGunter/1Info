#ifndef COMENTARIOS_H
#define COMENTARIOS_H
#include <iostream>

class Comentarios {
private:
    int numComentarios;
    std::string *losComentarios;
    void reservarMemoria(int n);
    void liberarMemoria();

public:
    Comentarios(const Comentarios &otro);
    int getNumComentarios() const;
    Comentarios & operator=(const Comentarios & otro);
    friend std::istream & operator>>(std::istream & in, Comentarios & c);
    friend std::ostream & operator<<(std::ostream & out, const Comentarios &c);
    const std::string& operator[](int index) const;
    std::string& operator[](int index);
    void redimensionar(int n);


    Comentarios();
    ~Comentarios();
    Comentarios & operator+=(const std::string & cadena);

};

#endif