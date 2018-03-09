//
// Created by ishan on 9/3/18.
//

#ifndef SFMLSNIPPETS_COMMAND_QUEUE_HPP
#define SFMLSNIPPETS_COMMAND_QUEUE_HPP


#include <queue>
#include "command.hpp"

class CommandQueue {

    public:
        void push(const Command& command);
        Command pop();
        bool isEmpty() const;

    private:
        std::queue<Command> queue;

};


#endif //SFMLSNIPPETS_COMMAND_QUEUE_HPP
