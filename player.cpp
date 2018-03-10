//
// Created by ishan on 9/3/18.
//

#include <iostream>
#include "player.hpp"
#include "aircraft.hpp"
#include "category.hpp"

struct AircraftMover {
    sf::Vector2f velocity;

    AircraftMover(float vx, float vy) : velocity(vx, vy) {
    }

    void operator() (Aircraft& aircraft, sf::Time) const {
        aircraft.accelerate(velocity);
    }
};

void Player::handleEvent(const sf::Event &event, CommandQueue &commands) {
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
        Command output;
        output.category = static_cast<unsigned int>(Category::Type::PlayerAircraft);
        output.action = [] (SceneNode& sceneNode, sf::Time) {
            sf::Vector2f sceneNodePosition = sceneNode.getPosition();
            std::cout << sceneNodePosition.x << ", " << sceneNodePosition.y << std::endl;
        };
        commands.push(output);
    }
}

void Player::handleRealTimeInput(CommandQueue& commands) {
    const float playerSpeed = 30.f;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        Command moveLeft;
        moveLeft.category = static_cast<unsigned int>(Category::Type::PlayerAircraft);
        moveLeft.action = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.f));
        commands.push(moveLeft);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        Command moveRight;
        moveRight.category = static_cast<unsigned int>(Category::Type::PlayerAircraft);
        moveRight.action = derivedAction<Aircraft>(AircraftMover(playerSpeed, 0.f));
        commands.push(moveRight);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        Command moveUp;
        moveUp.category = static_cast<unsigned int>(Category::Type::PlayerAircraft);
        moveUp.action = derivedAction<Aircraft>(AircraftMover(0.f, -playerSpeed));
        commands.push(moveUp);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        Command moveDown;
        moveDown.category = static_cast<unsigned int>(Category::Type::PlayerAircraft);
        moveDown.action = derivedAction<Aircraft>(AircraftMover(0.f, playerSpeed));
        commands.push(moveDown);
    }
}
