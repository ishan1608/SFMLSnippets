//
// Created by ishan on 11/2/18.
//

#ifndef SFMLSNIPPETS_AIRCRAFT_HPP
#define SFMLSNIPPETS_AIRCRAFT_HPP


#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "entity.hpp"
#include "resource_identifiers.hpp"

class Aircraft : public Entity {  // Inherits indirectly SceneNode
    public:
        enum class Type {
            Eagle,
            Raptor,
        };

        explicit Aircraft(Type type, const TextureHolder& textures);
        virtual unsigned int getCategory() const;

    private:
        Type type;
        sf::Sprite sprite;

        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //SFMLSNIPPETS_AIRCRAFT_HPP
