#include <iostream>
#include "Game.h"
int main() {
    Game game;
    if(game.playGame()){
        std::cout << "Player Wins!";
    }else{
        std::cout << "Computer Wins!";
    }
    return 0;
}
