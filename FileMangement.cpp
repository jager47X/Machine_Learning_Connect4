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
    //previous csv
    {

        file<<"GAME,";
        file<< this->CountOfGame.pop_back();file<<","<<std::endl;
        file<<"Winner,";
        file<< this->WinnerOfGame.pop_back();file<<","<<std::endl;
        file<<"Location,";
     while(ArrayOfOwner.empty()){
         file<< this->ArrayOfLoc.pop_back();file<<","<<std::endl;
     }
        file<< std::endl;

        file<<"Owner,";
        while(ArrayOfOwner.empty()){
            file<< this->ArrayOfOwner.pop_back();file<<","<<std::endl;
        }
        file<< std::endl;

        file<<"Turn,";
        while(ArrayOfOwner.empty()){
            file<< this->ArrayOfTurn.pop_back();file<<","<<std::endl;
        }
            file<< std::endl;

        numberOfGame++;
    }
    BoardToArray(GAME);
    file<<"GAME,"<<numberOfGame<<","<<std::endl;
    file<<"Winner,"<<GAME.GetWinner()<<","<<std::endl;

    file<<"Location,";
    for (int i = 0; i < MAXSIZE; i++) {
        if (this->CSV[i].OwnerOfTile < 0) {//desase by turn
            break;
        }
        if(this->CSV[i].GetLocation()>0){file << this->CSV[i].GetLocation()<< ",";}


    }
    file<< std::endl;

    file<<"Owner,";
        for (int i = 0; i < MAXSIZE; i++) {
            if (this->CSV[i].OwnerOfTile < 0) {//desase by turn
                break;
            }

            if(this->CSV[i].OwnerOfTile>0){file<<this->CSV[i].OwnerOfTile<< ",";}

        }
    file<< std::endl;

    file<<"Turn,";
            for (int i = 0; i < MAXSIZE; i++) {
                if (this->CSV[i].turnOfTile < 0) {//desase by turn
                    break;
                }
                if(this->CSV[i].turnOfTile>0){file << this->CSV[i].turnOfTile<< ",";}



            }
    file<< std::endl;


    file.close();
}

void FileMangement ::Import_CSV(){

    std::ifstream data;
    data.open(Data_Source_Index);
    std::string GAME,Title,Winner,Loc,Owner,Turn;
    std::string line;
    std::stringstream lineStream(line);
    int rows=0;
    int col=0;
    while(!data.eof())
    {
        std::getline(lineStream,Title,',');
        std::getline(lineStream,GAME,',');
        this->CountOfGame=GAME;
        std::getline(lineStream,Title,',');
        std::getline(lineStream,Winner,',');
        this->WinnerOfGame=Winner;

        std::getline(lineStream,Title,',');
        std::getline(lineStream,Loc,',');
        this->ArrayOfLoc=Loc;

        std::getline(lineStream,Title,',');
        std::getline(lineStream,Owner,',');
        this->ArrayOfOwner=Owner;

        std::getline(lineStream,Title,',');
        std::getline(lineStream,Turn,',');
        this->ArrayOfTurn=Turn;
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

void  FileMangement ::BoardToArray(Connect4 &GAME){

int index=0;
    for (int BOARD_COLUMN = 0;  BOARD_COLUMN<=COLS_SIZE-1; BOARD_COLUMN++) {
        for (int BOARD_ROW = 0; BOARD_ROW <= ROWS_SIZE - 1; BOARD_ROW++) {
            CopyOfBoard[BOARD_COLUMN][BOARD_ROW].OwnerOfTile=GAME.GetOwnerOfTile(BOARD_COLUMN,BOARD_ROW);
            CopyOfBoard[BOARD_COLUMN][BOARD_ROW].turnOfTile=GAME.GetTurnOfTile(BOARD_COLUMN,BOARD_ROW);
            CopyOfBoard[BOARD_COLUMN][BOARD_ROW].locOfTile=GAME.GetLocOfTile(BOARD_COLUMN,BOARD_ROW);
            index++;
            SortByTurn(BOARD_COLUMN,BOARD_ROW);
        }
    }

}

void  FileMangement ::SortByTurn(int colmns,int rows) {
    int index=1;
    for (int i = 0; i < MAXSIZE; i++) {
        if(this->CopyOfBoard[colmns][rows].turnOfTile==i){
           this->CSV[i].OwnerOfTile=this->CopyOfBoard[colmns][rows].OwnerOfTile;
            this->CSV[i].turnOfTile=this->CopyOfBoard[colmns][rows].turnOfTile;
            this->CSV[i].locOfTile=this->CopyOfBoard[colmns][rows].locOfTile;
           std::cout<<"OwnerOfTile: "<<this->CSV[i].OwnerOfTile<<"\t";//bad
           std::cout<<"turnOfTile "<<this->CSV[i].turnOfTile<<"\t";//ok
           std::cout<<"locOfTile "<<this->CSV[i].locOfTile<<"\t";//bad
        }
    }

}

