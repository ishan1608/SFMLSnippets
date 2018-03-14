//
// Created by ishan on 9/3/18.
//

#ifndef SFMLSNIPPETS_PLAYER_HPP
#define SFMLSNIPPETS_PLAYER_HPP


#include <SFML/Window/Event.hpp>
#include <map>
#include "command_queue.hpp"

class Player {
    public:
        enum class Action {
            MoveLeft,
            MoveRight,
            MoveUp,
            MoveDown
        };
        Player();

        void handleEvent(const sf::Event& event, CommandQueue& commands);
        void handleRealTimeInput(CommandQueue &commands);

        void assignKey(Action action, sf::Keyboard::Key key);
        sf::Keyboard::Key getAssignedKey(Action action) const;

    private:
        std::map<sf::Keyboard::Key, Action> keyBinding;
        std::map<Action, Command> actionBinding;

        void initializeKeyBindings();
        void initializeActions();
        static bool isRealtimeAction(Action action);
};


#endif //SFMLSNIPPETS_PLAYER_HPP
