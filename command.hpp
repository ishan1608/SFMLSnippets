//
// Created by ishan on 21/2/18.
//

#ifndef SFMLSNIPPETS_COMMAND_HPP
#define SFMLSNIPPETS_COMMAND_HPP


#include <functional>
#include <SFML/System/Time.hpp>

//#include "scene_node.hpp"
class SceneNode;

struct Command
{
    Command();

    std::function<void(SceneNode&, sf::Time)> action;
    unsigned int category;
};


#endif //SFMLSNIPPETS_COMMAND_HPP
