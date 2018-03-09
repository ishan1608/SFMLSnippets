//
// Created by ishan on 9/3/18.
//

#ifndef SFMLSNIPPETS_PLAYER_HPP
#define SFMLSNIPPETS_PLAYER_HPP


#include <SFML/Window/Event.hpp>
#include "command_queue.hpp"

class Player {
    public:
        void handleEvent(const sf::Event& event, CommandQueue& commands);
        void handleRealTimeInput(CommandQueue &commands);
};


#endif //SFMLSNIPPETS_PLAYER_HPP
