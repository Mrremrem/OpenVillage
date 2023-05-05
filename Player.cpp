//
// Created by mrremrem on 6/29/22.
//

#include "Player.h"
#include "Directions.h"
#include "SpriteSheet.h"
#include <SFML/System/Vector2.hpp>

Player::Player(TextureManager* textures, sf::Vector2f cameraSize, int spriteDistance):
    playerSheet(textures, PLAYER_SHEET_DIR),
    cameraSize(cameraSize),
    spriteDistance(spriteDistance),
    hitBox(false) {

    playerSheet.setAnimation("Idle_Right");
    playerSheet.getSprite()->setPosition(sf::Vector2f(0, 0));

    camera.setSize(cameraSize.x, cameraSize.y);
    camera.setCenter(playerSheet.getSprite()->getPosition());
}

void Player::setDirection(Direction direction) {
    prevDirection = this->direction;
    this->direction = direction;
}

void Player::setPosition(sf::Vector2f position) {
    playerSheet.getSprite()->setPosition(position);
}

void Player::setSpeed(sf::Vector2f speed) {
    this->speed = speed;
}

sf::Vector2f Player::getPosition() {
    return playerSheet.getSprite()->getPosition();
}

Direction Player::getDirection() {
    return direction;
}

sf::View Player::getCameraView() {
    return camera;
}

/*
 * Moves player (well, technically camera)
 * Pre: none
 * Post: moves player camera based on direction
 */
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
 * Updates sprite
 * Pre: none
 * Post: Collision box position updated
 */
void Player::update() {
    playerSheet.update();
    if (direction == Direction::Up) {
        playerSheet.setAnimation("Walk_Up");
    } else if (direction == Direction::Down) {
        playerSheet.setAnimation("Walk_Down");
    } else if (direction == Direction::Left) {
        playerSheet.setAnimation("Walk_Left");
    } else if (direction == Direction::Right) {
        playerSheet.setAnimation("Walk_Right");
    } else if (direction == Direction::None) {
        if (prevDirection == Direction::Up) {
            playerSheet.setAnimation("Idle_Up");
        } else if (prevDirection == Direction::Down) {
            playerSheet.setAnimation("Idle_Down");
        } else if (prevDirection == Direction::Left) {
            playerSheet.setAnimation("Idle_Left");
        } else if (prevDirection == Direction::Right) {
            playerSheet.setAnimation("Idle_Right");
        }
    }

    
}

/*
 * Renders player
 * Checks direction and flips left/right or sets up/down
 * Sets player coords
 */
void Player::render(sf::RenderWindow& window) {
    playerSheet.render(window);
    //hitBox.render(window);
    window.setView(camera);
}

