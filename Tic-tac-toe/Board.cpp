/*
 * Board.cpp
 *
 *  Created on: May 3, 2018
 *      Author: mcsa
 */

#include "Board.h"
using namespace std;

Board::Board(uint size){
	create(size);

	for (int i = 0; i < tableSize; ++i) {
		for (int j = 0; j < tableSize; ++j) {
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

void Board::create(uint size){
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

Board& Board::operator=(const Board& b){//TODO if correct

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

char Board::operator[](const Coordinate& c) const{
	if((c.x >= tableSize) || (c.y >= tableSize))
		throw IllegalCoordinateException(c.x,c.y);
	else{
		int x = c.x;
		int y = c.y;

		return board[y][x].getStatus();
	}
}

Cell& Board::operator[](const Coordinate& c){
	if((c.x >= tableSize) || (c.y >= tableSize)){
		throw IllegalCoordinateException(c.x,c.y);
	}
	else{
		int x = c.x;
		int y = c.y;

		return board[y][x];
	}
}

uint Board::size() const{
	return tableSize;
}



