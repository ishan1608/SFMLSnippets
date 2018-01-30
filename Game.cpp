//
// Created by ishan on 29/1/18.
//

#include "Game.hpp"

const float Game::playerSpeed = 100.f;

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
    sf::Clock clock;
    while (window.isOpen()) {
        processEvents();
        sf::Time deltaTime = clock.restart();
        update(deltaTime);
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
    sf::Vector2f movement(0.f, 0.f);

    if (isMovingUp) {
        movement.y -= playerSpeed;
    }

    if (isMovingDown) {
        movement.y += playerSpeed;
    }

    if (isMovingLeft) {
        movement.x -= playerSpeed;
    }

    if (isMovingRight) {
        movement.x += playerSpeed;
    }

    player.move(movement * deltaTime.asSeconds());
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
