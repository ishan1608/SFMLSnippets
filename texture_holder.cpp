//
// Created by ishan on 3/2/18.
//

#include "texture_holder.hpp"

void TextureHolder::load(Textures::TextureID id, const std::string &filename) {
    std::unique_ptr<sf::Texture> texture(new sf::Texture());
    texture->loadFromFile(filename);

    textureMap.insert(std::make_pair(id, std::move(texture)));
}

sf::Texture &TextureHolder::get(Textures::TextureID id) {
    auto found = textureMap.find(id);
    return *found->second;
}

const sf::Texture &TextureHolder::get(Textures::TextureID id) const {
    auto found = textureMap.find(id);
    return *found->second;
}
