#pragma once

#include "Player.h"

class Champion: public Player {
private:
    gameChar myChar;
    
public:
    Champion();
	const string name() const override { return "Alex Grinshpun"; }
	const Coordinate play(const Board& board) override;
	char getChar() const;
	void setChar(const char c);
};
