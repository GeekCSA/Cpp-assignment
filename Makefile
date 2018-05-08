
CXX=clang++-5.0
CXXFLAGS=-std=c++14 -Wall -Werror -Wvla

all: Board.o Cell.o main.o

Board.o: Board.cpp Board.h
	$(CXX) $(CXXFLAGS) -c Board.cpp -o Board.o

Cell.o: Cell.cpp Cell.h
	$(CXX) $(CXXFLAGS) -c Cell.cpp -o Cell.o

clean:
	rm *.o 