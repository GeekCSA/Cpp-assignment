#include "TicTacToe.h"
#include "Champion.h"

TicTacToe::TicTacToe(int size):table_size(size){
	play_board = Board(size);
}

const Board& TicTacToe::board() const{
	return play_board;
}


bool TicTacToe::checkPoint(const Coordinate& coord) const{
	if (play_board[coord]!='.')
		return false;

	return true;
}

bool TicTacToe::checkWinner(const Coordinate& coord,const char c) const{

	bool thereIsAVictory = true;

	for(int i = 0; i < play_board.size() && thereIsAVictory; ++i){

		if(play_board[Coordinate{coord.y,static_cast<uint>(i)}] != c)
			thereIsAVictory = false;
	}
	if(thereIsAVictory){
//		cout << "run on x" << endl;
		return thereIsAVictory;
	}

	thereIsAVictory = true;

	for(int i = 0; i < play_board.size() && thereIsAVictory; ++i){
		if(play_board[Coordinate{static_cast<uint>(i),coord.x}] != c)
			thereIsAVictory = false;
	}
	if(thereIsAVictory){
//		cout << "run on y" << endl;
		return thereIsAVictory;
	}

	thereIsAVictory = true;

	for(int i = 0; i < play_board.size() && thereIsAVictory; ++i){
		if(play_board[Coordinate{static_cast<uint>(i),static_cast<uint>(i)}] != c)
			thereIsAVictory = false;
	}
	if(thereIsAVictory){
//		cout << "run on main diagonal" << endl;
		return thereIsAVictory;
	}

	thereIsAVictory = true;

	for(int i = 0; i < play_board.size() && thereIsAVictory; ++i){
		if(play_board[Coordinate{play_board.size() - 1 - static_cast<uint>(i),static_cast<uint>(i)}] != c)
			thereIsAVictory = false;
	}
	if(thereIsAVictory){
//		cout << "run on secondary diagonal" << endl;
		return thereIsAVictory;
	}

	return false;
}

void TicTacToe::play(Player& p1,Player& p2){

	play_board = '.';

	bool win = false;
	char charOfWinner = '.';
	int i = 0;

	p1.myChar = 'X';
	p2.myChar = 'O';

	while(i<=table_size*table_size && !win){
		++i;

		Coordinate coord={0,0};
		try{
//			cout << "player 1" << endl;
			coord = p1.play(play_board);
			if(checkPoint(coord)){
				play_board[coord] = p1.getChar();
			}
			else{
				throw IllegalCoordinateException(coord.y,coord.x);
				win = true;
				charOfWinner = p2.getChar();
			}

			win = checkWinner(coord,p1.getChar());
			if(win){
				charOfWinner = p1.getChar();
				cout << "Has winner 1" << endl;
				break;
			}
		}catch(...){
			cout << "Throw exception" << endl;

			win = true;
			charOfWinner = p2.getChar();
			break;
		}

		cout << play_board << endl;

		++i;

		if(i < table_size*table_size ){
			try{
				cout << "player 2" << endl;
				coord = p2.play(play_board);
				if(checkPoint(coord)){
					play_board[coord] = p2.getChar();
				}
				else{
					throw IllegalCoordinateException(coord.y,coord.x);
					win = true;
					charOfWinner = p1.getChar();
				}

				win = checkWinner(coord,p2.getChar());
				if(win){
					charOfWinner = p2.getChar();
					cout << "Has winner 2" << endl;
					break;
				}
			}catch(...){
				cout << "Throw exception" << endl;

				win = true;
				charOfWinner = p1.getChar();
				break;
			}
			cout << play_board << endl;

		}
	}

	if(charOfWinner == p1.getChar()){
		winnerPlayer = &p1;
		cout << "Has winner 3" << endl;
	}
	if(charOfWinner == p2.getChar()){
		winnerPlayer = &p2;
		cout << "Has winner 4" << endl;
	}
	if(charOfWinner == '.'){
		winnerPlayer = &p2;
		cout << "Has draw" << endl;
	}
}
