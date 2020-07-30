#ifndef INFOPARADA
#define INFOPARADA
#include <iostream>
#include <cassert>
class InfoParada {
private:
	bool activa;
	int indice_parada;
public:
	int getIndice() const;
        inline void setIndice(int i){ indice_parada = i; };
	bool estaActiva() const;
	friend std::istream& operator>>(std::istream& is, InfoParada& parada);
};
std::istream& operator>>(std::istream& is, InfoParada& parada);

#endif // !INFOPARADA
