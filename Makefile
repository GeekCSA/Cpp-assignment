a: main.o Cell.o Board.o
	clang++-5.0 main.o Cell.o Board.o -o a

main.o: main.cpp
	clang++-5.0 -std=c++14 -c main.cpp

Cell.o:
	clang++-5.0 -c Cell.cpp

Board.o:
	clang++-5.0 -c Board.cpp
