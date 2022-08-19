//
// Created by mrremrem on 6/29/22.
//

#include "Player.h"

Player::Player(sf::Vector2f cameraSize, sf::Vector2f position, int spriteDistance):
    cameraSize(cameraSize),
    position(position),
    spriteDistance(spriteDistance) {
    if (!texture.loadFromFile(PLAYER_TEXTURE_DIRECTORY)){
        throw std::runtime_error("Error: Could not find \'Red_Man.png\'");
    }

    sprite.setTexture(texture);

    // Initializes camera
    camera.setSize(cameraSize.x, cameraSize.y);
    camera.setCenter(position);
}

void Player::setDirection(Direction direction) {
    this->direction = direction;
}

void Player::setPosition(sf::Vector2f position) {
    this->position = position;
}

void Player::setSpeed(sf::Vector2f speed) {
    this->speed = speed;
}

void Player::setScale(sf::Vector2f scale){
    this->scale = scale;
}

sf::Vector2f Player::getPosition() {
    return sprite.getPosition();
}

Direction Player::getDirection() {
    return direction;
}

sf::View Player::getCameraView() {
    return camera;
}

void Player::move() {
    // No point in moving if stationary
    if (direction == Direction::None){
        return;
    }

    switch (direction) {
        case Direction::Up:
            camera.move(0, -cameraSpeed);
            break;
        case Direction::Down:
            camera.move(0, cameraSpeed);
            break;
        case Direction::Left:
            camera.move(-cameraSpeed, 0);
            break;
        case Direction::Right:
            camera.move(cameraSpeed, 0);
            break;
    }
}

/*
 * Renders player
 * Checks direction and flips left/right or sets up/down
 * Sets player coords
 */
void Player::render(sf::RenderWindow &window) {
    sprite.setPosition(position);
    sprite.setScale(scale);

    window.draw(sprite);
    window.setView(camera);
}