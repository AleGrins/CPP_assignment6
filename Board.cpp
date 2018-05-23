#include "Board.h"
#include <iostream>
#include <vector>
#include <exception>

using namespace std;

//display 2D coordinates
std::ostream& operator<<(std::ostream& os, const Coordinate& ind)
{
    return os << ind.i << "," << ind.j;
}

gameChar::gameChar() { c = '.'; }

gameChar::gameChar(const char c_)
{
	if(!validChar(c_)) throw IllegalCharException(c_);
	c = c_;
}

gameChar& gameChar::operator= (const gameChar& other) const { c = other.c; }

bool gameChar::operator== (const gameChar& other) const { return (c == other.c); }		
bool gameChar::operator== (char c_) const { return (c == c_); }
bool gameChar::operator!= (const gameChar& other) const { return (c != other.c); }		
bool gameChar::operator!= (char c_) const { return (c != c_); }
		
bool gameChar::validChar(char c) //check that given char is legal
{
	if(c == '.' || c == 'X' || c == 'O') return true;
	return false;
}

//constructor
Board::Board(const int N)   
{
    boardSize = N;
    for(int i=0; i<N; i++){
    	gameChar c = '.';
    	vector<gameChar> temp;
    	for(int j=0; j<N; j++){
    		temp.push_back(c);
    	}
    	temp.push_back(c);
    	board.push_back(temp);
    }
}

Board::Board()   
{
    boardSize = 3;
    for(int i=0; i<3; i++){
    	gameChar c = '.';
    	vector<gameChar> temp;
    	for(int j=0; j<3; j++){
    		temp.push_back(c);
    	}
    	temp.push_back(c);
    	board.push_back(temp);
    }
}
	
//assignment from other board
Board& Board::operator= (const Board& other)
{
	board = other.board;
    boardSize = other.boardSize;
    return *this;
}
	
//assignment from a char, fills entire board with provided char
Board& Board::operator= (char c)
{
	gameChar tmp(c);
    for(int i=0; i<boardSize; i++){
    	for(int j=0; j<boardSize; j++){
    		board[i][j] = tmp;
    	}
    }
    return *this;
}

//access board member indicated by 2D coordinate ind
gameChar& Board::operator[](const Coordinate ind) 
{ 
	if(!inBounds(ind)) throw IllegalCoordinateException(ind);
	return board[ind.i][ind.j]; 
}
const gameChar& Board::operator[](const Coordinate ind) const
{
    if(!inBounds(ind)) throw IllegalCoordinateException(ind);
    return board[ind.i][ind.j];
}

int Board::size() const
{
    return boardSize;
}
	
bool Board::inBounds(Coordinate ind) const //check that coordinates are not outside the board
{
	if(int (ind.i) < 0 || int (ind.j) < 0 || int (ind.i) >= boardSize || int (ind.j) >= boardSize) return false;
	return true;
}



