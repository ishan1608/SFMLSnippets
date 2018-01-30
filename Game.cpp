//
// Created by ishan on 29/1/18.
//

#include "Game.hpp"

Game::Game()
: window(sf::VideoMode(640, 480), "Shoot-em-up")
, player()
, isMovingUp(false)
, isMovingDown(false)
, isMovingLeft(false)
, isMovingRight(false)
{
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
        switch (event.type) {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, true);
                break;
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
        }
    }
}

void Game::update() {
    sf::Vector2f movement(0.f, 0.f);

    if (isMovingUp) {
        movement.y -= 1.f;
    }

    if (isMovingDown) {
        movement.y += 1.f;
    }

    if (isMovingLeft) {
        movement.x -= 1.f;
    }

    if (isMovingRight) {
        movement.x += 1.f;
    }

    player.move(movement);
}

void Game::render() {
    window.clear(sf::Color::Black);
    window.draw(player);
    window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    switch (key) {
        case sf::Keyboard::W:
            isMovingUp = isPressed;
            break;
        case sf::Keyboard::S:
            isMovingDown = isPressed;
            break;
        case sf::Keyboard::A:
            isMovingLeft = isPressed;
            break;
        case sf::Keyboard::D:
            isMovingRight = isPressed;
            break;
        default:
            break;
    }
}
