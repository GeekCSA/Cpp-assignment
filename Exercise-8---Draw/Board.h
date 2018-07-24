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
#include <fstream>

#include "Cell.h"
#include "RGB.h"
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
	Board(int size = 0);
	Board(const Board&);

	~Board();

    friend std::istream & operator>>(std::istream&, Board&);
    friend std::ostream & operator<<(std::ostream&, const Board&);

    Board& operator=(const Board&);
    Board& operator=(const char);

    char operator[](const Cell&) const;
    Cell& operator[](const Cell&);

    std::string draw(int size);
};

#endif /* BOARD_H_ */
