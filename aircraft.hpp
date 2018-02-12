//
// Created by ishan on 11/2/18.
//

#ifndef SFMLSNIPPETS_AIRCRAFT_HPP
#define SFMLSNIPPETS_AIRCRAFT_HPP


#include <SFML/Graphics/Sprite.hpp>
#include "entity.hpp"

class Aircraft : public Entity {  // Inherits indirectly SceneNode
    public:
        enum class Type {
            Eagle,
            Raptor,
        };

        explicit Aircraft(Type type);

        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        Type type;
        sf::Sprite sprite;
};


#endif //SFMLSNIPPETS_AIRCRAFT_HPP
