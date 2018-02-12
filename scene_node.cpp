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
