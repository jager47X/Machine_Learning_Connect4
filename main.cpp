#include <iostream>
#include "Connect4.h"
#include "FileMangement.h"
int main() {
    FileMangement File;

    File.Import_CSV();

    Connect4 game;
    // game.play(AI.decition(),AI.decition());
    game=game.play();
    File.Output_CSV(game);//output current data to csv
    return 0;
}


//Connect 4 play(); ok
// File management make 100 test data.