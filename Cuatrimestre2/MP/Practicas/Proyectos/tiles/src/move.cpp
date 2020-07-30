/**
 * @file move.cpp
 * @author DECSAI
 * @note To be implemented by students
 */
#include <string>
#include "move.h"

using namespace std;

Move::Move(){
    row = column = 0;
    ishorizontal = true;
    letters = "";
    score = 0;
}

void Move::set(int r, int c, char h, const std::string& l){
    row = r;
    column = c;
    ishorizontal = h == 'H' || h == 'h';
    letters = l;
}

void Move::setRow(int r){
    row = r;
}

void Move::setCol(int c){
    column = c;
}

void Move::setHorizontal(char h){
    if (h == 'H' || h == 'h')
        ishorizontal = true;
    else if (h == 'V' || h == 'v')
        ishorizontal = false;
}

void Move::setLetters(const std::string& l){
    letters = l;
 }

int Move::findScore(const Language& l) const{
    int punt = 0;
    //first we have to make sure its a valid word
    if (l.query(letters)){
        //then we add the points
        for (int i=0; i < letters.length(); i++)
            punt += l.getScore(letters[i]);
        
    } else
        punt = -1;
    return punt;
}

void Move::setScore(int s){
    score = s; 
}

int Move::getScore() const {
    return score;
}

int Move::getRow() const{
    return row;
}

int Move::getCol() const{
    return column;
}

bool Move::isHorizontal() const{
    return ishorizontal;
}

std::string Move::getLetters() const{
    return letters;
}

void Move::print(std::ostream& os) const{
   os << (ishorizontal? 'H':'V')<< " "  << row << " " << column 
            << " " << toUTF(letters);
}

void Move::read(std::istream& is){
    char caracter;
    is >> caracter;
    is >> row;
    is >> column;
    is >> letters;
    if (!is.eof()){
        letters = normalizeWord(letters);
        ishorizontal = caracter == 'h' || caracter == 'H';
    }
}


std::ostream& operator<<(std::ostream& os, const Move & m){
    m.print(os);
    return os;
}

std::istream& operator>>(std::istream& is, Move & m){
    m.read(is);
    return is;
}
