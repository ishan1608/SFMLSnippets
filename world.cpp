//
// Created by ishan on 14/2/18.
//

#include "world.hpp"
#include "sprite_node.hpp"
#include <SFML/Graphics/Texture.hpp>

World::World(sf::RenderWindow &window)
: window(window)
, worldView(window.getDefaultView())
, worldBounds(
    0.f,                    // left
    0.f,                    // top
    worldView.getSize().x,  // width
    2000.f)                 // height
, spawnPosition(
    worldView.getSize().x / 2.f,
    worldBounds.height - (worldView.getSize().y / 2.f)
)
, scrollSpeed(-50.f)
, playerAircraft(nullptr)
{
    loadTextures();
    buildScene();

    worldView.setCenter(spawnPosition);
}

void World::loadTextures() {
    textures.load(Textures::ID::Eagle, "media/textures/eagle.png");
    textures.load(Textures::ID::Raptor, "media/textures/raptor.png");
    textures.load(Textures::ID::Desert, "media/textures/desert.png");
}

void World::buildScene() {
    // Initialize the different layers
    for (std::size_t i = 0; i < LayerCount ; i++) {
        SceneNode::SceneNodePointer layer(new SceneNode());
        sceneLayers[i] = layer.get();

        sceneGraph.attachChild(std::move(layer));
    }

    // Prepare the tiled background
    sf::Texture& texture = textures.get(Textures::ID::Desert);
    sf::IntRect textureRect(worldBounds);
    texture.setRepeated(true);

    // Add the background sprite to the scene
    std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(texture, textureRect));
    backgroundSprite->setPosition(worldBounds.left, worldBounds.top);
    sceneLayers[Background]->attachChild(std::move(backgroundSprite));
}
