#include "tiles.h"
#include <cassert>

Tiles::Tiles() {
    cell = nullptr;
    rows = columns = 0;
}

Tiles::Tiles(int r, int c) {
    cell = nullptr;
    allocate(r, c);
}

Tiles::Tiles(const Tiles& orig) {
    cell = nullptr;
    copy(orig);
}

Tiles::~Tiles() {
    deallocate();
}

void Tiles::setSize(int r, int c) {
    allocate(r, c);
}

Tiles& Tiles::operator=(const Tiles& orig) {
    if (this != &orig)
        copy(orig);
    return *this;
}

int Tiles::getWidth() const {
    return columns;
}

int Tiles::getHeight() const {
    return rows;
}

char Tiles::get(int r, int c) const {
    assert(r >= 0 && r < rows && c >= 0 && c < columns);
    return cell[r][c];
}

void Tiles::set(int r, int c, char l) {
    assert (r >= 0 && r < rows && c >= 0 && c < columns);
    cell[r][c] = l;
}

void Tiles::add(const Move& m) {
    int k = -1;
    int m_row = m.getRow()-1;
    int m_col = m.getCol()-1;
    for (int i = m_row; i < (m_row + m.getLetters().length()) && !m.isHorizontal(); i++)
        if (i >= 0 && i < rows && m_col >= 0 && m_col < columns)
            set(i, m_col, m.getLetters().at(++k));

    for (int i = m_col; i < (m_col + m.getLetters().length()) && m.isHorizontal(); i++)
        if (m_row >= 0 && m_row < rows && i >= 0 && i < columns)
            set(m_row, i, m.getLetters().at(++k));
}

void Tiles::print(std::ostream& os) const {
    os << getHeight() << " " << getWidth() << "\n";
    for (int i = 0; i < getHeight(); i++) {
        for (int j = 0; j < getWidth(); j++)
            os << toUTF(get(i, j)) << " ";
        os << "\n";
    }
    os << "\n";
}

bool Tiles::read(std::istream& is) {
    bool ok = true;
    int h, w;
    std::string letter;
    is >> h >> w;
    setSize(h,w);
    for (int i = 0; i < getHeight() && ok; i++) {
        for (int j = 0; j < getWidth() && ok; j++) {
            if (!is.eof()) {
                is >> letter;
                set(i, j, toISO(letter).at(0));
            } else
                ok = false;
        }
    }
    return ok;
}

void Tiles::allocate(int r, int c) {
    deallocate();
    columns = c;
    rows = r;
    cell = new char*[rows];
    for (int i = 0; i < rows; i++)
        cell[i] = new char [columns];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            cell[i][j] = EMPTY;
}

void Tiles::deallocate() {
    if (cell != nullptr){
        for (int i = 0; i < rows; i++)
            delete [] cell[i];
        delete [] cell;
    }
}

void Tiles::copy(const Tiles& t) {
    allocate(t.getHeight(), t.getWidth());
    for (int i = 0; i < t.rows; i++)
        for (int j = 0; j < t.columns; j++)
            set(i, j, t.get(i, j));
}

Move Tiles::findMaxWord(int r, int c, bool hrz) const{
    Move aux;
    int fila = r-1;
    int columna = c-1;
    std::string word = "";
    int fila_word = -1, columna_word = -1;
    bool continuar = true;
    int j = -1;
    //Horizontal
    if (hrz){        
        fila_word = fila;
        //desde la posicion hacia izquierda
        for (int j=columna -1; j >= 0 && columna != 0 && continuar; j--){
            if (get(fila,j) != EMPTY){
                word.push_back(get(fila,j));
            } else{
                continuar = false;
                columna_word = j+1;
            }
        }
        if (columna_word == -1)
            columna_word = columna;
        
        if (j == 0)
            columna_word = j;
        
        //invertimos la palabra
        for (int i=0; i < word.length() / 2; i++){
            char c_aux = word.at(i);
            word[i] = word[word.length()-1-i];
            word[word.length()-1-i] = c_aux;
        } 
        //añadimos el caracter
        word.push_back(get(fila,columna));
        //desde la posicion hasta la derecha
        continuar = true;
        for (int i=columna+1; i < getWidth() && columna != getWidth()-1 && continuar; i++)
            if (get(fila,i) != EMPTY)
                word.push_back(get(fila,i));
            else{
                continuar = false;
            }
        
        
        aux.set(fila_word+1,columna_word+1,'H',word);
    } else{
        columna_word = columna;
        //desde la posicion hacia arriba
        for (int j=fila -1; j >= 0 && fila != 0 && continuar; j--){
            if (get(j,columna) != EMPTY){
                word.push_back(get(j,columna));
            } else{
                continuar = false;
                fila_word = j+1;
            }
        }
        if (fila_word == -1)
            fila_word = fila;
        
        if (j == 0)
            fila_word = j;
        
        //invertimos la palabra
        for (int i=0; i < word.length() / 2; i++){
            char c_aux = word.at(i);
            word[i] = word[word.length()-1-i];
            word[word.length()-1-i] = c_aux;
        } 
        //añadimos el caracter
        word.push_back(get(fila,columna));
        //desde la posicion hasta abajo
        continuar = true;
        for (int i=fila+1; i < getHeight() && fila != getHeight()-1 && continuar; i++)
            if (get(i,columna) != EMPTY)
                word.push_back(get(i,columna));
            else
                continuar = false;
        
        
        aux.set(fila_word+1,columna_word+1,'V',word);
    }
   // char caracter = hrz ? 'H' : 'V';
    return aux;
}

Movelist Tiles::findCrosswords(const Move &m, const Language &l) const{
    // Primero metemos el move en el tablero en los huecos disponibles
    // Creamos un tablero auxiliar
    Tiles otro(*this);
    bool continuar = true;
    int k=0;
    Movelist lista;
    //horizontal
    if (m.isHorizontal()){
        int fila = m.getRow()-1, columna = m.getCol()-1;
        for (int i=columna; i < getWidth() && continuar; i++){
            if (i == columna && get(fila,columna) != EMPTY){
                m.setScore(NOT_FREE);
                continuar = false;
            }
            else{
                if (get(fila,i) == EMPTY)
                    otro.set(fila,i,m.getLetters().at(k++));
            }
                
        }
        //una vex que acabe comprobamos si ha cabido la palabra
        if (k < m.getLetters().length())
            m.setScore(BOARD_OVERFLOW);
    } 
    //vertical
    else{
        
    }
}