#include "Champion.h"

Champion::Champion() 
{
    gameChar tmp ('X');
    myChar = tmp;
}

const Coordinate Champion::play(const Board& board) 
{
    //If playing as X, defeat the dummy players by filling main diagonal
    if(myChar == 'X'){ 
        if(board[{0,0}] == '.'){ //Making the first move
            Coordinate myMove {0,0};
            return myMove;
        } 
        for(int i=1; i<board.size(); i++){
            if(board[{uint (i),uint (i)}] == '.'){
                Coordinate myMove {uint (i),uint (i)};
                return myMove;
            }
        }
    }
    
    //If playing as O, win by filling other diagonal, with first 2 moves filling the corners
    else{
        if(board[{uint (board.size() - 1),0}] == '.'){ //Take bottom left corner
            Coordinate myMove {uint (board.size() - 1),0};
            return myMove;
        } 
        
        //Fill rest of diagonal starting from top right corner
        for(int i=0, j=board.size() - 1; j>0; i++, j--){
            if(board[{uint (i),uint (j)}] == '.'){
                Coordinate myMove {uint (i),uint (j)};
                return myMove;
            }
        }
    }
    Coordinate myMove {0,0};
    return myMove;
}
