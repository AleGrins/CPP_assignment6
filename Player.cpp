#include "Player.h"

Player::Player() {}

const string Player::name() const {}

const Coordinate Player::play(const Board& board) {}

gameChar Player::getChar() const { return myChar; }

void Player::setChar(const char c)
{
    try {
		gameChar tmp (c);
    		myChar = tmp;  
	} catch (const IllegalCharException& ex) {
		cout << "Illegal char: " << ex.theChar() << endl; 
	}
}
