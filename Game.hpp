//
// Created by ishan on 29/1/18.
//

#ifndef SFMLSNIPPETS_GAME_HPP
#define SFMLSNIPPETS_GAME_HPP

#include <SFML/Graphics.hpp>
#include "resource_holder.hpp"
#include "aircraft.hpp"
#include "world.hpp"
#include "player.hpp"

class Game {
    public:
        Game();
        void run();

    private:
        void processInput();
        void update(sf::Time);
        void render();
        void updateStatistics(sf::Time elapsedTime);

        static const sf::Time TimePerFrame;

        sf::RenderWindow window;
        World world;
        Player player;

        sf::Font font;
        sf::Text statisticsText;
        sf::Time statisticsUpdateTime;
        std::size_t statisticsNumFrames;
};

#endif //SFMLSNIPPETS_GAME_HPP
