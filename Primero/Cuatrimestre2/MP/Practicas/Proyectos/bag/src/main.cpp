/**
 * @file main.cpp
 * @author Salvador Romero Cortés
 * @note To be implemented by students either completely or by giving them
 * key functions prototipes to guide the implementation
 */

#include <iostream>

#include "language.h"
#include "bag.h"

using namespace std;


/**
 * @brief Shows final data in a form detectable by autovalidation scripts
 * @param l Language
 * @param random Random seed
 * @param b Final bag
 * @param nwords Number of words found
 * @param result Aggregation of all valid words found
 */
void HallOfFame(const Language &l, int random, const Bag &b,
        int nwords, const string &result);

/**
 * @brief Main function. 
 * @return 
 */
int main() {
    Language language;
    Bag bag;
    string word, lang, result="";
    int random, count = 0;
    
    /// @warning Read language
    cout << "Select language: ";
    cin >> lang;
    language.setLanguage(lang);
    
    /// @warning Show allowed letters
    cout << "The allowed letters for the language are: ";
    for (int i=0; i < language.getLetterSet().length(); i++)
        cout << toUTF(language.getLetterSet()[i]);
    
    /// @warning Read random and define bag
    cout << "\nEnter the seed for the shuffle: ";
    cin >> random;
    bag.setRandom(random);
    bag.define(language);

    /// @warning Extract a 5-letter word from the bag
    /// check whether it is in the dictionary or not
    /// if it is, count a new word, and aggregate the 
    /// word to result ... result = result + word +" - ";
    while (bag.size()>0){
        for (int j=0; j < 5; j++){
            word = bag.extract(5);
            cout << endl << toUTF(word);
            if (language.query(word)){
                cout << "\t ***";
                result = result + word +" - ";
                count++;
            }
        }
    }
    
    /// @warning Finish when the bag is empty and show results
    /// thru HallOfFame(...))
    HallOfFame(language,random, bag,count,result);
    return 0;
}

void HallOfFame(const Language &l, int random, const Bag &b,  
        int nwords, const string &result) {
    cout << endl <<"%%%OUTPUT" << endl << "LANGUAGE: "<<l.getLanguage()<< " ID: " << random << endl;
    cout << "BAG ("<<b.size()<<"): " << toUTF(b.to_string()) << endl;
    cout << nwords << " words found "<<endl << 
            toUTF(result) << endl;    
}


