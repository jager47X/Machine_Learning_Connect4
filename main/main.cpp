#include <iostream>
#include "../Connect4/Connect4.h"
#include "../File/FileMangement.h"
int main() {
    FileMangement File;
    File.Import_CSV();
    Connect4 game;
    int setOfGame=0;
    std::cin>>setOfGame;
    //AI
    //
    //  game=game.play(AI.decision(),AI.decision(),setofgame);
    //set game play
    game=game.play();//dynamic allocation prefered
    File.Output_CSV(game);//output current data to csv
    return 0;
}


//Connect 4 play(); ok
// File management make 100 test data.