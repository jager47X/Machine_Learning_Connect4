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

    //previous csv
    if(file.is_open()){

/*
        file<<"GAME,";
        for (auto i = CountOfGame.begin(); i != CountOfGame.begin()+1; ++i){
            file<<*i<<","<<std::endl;
            std::cout<< *i<<","<<std::endl;
        }
        file<<"Winner,";
        for (auto i = WinnerOfGame.begin(); i != WinnerOfGame.begin()+1; ++i){
            file<<*i<<","<<std::endl;
            std::cout<< *i<<","<<std::endl;
        }
        file<<"Location,";
     while(!ArrayOfLoc.empty()){
         for (auto i = ArrayOfLoc.begin(); i != ArrayOfLoc.begin()+1; ++i){
             file<<*i<<","<<std::endl;
             std::cout<< *i<<","<<std::endl;
         }
     }
        file<<"Owner,";
        while(!ArrayOfOwner.empty()) {
            for (auto i = ArrayOfOwner.begin(); i != ArrayOfOwner.begin()+1; ++i){
                file<<*i<<","<<std::endl;
                std::cout<< *i<<","<<std::endl;
            }
        }

        file<<"Turn,";
            for (auto i = ArrayOfTurn.begin(); i != ArrayOfTurn.begin()+1; ++i){
                file<<*i<<","<<std::endl;
                std::cout<< *i<<","<<std::endl;
            }

        file<< std::endl;

*/

    //current one convert to csv^


    BoardToArray(GAME);//GAME->CopyofBoard

    for (int BOARD_COLUMN = 0;  BOARD_COLUMN<=COLS_SIZE-1; BOARD_COLUMN++) {
        for (int BOARD_ROW = 0; BOARD_ROW <= ROWS_SIZE - 1; BOARD_ROW++) {
            if(CopyOfBoard[BOARD_COLUMN][BOARD_ROW].OwnerOfTile!=0){
                SortByTurn(BOARD_COLUMN,BOARD_ROW);//runs only owner is 1 or 2;
            }
        }
        }


    file<<"GAME,"<<Current_game_index<<","<<std::endl;
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



    }
    file.close();
}

void FileMangement ::Import_CSV(){

    std::ifstream data;
    data.open(Data_Source_Index);
    std::string IMPORT_GAME,Title,Winner,Loc,Owner,Turn,GAMEINDEX;
    
    int rows=0;
    int col=0;
    bool next=true;
    bool firstTime=true;
    int counter=1;
    if(data.is_open()){
        while(next==true)
        {
            std::cout<<"Loading CSV...";
            next= false;
            if(firstTime==true){
                std::getline(data,Title,',');//GAME
                if(Title!="GAME"){
                    counter=0;
                    std::cout<<"EMPTY CSV";
                    break;
                }
                            }
            std::getline(data,GAMEINDEX,',');//GAME INDEX
            this->CountOfGame.push_back(GAMEINDEX);

            std::getline(data,Title,',');//Winner

            std::getline(data,Winner,',');// 1 0r 2 or 0
            this->WinnerOfGame.push_back(Winner);


            std::getline(data,Title,',');//Tile

            while(std::getline(data,Loc,',')){ // tile index
                if(Loc=="\nOwner"){//if it read next title stop
                    Title=Loc;//next title
                    break;
                }
                this->ArrayOfLoc.push_back(Loc);
            }
            while(std::getline(data,Owner,',')){// 1 or 2 or 0
                if(Owner=="\nTurn"){//if it read next title stop
                    Title=Owner;//next title
                    break;
                }
                this->ArrayOfOwner.push_back(Owner);
            }
            while(std::getline(data,Turn,',')){// 1 or 2 or 0
                if(Turn=="\nGAME"){//if it read next title stop
                    Title=Turn;//next title
                    break;
                }
                this->ArrayOfTurn.push_back(Turn);
            }

            if(Title!="\nGAME"){
                break;
            }else{
                next=true;
                firstTime=false;// not read title twice
                counter++;
            }
        }
        data.close();
        std::cout<<"\nThis CSV contains "<<counter<<" set of games !"<<std::endl;

    }else{
        std::cout<<"ERROR unable to open file. Check index error or file maybe corrupted\n";
    }
Current_game_index=counter+1;

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


    for (int BOARD_COLUMN = 0;  BOARD_COLUMN<=COLS_SIZE-1; BOARD_COLUMN++) {
        for (int BOARD_ROW = 0; BOARD_ROW <= ROWS_SIZE - 1; BOARD_ROW++) {
            CopyOfBoard[BOARD_COLUMN][BOARD_ROW].OwnerOfTile=GAME.GetOwnerOfTile(BOARD_COLUMN,BOARD_ROW);
            CopyOfBoard[BOARD_COLUMN][BOARD_ROW].turnOfTile=GAME.GetTurnOfTile(BOARD_COLUMN,BOARD_ROW);
            CopyOfBoard[BOARD_COLUMN][BOARD_ROW].locOfTile=GAME.GetLocOfTile(BOARD_COLUMN,BOARD_ROW);
        }
    }

}

bool  FileMangement ::SortByTurn(int colmns,int rows) {
    int index=1;
    for (int i = 0; i < MAXSIZE; i++) {
        if(this->CopyOfBoard[colmns][rows].turnOfTile==i){
           this->CSV[i].OwnerOfTile=this->CopyOfBoard[colmns][rows].OwnerOfTile;
            this->CSV[i].turnOfTile=this->CopyOfBoard[colmns][rows].turnOfTile;
            this->CSV[i].locOfTile=this->CopyOfBoard[colmns][rows].locOfTile;
         //  std::cout<<"OwnerOfTile: "<<this->CSV[i].OwnerOfTile<<"\t";//bad
       //    std::cout<<"turnOfTile "<<this->CSV[i].turnOfTile<<"\t";//ok
        //   std::cout<<"locOfTile "<<this->CSV[i].locOfTile<<"\t";//bad
           return true;
        }
    }
return false;
}
