/**
 * @file player.cpp
 * @author DECSAI
 * @note To be implemented by students
 */

#include <cstring>
#include <cassert>
#include "player.h"
///@warning complete missing #includes
/// See http://www.cplusplus.com/reference/cstring/ for details about cstrings
using namespace std;

/**
 * @brief Removes a position from a cstring
 * @param cstr The cstring
 * @param pos The position
 * @return The cstring is modified
 * @warning To be fully implemented
 */
void removeCString(char *cstr, int pos);

/**
 * @brief Sort a cstring from A to Z
 * @param cstr The cstring
 * @return The cstring is modified
 * @warning To be fully implemented
 */
void sortCString(char *cstr);

Player::Player(){
    clear();
}

int Player::size() const{
   return strlen(letters);
}

std::string Player::to_string() const{
    string out = letters;
    return out;
}

void Player::clear(){
    letters[0] = '\0';
}

bool Player::isValid(const std::string s) const{
    /*
     * We first check how many repetition has a letter, then we check if there is the
     * more or equal amount of repetitions in this->letters
     */
    bool valid = true;
    char letters_copy, cstring[MAXPLAYER+1];
    strcpy(cstring, s.c_str());
    int counter_string, counter_letters;
    for (int i=0; i < strlen(cstring) && valid; i++){
        counter_string = 0;
        for (int j = 0; j < strlen(cstring); j++){
            if (cstring[i] == cstring[j])
                counter_string++;
        }
        counter_letters = 0;
        for (int k=0; k < this->size(); k++){
            if (s[i] == letters[k])
                counter_letters++;
            
        }
        if (counter_letters < counter_string)
            valid = false;
    }
    return valid;
}

bool Player::extract(const std::string s){      
    bool extract = this->isValid(s), run_iteration;
    char cstring[MAXPLAYER+1];
    strcpy(cstring, s.c_str());
    if (extract){
        for (int i=0; i < strlen(cstring); i++){
            run_iteration = true;
            for (int j=0; j < this->size() && run_iteration;j++){
                if (cstring[i] == letters[j]){
                    removeCString(letters,j);
                    run_iteration = false;
                }
                
            }
        }
    }
    return extract;
}


void Player::add(std::string frombag){
    char csfrombag[MAXPLAYER+1];
    strcpy(csfrombag, frombag.c_str());    
    assert(strlen(csfrombag) + this->size() <= MAXPLAYER);
    strcat(letters,csfrombag);
    sortCString(letters);
}

void sortCString(char *cstring){
    char insert;
    int j;
    
    for (int i=1; i < strlen(cstring);i++){
        insert = cstring[i];
        
        for (j=i; j > 0 && insert < cstring[j-1]; j--)
            cstring[j] = cstring[j-1];
        
        cstring[j] = insert;    
    }
}

void removeCString(char *cstr, int pos){
    if (pos >= 0 && pos < strlen(cstr)){
        for (int i=pos; i < strlen(cstr); i++){
            cstr[i] = cstr[i+1];
        }
    }
}

