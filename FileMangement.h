//
// Created by yutto on 9/17/2023.
//
#include <fstream>
#include "vector"
#include "iostream"
#ifndef C4ML_FILEMANGEMENT_H
#define C4ML_FILEMANGEMENT_H
#include "Connect4.h"

class FileMangement {
private:

    std::vector<std::string> CopyOfCSV;
    Connect4 CopyOfGame;
    // int Find_Current_CSVline();
public:
    void Output_CSV(Connect4 game);

    void Import_CSV();
};


#endif //C4ML_FILEMANGEMENT_H
