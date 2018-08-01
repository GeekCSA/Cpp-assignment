/*
 * Board.cpp
 *
 *  Created on: May 3, 2018
 *      Author: Nissan and Moshe
 */

#include <stdio.h>
#include <math.h>

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

std::istream& operator>>(std::istream& input, Board& board){

	char c;
	int numOfRow = 0;
	bool isFirstLine = false;

	std::string line;

	while(std::getline(input,line)){
		//std::cout << line << endl;
		if(!isFirstLine){
			isFirstLine = true;
			board.free();
			board.create(line.length());
		}

		for (int i = 0; i < line.length(); ++i) {
			board[{numOfRow,i}] = line[i];
		}
		++numOfRow;
	}

	return input;
}


std::string Board::draw(int size){

	int num = 0;
	std::string fileName = "board"+to_string(num)+".ppm";

	while(true){
		ifstream f("board"+to_string(num)+".ppm");
		if(!f.good())
			break;
		else{
			num++;
		}
	}
	fileName = "board"+to_string(num)+".ppm";
	const int dimx = size, dimy = size;
	ofstream imageFile(fileName, ios::out | ios::binary);
	imageFile << "P6" << endl << dimx <<" " << dimy << endl << 255 << endl;
	RGB image[dimx*dimy];
	for (int j = 0; j < dimy; ++j)  {  // row
		for (int i = 0; i < dimx; ++i) { // column
			image[dimx*j+i].red = (20);
			image[dimx*j+i].green = (200);
			image[dimx*j+i].blue = (200);
		}
	}

	//Drawing rows and columns



	//Drawing the columns

	//std::cout << tableSize << endl;

	for (int i = 0; i < tableSize; ++i) {

		int Xfrom = i * (dimx/tableSize);

		for (int r = 10; r < dimy - 10 ; ++r) {

			image[dimy * (r) + Xfrom].red = (0);
			image[dimy * (r) + Xfrom].green = (0);
			image[dimy * (r) + Xfrom].blue = (0);
		}
	}

	//Drawing the rows
	for (int j = 0; j < tableSize; ++j) {

		int Yfrom = j * (dimy/tableSize) ;

		for (int r = 10; r < dimx - 10 ; ++r) {

			image[(r) + Yfrom * dimy].red = (0);
			image[(r) + Yfrom * dimy].green = (0);
			image[(r) + Yfrom * dimy].blue = (0);
		}
	}


	int loop = 0;
	//Drawing symbols
	for (int row = 0; row < tableSize; ++row) {
		for (int column = 0; column < tableSize; ++column) {

			int Xfrom = column * (dimx/tableSize);
			int Xto = (column + 1) * (dimx/tableSize);//not include the last bit
			int Yfrom = row * (dimy/tableSize) ;
			int Yto = (row + 1) * (dimy/tableSize);

			if (board[row][column] == 'X') {

				//Drawing X
				for (int r = 10; r < Yto - Yfrom - 10 ; ++r) {

					//Drawing \ diagonal of X
					image[dimy * (r + Yfrom) + Xfrom + r].red = (0);
					image[dimy * (r + Yfrom) + Xfrom + r].green = (0);
					image[dimy * (r + Yfrom) + Xfrom + r].blue = (0);

					//Drawing / diagonal of X
					image[dimy * (r + Yfrom) + Xto - (r)].red = (0);
					image[dimy * (r + Yfrom) + Xto - (r)].green = (0);
					image[dimy * (r + Yfrom) + Xto - (r)].blue = (0);

				}
				//cout << "(" << column << "," << row <<") - X" << endl;
			}
			else if(board[row][column] == 'O'){
				//Drawing O
				int stepFromCenter = 0;
				bool arriveToCenter = false;
				int halfsize = (Xto - Xfrom) / 2;

				int R = (Xto - Xfrom) / 2;
				int Ox = (Xto - Xfrom) / 2;
				int Oy = (Yto - Yfrom) / 2;

				for (int X = 10; X < Yto - Yfrom - 10 ; ++X) {

					int Y = sqrt(R*R - (X - Ox)*(X - Ox)) + Oy;

					int attach = 20;

					//Drawing bottom size of the circle
					image[dimy * (Y + Yfrom - attach) + Xfrom + X].red = (0);
					image[dimy * (Y + Yfrom - attach) + Xfrom + X].green = (0);
					image[dimy * (Y + Yfrom - attach) + Xfrom + X].blue = (0);

					image[dimy * (Yto - Y + attach) + Xfrom + X].red = (0);
					image[dimy * (Yto - Y + attach) + Xfrom + X].green = (0);
					image[dimy * (Yto - Y + attach) + Xfrom + X].blue = (0);

				}
				//cout << "(" << column << "," << row <<") - O" << endl;
			}
		}
	}

	///
	///image processing
	///
	imageFile.write(reinterpret_cast<char*>(&image), 3*dimx*dimy);
	imageFile.close();

	return fileName;
}

