#pragma once

#include "Player.h"

class Champion: public Player {
private:
    myChar myChar;
    
public:
    Champion();
	const string name() const override { return "Alex Grinshpun"; }
	const Coordinate play(const Board& board) override;
};