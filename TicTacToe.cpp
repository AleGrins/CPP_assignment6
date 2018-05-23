#include "Player.h"
#include "Board.h"
#include "TicTacToe.h"

TicTacToe::TicTacToe(int i)
{
    Board tmp{i};
    gameBoard = tmp;
}

void TicTacToe::play(Player Px, Player Po)
{
    Px.setChar('X');
    Po.setChar('O');
    theWinner = &Px;
    int moves = 0, maxMoves = gameBoard.size() * gameBoard.size();
    Coordinate coord{0,0};
    while(moves <= maxMoves){
        
        //First player makes a move
        try { coord = Px.play(gameBoard); }
        catch (...){
            theWinner = &Po;
            break; 
        }
        //Check for illegal moves
        if(gameBoard[coord] != '.'){
            theWinner = &Po;
            break;
        }
        gameBoard[coord] = Px.getChar();
        moves++;
        if(moves >= (gameBoard.size()*2)-1){ //Minimum number of moves for possible victory
            if(checkVictory(Px.getChar())) break; //Stop if X wins
        }
        
        //Second player makes a move
        try { coord = Po.play(gameBoard); }
        catch (...) { break; }
        //Check for illegal moves
        if(gameBoard[coord] != '.') break;
        gameBoard[coord] = Po.getChar();
        moves++;
        if(moves >= (gameBoard.size()*2)-1){ //Minimum number of moves for possible victory
            if(checkVictory(Po.getChar())){ //Stop if O wins
                theWinner = &Po;
                break;
            } 
        }
        
        if(moves == maxMoves){
            theWinner = &Po;
            break;
        } 
    }
}

Board TicTacToe::board() const
{
    return gameBoard;
}

Player TicTacToe::winner() const
{
    return *theWinner;
}

bool TicTacToe::checkVictory(const gameChar c)
{
    bool victory = true;
    for(int i=0; i<gameBoard.size(); i++){
        //Going over first column
        //If found an instance of char c, check if it's part of a full row or diagonal
        if(gameBoard[{uint (i),0}] == c){
            
            if(i == 0){ //Check main diagonal
               for(int j=1; j<gameBoard.size() && victory; j++){
                   if(gameBoard[{uint (j),uint (j)}] != c) victory = false;
               }
               if(victory) return true;
            }
            
            if(i == gameBoard.size() - 1){ //Check other diagonal
               victory = true;
               for(int j=i, k=0; k<gameBoard.size() && victory; j--, k++){
                   if(gameBoard[{uint (j),uint (k)}] != c) victory = false;
               }
               if(victory) return true;
            }
            
            //Check potential row
            victory = true;
            for(int j=1; j<gameBoard.size() && victory; j++){
                if(gameBoard[{uint (i),uint (j)}] != c) victory = false;
            }
            if(victory) return true;
        }
    }
    for(int j=0; j<gameBoard.size(); j++){
        if(gameBoard[{0,uint (j)}] == c){
            victory = true;
            for(int i=1; i<gameBoard.size() && victory; i++){
                if(gameBoard[{uint (i),uint (j)}] != c) victory = false;
            }
            if(victory) return true;
        }
    }
    return false;
}
