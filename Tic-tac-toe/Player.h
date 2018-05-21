#pragma once
#include <iostream>
#include "Coordinate.h"
#include "Board.h"
#include <string>
using namespace std;

class Player{

    public:
        virtual const string name() const=0;
        virtual const Coordinate play(const Board& board)=0;
        char getChar(){
            return myChar;
        }
        char myChar;
        
};