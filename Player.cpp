//
// Created by mrremrem on 6/29/22.
//

#include "Player.h"
#include "Directions.h"
<<<<<<< HEAD
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
=======
#include "Entity.h"
#include "SpriteSheet.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

Player::Player(ResourceManager<sf::Texture>& textures, sf::Vector2f viewSize):
Entity(EntityType::Player, EntityState::Idle),
spriteSheet(textures, PLAYER_SHEET_DIR),
viewSize(viewSize),
hitBox(false) {
    
    const int DEFAULT_SPEED = 5;
    speed = sf::Vector2f(DEFAULT_SPEED, DEFAULT_SPEED);
}

/*
 * Updates player Direction
 * Pre: none
 * Post: none
 */
void Player::handleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        setDirection(Direction::Up);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ||
               sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        setDirection(Direction::Down);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
               sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        setDirection(Direction::Left);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
               sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        setDirection(Direction::Right);
    } else {
        setDirection(Direction::None);
>>>>>>> e58c56e (Hurrah! Binary Trees!)
    }
}

/*
 * Updates sprite
 * Pre: none
 * Post: Collision box position updated
 */
void Player::update() {
<<<<<<< HEAD
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

    
=======
    handleInput();
    moveSprite();
    updateWalkingAnimation();

    spriteSheet.update();

    // Updates player view
    view.setCenter(spriteSheet.getSprite().getPosition());
    view.setSize(viewSize);
>>>>>>> e58c56e (Hurrah! Binary Trees!)
}

/*
 * Renders player
<<<<<<< HEAD
 * Checks direction and flips left/right or sets up/down
 * Sets player coords
 */
void Player::render(sf::RenderWindow& window) {
    playerSheet.render(window);
    //hitBox.render(window);
    window.setView(camera);
}

=======
 * Pre: none
 * Post: renders player to window
 */
void Player::render(sf::RenderWindow& window) {
    window.setView(view);
    spriteSheet.render(window);
    //hitBox.render(window);
}

/*
 * Sets player direction and stores
 * previous direction
 * Pre: none
 * Post: this->direction = direction
 */
void Player::setDirection(Direction direction) {
    // Tests if directions are different before updating prevDirection
    if (this->direction != direction) {
        prevDirection = this->direction;
        this->direction = direction;
    }
}

/*
 * Sets player's position
 * Pre: none
 * Post: Sets player's position to position
 */
void Player::setPosition(sf::Vector2f position) {
    spriteSheet.getSprite().setPosition(position);
}

/*
 * Sets player's scale
 * Pre: none
 * Post: Sets player's scale to scale
 */
void Player::setScale(sf::Vector2f scale) {
    spriteSheet.getSprite().setScale(scale);
}

/*
 * Sets player's speed
 * Pre: none
 * Post: none
 */
void Player::setSpeed(sf::Vector2f speed) {
    this->speed = speed;
}

/*
 * Gets player's position
 * Pre: none
 * Post: none
 */
sf::Vector2f Player::getPosition() {
    return spriteSheet.getSprite().getPosition();
}

/*
 * Sets player animation
 * Pre: none
 * Post: none
 */
void Player::setAnimation(const std::string& animation) {
    spriteSheet.setAnimation(animation);
}

/*
 * Sets player's layer
 * Pre: layerNum >= 0
 * Post: this->layerNum = layerNum
 */
/*void Player::setLayerNum(int layerNum) {
    layerNum = layerNum;
}*/

/*
 * Gets player's current direction
 * Pre: none
 * Post: none*/
Direction Player::getDirection() {
    return direction;
}

/*
 * Gets player's current world view
 * Pre: none
 * Post: none
 */
sf::View& Player::getView() {
    return view;
}

/*
 * Gets player's sprite
 * Pre: none
 * Post: none
 */
SpriteSheet& Player::getSpriteSheet() {
    return spriteSheet;
}

/*
 * Tests if player is colliding with object
 * Pre: none
 * Post: returns true if player collides with other
 */
const bool Player::isColliding(Entity& other) {
    return false;
}

/*
 * Returns Player ID
 * Pre: none
 * Post: none
 */
const std::string Player::getID() {
    return ID;
}

/*
 * Gets current entity's layer
 * Pre: none
 * Post: none
 */
/*const int Player::getLayerNum() {
    return layerNum;
}*/

/*
 * Moves player (well, technically camera)
 * Pre: none
 * Post: moves player camera based on direction
 */
void Player::moveSprite() {
    // No point in moving if stationary
    //std::cout << "Current direction: ";
    if (direction != Direction::None) {
        switch (direction) {
            case Direction::Up:
                //view.move(0, -viewSpeed);
                std::cout << "DEBUG: Old position: " << spriteSheet.getSprite().getPosition().x << ", " 
                << spriteSheet.getSprite().getPosition().y << std::endl;
                spriteSheet.getSprite().move(0, -speed.y);
                //view.move(0, -speed.y / 2);
                std::cout << "Up" << std::endl;
                std::cout << "DEBUG: New position: " << spriteSheet.getSprite().getPosition().x << ", " 
                << spriteSheet.getSprite().getPosition().y << std::endl;
                break;
            case Direction::Down:
                //view.move(0, viewSpeed);
                spriteSheet.getSprite().move(0, speed.y);
                std::cout << "Down" << std::endl;
                break;
            case Direction::Left:
                //view.move(-viewSpeed, 0);
                spriteSheet.getSprite().move(-speed.x, 0);
                std::cout << "Left" << std::endl;
                break;
            case Direction::Right:
                //view.move(viewSpeed, 0);
                spriteSheet.getSprite().move(speed.x, 0);
                std::cout << "Right" << std::endl;
                break;
        }
    }

    //std::cout << "If no enter then none" << std::endl;
}

void Player::updateWalkingAnimation() {
    if (direction == Direction::Up) {
        spriteSheet.setAnimation("Walk_Up");
    } else if (direction == Direction::Down) {
        spriteSheet.setAnimation("Walk_Down");
    } else if (direction == Direction::Left) {
        spriteSheet.setAnimation("Walk_Left");
    } else if (direction == Direction::Right) {
        spriteSheet.setAnimation("Walk_Right");
    } else if (direction == Direction::None) {
        if (prevDirection == Direction::Up) {
            spriteSheet.setAnimation("Idle_Up");
        } else if (prevDirection == Direction::Down) {
            spriteSheet.setAnimation("Idle_Down");
        } else if (prevDirection == Direction::Left) {
            spriteSheet.setAnimation("Idle_Left");
        } else if (prevDirection == Direction::Right) {
            spriteSheet.setAnimation("Idle_Right");
        }
    }
}

/*
 * Tests if this entity is less than other entity
 * Pre: none
 * Post: Returns true if this entity is less than
 * other entity
 */
/*bool Player::operator<(Entity& other) {
    if (layerNum != other.getLayerNum()) {
        return layerNum > other.getLayerNum();
    }

    return ID < other.getID();
}*/

/*
 * Tests if this entity is less than other entity
 * Pre: none
 * Post: Returns true if this entity is less than
 * other entity
 */
/*bool Player::operator==(Entity& other) {
    return layerNum == other.getLayerNum() && ID == other.getID();
}*/
>>>>>>> e58c56e (Hurrah! Binary Trees!)
