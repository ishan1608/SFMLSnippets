//
// Created by ishan on 11/2/18.
//

#include "aircraft.hpp"
#include "resource_holder.hpp"

Textures::ID toTextureID(Aircraft::Type type) {
    switch (type) {
        case Aircraft::Type::Eagle:
            return Textures::ID::Eagle;
        case Aircraft::Type::Raptor:
            return Textures::ID::Raptor;
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
