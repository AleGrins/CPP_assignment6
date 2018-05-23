#include "Player.h"

Player::Player() {}

const string Player::name() const {}

const Coordinate Player::play(const Board& board) {}

gameChar Player::getChar() const { return myChar; }

const void Player::setChar(const char c)
{
    try {
		gameChar tmp (c);
    		myChar = tmp;  
	} catch (const IllegalCharException& ex) {
		cout << "Illegal char: " << ex.theChar() << endl; 
	}
}
