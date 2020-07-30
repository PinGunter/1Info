/**
 * @studen Salvador Romero Cortés
 * @file main.cpp
 * @author DECSAI
 * @note To be implemented by students either completely or by giving them
 * key functions prototipes to guide the implementation
 */


#include <iostream>
#include <fstream>
#include "bag.h"
#include "player.h"
#include "move.h"
#include "movelist.h"
#include "tiles.h"
#include "language.h"
using namespace std;


#define ERROR_ARGUMENTS 1
#define ERROR_OPEN 2
#define ERROR_DATA 3
#define PASSWORD "MPALABRADOS-V1"
/**
 * @brief Reports an important error and exits the program
 * @param errorcode An integer representing the error detected, which is represented
 * by several symbolic constants: ERROR_ARGUMENTS, ERROR_OPEN y ERROR_DATA
 * @param errorinfo Additional information regarding the error: "" (empty string) for 
 * errors parsing the arguments to main() and, for the case of errors opening or 
 * reading/writing data, the name of the file thas has failed.
 */
void errorBreak(int errorcode, const string & errorinfo);


/**
 * @brief Main function. 
 * @return 
 */
int main(int nargs, char * args[]) {
    string lang = "",
           playfile_name = "",
           matchfile_open = "",
            matchfile_save = "",
            password = "";
            
    
    int width = 0, height = 0, id = -1, score = 0;        
    bool nueva_partida = nargs >= 9 && nargs <=13;
    bool continuar_partida = nargs == 7 || nargs == 5;
    Language language;
    Bag bag;
    Player player;
    Move move;
    Movelist original,
            legal,
            accepted,
            rejected;
    Tiles tiles;
    ostream *output;
    ifstream playfile, match_entrada;
    ofstream match_salida;
    /*
 * 1) El main() recibe múltiples parámetros de entrada, distinguiendo
entre dos modos de funcionamiento.

    * a) Empezar una partida nueva. Para ello los parámetros de
llamada serán
-l <lang> -w <int> -h <int> -p <pfile> [-r <int> -save <matchfile>]
especificando el diccionario, el ancho y alto del tablero de
juego, el fichero de movimientos registrados y, opcional-
mente, el número aleatorio y la posibilidad de salvar la la
jugada en un fichero con extensión .match con la opción
-save . En caso de que no se indique esta última opción,
entonces deberá mostrar el estado final de la partida con el
mismo formato (ver Sección ??).

     * b) Continuar una partida existente. Para ello los parámetros
de llamada serán
5Metodologı́a de la Programación
MPALABRADOS (tiles-1)
-open <matchfile> -p <playfile> [-save <matchfile>]
indicando la apertura de un fichero .match desde el que
se restaura el estado anterior de la partida, y un fichero
de movimientos. Opcionalmente, se podrá grabar la partida
final si se indica el parámetro -save comentado antes.
*/
    
    
    if (!nueva_partida && !continuar_partida)
        errorBreak(ERROR_ARGUMENTS,"");
    
    //Modo empezar partida nueva
    for (int i=1; i < nargs && nueva_partida;){
        string aux = args[i++];
        if (aux == "-l")
            lang=args[i++];
        else if (aux == "-w")
            width = atoi(args[i++]);
        else if (aux == "-h")
            height = atoi(args[i++]);
        else if (aux == "-p")
            playfile_name = args[i++];
        else if (aux == "-r")
            id = atoi(args[i++]);
        else if (aux == "-save")
            matchfile_save = args[i++];
        else
            errorBreak(ERROR_ARGUMENTS,"");
    }
    
    //Modo continuar actual
    for (int i=1; i < nargs && continuar_partida;){
        string aux = args[i++];
        if (aux == "-open")
            matchfile_open = args[i++];
        else if (aux == "-p")
            playfile_name = args[i++];
        else if (aux == "-save")
            matchfile_save = args[i++];
        else
            errorBreak(ERROR_ARGUMENTS,"");
    }
    
    //ficheros
    if (matchfile_save == ""){
        output = &cout;
        password = "%%%OUTPUT";
    }
    else{
        match_salida.open(matchfile_save);
        if (!match_salida)
            errorBreak(ERROR_OPEN,matchfile_save);
        output = &match_salida;
        password = PASSWORD;
    }
   
    if (matchfile_open != ""){
        match_entrada.open(matchfile_open);
        if (!match_entrada)
            errorBreak(ERROR_OPEN,matchfile_open);
    }
    
    
    playfile.open(playfile_name);
    if (!playfile)
        errorBreak(ERROR_OPEN, playfile_name);
    
    

/*
 * 2. Crear una instancia de la clase Language con el ID indicado.
*/
    /*
 * 3. Crear una instancia de la clase Bag, si es una partida nueva,
inicializar la bolsa, en otro caso, cargarla directamente desde el
fichero .match*/
/* 4. Crear una instancia de la clase Player y inicializarla por com-
pleto con caracteres de la bolsa o bien leerla del fichero .match.*/

 /* 5. Crear una instancia de la clase Tiles y dimensionarla según
los parámetros leı́dos, bien desde la lı́nea de comandos, bien
desde el fichero .match.*/
    
    if (nueva_partida){
        language.setLanguage(lang);
        if (id != -1)
            bag.setRandom(id);
        bag.define(language);
        player.add(bag.extract(MAXPLAYER));
        tiles.setSize(height,width);
    } 
    else{
        int useless;
        string play, bolsa,verifypsswd;
        
        match_entrada >> verifypsswd;
        if (!match_entrada)
            errorBreak(ERROR_DATA,matchfile_open);
        
        if (verifypsswd != PASSWORD)
            errorBreak(ERROR_DATA,matchfile_open);
        match_entrada >> score;
        match_entrada >> lang;
        if (!match_entrada)
            errorBreak(ERROR_DATA,matchfile_open);
        language.setLanguage(lang);

        if (!tiles.read(match_entrada))
            errorBreak(ERROR_DATA,matchfile_open);
        
        
        match_entrada >> useless >> play; 
        if (!match_entrada)
            errorBreak(ERROR_DATA,matchfile_open);
        
        match_entrada >> useless >> bolsa;
        if (!match_entrada)
            errorBreak(ERROR_DATA,matchfile_open);
        
        bag.define(language);
        bag.set(toISO(bolsa));
        player.add(toISO(play));
        match_entrada.close();
    }

    

 /* 6. Crear una instancia de la clase bf Movelist llamada original
y leer todos los movimientos desde el fichero indicado en el
parámetro -p usando operador sobrecargado >>*/

    playfile >> original;
    if (playfile.eof())
        errorBreak(ERROR_DATA,playfile_name);
    playfile.close();
    
 /* 7. Crear una instancia de Movelist llamada legal que contenga
sólo los movimientos de original que están en el diccionario
del lenguaje elegido. Usar, para ello, el método zip(...)*/

    legal = original;
    legal.zip(language);
    
 /* 8. Crear dos instancias adicionales de Movelist y llamarlas accepted
y rejected*/
    
 /* 9. Recorrer toda la lista de movimientos leı́da y, por cada uno de
ellos.

     * a) Si el movimiento está en el diccionario, añadir la palabra a
la lista accepted , calcular su puntuación, según el idioma
y acumularla. A continuación, se deberá colocar cada mo-
vimiento en su posición correspondiente en la instancia de
Tiles creada anteriormente, ignorando aquellos caracteres
que caigan fuera de las dimensiones permitidas y sobrees-
cribiendo los caracteres que se crucen.

     * b) En otro caso añadirla a la lista rejected .
*/
    for (int i=0; i < legal.size(); i++){
        move = legal.get(i);
        string word = move.getLetters();
        if (player.isValid(word)){
            player.extract(word);
            player.add(bag.extract(MAXPLAYER-player.to_string().length()));
           
            move.setScore(move.findScore(language));
            accepted.add(move);

            tiles.add(move);
        } else
            rejected.add(move);   
    }
    
    
 /* 10. Terminar mostrando el estado de la partida en pantalla o guardándo-
lo en disco según la presencia o no de -save .
11. Si en cualquier momento se presenta un error en los argumen-
tos, en la apertura de ficheros o en la lectura de datos del fiche-
ro, se debe usar la función errorBreak(...) para notificar el error
y parar el programa 
 */
    *output << toUTF(password) << endl;
    *output << accepted.getScore() + score << endl;
    *output << toUTF(language.getLanguage()) << endl;
    tiles.print(*output);
    *output << player.size() << " " << toUTF(player.to_string()) << endl;
    *output << bag.size() << " " << toUTF(bag.to_string()) << endl;
    
    return 0;
}


void errorBreak(int errorcode, const string &errordata) {
    cerr << endl << "%%%OUTPUT" << endl;
    switch(errorcode) {
        case ERROR_ARGUMENTS:
            cerr<<"Error in call. Please use either:"<<endl;
            cerr<< "-l <language> -w <width> -h <height> -p <playfile> [-r <randomnumber> -save <matchfile>]"<<endl;
            cerr<< "-open <matchfile> -p <playfile> [-save <matchfile>]"<<endl;            
            break;
        case ERROR_OPEN:
            cerr<<"Error opening file "<<errordata << endl;
            break;
        case ERROR_DATA:
            cerr<<"Data error in file "<<errordata << endl;
            break;
    }
    std::exit(1);
}
