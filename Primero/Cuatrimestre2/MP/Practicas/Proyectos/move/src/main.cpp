/**
 * @file main.cpp
 * @author DECSAI
 * @note To be implemented by students either completely or by giving them
 * key functions prototipes to guide the implementation
 */

#include <iostream>
#include <fstream>
#include "language.h"
#include "bag.h"
#include "player.h"
#include "move.h"
using namespace std;


#define ERROR_ARGUMENTS 1
#define ERROR_OPEN 2
#define ERROR_DATA 3
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
 * @brief Shows final data
 * @param l Language
 * @param random Random seed
 * @param b Final bag
 * @param p Final player
 * @param nwords Number of words found
 * @param score Number of points scored
 * @param result Aggregation of all valid words found
 */
void HallOfFame(const Language &l, int random, const Bag &b, const Player &p, 
        int nwords, int score, const string &result);


/**
 * @brief Main function. 
 * @return 
 */
int main(int nargs, char * args[]) {
    Bag bag;
    Player player;
    Language language;
    Move move;
    //goodmoves = cumplen ambas
    //badmoves = !goodmove
    string word, lang="", goodmoves="", badmoves="", ifilename="", ofilename="";
    int random=-1, nwords=0, score=0;
    ifstream ifile; ofstream ofile;
    istream *input; ostream *output;
    /// @warning: Declare more vars when needed
    
    /// @warning: Check arguments

    /// @warning: Process arguments
    
    //There has to be at least 3 arguments: the binary file, "-l" an the language
    //There cant be any more than 7 arguments
    if (nargs < 3 || nargs > 7){
        errorBreak(ERROR_ARGUMENTS,"");
    }
    
    for (int i=1; i < nargs;){
        string arg = args[i++];
        if (arg == "-l"){
            lang = args[i++];
        }
        else if (arg == "-i"){
            ifilename = args[i++];
        }
        else if (arg == "-r"){
            random = atoi(args[i++]);
        }
        else{
            cout << "ha fallado argumento " << i << endl;
            errorBreak(ERROR_ARGUMENTS,"");
        }
    }
     
    //we check for the mandatory parameter
    if (lang == "")
        errorBreak(ERROR_ARGUMENTS,"");
    
    //now we check if theres been a file input
    if (ifilename == ""){
        input = &cin;
        cout << "no ha habido archivo, se coge el cin" << endl;
    }
    else{
        cout << "vamos a abrir el archivo" << endl;
        ifile.open(ifilename);
        //we check if there's been a problem opening the file
        if (!ifile){
            cout << "no se ha podido abrir" << endl;
            errorBreak(ERROR_OPEN, ifilename);
        }
        else{
            cout << "se ha abierto bien" << endl;
            input = &ifile;
        }
    }
    
    //now we set the language¡,the id and the bag
    language.setLanguage(lang);
    if (random != -1)
        bag.setRandom(random);
    
    bag.define(language);
    
    //print the language, bag and id
    cout << "Language selected: " << toUTF(lang) << endl;
    cout << "The available letters for this language are: " << toUTF(language.getLetterSet()) << endl;
    if (random == -1)
        cout << "The seed has been randomnly selected" << endl;
    else
        cout << "The seed for the bag is: " << random << endl;
    
	/*
	1. El main() recibe como parámetro obligatorio "-l <ID>" y co-
	mo parámetros opcionales "-i <file>" y "-r <random>" ,
	en cualquier orden entre los tres. Si se especifica "-i" se leen
	los datos desde ese fichero, si no, se leen desde el teclado. Si
	se especifica "-r" se define el aleatorio con el número indica-
	do, si no, no se define aleatorio.
	2. Crear una instancia de la clase Language con el anterior ID y
	mostrar el conjunto de caracteres permitido para ese lenguaje.
	3. Crear una instancia de la clase Bag, inicializar el generador de
	números aleatorios con el número aleatorio anterior, si es que
	se ha indicado, y definir su contenido en base al lenguaje que
	se ha declarado anteriormente.*/
 
    player.add(bag.extract(MAXPLAYER));
    do{
        cout << "BAG: " << toUTF(bag.to_string()) << endl;
        cout << "PLAYER: " << toUTF(player.to_string()) << endl;
        cout << "REMAINING BAG: " << bag.size() << endl;
        cout << "ENTER MOVE: " << endl;
        move.read(*input);
        word = move.getLetters();
        
        if(!input->eof() && word.length() > 1){
            //comprobar que sea valido con player y language
            if (player.isValid(word)){
                player.extract(toISO(word));
                player.add(bag.extract(MAXPLAYER-player.to_string().length()));
                
                if (language.query(word)){
                    cout << "WORD FOUND" << endl;
                    goodmoves = goodmoves + word + " - ";
                    score += move.findScore(language);
                    nwords++;
                }
                else{
                    cout << "NOT REGISTERED" << endl;
                    badmoves += word + " - ";
                }
            }
            else{
                cout << "INVALID" << endl;
                badmoves += word + " - ";
            }
        }
        else if (input->eof()){
            errorBreak(ERROR_DATA,ifilename);
        }
        
        
    } while (word.length() > 1);
    
    //antes de acabar el programa cerramos los archivos que hallamos abierto
    if (ifilename != "")
        ifile.close();
        /*
	4. Crear una instancia de la clase Player y llenarla por comple-
	to con caracteres de la bolsa. Este objeto player deberá estar
	siempre ordenado de la A a la Z.
	5. Repetir la siguiente secuencia hasta que se lea un movimiento
	con la palabra "@"
	a) Usar el método read(...) para leer un movimiento (desde
	teclado o desde el fichero de entrada, según el parámetro
	"-i" ). Los valores para isHorizontal, row y column se leen
	pero se van a ignorar en el resto del programa, pues sólo se
	usará letters. En las anteriores prácticas se han usado pa-
	labras con letras controladas, pues, al fin y al cabo, todas
	provenı́an de bag, las cuales provienen del diccionario, y
	todas siguen el mismo patrón del juego scrabble: las letras
	son mayúsculas, no contienen tildes ni diéresis, aunque al-
	gunos caracteres internacionales están soportados, como
	la Ñ. Aunque no se ha usado hasta ahora, al incluir langua-
	ge.h en cualquier proyecto, también se incluye la definición
	de esta constante:
	static const std::string ALPHABET=toISO(” ABCDEFGHIJKLMNOPQRSTUVWXYZÑ”);
	Esto quiere decir que cualquier palabra que se consulte en
	el diccionario debe estar representada con caracteres de
	ese ALPHABET Esta es la primera vez que exponemos el
	programa a leer datos externos no controlados, por lo que
	habrı́a que transformar cada palabra de juego que se lee,
	a una palabra expresada en ese alfabeto. Y eso es lo que
	hace la función normalizeWord(...)
	b) Si la palabra leı́da es válida para el valor de Player (al me-
	nos ha de tener dos caracteres) entonces se anota la pala-
	bra, se calcula la puntuación de la palabra según el diccio-
	nario y se anota, se eliminan las letras de player, se sacan
	nuevas letras de bag para rellenar player, y se sigue ju-
	gando. Ya nos estamos acercando al ciclo de juego de la
	práctica final.
	c) Si la palabra leı́da no es compatible con el valor de player,
	se desecha y se lee el siguiente movimiento.
	6. Terminar con la llamada a HallOfFame para visualizar los re-
	sultados.
	7. Si en cualquier momento se presenta un error en los argumen-
	tos, en la apertura de ficheros o en la lectura de datos del fiche-
	ro, se debe usar la función errorBreak(...) para notificar el error
	y parar el programa.
	*/

    /// @warning: final report
    HallOfFame(language, random, bag, player, nwords, score, goodmoves);
    return 0;
}

void HallOfFame(const Language &l, int random, const Bag &b, const Player &p, 
        int nwords, int score, const string &result) {
    cout << endl << "%%%OUTPUT" << endl << "LANGUAGE: "<<l.getLanguage()<< " ID: " << random << endl;
    cout << "BAG ("<<b.size()<<"): " << toUTF(b.to_string()) << endl;
    cout << "PLAYER (" <<p.size() << "): " << toUTF(p.to_string())<<endl;
    cout << nwords << " words and " << score << " points "<<endl << 
            toUTF(result) << endl;    
}

void errorBreak(int errorcode, const string &errordata) {
    cerr << endl << "%%%OUTPUT" << endl;
    switch(errorcode) {
        case ERROR_ARGUMENTS:
            cerr<<"Error in call. Please use:\n -l <language>  [-r <randomnumber> -i <inputfile>]"<<endl;
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

