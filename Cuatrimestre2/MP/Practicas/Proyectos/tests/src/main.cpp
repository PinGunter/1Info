/**
 * @file main.cpp
 * @author DECSAI
 * @note To be implemented by students either completely or by giving them
 * key functions prototipes to guide the implementation
 */

#include <string>
#include <cassert>
#include <iostream>
#include <random>
#include <fstream>
#include <cmath>
#include "language.h"
#include "bag.h"
#include "player.h"
#include "move.h"
#include "movelist.h"
#include "tiles.h"
#include "window.h"
#include "AnsiTerminal.h"
using namespace std;


#define ERROR_ARGUMENTS 1
#define ERROR_OPEN 2
#define ERROR_DATA 3
#define GENERAL_ERROR 4
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
    Move move;
    Game game;
    int w = -1, h = -1, wait = 0;
    string lang = "", ifilematch = "", ofilematch = "", word;
    ifstream ifile;
    ofstream ofile;
    bool end = false;
    char c;
    bool nueva_partida, continuar_partida, primer_turno,es_vacio, continuar, in_id = false;
    game.score = 0;

    /// Check arguments

    nueva_partida = nargs == 7 || nargs == 9 || nargs == 11;
    continuar_partida = nargs == 3 || nargs == 5;
    if (!nueva_partida && !continuar_partida)
        errorBreak(ERROR_ARGUMENTS, "");

    //empezar partida nueva
    for (int i = 1; i < nargs && nueva_partida;) {
        string aux = args[i++];
        if (aux == "-l")
            lang = args[i++];
        else if (aux == "-w")
            w = atoi(args[i++]);
        else if (aux == "-h")
            h = atoi(args[i++]);
        else if (aux == "-r"){
            game.random = atoi(args[i++]);
            in_id = true;
        }
        else if (aux == "-save")
            ofilematch = args[i++];
        else
            errorBreak(ERROR_ARGUMENTS, "");

    }

    //continuar partida
    for (int i = 1; i < nargs && continuar_partida;) {
        string aux = args[i++];
        if (aux == "-open")
            ifilematch = args[i++];
        else if (aux == "-save")
            ofilematch = args[i++];
        else
            errorBreak(ERROR_ARGUMENTS, "");

    }

    // Process arguments
    if (ifilematch != "") {
        ifile.open(ifilematch);
        if (!ifile)
            errorBreak(ERROR_OPEN,ifilematch);
        ifile >> game;
        if (!ifile)
            errorBreak(ERROR_DATA, ifilematch);
        
        ifile.close();
    }

    if (ofilematch != "") {
        ofile.open(ofilematch);
        if (!ofile)
            errorBreak(ERROR_OPEN,ofilematch);
    }
     /// load data from file, if asked to in arguments

    // Game's main loop 
    // 1) First set the size of the window according to the size (rows & columns) of
    // the new Tiles
    if (nueva_partida){
        game.language.setLanguage(lang);
        if (in_id)
            game.bag.setRandom(game.random);
        game.bag.define(game.language);
        game.player.add(toISO(game.bag.extract(MAXPLAYER)));
        game.tiles.setSize(h, w);
    }
    
    es_vacio = true;
    for (int i=0; i < game.tiles.getHeight(); i++)
        for (int j=0; j < game.tiles.getWidth(); j++)
            if (game.tiles.get(i,j) != EMPTY)
                es_vacio = false;
    primer_turno = nueva_partida || es_vacio;
    continuar = true;
    while (!end) {
        game.setWindowSize();
        // 2) Given the inner data members, it pretty-prints the screen
        game.doPaint();
        setCursorOn();
        // 3) Reads the movement from cin
        cin >> move;
        setCursorOff();
        word = move.getLetters();
        if (word == "_") {
            end = true;
        } else{    
            //errores previos al findcrossword
            /* INFEASABLE WORD*/
            if (!game.player.isValid(move.getLetters())){
                game.crosswords.clear();
                move.setScore(INFEASIBLE_WORD);
                game.rejectedmovements.add(move);
                game.crosswords.add(move);
                game.doBadCrosswords("Infeasable word");
            }
            /*  NOT FREE    */
            else if (game.tiles.get(move.getRow()-1,move.getCol()-1) != EMPTY){
                game.crosswords.clear();
                move.setScore(NOT_FREE);
                game.rejectedmovements.add(move);
                game.crosswords.add(move);
                game.doBadCrosswords("Bad crosswords found!");

             /*     errores despues del findcrossword*/
            } else {
                game.crosswords = game.tiles.findCrosswords(move,game.language);
                if (game.crosswords.size() != 0 && game.crosswords.getScore() >= 0 && (primer_turno || continuar)){
                     if (game.doConfirmCrosswords("Accept movement?")){
                         primer_turno = false;
                        for (int i=0; i < game.crosswords.size(); i++){
                            game.tiles.add(game.crosswords.get(i));
                        }
                        game.score += game.crosswords.getScore();
                        game.acceptedmovements.add(move);
                        game.player.extract(word);
                        game.player.add(game.bag.extract(MAXPLAYER-game.player.to_string().length()));
                    }
                }
                else if (game.crosswords.size()==1 && game.crosswords.get(0).getLetters() == word){//(game.acceptedmovements.size() >= 1 || continuar_partida) ){
                    move.setScore(MISSING_CROSSWORDS);
                    game.rejectedmovements.add(move);
                    game.doBadCrosswords("Missing crosswords");
                } else if (game.crosswords.size() == 0){
                    game.crosswords.clear();
                    move.setScore(BOARD_OVERFLOW);
                    game.rejectedmovements.add(move);
                    game.crosswords.add(move);
                    game.doBadCrosswords("Board overflow");
                } else{
                    move.setScore(NONEXISTENT_WORD);
                    game.rejectedmovements.add(move);
                    game.doBadCrosswords("Bad crosswords found!");
                }
            }
        

            // Checks whether the movement is valid accoring to the letters in player    
           
                // Finds all the crosswords produced by move and inform about the reasons of rejection
             
                        //Checks that the crosswords are valid, that is either has a positive score
              
            //      or produces at least a cross with other existin letters
            // Once a valid move is detected, the user is asked to confirm

            // call doConfirmCrosswords()

            //     the movement. If he/she does (by pressing Y o y) then the movement
            //     is inserted in tiles and its score is calculated,
            //     otherwise, the move is just ignored
            // If valid and accepted, computes the score and adds it
            // Show crosswords found
            // If it is a bad crosswords
            
            // call doBadCrosswords()

            // If not valid w.r.t. player

            // call doBadCrosswords()

        }
    }
        // End of game
        // Save file or print screen
    if (ofilematch != ""){
        ofile << toUTF(PASSWORD) << endl;
        ofile << game;
        ofile.close();
    } else
        cout << "\n%%%OUTPUT" << endl << game;
    
    
    return 0;

}

ostream & operator<<(ostream & os, const Game & game) {
    os << game.score << endl;
    os << toUTF(game.language.getLanguage()) << endl;
    game.tiles.print(os);
    os << game.player.size() << " " << toUTF(game.player.to_string()) << endl;
    os << game.bag.size() << " " << toUTF(game.bag.to_string()) << endl;

    return os;
}

istream & operator>>(istream & is, Game &game) {
    int useless;
    string play, bolsa, verifypsswd, lang;
    is >> verifypsswd;

    if (!is)
        return is;
    
    if (verifypsswd != PASSWORD)
        errorBreak(ERROR_DATA,"");
    is >> game.score;
    is >> lang;
    if (!is)
        return is;
    game.language.setLanguage(lang);

    if (!game.tiles.read(is))
        return is;

    is >> useless >> play;
    if (!is)
        return is;

    is >> useless >> bolsa;
    if (!is)
        return is;
    game.bag.define(game.language);
    game.bag.set(toISO(bolsa));
    game.player.add(toISO(play));

    return is;
}

void errorBreak(int errorcode, const string &errordata) {
    cerr << endl << "%%%OUTPUT" << endl;
    switch (errorcode) {
        case ERROR_ARGUMENTS:
            cerr << "Error in call. Please use either:" << endl;
            cerr << "-l <language> -w <width> -h <height> [-r <randomnumber> -save <matchfile>]" << endl;
            cerr << "-open <matchfile> [-save <matchfile>]" << endl;
            break;
        case ERROR_OPEN:
            cerr << "Error opening file " << errordata << endl;
            break;
        case ERROR_DATA:
            cerr << "Data error in file " << errordata << endl;
            break;
        case GENERAL_ERROR:
            cerr << "Error: " << errordata << endl;
            break;
    }
    std::exit(1);
}

