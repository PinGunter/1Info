/**
 * @file bag.cpp
 * @author DECSAI
 * @note To be implemented by students except function shuffle()
 */
#include <cassert>
#include <random>
#include <algorithm>
#include "language.h"
#include "bag.h"
#include <fstream>


using namespace std;

/**
 * @brief Randomly reorders a vector of char
 * @param s Vector of char
 * @param n Number of char in the vector
 * @author DECSAI
 */
void shuffleVector(char *s, int n, int id);

/**
 * @brief Removes a position from a vector and compacts the remaining positions, 
 * thus reducing its size
 * @param s Vector of char
 * @param n Number of chars
 * @param p Position to remove
 * @warning TO BE FULLY IMPLEMENTED. 
 * @warning Check parameters const/&/* and their types
 */
void removeVector(char *s,int &n, int p);


// Main methods

Bag::Bag() {
    nletters = 0;
    id = time(NULL);
    if (id > 69999)
    	id = 69999;
}

char Bag::get(int p) const{
    //first we check if the p parameter is withing legal bounds
    char out;
    if (p < 0 || p >= nletters){
        out = '\0';           
    }
    else{
        out = letters[p];
    }
    return out;
}

void Bag::set(int p, char c){
    //the method will only do anything if p is within legal bounds
    if (p >= 0 && p < nletters){
        letters[p] = c;
    }
}


void Bag::setRandom(int id){
    this->id = id;
}

void Bag::define(const Language &l){
    ifstream ifile("build/bags.data");
    string mybag, mylang;
    int myrandom;
    bool found=false;

    if (!ifile) return;
    while (!ifile.eof() && !found) {
        ifile >> mylang >> myrandom >> mybag;
        if (ifile && mylang==l.getLanguage() && myrandom == this->id)
            found = true;
    }
    ifile.close();
    if (found)
        this->set(toISO(mybag));
    else
        this->set("");
}

int Bag::size() const{
    return nletters;
}

std::string Bag::to_string()const{
    string output;
    int n = size();
    for (int i=0; i < n; i++)
        output.push_back(get(i));
    return output;
}

void Bag::set(string s){
    nletters = s.length();
    for (int i=0; i < nletters; i++)
        set(i,s[i]);
}

std::string Bag::extract(int n){
    string extracted;
    int current_size = size();
    if (n < current_size){
        for (int i=0; i < n; i++){
            extracted.push_back(get(0));
            removeVector(letters,nletters,0);
        }
    } else{
        for (int i=0; i < current_size; i++){
            extracted.push_back(get(i));
        }
        nletters = 0;

    }
    return extracted;
}


// Auxiliary functions 

void shuffleVector(char *s, int n, int id) {
    vector <char> aux(s, s+n);
    unsigned seed = id;
    std::shuffle(aux.begin(), aux.end(), std::default_random_engine(seed));
    for (int i=0; i<n; i++)
        s[i] = aux[i];    
}

void removeVector(char *s, int &n, int p){
    for (int i=p; i < n-1; i++){
        s[i] = s[i+1];
    }    
    n--;
}
