//
// Created by ishan on 14/2/18.
//

#ifndef SFMLSNIPPETS_SPRITE_NODE_HPP
#define SFMLSNIPPETS_SPRITE_NODE_HPP


#include <SFML/Graphics/Sprite.hpp>
#include "scene_node.hpp"

class SpriteNode : public SceneNode {
    public:
        explicit SpriteNode(const sf::Texture& texture);
        SpriteNode(const sf::Texture& texture, const sf::IntRect& rect);

    private:
        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

        sf::Sprite sprite;
};


#endif //SFMLSNIPPETS_SPRITE_NODE_HPP
