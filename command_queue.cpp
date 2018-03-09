//
// Created by ishan on 9/3/18.
//

#include "command_queue.hpp"

void CommandQueue::push(const Command &command) {
    queue.push(command);
}

Command CommandQueue::pop() {
    Command command = queue.front();
    queue.pop();
    return command;
}

bool CommandQueue::isEmpty() const {
    return queue.empty();
}
