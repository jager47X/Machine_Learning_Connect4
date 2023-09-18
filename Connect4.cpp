//
// Created by yutto on 9/16/2023.
//

#include "Connect4.h"
#include "Connect4.h"

Connect4::Connect4() {
    ResetBoard();

}

Connect4::~Connect4() {

}

Connect4 Connect4::play() {
    int input = 0, turn = 1;
    Connect4 game;

    do {
        if (game.FullBoard() == false) {
            do {
                game.DisplayBoard();
                std::cout << ("Player 1 Select between 1-7>>");
                std::cin >> input;

            } while (game.PlayerDrop(input, game.PLAYER1) != true);

             std::cout << "Player 1 Selected " << input << std::endl;
            if (game.WinCheck(game.PLAYER1) == true) {
                std::cout << "\nPlayer 1 won.\n";
                game.SetWinner(1);
                game.DisplayBoard();
                break;
            }
        }

        if (this->FullBoard() == false) {
            do {
                game.DisplayBoard();
                  std::cout << ("Player 2 Select between 1-7>>");
                    std::cin >> input;
            } while (game.PlayerDrop(input, game.PLAYER2) != true);

              std::cout << "Player 2 Selected " << input << std::endl;
            if (game.WinCheck(game.PLAYER2) == true) {
                std::cout << "\nPlayer 2 won.\n";
                game.SetWinner(2);
                game.DisplayBoard();
                break;
            }
        }

    } while (game.FullBoard() == false);
    return game;
}

bool Connect4::PlayerDrop(int dropChoice, char activePlayer){
    dropChoice--;//adjust to array size selection for user is 1-7; so minus 1 to fit array.

    //   std::cout << "\ndropChoice is " << dropChoice << std::endl;

    if(FullBoard()==false) {
        if (dropChoice >=0&&dropChoice<=6) {//0-6
            for (int BOARD_COLUMN = 5; BOARD_COLUMN >=0; BOARD_COLUMN--){
                if(Board[BOARD_COLUMN][dropChoice].OwnerOfTile==0){
                    Board[BOARD_COLUMN][dropChoice].OwnerOfTile=Board[BOARD_COLUMN][dropChoice].ToOwnerOfTile(activePlayer);
                    Board[BOARD_COLUMN][dropChoice].turnOfTile=turn;
                    Board[BOARD_COLUMN][dropChoice].SetLocation(BOARD_COLUMN,dropChoice);
                    Board[BOARD_COLUMN][dropChoice].locOfTile=Board[BOARD_COLUMN][dropChoice].GetLocation();
                    
                    std::cout<<"OwnerOfTile: "<<Board[BOARD_COLUMN][dropChoice].OwnerOfTile<<"\t";//bad
                    std::cout<<"turnOfTile "<<Board[BOARD_COLUMN][dropChoice].turnOfTile<<"\t";//ok
                    std::cout<<"locOfTile "<<Board[BOARD_COLUMN][dropChoice].locOfTile<<"\t";//bad
                    turn++;
                    return true;
                }
            }

        }
        else {
            std::cout << ("(!)Invalid Selection\n");
            return false;
        }
    }



    //  std::cout<<("\nNo Space to put tiles\n");
    return false;
}
void Connect4::DisplayBoard()  {
    for (int BOARD_COLUMN = 0; BOARD_COLUMN <= COLS_SIZE-1; ++BOARD_COLUMN)
    {
        //std::cout<<BOARD_COLUMN;
        for (int BOARD_ROW = 0; BOARD_ROW <= ROWS_SIZE-1; ++BOARD_ROW)
        {
            //std::cout<<BOARD_ROW;
            std::cout << ToactivePlayer(Board[BOARD_COLUMN][BOARD_ROW]);
        }std::cout<<std::endl;
    }
    //std::cout << "1234567" << std::endl;
}
/*
 *
 * 11_2_3_4_5_6_7_
21_2_3_4_5_6_7_
31_2_3_4_5_6_7_
41_2_3_4_5_6_7_
51_2_3_4_5_6_7_
61_2_3_4_5_6_7_
 */
void Connect4::ResetBoard()
{

    for (int BOARD_COLUMN = 0;  BOARD_COLUMN<=COLS_SIZE-1; BOARD_COLUMN++)
    {
        for (int BOARD_ROW = 0; BOARD_ROW <= ROWS_SIZE-1; BOARD_ROW++)
        {

            Board[BOARD_COLUMN][BOARD_ROW].OwnerOfTile=0;
            Board[BOARD_COLUMN][BOARD_ROW].turnOfTile = 0;
        }
    }
}
char Connect4::ToactivePlayer(Tile tile) {
    if (tile.OwnerOfTile == 1)
        return PLAYER1;
    if (tile.OwnerOfTile == 2)
        return PLAYER2;
    //if (tile.OwnerOfTile == 0)
    return EMPTY;


}
bool Connect4::WinCheck(char activePlayer)
{
    for (int BOARD_COLUMN = COLS_SIZE-1; BOARD_COLUMN >=0 ; BOARD_COLUMN--) {
        for (int BOARD_ROW = ROWS_SIZE - 1; BOARD_ROW >= 0; BOARD_ROW--) {
            if (
                    (Board[BOARD_COLUMN][BOARD_ROW].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN-1][BOARD_ROW].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN-2][BOARD_ROW].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN-3][BOARD_ROW].ToactivePlayer() == activePlayer)
                    ) {
                if (activePlayer == PLAYER1) {
                    winner = 1;
                }
                else {
                    winner = 2;
                }
                return true;
            }
            if (
                    (Board[BOARD_COLUMN][BOARD_ROW].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN ][BOARD_ROW-1].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN][BOARD_ROW-2].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN] [BOARD_ROW-3].ToactivePlayer() == activePlayer)
                    ) {
                if (activePlayer == PLAYER1) {
                    winner = 1;
                }
                else {
                    winner = 2;
                }
                return true;
            }
            if (
                    (Board[BOARD_COLUMN][BOARD_ROW].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN - 1][BOARD_ROW + 1].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN - 2][BOARD_ROW + 2].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN - 3][BOARD_ROW + 3].ToactivePlayer() == activePlayer)
                    ) {
                if (activePlayer == PLAYER1) {
                    winner = 1;
                }
                else {
                    winner = 2;
                }
                return true;
            }
            if (
                    (Board[BOARD_COLUMN][BOARD_ROW].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN + 1][BOARD_ROW - 1].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN + 2][BOARD_ROW - 2].ToactivePlayer() == activePlayer) &&
                    (Board[BOARD_COLUMN + 3][BOARD_ROW - 3].ToactivePlayer() == activePlayer)
                    ) {
                if (activePlayer == PLAYER1) {
                    winner = 1;
                }
                else {
                    winner = 2;
                }
                return true;

            }

        }
    }

    winner=0;
    return false;
}

bool Connect4::FullBoard() {

    int full = 0;
    for (int BOARD_ROW = 0; BOARD_ROW <= ROWS_SIZE+1; BOARD_ROW++) {
        if( ToactivePlayer(Board[0][BOARD_ROW]) != EMPTY)
            full++;
    }
    if (full >= 7) {
        std::cout << "Board is full. Withdraw.\n";
        return true;
    }
    winner=-1;
    return false;
}


void Connect4::SetTile(Tile New_tile,int col, int row)
{
    Board[col][row] = New_tile;
}
int Connect4::GetTurnOfTile( int BOARD_COLUMN, int BOARD_ROW) {//triple return
    Tile CopyOfBoard[COLS_SIZE][ROWS_SIZE];
    CopyOfBoard[BOARD_COLUMN][BOARD_ROW].turnOfTile=Board[BOARD_COLUMN][BOARD_ROW].turnOfTile;
    std::cout<<"FileMangement ::BoardToArray turnOfTile: "<<CopyOfBoard[BOARD_COLUMN][BOARD_ROW].turnOfTile;//bad
    return CopyOfBoard[BOARD_COLUMN][BOARD_ROW].turnOfTile;
}
int Connect4::GetOwnerOfTile( int BOARD_COLUMN, int BOARD_ROW) {//triple return
    Tile CopyOfBoard[COLS_SIZE][ROWS_SIZE];
    CopyOfBoard[BOARD_COLUMN][BOARD_ROW].OwnerOfTile=Board[BOARD_COLUMN][BOARD_ROW].OwnerOfTile;
    std::cout<<"FileMangement ::BoardToArray OwnerOfTile "<<CopyOfBoard[BOARD_COLUMN][BOARD_ROW].OwnerOfTile<<"\t";//ok

    return CopyOfBoard[BOARD_COLUMN][BOARD_ROW].OwnerOfTile;
}
int Connect4::GetLocOfTile( int BOARD_COLUMN, int BOARD_ROW) {//triple return
    Tile CopyOfBoard[COLS_SIZE][ROWS_SIZE];
    CopyOfBoard[BOARD_COLUMN][BOARD_ROW].locOfTile=Board[BOARD_COLUMN][BOARD_ROW].locOfTile;
    std::cout<<"FileMangement ::BoardToArray locOfTile "<< CopyOfBoard[BOARD_COLUMN][BOARD_ROW].locOfTile<<"\t";//bad

    return CopyOfBoard[BOARD_COLUMN][BOARD_ROW].locOfTile;
}

void Connect4::SetWinner(int New_Winner) {
    this->winner = New_Winner;
}
int  Connect4::GetWinner() {
    return this->winner;
}

void SetLocation();
