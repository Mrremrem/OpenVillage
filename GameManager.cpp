//
// Created by mrremrem on 7/2/22.
//

#include "GameManager.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/WindowStyle.hpp>

GameManager::GameManager():
window("Open Village", WINDOW_SIZE, sf::Style::Titlebar | sf::Style::Close),
textures(TEXTURE_CONFIG_DIR),
fonts(FONT_CONFIG_DIR),
playerViewsList(),
homeVillage(textures, fonts, playerViewsList) {
    elapsedTime = clock.restart();

    // Initializes player stats
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
    //homeVillage.handleInput();
}

/*
 * Updates world and objects in world
 * Pre: none
 * Post: none
 */
void GameManager::update() {
    float frameTime = 1.0f / MAX_FPS;

    // Checks if time elapsed exceeds frame time
    if (elapsedTime.asSeconds() >= frameTime){
        homeVillage.update(*window.getRenderWindow());

        elapsedTime -= sf::seconds(frameTime);
    }
}

/*
 * Begins rendering everything
 * Pre: none
 * Post: Renders homeVillage to window
 */
void GameManager::render() {
    window.beginDraw();

    homeVillage.render(*window.getRenderWindow());

    window.endDraw();
}

/*void GameManager::updatePlayerDebug() {
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
}*/

// Leaving this here in case I need it
/*void GameManager::updateTextboxDebug() {
    // Setting player info on top left corner
    sf::Vector2f topLeftCorner = window.getRenderWindow()->mapPixelToCoords(sf::Vector2i(0, 200));
}*/