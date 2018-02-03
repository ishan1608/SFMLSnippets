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
, isMovingUp(false)
, isMovingDown(false)
, isMovingLeft(false)
, isMovingRight(false)
{
    if (!init()) {
        throw std::runtime_error("Couldn't initialize the game.");
    }
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

bool Game::init() {
    try {
        textures.load(Textures::TextureID::Airplane, "media/textures/eagle.png");
    } catch (std::runtime_error& error) {
        std::cout << "Exception: " << error.what() << std::endl;
        return false;
    }

    player.setTexture(textures.get(Textures::TextureID::Airplane));
    player.setPosition(100.f, 100.f);
    return true;
}
