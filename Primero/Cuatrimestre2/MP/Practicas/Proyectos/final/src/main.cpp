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
    int w=-1, h=-1, wait=0;
    string lang="",ifilematch="", ofilematch="", word;
    ifstream ifile; ofstream ofile;
    bool end=false;
	 char c;
    
    /// Check arguments

    // Process arguments

    /// load data from file, if asked to in arguments

    // Game's main loop 
    // 1) First set the size of the window according to the size (rows & columns) of
    // the new Tiles

    while (!end)  {
        // 2) Given the inner data members, it pretty-prints the screen

        // 3) Reads the movement from cin
        cin >> move;
        word = move.getLetters();
        if (word=="_") {
            end=true;
        // Checks whether the movement is valid accoring to the letters in player    
            // Finds all the crosswords produced by move and inform about the reasons of rejection
            game.crosswords = game.tiles.findCrosswords(move,game.language);
            //Checks that the crosswords are valid, that is either has a positive score
            //      or produces at least a cross with other existin letters
                // Once a valid move is detected, the user is asked to confirm
            
                // call doConfirmCrosswords()
            
                //     the movement. If he/she does (by pressing Y o y) then the movement
                //     is inserted in tiles and its score is calculated,
                //     otherwise, the move is just ignored
            // If valid and accepted, computes the score and adds it
                score +=move.getScore();
                // Show crosswords found
            // If it is a bad crosswords
 
                // call doBadCrosswords()
                
            // If not valid w.r.t. player

                // call doBadCrosswords()
    }
    // End of game
    // Save file or print screen
 
    return 0;
    }
}

ostream & operator<<(ostream & os, const Game & game)  {
    // To implement
    return os;
}

istream & operator>>(istream & is, Game &game) {
    // To implement
    return is;
}

void errorBreak(int errorcode, const string &errordata) {
    cerr << endl << "%%%OUTPUT" << endl;
    switch(errorcode) {
        case ERROR_ARGUMENTS:
            cerr<<"Error in call. Please use either:"<<endl;
            cerr<< "-l <language> -w <width> -h <height> [-r <randomnumber> -save <matchfile>]"<<endl;
            cerr<< "-open <matchfile> [-save <matchfile>]"<<endl;            
            break;
        case ERROR_OPEN:
            cerr<<"Error opening file "<<errordata << endl;
            break;
        case ERROR_DATA:
            cerr<<"Data error in file "<<errordata << endl;
            break;
        case GENERAL_ERROR:
            cerr<<"Error: "<<errordata << endl;
            break;
    }
    std::exit(1);
}

