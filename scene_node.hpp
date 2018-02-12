//
// Created by ishan on 11/2/18.
//

#ifndef SFMLSNIPPETS_SCENE_NODE_HPP
#define SFMLSNIPPETS_SCENE_NODE_HPP


#include <bits/unique_ptr.h>
#include <vector>

class SceneNode {
    public:
        typedef std::unique_ptr<SceneNode> SceneNodePointer;

        SceneNode();
        void attachChild(SceneNodePointer child);
        SceneNodePointer detachChild(const SceneNode& sceneNode);

    private:
        std::vector<SceneNodePointer> children;
        SceneNode* parent;
};


#endif //SFMLSNIPPETS_SCENE_NODE_HPP
