#include "Board.h"
#include <iostream>
#include <vector>
#include <exception>

using namespace std;

myChar::myChar(const char c_)
{
	if(!validChar(c_)) throw IllegalCharException(c_);
	c = c_;
}

bool myChar::operator== (const myChar& other) const { return (c == other.c); }		
bool myChar::operator== (char c_) const { return (c == c_); }

bool myChar::validChar(char c) //check that given char is legal
{
	if(c == '.' || c == 'X' || c == 'O') return true;
	return false;
}


//constructor
Board::Board(const int N)   
{
    size = N;
    for(int i=0; i<N; i++){
    	myChar c = '.';
    	vector<myChar> temp;
    	for(int j=0; j<N; j++){
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
    size = other.size;
    return *this;
}
	
//assignment from a char, fills entire board with provided char
Board& Board::operator= (char c)
{
	myChar tmp(c);
    for(int i=0; i<size; i++){
    	for(int j=0; j<size; j++){
    		board[i][j] = tmp;
    	}
    }
    return *this;
}

//access board member indicated by 2D coordinate ind
myChar& Board::operator[](index ind) 
{ 
	if(!inBounds(ind)) throw IllegalCoordinateException(ind);
	return board[ind.i][ind.j]; 
}
	
bool Board::inBounds(index ind) //check that coordinates are not outside the board
{
	if(ind.i < 0 || ind.j < 0 || ind.i >= size || ind.j >= size) return false;
	return true;
}



