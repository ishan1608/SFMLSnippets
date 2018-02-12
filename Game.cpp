//
// Created by ishan on 29/1/18.
//

#include <iostream>
#include "Game.hpp"

const float Game::playerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
: window(sf::VideoMode(640, 480), "Shoot-em-up")
//, airplane()
, isMovingUp(false)
, isMovingDown(false)
, isMovingLeft(false)
, isMovingRight(false)
{
    if (!init()) {
        throw std::runtime_error("Couldn't initialize the game.");
    }
}

bool Game::init() {
//    try {
//        textures.load(Textures::ID::Airplane, "media/textures/eagle.png");
//        textures.load(Textures::ID::Landscape, "media/textures/desert.png");
//    } catch (std::runtime_error& error) {
//        std::cout << "Exception: " << error.what() << std::endl;
//        return false;
//    }
//
//    airplane.setTexture(textures.get(Textures::ID::Airplane));
//    landscape.setTexture(textures.get(Textures::ID::Landscape));
//    airplane.setPosition(100.f, 100.f);
    return true;
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

//    airplane.move(movement * deltaTime.asSeconds());
}

void Game::render() {
    window.clear(sf::Color::Black);
    // NTOE: Airplane needs to be drawn after landscape
    // If landscape is drawn after the airplane. The airplane will be hidden under landscape
//    window.draw(landscape);
//    window.draw(airplane);
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
