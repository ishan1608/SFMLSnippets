//
// Created by ishan on 14/2/18.
//

#include "sprite_node.hpp"
#include <SFML/Graphics/RenderTarget.hpp>

SpriteNode::SpriteNode(const sf::Texture& texture)
: sprite(texture) {
}

SpriteNode::SpriteNode(const sf::Texture &texture, const sf::IntRect& rect)
: sprite(texture, rect) {
}

void SpriteNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(sprite, states);
}
