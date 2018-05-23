#include "Player.h"

Player::Player() {}

const string Player::name() const {}

const Coordinate Player::play(const Board& board) {}

gameChar Player::getChar() const { return myChar; }

void Player::setChar(gameChar c) const
{
    try {
		myChar = c;  
	} catch (const IllegalCharException& ex) {
		cout << "Illegal char: " << ex.theChar() << endl; 
	}
}
