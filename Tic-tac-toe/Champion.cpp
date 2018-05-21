#include "Champion.h"

/**
 *
 */
const Coordinate Champion::play(const Board& board){

	if(board[Coordinate{0,0}] == '.')
		return Coordinate{board.size()-1,board.size()-1};
	else{
		if(board[Coordinate{1,0}] != '.'){
			for(uint i = 0; i < board.size(); ++i){
				if(board[Coordinate{board.size()-1,i}] == '.'){
					cout << "x: " << i << ", y: " << board.size()-1 << endl;
					return Coordinate{board.size()-1,i};
				}
			}
		}
		else{
			for(uint i = 0; i < board.size(); ++i){
				if(board[Coordinate{i,board.size()-1}] == '.'){
					cout << "y: " << i << ", x: " << board.size()-1 << endl;
					return Coordinate{i,board.size()-1};
				}
			}
		}
	}
}
