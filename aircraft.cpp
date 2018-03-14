//
// Created by ishan on 11/2/18.
//

#include "aircraft.hpp"
#include "resource_holder.hpp"
#include "category.hpp"

Textures::ID toTextureID(Aircraft::Type type) {
    switch (type) {
        case Aircraft::Type::Eagle:
            return Textures::ID::Eagle;
        case Aircraft::Type::Raptor:
            return Textures::ID::Raptor;
        default:
            return Textures::ID::Eagle;
    }
}

Aircraft::Aircraft(Aircraft::Type type, const TextureHolder& textures)
: type(type)
, sprite(textures.get(toTextureID(type))) {
    sf::FloatRect bounds = sprite.getLocalBounds();
    sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}

unsigned int Aircraft::getCategory() const {
    switch (this->type) {
        case Aircraft::Type::Eagle:
            return static_cast<unsigned int>(Category::Type::PlayerAircraft);
        default:
            return static_cast<unsigned int>(Category::Type::EnemyAircraft);
    }
}
