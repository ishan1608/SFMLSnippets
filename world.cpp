//
// Created by ishan on 14/2/18.
//

#include "world.hpp"
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
    // Blank implementation
}
