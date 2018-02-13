//
// Created by ishan on 11/2/18.
//

#include "entity.hpp"

void Entity::setVelocity(sf::Vector2f velocity) {
    this->velocity = velocity;
}

void Entity::setVelocity(float vx, float vy) {
    velocity.x = vx;
    velocity.y = vy;
}

sf::Vector2f Entity::getVelocity() const {
    return velocity;
}

void Entity::updateCurrent(sf::Time dt) {
    move(velocity * dt.asSeconds());
}
