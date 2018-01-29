//
// Created by ishan on 29/1/18.
//

#include "Game.hpp"

Game::Game()
: window(sf::VideoMode(640, 480), "Shoot-em-up")
, player() {
    player.setRadius(40.f);
    player.setPosition(100.f, 100.f);
    player.setFillColor(sf::Color::Cyan);
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}

void Game::update() {
}

void Game::render() {
    window.clear(sf::Color::Black);
    window.draw(player);
    window.display();
}
