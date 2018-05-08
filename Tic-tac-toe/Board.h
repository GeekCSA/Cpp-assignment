/*
 * Board.h
 *
 *  Created on: May 3, 2018
 *      Author: Moshe and Nissan
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Cell.h"
#include "IllegalCoordinateException.h"

class Board{
private:
	//Size of the table
	int tableSize;

	//The table
	Cell** board;

	void free();
	void create(int);

public:
	Board(int);
	Board(const Board&);

	~Board();

    friend std::istream & operator>>(std::istream&, const Board&);
    friend std::ostream & operator<<(std::ostream&, const Board&);

    Board& operator=(const Board&);
    Board& operator=(const char) throw (IllegalCharException);

    char operator[](const Cell&) const throw (IllegalCoordinateException);
    Cell& operator[](const Cell&) throw (IllegalCoordinateException);
};



#endif /* BOARD_H_ */
