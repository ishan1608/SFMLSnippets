//
// Created by ishan on 29/1/18.
//

#ifndef SFMLSNIPPETS_GAME_HPP
#define SFMLSNIPPETS_GAME_HPP

#include <SFML/Graphics.hpp>

class Game {
    public:
        Game();
        void run();

    private:
        void processEvents();
        void update();
        void render();

    private:
        sf::RenderWindow window;
        sf::CircleShape player;
};

#endif //SFMLSNIPPETS_GAME_HPP
