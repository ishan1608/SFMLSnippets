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
        void update(sf::Time);
        void render();

    private:
        sf::RenderWindow window;
        sf::Texture eagleTexture;
        sf::Sprite player;

        bool isMovingUp;
        bool isMovingDown;
        bool isMovingLeft;
        bool isMovingRight;

        static const float playerSpeed;
        static const sf::Time TimePerFrame;

        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
};

#endif //SFMLSNIPPETS_GAME_HPP
