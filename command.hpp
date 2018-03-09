//
// Created by ishan on 21/2/18.
//

#ifndef SFMLSNIPPETS_COMMAND_HPP
#define SFMLSNIPPETS_COMMAND_HPP


#include <functional>
#include <SFML/System/Time.hpp>
#include <cassert>

//#include "scene_node.hpp"
class SceneNode;

struct Command
{
    Command();

    std::function<void(SceneNode&, sf::Time)> action;
    unsigned int category;
};

template <typename GameObject, typename Function>
std::function<void(SceneNode&, sf::Time)>
derivedAction(Function fn) {
    return [=] (SceneNode& sceneNode, sf::Time dt) {
        // Check if cast is safe
        assert(dynamic_cast<GameObject*>(&sceneNode) != nullptr);

        // Downcast node and invoke function on it
        fn(static_cast<GameObject&>(sceneNode), dt);
    };
};

#endif //SFMLSNIPPETS_COMMAND_HPP
