//
// Created by ishan on 14/2/18.
//

#include "world.hpp"
#include "sprite_node.hpp"
#include <SFML/Graphics/Texture.hpp>

World::World(sf::RenderWindow &window)
: window(window)
, worldView(window.getDefaultView())
, textures()
, sceneGraph()
, sceneLayers()
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

    // Prepare the view
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

    // Add player's aircraft
    std::unique_ptr<Aircraft> leader(new Aircraft(Aircraft::Type::Eagle, textures));
    playerAircraft = leader.get();
    playerAircraft->setPosition(spawnPosition);
    playerAircraft->setVelocity(40.f, scrollSpeed);
    sceneLayers[Air]->attachChild(std::move(leader));

    // Add two escorting aircraft(s), placed relatively to the main plane
    std::unique_ptr<Aircraft> leftEscort(new Aircraft(Aircraft::Type::Raptor, textures));
    leftEscort->setPosition(-80.f, 50.f);
    playerAircraft->attachChild(std::move(leftEscort));

    std::unique_ptr<Aircraft> rightEscort(new Aircraft(Aircraft::Type::Raptor, textures));
    rightEscort->setPosition(80.f, 50.f);
    playerAircraft->attachChild(std::move(rightEscort));
}

void World::draw() {
    window.setView(worldView);
    window.draw(sceneGraph);
}

void World::update(sf::Time dt) {
    // Scroll the world
    worldView.move(0.f, scrollSpeed * dt.asSeconds());
//    // Reset player velocity
//    playerAircraft->setVelocity(0.f, 0.f);

    sf::Vector2f position = playerAircraft->getPosition();
    sf::Vector2f velocity = playerAircraft->getVelocity();

    if ((position.x <= worldBounds.left + 150) ||
        (position.x >= worldBounds.left + worldBounds.width - 150)) {
        velocity.x = -velocity.x;
        playerAircraft->setVelocity(velocity);
    }

    // Forward commands to the scene graph
    while (!commandQueue.isEmpty()) {
        sceneGraph.onCommand(commandQueue.pop(), dt);
    }

    // Regular update step
    sceneGraph.update(dt);
}

CommandQueue& World::getCommandQueue() {
    return commandQueue;
}
