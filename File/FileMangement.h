//
// Created by yutto on 9/17/2023.
//
#include <fstream>
#include "vector"
#include "iostream"
#ifndef C4ML_FILEMANGEMENT_H
#define C4ML_FILEMANGEMENT_H
#include "../Connect4/Connect4.h"

class FileMangement{
private:
    Connect4::Tile CopyOfBoard[COLS_SIZE][ROWS_SIZE];
    static int const MAXSIZE= COLS_SIZE * ROWS_SIZE;
    Connect4::Tile CSV[MAXSIZE];//for output the current game

    std::vector<std::string> CountOfGame;//for output
    std::vector<std::string> WinnerOfGame;//for output
    std::vector<std::string> ArrayOfOwner;//for output
    std::vector<std::string> ArrayOfLoc;//for output
    std::vector<std::string> ArrayOfTurn;//for output
     int Current_game_index;//for output
    bool SortByTurn(int colmns,int rows);
    void BoardToArray(Connect4 &GAME);
public:

    void Output_CSV(Connect4 &game);//half done 9/30
    void Import_CSV(); //9/30//23 completed

};


#endif //C4ML_FILEMANGEMENT_H
