//
// Created by ishan on 11/2/18.
//

#ifndef SFMLSNIPPETS_SCENE_NODE_HPP
#define SFMLSNIPPETS_SCENE_NODE_HPP


#include <bits/unique_ptr.h>
#include <vector>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/NonCopyable.hpp>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable {
    public:
        typedef std::unique_ptr<SceneNode> SceneNodePointer;

        SceneNode();

        void attachChild(SceneNodePointer child);
        SceneNodePointer detachChild(const SceneNode& sceneNode);

    private:
        std::vector<SceneNodePointer> children;
        SceneNode* parent;

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
        void drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;
};


#endif //SFMLSNIPPETS_SCENE_NODE_HPP
