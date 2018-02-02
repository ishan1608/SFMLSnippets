//
// Created by ishan on 3/2/18.
//

#ifndef SFMLSNIPPETS_TEXTURE_HOLDER_HPP
#define SFMLSNIPPETS_TEXTURE_HOLDER_HPP

#include <map>
#include <memory>
#include <SFML/Graphics.hpp>


// Resources
namespace Textures {
    enum ID {
        Landscape, Airplane, Missile
    };
}

class TextureHolder {
    private:
        std::map<Textures::ID, std::unique_ptr<sf::Texture>> textureMap;
    public:
        void load(Textures::ID id, const std::string& filename);
        sf::Texture& get(Textures::ID id);
        const sf::Texture& get(Textures::ID id) const;
};


#endif //SFMLSNIPPETS_TEXTURE_HOLDER_HPP
