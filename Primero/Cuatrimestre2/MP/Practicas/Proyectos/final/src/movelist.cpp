/**
 * @file movelist.cpp
 * @author DECSAI
 * @note To be implemented by students
 * @warning Complete the code
 *  */
#include <iostream>
#include "movelist.h"

using namespace std;

bool Movelist::print(std::ostream &os, bool scores) const {
    bool res = true;
    for (int i = 0; i < size() && res; i++) {
        get(i).print(os);
        if (scores)
            os << " (" << get(i).getScore() << ") - ";
        else
            os << " - ";
        if (os.bad())
            res = false;
    }
    return res;
}

// privados

void Movelist::allocate(int n) {
    // Move *aux = new Move[n];
    //for (int i=0; i < nMove; i++)
    //  aux[i] = get(i);
    if (moves != nullptr)
        deallocate();
    moves = new Move[n];
    nMove = n;
}

void Movelist::deallocate() {
    if (moves != nullptr) {
        delete [] moves;
        moves = nullptr;
    }
    nMove = 0;
}

void Movelist::copy(const Movelist & ml) {
    //    bool equal = size() == ml.size();
    //    for (int i=0; i < size() && equal; i++)
    //        equal = get(i).getScore() == ml.get(i).getScore() && get(i).getRow() == ml.get(i).getRow() && get(i).getCol() == ml.get(i).getCol() && get(i).isHorizontal() == ml.get(i).isHorizontal() && get(i).getLetters() == ml.get(i).getLetters();
    //    if (!equal){
    deallocate();
    for (int i = 0; i < ml.size(); i++)
        add(ml.get(i));
    //    }
}

// publicos
//     constructores

Movelist::Movelist() {
    moves = nullptr;
    nMove = 0;
}

Movelist::Movelist(int nmov) {
    moves = nullptr;
    nMove = 0;
    allocate(nmov);
}

Movelist::Movelist(const Movelist& orig) {
    moves = nullptr;
    nMove = 0;
    copy(orig);
}

Movelist::~Movelist() {
    deallocate();
}

//      Operador sobrecargado

Movelist& Movelist::operator=(const Movelist& orig) {
    if (this != &orig) {
        copy(orig);
    }
    return *this;
}

//      Get

Move Movelist::get(int p) const {
    assert(p >= 0 && p < size());
    return moves[p];
}

int Movelist::getScore() const{
    int score = 0;
    bool validscore = true;
    for (int i = 0; i < size() && validscore; i++) {
        if (get(i).getScore() >= 0)
            score += get(i).getScore();

        else {
            validscore = false;
            score = get(i).getScore();
        }
    }
    return score;
}

//         Set

void Movelist::set(int p, const Move& m) {
    assert(p >= 0 && p <= size());
    moves[p] = m;
}

int Movelist::find(const Move & mov) const {
    int pos = -1;
    for (int i = 0; i < size(); i++) {
        //if (get(i) == mov) 
        if (get(i).getScore() == mov.getScore() && get(i).getRow() == mov.getRow() && get(i).getCol() == mov.getCol() && get(i).isHorizontal() == mov.isHorizontal() && get(i).getLetters() == mov.getLetters())
            pos = i;
    }
    return pos;
}

void Movelist::add(const Move& mov) {
    Movelist aux(size() + 1);
    for (int i = 0; i < size(); i++)
        aux.set(i, get(i));
    allocate(aux.size());
    for (int i = 0; i < aux.size(); i++)
        set(i, aux.get(i));
    set(size() - 1, mov);
    //    allocate(nMove +1);
    //    set(nMove,mov);
    //    nMove++;
}

//      Remove

void Movelist::remove(int p) {
    Movelist aux(size() - 1);
    for (int i = 0, k = 0; i < size(); i++) {
        if (i != p)
            aux.set(k++, get(i));
    }
    allocate(aux.size());
    for (int i = 0; i < aux.size(); i++)
        set(i, aux.get(i));

    //    
    //    Move *aux = new Move[nMove-1];
    //    for (int i=0; i < size(); i++){
    //        if (i != p)
    //            aux[i] = get(i);
    //    }
    //    delete [] moves;
    //    moves = aux;
    //    nMove--;
}

void Movelist::remove(const Move& mov) {
    int position = find(mov);
    if (position != -1)
        remove(position);
}

//      Clear

void Movelist::clear() {
    deallocate();
}

//      Read

bool Movelist::read(std::istream &is) {
    bool fin, no_error = true, car_valido;
    Move aux;
    int fila, columna;
    std::string mov;
    char caracter;
    
    do {
        is >> caracter >> fila >> columna >> mov;
        car_valido = caracter == 'h' || caracter == 'H' || caracter == 'v' || caracter == 'V';
        if (!car_valido || !is){
            no_error = false;
            fin = true;
        }
        else {
            fin = mov == "@" || is.eof();

            if (!fin){
                aux.set(fila, columna, caracter, mov);
                add(aux);
            }
        }
    } while (!fin);

    return no_error;
}

//      ZIP

void Movelist::zip(const Language& l) {
    //words have to be >1 && exist in lang
    bool valid;
    int i = 0;
    while (i < size()) {
        valid = get(i).getLetters().size() >= 2 && l.query(get(i).getLetters());
        if (!valid)
            remove(i);
        else
            i++;

        }
}

std::ostream & operator<<(std::ostream & os, const Movelist & i){
    i.print(os);
    return os;
}


std::istream & operator>>(std::istream & is, Movelist & i){
    i.read(is);
    return is;
}

