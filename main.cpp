#include <iostream>
#include "Game.hpp"

int main()
{
    try {
        Game game;
        game.run();
    } catch (std::exception& exception) {
        std::cout << "\nEXCEPTION: " << exception.what() << std::endl;
    }
}
