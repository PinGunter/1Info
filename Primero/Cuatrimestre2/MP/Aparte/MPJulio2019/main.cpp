#include <iostream>
#include "Comentarios.h"
#include "Imagen.h"

using namespace std;

int main(int argc, char *args[]) {
    //verificacion de argumentos
    if (argc != 7){
        cerr << "Error, se necesitan 6 argumentos, de la manera: fila columna alto ancho fichero1.pgm fichero2.pgm" << std::endl;
        return 1;
    }
    
    //procesamos los argumentos
    int f_inicio, c_inicio, ancho, alto;
    f_inicio = atoi(args[1]); c_inicio = atoi(args[2]);
    alto = atoi(args[3]); ancho = atoi(args[4]);
   
    string fichero1, fichero2;
    string *fich_mayor;
    fichero1 = args[5]; fichero2 = args[6];
    
    Imagen primera(fichero1), segunda(fichero2);
    Imagen subimg1, subimg2;
    Imagen *mayor;
    
    subimg1 = primera.SubImagen(f_inicio,c_inicio,alto,ancho);
    subimg2 = segunda.SubImagen(f_inicio, c_inicio, alto, ancho);
    
    mayor = (subimg1 > subimg2) ? &subimg1 : &subimg2;
    fich_mayor = (mayor == &subimg1) ? &fichero1 : &fichero2;
    cout << "La mayor subimagen tiene los comentarios: " << std::endl << (*mayor).getComentarios() <<  std::endl;
    cout << "El fichero donde se encuentra la mayor subimagen es el fichero " << *fich_mayor << std::endl;

}
