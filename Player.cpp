//
// Created by mrremrem on 6/29/22.
//

#include "Player.h"
#include "Directions.h"
#include "Entity.h"
#include "SpriteSheet.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

Player::Player(ResourceManager<sf::Texture>& textures, sf::View& view):
Entity(EntityType::Player, EntityState::Idle),
spriteSheet(textures, PLAYER_SHEET_DIR),
view(view),
hitBox(spriteSheet.getSprite(), false) {
    
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
    }
}

/*
 * Updates sprite
 * Pre: none
 * Post: Collision box position updated
 */
void Player::update() {
    handleInput();
    moveSprite();
    updateWalkingAnimation();

    spriteSheet.update();

    // Updates player view
    view.setCenter(spriteSheet.getSprite().getPosition());

    // Updates hitbox
    hitBox.update();
}

/*
 * Renders player
 * Pre: none
 * Post: renders player to window
 */
void Player::render(sf::RenderWindow& window) {
    window.setView(view);
    spriteSheet.render(window);
    hitBox.render(window);
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
 * Sets player view size
 * Pre: none
 * Post: view.getSize() = size
 */
void Player::setViewSize(sf::Vector2f size) {
    view.setSize(size);
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