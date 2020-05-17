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
