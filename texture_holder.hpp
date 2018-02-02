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
    enum class TextureID {
        Landscape, Airplane, Missile
    };
}

class TextureHolder {
    private:
        std::map<Textures::TextureID, std::unique_ptr<sf::Texture>> textureMap;
    public:
        void load(Textures::TextureID id, const std::string& filename);
        sf::Texture& get(Textures::TextureID id);
        const sf::Texture& get(Textures::TextureID id) const;
};


#endif //SFMLSNIPPETS_TEXTURE_HOLDER_HPP
