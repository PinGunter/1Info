/**
 * @file tiles.h
 * @author DECSAI
 * @note To be implemented by students
 */

#ifndef TILES_H
#define TILES_H
#include <iostream>
#include "move.h"
#include "movelist.h"

#define EMPTY '.'


/**
 * @brief Class used to store a double-dimension matrix to store all the characters of the game Scrabble. 
 * See https://en.wikipedia.org/wiki/Scrabble for more details
 * By default, all the positions are initialized to the @p EMPTY value
 * **Please note that all the characters are stored in ISO8859 standard and in uppercase**
*/
class Tiles {
public:

	/**
	 * @brief Find the maximum number of consecutive letters in the matrix starting
	 * from the specified position and following the given direction. It must explore
	 * rows (columns) *before* and *after* to that indicated in the parameters until 
	 * reaching the limits of the matrix or an empty space. It stores that word as a
	 * move, whose values @p row and @p column must be found as to be the maximum number
	 * of consecutive letters. The word found is not checked in any language, it is a free
	 * sequence of letters, therefore it is not scored accoring to any language neither
	 * @param r Row
	 * @param c Column
	 * @param hrz Direction horizontal/vertical
	 * @return An instance of Move without checking whether it belongs to a 
	 * langauge or not, nor to compute its score
	 * @warning Please use only the methods set() and get() above to access to the matrix
	 */
	Move findMaxWord(int r, int c, bool hrz) const;	 
	/**
	 * @brief  Given a move, it computes all the crosswords with the existing letters
	 * in the matrix. Each crossword is stored in an instance of the class Move,
	 * and the whole set of crosswords found in an instance of Movelist. Each crossword (move)
	 * stored in the result must be scored according to the given language as specified in move.h
	 * In the case that the specified movement does not fit within the bound of the matrix, it returns an 
	 * empty list of movements.
	 * @param m Movement 
	 * @param l Language
	 * @return A set of scored crosswords, each one stored as a movement within the list of movements. If the
	 * movement does not fit within the matrix, an empty list is returned
	 * @warning Please use only the methods set() and get() above to access to the matrix
	 */
	Movelist findCrosswords(const Move &m, const Language &l) const;
	

};

#endif /* TILES_H */

