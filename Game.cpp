//
// Created by ishan on 29/1/18.
//

#include <iostream>
#include "Game.hpp"
#include "string_helpers.hpp"

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
: window(sf::VideoMode(640, 480), "Shoot-em-up", sf::Style::Close)
, world(window)
, player()
, font()
, statisticsText()
, statisticsUpdateTime()
, statisticsNumFrames(0)
{
    // Disable key-repeat
    window.setKeyRepeatEnabled(false);

    font.loadFromFile("media/sansation.ttf");
    statisticsText.setFont(font);
    statisticsText.setPosition(5.f, 5.f);
    statisticsText.setCharacterSize(10);
}

void Game::run() {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (window.isOpen()) {
        processInput();  // NOTE: Processing events even before timeSinceLasUpdate is less than TimePerFrame
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            processInput();
            update(TimePerFrame);
        }
        updateStatistics(elapsedTime);
        render();
    }
}

void Game::processInput() {
    CommandQueue& commands = world.getCommandQueue();

    sf::Event event;
    while (window.pollEvent(event)) {

        player.handleEvent(event, commands);

        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }

    player.handleRealTimeInput(commands);
}

void Game::update(sf::Time deltaTime) {
    world.update(deltaTime);
}

void Game::render() {
    window.clear(sf::Color::Black);
    world.draw();

    window.setView(window.getDefaultView());
    window.draw(statisticsText);
    window.display();
}

void Game::updateStatistics(sf::Time elapsedTime) {
    statisticsUpdateTime += elapsedTime;
    statisticsNumFrames += 1;

    if (statisticsUpdateTime >= sf::seconds(1.0f)) {
        statisticsText.setString(
                "Frames / Second = " + toString(statisticsNumFrames) + "\n" +
                "Time / Update = " + toString(statisticsUpdateTime.asMicroseconds() / statisticsNumFrames) + "us");

        statisticsUpdateTime -= sf::seconds(1.0f);
        statisticsNumFrames = 0;
    }
}
