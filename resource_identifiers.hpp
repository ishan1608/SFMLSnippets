//
// Created by ishan on 15/2/18.
//

#ifndef SFMLSNIPPETS_RESOURCEIDENTIFIERS_HPP
#define SFMLSNIPPETS_RESOURCEIDENTIFIERS_HPP

// Forward declaration of SFML classes
namespace sf
{
    class Texture;
}

namespace Textures {
    enum class ID {
        Eagle, Raptor, Desert
    };
}

// Forward declaration and a few type definitions
template <typename Resource, typename Identifier>
class ResourceHolder;

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

#endif //SFMLSNIPPETS_RESOURCEIDENTIFIERS_HPP
