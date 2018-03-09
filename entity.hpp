//
// Created by ishan on 11/2/18.
//

#ifndef SFMLSNIPPETS_ENTITY_HPP
#define SFMLSNIPPETS_ENTITY_HPP


#include <SFML/System.hpp>
#include "scene_node.hpp"

class Entity : public SceneNode {
    public:
        void setVelocity(sf::Vector2f velocity);
        void setVelocity(float vx, float vy);

        void accelerate(sf::Vector2f velocity);
        void accelerate(float vx, float vy);

        sf::Vector2f getVelocity() const;

    private:
        sf::Vector2f velocity;

    void updateCurrent(sf::Time dt);
};


#endif //SFMLSNIPPETS_ENTITY_HPP
