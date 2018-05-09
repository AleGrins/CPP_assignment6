#include <iostream>
#include <vector>
#include <exception>
using namespace std;

#pragma once

struct index //used to receive 2D coordinates for the [] overload
{
	int i, j;
};
	
//display 2D coordinates
std::ostream& operator<<(std::ostream& os, const index& ind)
{
    return os << ind.i << "," << ind.j;
}

//coordinates out of bounds, returns given coordinates
class IllegalCoordinateException : public std::exception {
	index ind;
    
    public:
    	IllegalCoordinateException(index ind_) : ind (ind_) {}

        index theCoordinate() const { return ind; }
};

//illegal character, returns given char
class IllegalCharException : public std::exception {
	char c;
    
    public:
    	IllegalCharException(char c_) : c (c_) {}

        char theChar() const { return c; }
};

//custom char class to accept only specific chars and throw exception otherwise
class myChar {
	public:
		myChar(const char c_);
		
		bool operator== (const myChar& other);		
		bool operator== (char c_);
		
		friend ostream& operator<< (ostream& output, const myChar& ch)
		{ 
    		output << ch.c;
    		return output;            
    	} 
	
	private:
		char c;
		
		bool validChar(char c); //check that given char is legal
};

class Board {
public:
	
	//constructor
    Board(const int N);
	
	//assignment from other board
	Board& operator= (const Board& other);
	
	//assignment from a char, fills entire board with provided char
	Board& operator= (char c);

	//access board member indicated by 2D coordinate ind
	myChar& operator[](index ind);
	
	//display the board
	friend ostream& operator<< (ostream& output, const Board& b)
	{ 
		for(int i=0; i<b.size; i++){
    		for(int j=0; j<b.size; j++){
    			output << b.board[i][j];
    		}
    		output << endl;
    	}
    	return output;            
    } 
	
private:
	vector<vector<myChar> >board; 
	int size;
	
	bool inBounds(index ind); //check that coordinates are not outside the board
};


