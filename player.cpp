//
// Created by ishan on 9/3/18.
//

#include <iostream>
#include "player.hpp"
#include "aircraft.hpp"
#include "category.hpp"

struct AircraftMover {
    AircraftMover(float vx, float vy) : velocity(vx, vy) {
    }

    void operator() (Aircraft& aircraft, sf::Time dt) const {
        aircraft.accelerate(velocity);
    }

    sf::Vector2f velocity;
};

Player::Player() {
    // Set initial key bindings
    initializeKeyBindings();

    // Set initial action bindings
    initializeActions();

    // Assign all categories to player's aircraft
    for (auto& pair : actionBinding) {
        pair.second.category = static_cast<unsigned int>(Category::Type::PlayerAircraft);
    }
}

void Player::handleEvent(const sf::Event &event, CommandQueue &commands) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::P) {
            Command output;
            output.category = static_cast<unsigned int>(Category::Type::PlayerAircraft);
            output.action = [] (SceneNode& sceneNode, sf::Time) {
                sf::Vector2f sceneNodePosition = sceneNode.getPosition();
                std::cout << sceneNodePosition.x << ", " << sceneNodePosition.y << std::endl;
            };
            commands.push(output);
        }

        // Check if pressed key appears in key binding, trigger command if so
        auto found = keyBinding.find(event.key.code);
        if (found != keyBinding.end() && !isRealtimeAction(found->second)) {
            commands.push(actionBinding[found->second]);
        }
    }
}

void Player::handleRealTimeInput(CommandQueue& commands) {
    // Traverse all assigned keys and check if they are pressed
    for (const auto binding : keyBinding) {
        // If key is pressed, lookup action and trigger corresponding command
        if (sf::Keyboard::isKeyPressed(binding.first) && isRealtimeAction(binding.second)) {
            commands.push(actionBinding[binding.second]);
        }
    }
}

void Player::initializeKeyBindings() {
    keyBinding[sf::Keyboard::Left] = Action::MoveLeft;
    keyBinding[sf::Keyboard::Right] = Action::MoveRight;
    keyBinding[sf::Keyboard::Up] = Action::MoveUp;
    keyBinding[sf::Keyboard::Down] = Action::MoveDown;
}

void Player::initializeActions() {
    const float playerSpeed = 10.f;

    actionBinding[Action::MoveLeft].action = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.f));
    actionBinding[Action::MoveRight].action = derivedAction<Aircraft>(AircraftMover(+playerSpeed, 0.f));
    actionBinding[Action::MoveUp].action = derivedAction<Aircraft>(AircraftMover(0.f, -playerSpeed));
    actionBinding[Action::MoveDown].action = derivedAction<Aircraft>(AircraftMover(0.f, +playerSpeed));
}

bool Player::isRealtimeAction(Player::Action action) {
    switch (action) {
        case Action::MoveLeft:
        case Action::MoveRight:
        case Action::MoveUp:
        case Action::MoveDown:
            return true;
        default:
            return false;
    }
}

/**
 * Change key for an action
 * @param action Action to change
 * @param key New "key" to map
 */
void Player::assignKey(Player::Action action, sf::Keyboard::Key key) {
    // Remove all the keys that already map the action
    for (const auto binding : keyBinding) {
        if (binding.second == action) {
            keyBinding.erase(binding.first);
        }
    }

    // Insert new binding
    keyBinding[key] = action;
}

/**
 * Get the current key assigned for an action
 * @param action Action to check for
 * @return key (sf::Keyboard::Key) currently mapped key
 */
sf::Keyboard::Key Player::getAssignedKey(Player::Action action) const {
    for (const auto binding : keyBinding) {
        if (binding.second == action) {
            return binding.first;
        }
    }
}
