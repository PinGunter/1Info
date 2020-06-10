#ifndef LISTA_H
#define LISTA_H

struct Celda {
	double info;
	Celda* sig;
};

class Lista{
private:
	Celda * l;
public:
	/**
	* @brief constructor basico de la clase
	*/
	Lista();

	/**
	*@brief metodo para a�adir un nuevo valor al final de la lista
	*@param dato la nueva info que se a�ade
	*/
	void aniadir(double dato);

	/**
	*@brief metodo para eliminar el ultimo valor de la lista
	*/
	void eliminarUltimo();

	/**
	*@brief metodo para liberar la memoria usada
	*/
	void liberar();

	/**
	*@brief metodo para mostrar por pantalla la lista 
	*/
	void imprimir() const;

	/**
	* @brief metodo para insertar un dato despu�s de una celda concreta
	* @param direccion la direccion de memoria donde se encuentra la celda tras la que se introduce el nuevo dato
	* @param dato el dato que se inserta
	*/
	void insertarTras(Celda* direccion, double dato);

	/**
	* @brief metodo para eliminar una celda de la lista
	* @param celda la direcion de memoria de la celda que se va a borra
	*/
	void eliminar(Celda* celda);

	/**
	* @brief metodo que devuelve un puntero a la celda n-esima
	* @param posicion posicion en la lista de la celda
	* @retval puntero a la celda
	*/
	Celda* getCelda(int posicion);
};


#endif