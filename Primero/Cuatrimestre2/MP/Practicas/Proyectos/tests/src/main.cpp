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
string errorSwitch(int a);

int main() {
    Bag bag;
    Language lang;
    Player player;
    Tiles tiles, otro;
    Move move;
    Movelist list;
    int a, b;
    int score;
    char auxi;
    bool copiar = true;


    lang.setLanguage("ES");

    tiles.setSize(15, 15);

    char respuesta;
    int turnos = 0;
    while (turnos < 10) {
        tiles.print(cout);
        cin >> move;
        list = tiles.findCrosswords(move, lang);
        for (int i = 0; i < list.size(); i++) {
            if (list.size() == 1 && turnos != 0)
                list.get(i).setScore(MISSING_CROSSWORDS);
            string a = to_string(list.get(i).getScore());
            if (atoi(a.c_str()) < 0)
                a = errorSwitch(list.get(i).getScore());

            cout << list.get(i) << " " << a << endl;
        }

        if (list.getScore() >= 0) {
            cout << "\nAñadir? ";
            cin >> respuesta;
            if (respuesta == 's') {
                for (int i = 0; i < list.size(); i++)
                    tiles.add(list.get(i));
            }
        }else
            cout << "\nBad crosswords";

        //tiles.add(move);

        turnos++;
    }
    return 0;

}

string errorSwitch(int a) {
    switch (a) {
        case -1:
            return "UNKNOWN";
            break;
        case -2:
            return "BOARD_OVERFLOW";
            break;
        case -3:
            return "NONEXISTENT_WORD";
            break;
        case -4:
            return "INFEASABLE_WORD";
            break;
        case -5:
            return "NOT_FREE";
            break;
        case -6:
            return "MISSING_CROSSWORDS";
            break;
    }
}