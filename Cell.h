/*
 * cell.h
 *
 *  Created on: May 3, 2018
 *      Author: mcsa
 */

#ifndef CELL_H_
#define CELL_H_

//#include "Coordinate.h"

class Cell{

private:

	//Cell's location in the board.
//	coordinate cellCoordinate;

	int x_location;
	int y_location;

	//Status of the cell: empty (.) or hold (X or O)
	char status;

public:

	Cell();
	Cell(int,int);
	Cell(const Cell&);


	/**
	 * The function returns true if the cell is empty else returns false
	 */
	bool isEmpty() const;

	/**
	 * The function gets char (X or O) and puts it in the cell.
	 */
	void Catch_a_cell(char);

	/**
	 * These functions return the coordinate of the cell.
	 */
	int getX() const;
	int getY() const;

	/**
	 * The function returns the status of the cell.
	 */
	char getStatus() const;

	bool checkIfStatusIsCorrect(char c);

    friend std::istream & operator>>(std::istream&, const Cell&);
    friend std::ostream & operator<<(std::ostream&, const Cell&);

    operator char()const{
    	return status;
    }

    Cell& operator=(const Cell&);
    Cell& operator=(const char);
};


#endif /* CELL_H_ */
