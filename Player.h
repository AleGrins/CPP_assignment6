#pragma once

#include "Board.h"

class Player {
public:
	gameChar myChar;
	Player();
	virtual const string name() const;
	virtual const Coordinate play(const Board& board);
	gameChar getChar() const;
	const void setChar(const char c);
};
