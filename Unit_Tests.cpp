#include "Board.h"

#include <iostream>
#include <vector> 
#include <string>

using namespace std;

int main() {
	myChar c ('X');
	cout << c << endl;
	
	Board board1{4};
	cout << board1 << endl;
	
	Board board2{6};
	cout << board2 << endl;
	
	board1 = board2;
	cout << board1 << endl;
	
	board1 = 'X';
	cout << board1 << endl;
	
	Board board3{3};
	board3[{1,1}]='O';
	cout << board3 << endl;
	
	try {
		board1[{3,6}]='O';   // This should raise an exception
	} catch (const IllegalCoordinateException& ex) {
		cout << "Illegal coordinate: " << ex.theCoordinate() << endl;  // prints "Illegal coordinate: 3,6"
	}
	
	cout << board3[{1,0}] << endl;
	
	try { 
		board1 = 'a';        // This should raise an exception
	} catch (const IllegalCharException& ex) {
		cout << "Illegal char: " << ex.theChar() << endl;  // "Illegal char: a"
	}
	
	try {
		board1[{0,1}] = 'x';  // This should raise an exception
	} catch (const IllegalCharException& ex) {
		cout << "Illegal char: " << ex.theChar() << endl;  // "Illegal char: x"
	}
}