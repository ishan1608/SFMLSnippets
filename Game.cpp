//
// Created by ishan on 29/1/18.
//

#include <iostream>
#include "Game.hpp"

const float Game::playerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
: window(sf::VideoMode(640, 480), "Shoot-em-up")
, player()
{
    if (!eagleTexture.loadFromFile("media/textures/eagle.png")) {
        std::cout << "Couldn't load eagle";
    }
    player.setTexture(eagleTexture);
    player.setPosition(100.f, 100.f);
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (window.isOpen()) {
        processEvents();  // NOTE: Processing events even before timeSinceLasUpdate is less than TimePerFrame
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
        }
    }
}

void Game::update(sf::Time deltaTime) {
    sf::Vector2f movement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        movement.y -= playerSpeed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        movement.y += playerSpeed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        movement.x -= playerSpeed;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movement.x += playerSpeed;
    }

    player.move(movement * deltaTime.asSeconds());
}

void Game::render() {
    window.clear(sf::Color::Black);
    window.draw(player);
    window.display();
}
