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
, moveRight(false)
, windowCenter(window.getSize() / 2u)
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
            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Button::Right) {
                    moveRight = true;
                }
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Button::Right) {
                    moveRight = false;
                }
                break;
            case sf::Event::MouseMoved: {
                sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                sf::Vector2i delta = windowCenter - mousePosition;
                this->delta += delta;
                if (delta.x != 0 || delta.y != 0) {
                    sf::Mouse::setPosition(windowCenter, window);
                }
                break;
            }
            default:
                break;
        }
    }
}

void Game::update(sf::Time deltaTime) {
    sf::Vector2f movement(0.f, 0.f);


    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        movement.x -= playerSpeed;
    }

    if (moveRight) {
        movement.x += playerSpeed;
    }

    // Use delta in player movement and reset delta
    movement.x += delta.x * 10;
    movement.y += delta.y * 10;
    delta = sf::Vector2i();

    player.move(movement * deltaTime.asSeconds());
}

void Game::render() {
    window.clear(sf::Color::Black);
    window.draw(player);
    window.display();
}
