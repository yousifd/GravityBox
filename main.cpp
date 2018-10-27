#include <cstdlib>
#include <ctime>

#include "Game.hpp"

int main(int argc, char* argv[]) {
    srand(time(0));

    Game game;

    game.Start();

    return 0;
}