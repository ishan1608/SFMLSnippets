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
        sf::Vector2i windowCenter;
        sf::Vector2i delta;

        bool moveRight;
        bool isPaused;
        bool mouseMovementPaused;

        static const float playerSpeed;
        static const sf::Time TimePerFrame;
};

#endif //SFMLSNIPPETS_GAME_HPP
