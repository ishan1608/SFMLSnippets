//
// Created by ishan on 29/1/18.
//

#include <iostream>
#include "Game.hpp"

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
: window(sf::VideoMode(640, 480), "Shoot-em-up")
, world(window)
{
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
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
        }
    }
}

void Game::update(sf::Time deltaTime) {
    world.update(deltaTime);
}

void Game::render() {
    window.clear(sf::Color::Black);
    world.draw();

    window.setView(window.getDefaultView());
    window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
}
