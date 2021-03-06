#pragma once

#include "Player.h"
#include "Board.h"

class TicTacToe {
private:
    Player* theWinner;
    Board gameBoard;
    

public:
    TicTacToe(int i);
	void play(Player Px, Player Po);
	Board board() const;
	Player winner() const;
	bool checkVictory(const gameChar c);
};
