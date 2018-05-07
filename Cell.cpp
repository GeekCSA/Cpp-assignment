/*
 * cell.cpp
 *
 *  Created on: May 3, 2018
 *      Author: mcsa
 */

using namespace std;

#include <iostream>
#include "Cell.h"

Cell::Cell(){

	x_location = 0;
	y_location = 0;

	status = '.';
}

Cell::Cell(int y, int x){

	x_location = x;
	y_location = y;

	status = '.';
}

Cell::Cell(const Cell& c){

	x_location = c.x_location;
	y_location = c.y_location;

	status = c.status;
}


void Cell::Catch_a_cell(char c){
	if (status == '.')
		if(c == 'X' || c =='O')
			status = c;
		else
			throw std::invalid_argument( "Incorrect value\n" );

	else
		throw std::invalid_argument( "The cell is not empty\n" );
}

bool Cell::isEmpty() const{
	return status == '.';
}

int Cell::getX() const{
	return x_location;
}

int Cell::getY() const{
	return y_location;
}

char Cell::getStatus() const{
	return status;
}

std::ostream & operator<<(std::ostream& os, const Cell& c){
	return os << c.status;
}

Cell& Cell::operator=(const Cell& c){
	x_location = c.x_location;
	y_location = c.y_location;

	status = c.status;

	return *this;
}

Cell& Cell::operator=(const char c){
	if(c == '.' || c == 'X' || c == 'O'){
		status = c;
		return *this;
	}
	else
		throw IllegalCharException(c);
}









//std::istream & operator>>(std::istream& is, const Cell& c){
//
//	//TODO check the input if it correct
//
////	int x;
////	int y;
////	char s;
////
////	is >> x;
////	is >> y;
////	is >> s;
//
//	return is;
//
//}



