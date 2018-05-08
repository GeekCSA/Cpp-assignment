/*
 * Board.cpp
 *
 *  Created on: May 3, 2018
 *      Author: mcsa
 */

#include "Board.h"
using namespace std;

Board::Board(int size){
	create(size);

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			board[i][j] = Cell(i,j);
		}
	}
}

Board::Board(const Board& b){

	create(b.tableSize);

	for(int i = 0; i < tableSize; i++){
		for(int j = 0; j < tableSize; j++){
			board[i][j] = b.board[i][j];
		}
	}
}

void Board::create(int size){
	tableSize = size;

	//Create 2D array of cells
	board = new Cell*[tableSize];
	for(int i = 0; i < tableSize; i++)
		board[i] = new Cell[tableSize];
}

Board::~Board(){
	free();
}

void Board::free(){
	for(int i = 0; i < tableSize; i++)
		delete [] board[i];

	delete [] board;
}

std::ostream & operator<<(std::ostream& os, const Board& b){
	for(int i = 0; i < b.tableSize; i++){
		for(int j = 0; j < b.tableSize; j++)
			os << b.board[i][j];
		os << endl;
	}

	return os;
}

Board& Board::operator=(const Board& b){

	if(b.tableSize != tableSize){
		free();
		create(b.tableSize);
	}

	for(int i = 0; i < tableSize; i++)
		for(int j = 0; j < tableSize; j++){
			board[i][j] = b.board[i][j];
		}

	return *this;
}

Board& Board::operator=(const char c){

	if(c == '.' || c == 'X' || c == 'O'){
		for(int i = 0; i < tableSize; i++)
			for(int j = 0; j < tableSize; j++)
				board[i][j] = c;
		return *this;
	}
	else
		throw IllegalCharException(c);

}

char Board::operator[](const Cell& c) const{
	if((c.getX() >= tableSize) || (c.getY() >= tableSize))
		throw IllegalCoordinateException(c.getX(),c.getY());
	else{
		int x = c.getX();
		int y = c.getY();

		return board[y][x].getStatus();
	}
}

Cell& Board::operator[](const Cell& c){
	if((c.getX() >= tableSize) || (c.getY() >= tableSize)){
		throw IllegalCoordinateException(c.getX(),c.getY());
	}
	else{
		int x = c.getX();
		int y = c.getY();

		return board[y][x];
	}
}
