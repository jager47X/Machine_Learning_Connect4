//
// Created by yuto on 9/17/2023.
//

#include "FileMangement.h"
#include "File_Index.h"

#include <cstdlib>
#include <iostream>

void FileMangement ::Output_CSV(Connect4 &GAME) {

    std::ofstream file;
    file.open(Data_Source_Index);
    int numberOfGame = 1;

   // while(!file.eof()) {
    file<<"GAME,"<<numberOfGame<<","<<std::endl;

    file<<"Winner,"<<GAME.GetWinner()<<","<<std::endl;

    file<<"Tile,";
    for (int i = 0; i < MAXSIZE; i++) {
        if (this->CSV[i].OwnerOfTile < 0) {//desase by turn
            break;
        }
        file << this->CSV[i].GetLocation();
    }
    file<< std::endl;

    file<<"Owner,";
        for (int i = 0; i < MAXSIZE; i++) {
            if (this->CSV[i].OwnerOfTile < 0) {//desase by turn
                break;
            }
            file<<this->CSV[i].OwnerOfTile;
        }
    file<< std::endl;

    file<<"Turn,";
            for (int i = 0; i < MAXSIZE; i++) {
                if (this->CSV[i].OwnerOfTile < 0) {//desase by turn
                    break;
                }
                file<<this->CSV[i].turnOfTile;

            }
    file<< std::endl;

  //  }
    file.close();
}

void FileMangement ::Import_CSV(){

    std::ifstream data;
    data.open(Data_Source_Index);
    std::string line;

    while(std::getline(data,line))
    {
        std::stringstream lineStream(line);
        std::string cell;
        while(std::getline(lineStream,cell,','))
        {
            parsedRow.push_back(cell);
        }

        parsedCsv.push_back(parsedRow);
    }
    data.close();
    std::cout<<"Current line of this csv is "<< parsedCsv.size()<<std::endl;

}
/*
 * Game	1
Winner	2
Tile	13	12	11	22	14	32	15	42
Owner	1	2	1	2	1	2	1	2
Turn	1	2	3	4	5	6	7	8

 *
 *
 */


//CSV design
//Winner 1

void  FileMangement ::BoardToVector(Connect4 &GAME){
    GAME.GetWinner();
    for (int BOARD_COLUMN = 0;  BOARD_COLUMN<=COLS_SIZE-1; BOARD_COLUMN++) {
        for (int BOARD_ROW = 0; BOARD_ROW <= ROWS_SIZE - 1; BOARD_ROW++) {
            this->CopyOfBoard[BOARD_COLUMN][BOARD_ROW] = GAME.GetTile(BOARD_COLUMN, BOARD_ROW);
            SortByTurn(BOARD_COLUMN,BOARD_ROW);
        }
    }

}

void  FileMangement ::SortByTurn(int colmns,int rows) {
    int index=1;
    for (int i = 0; i < MAXSIZE; i++) {
        if(this->CopyOfBoard[colmns][rows].turnOfTile=i){
           this->CSV[i]=CopyOfBoard[colmns][rows];
        }
    }

}

