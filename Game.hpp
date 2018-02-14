//
// Created by ishan on 29/1/18.
//

#ifndef SFMLSNIPPETS_GAME_HPP
#define SFMLSNIPPETS_GAME_HPP

#include <SFML/Graphics.hpp>
#include "resource_holder.hpp"
#include "aircraft.hpp"
#include "world.hpp"

class Game {
    public:
        Game();
        void run();

    private:
        void processEvents();
        void update(sf::Time);
        void render();

        sf::RenderWindow window;
        World world;

        bool isMovingUp;
        bool isMovingDown;
        bool isMovingLeft;
        bool isMovingRight;

        static const float playerSpeed;
        static const sf::Time TimePerFrame;

        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
};

#endif //SFMLSNIPPETS_GAME_HPP
