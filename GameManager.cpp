//
// Created by mrremrem on 7/2/22.
//

#include "GameManager.h"
#include "TextureManager.h"

GameManager::GameManager():
        window("Open Village", WINDOW_SIZE),
        textures(TEXTURE_CONFIG_DIR),
        homeVillage(&textures, WINDOW_SIZE),
        redMan(&textures, CAMERA_SIZE, homeVillage.getBlockSize()),
        playerDebug() {
    elapsedTime = clock.restart();

    // Initializes player stats
    redMan.setSpeed(sf::Vector2f(DEFAULT_PLAYER_SPEED, DEFAULT_PLAYER_SPEED));
    //redMan.setScale(sf::Vector2f(DEFAULT_PLAYER_SCALE, DEFAULT_PLAYER_SCALE));
}

GameManager::~GameManager() {
    // Empty
}

sf::Time GameManager::getElapsedTime() {
    return clock.getElapsedTime();
}

void GameManager::restartClock() {
    elapsedTime += clock.restart();
}

WindowManager *GameManager::getWindow() {
    return &window;
}

void GameManager::handleInput() {
    // Place player.handleInput() here!
    sf::Event event;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        redMan.setDirection(Direction::Up);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
               sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        redMan.setDirection(Direction::Down);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
               sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        redMan.setDirection(Direction::Left);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
               sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        redMan.setDirection(Direction::Right);
    } else {
        redMan.setDirection(Direction::None);
    }
}

void GameManager::render() {
    window.beginDraw();

    homeVillage.render(*window.getRenderWindow());
    redMan.render(*window.getRenderWindow());
    playerDebug.render(*window.getRenderWindow());


    window.endDraw();
}

// Collision on world objects etc.
void GameManager::update() {
    // Single frame
    float frameTime = 1.0f / MAX_FPS;

    redMan.update();

    // Checks if time elapsed exceeds frame time
    if (elapsedTime.asSeconds() >= frameTime){
        homeVillage.update(*window.getRenderWindow(), redMan);

        updatePlayerDebug();

        elapsedTime -= sf::seconds(frameTime);
    }
}

void GameManager::updatePlayerDebug() {
    // Setting player info on top left corner
    sf::Vector2f topLeftView = window.getRenderWindow()->
    mapPixelToCoords(sf::Vector2i(0, 0));
    playerDebug.setPosition(topLeftView);

    // Displaying player x & y coords from screen
    sf::Vector2f playerCoords = redMan.getPosition();
    playerDebug.insert(0, "Player X: " + 
                        std::to_string(playerCoords.x));
    playerDebug.insert(1, "Player Y: " + 
                        std::to_string(playerCoords.y));

    // Displaying view's coordinates
    playerDebug.insert(2, "Camera X: " + 
                        std::to_string(redMan.getCameraView().getCenter().x));
    playerDebug.insert(3, "Camera Y: " + 
                        std::to_string(redMan.getCameraView().getCenter().y));
}

// Leaving this here in case I need it
/*void GameManager::updateTextboxDebug() {
    // Setting player info on top left corner
    sf::Vector2f topLeftCorner = window.getRenderWindow()->mapPixelToCoords(sf::Vector2i(0, 200));
}*/