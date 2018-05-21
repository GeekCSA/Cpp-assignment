#pragma once

#include <math.h>       /* ceil */
#include "DummyPlayers.h"


class TicTacToe{
    int table_size;
    Board play_board{1};
    string winnerStr;
    Player* winnerPlayer = nullptr;

    bool checkPoint(const Coordinate&) const;
    bool checkWinner(const Coordinate&,const char) const;

    public:
        TicTacToe(int);
        void play(Player&,Player&);//1st-'X' , 2nd- 'O'
        const Board& board() const;//final board of game
        Player& winner() const{
        	return *winnerPlayer;
        }
};
