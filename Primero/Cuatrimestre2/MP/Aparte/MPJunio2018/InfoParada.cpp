#include "InfoParada.h"

int InfoParada::getIndice() const {
    return indice_parada;
}

bool InfoParada::estaActiva() const {
    return activa;
}

std::istream& operator>>(std::istream& is, InfoParada& parada) {
    if (is) {
        char car;
        int i;
        is >> i;
        is >> car;
        parada.setIndice(i);
        if (car == 'S')
            parada.activa = true;
        else if (car == 'N')
            parada.activa = false;
    }
    return is;
}
