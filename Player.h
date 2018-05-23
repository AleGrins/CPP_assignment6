#pragma once

#include "Board.h"

class Player {
private:
    myChar myChar;

public:
	Player();
	virtual const string name() const;
	virtual const Coordinate play(const Board& board);
	myChar getChar() const;
	void setChat(const myChar c);
};