//
// Created by yutto on 9/17/2023.
//

#include "FileMangement.h"
#include "File_Index.h"

#include <cstdlib>
#include <iostream>

void FileMangement ::Output_CSV(Connect4 GAME) {
    GAME=this->CopyOfGame;
    std::ofstream file;
    file.open(Data_Source_Index);

    file.close();
}

void FileMangement ::Import_CSV(){

    std::ifstream file;
    file.open(Data_Source_Index);
    std::string line;
    while(std::getline(file,line)){
        CopyOfCSV.push_back(line);
    }
    for (auto i = CopyOfCSV.begin(); i != CopyOfCSV.end(); ++i)
       file<< *i;
    file.close();

    std::cout<<"Current line of this csv is "<<CopyOfCSV.size()<<std::endl;
}