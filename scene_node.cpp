//
// Created by ishan on 11/2/18.
//

#include <algorithm>
#include <cassert>
#include "scene_node.hpp"

SceneNode::SceneNode()
: children(),
parent(nullptr)
{
}

void SceneNode::attachChild(SceneNode::SceneNodePointer child) {
    child->parent = this;
    children.push_back(std::move(child));
}

SceneNode::SceneNodePointer SceneNode::detachChild(const SceneNode &sceneNode) {
    auto foundNode = std::find_if(children.begin(), children.end(), [&] (SceneNodePointer& p) -> bool {
            return p.get() == &sceneNode;
    });

    assert(foundNode != children.end());

    SceneNodePointer result = std::move(*foundNode);
    result->parent = nullptr;
    children.erase(foundNode);
    return result;
}

void SceneNode::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    // Transform the current SceneNode
    states.transform *= getTransform();
    // Draw the current SceneNode
    drawCurrent(target, states);
    // Draw all the children SceneNode(s)
    drawChildren(target, states);
}

void SceneNode::drawChildren(sf::RenderTarget &target, sf::RenderStates states) const {
    /*for (auto itr = children.begin(); itr != children.end(); ++itr) {
        (*itr)->draw(target, states);
    }*/
    for (const auto &itr : children) {
        itr->draw(target, states);
    }
}

void SceneNode::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
    // Blank implementation
}

void SceneNode::update(sf::Time dt) {
    updateCurrent(dt);
    updateChildren(dt);
}

void SceneNode::updateCurrent(sf::Time dt) {
    // Blank implementation
}

void SceneNode::updateChildren(sf::Time dt) {
    for (const SceneNodePointer &child : children) {
        child->update(dt);
    }
}
