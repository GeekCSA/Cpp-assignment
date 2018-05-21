/*
 * Board.h
 *
 *  Created on: May 3, 2018
 *      Author: mcsa
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "Cell.h"
#include "Coordinate.h"
#include "IllegalCoordinateException.h"

class Board{
private:
	//Size of the table
	uint tableSize;

	//The table
	Cell** board;


public:
	Board(uint);
	Board(const Board&);
	~Board();

	void create(uint);
	void free();

    friend std::istream & operator>>(std::istream&, const Board&);
    friend std::ostream & operator<<(std::ostream&, const Board&);

    Board& operator=(const Board&);
    Board& operator=(const char);

    char operator[](const Coordinate&) const;
    Cell& operator[](const Coordinate&);

	uint size() const;
};



#endif /* BOARD_H_ */
