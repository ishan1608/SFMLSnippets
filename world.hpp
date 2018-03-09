//
// Created by ishan on 14/2/18.
//

#ifndef SFMLSNIPPETS_WORLD_HPP
#define SFMLSNIPPETS_WORLD_HPP


#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "scene_node.hpp"
#include "aircraft.hpp"
#include "resource_identifiers.hpp"
#include "resource_holder.hpp"
#include "command_queue.hpp"

class World : private sf::NonCopyable {
    public:
        explicit World(sf::RenderWindow& window);
        void update(sf::Time dt);
        void draw();

        CommandQueue& getCommandQueue();

    private:
        void loadTextures();
        void buildScene();

        enum Layer : uint  //  Underlying type will be unsigned int
        {
            Background,
            Air,
            LayerCount
        };

        sf::RenderWindow& window;
        sf::View worldView;
        TextureHolder textures;

        SceneNode sceneGraph;
        std::array<SceneNode*, Layer::LayerCount> sceneLayers;
        CommandQueue commandQueue;

        sf::FloatRect worldBounds;
        sf::Vector2f spawnPosition;
        float scrollSpeed;
        Aircraft* playerAircraft;
};

#endif //SFMLSNIPPETS_WORLD_HPP
