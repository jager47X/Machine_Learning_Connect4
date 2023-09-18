//
// Created by yutto on 9/17/2023.
//
#include <fstream>
#include "vector"
#include "iostream"
#ifndef C4ML_FILEMANGEMENT_H
#define C4ML_FILEMANGEMENT_H
#include "Connect4.h"

class FileMangement{
private:
    Connect4::Tile CopyOfBoard[COLS_SIZE][ROWS_SIZE];
    static int const MAXSIZE= COLS_SIZE * ROWS_SIZE;
    Connect4::Tile CSV[MAXSIZE];
    std::vector<Connect4::Tile> CopyOfGame;
    int sortArray[ MAXSIZE];
    std::vector<std::vector<std::string> > parsedCsv;
    std::vector<std::string> parsedRow;
    void BoardToVector(Connect4 &GAME);
    // int Find_Current_CSVline();
public:
    void SortByTurn(int colmns,int rows);
    void Output_CSV(Connect4 &game);
    void Import_CSV();
};


#endif //C4ML_FILEMANGEMENT_H
