#include <iostream>
#include "../Connect4/Connect4.h"
#include "../File/FileMangement.h"
#include "../Machine_Learning/ML_Agent.h"
int main() {
    FileMangement File;
    File.Import_CSV();
    Connect4 game;//dynamic allocation
    int setOfGame=0;
    std::cin>>setOfGame;
    ML_Agent agent1,agent2;
    //  game=game.play(agent1.decision(),agent.decision(),setOfGame);
    //set game play


    game=game.play();//dynamic allocation prefered
    File.Output_CSV(game);//output current data to csv
    return 0;
}


//Connect 4 play(); ok
// File management make 100 test data.
//9/30


