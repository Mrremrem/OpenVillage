//
// Created by mrremrem on 6/29/22.
//

#ifndef OPENVILLAGE_PLAYER_H
#define OPENVILLAGE_PLAYER_H

#include <SFML/Graphics.hpp>
#include "Directions.h"
#include "CollisionBox.h"

/*
 * What?
 * Handles player information (position, sprite)
 */

class Player {
public:
    // Initializes player sprite
    Player(sf::Vector2f cameraSize, sf::Vector2f position, int spriteDistance); 

    void update(); // Updates collision box
    void render(sf::RenderWindow& window); // Renders player to screen


    void setDirection(Direction direction); // Sets player direction
    void setPosition(sf::Vector2f position);
    void setSpeed(sf::Vector2f speed);
    void setScale(sf::Vector2f scale);

    sf::Vector2f getPosition();
    Direction getDirection();
    sf::View getCameraView();

    void move();

private:
    std::string PLAYER_TEXTURE_DIRECTORY = "Assets/Media/Textures/Red_Man.png";
    sf::Vector2f speed;

    sf::Texture texture;
    sf::Sprite sprite;

    sf::Vector2f position;
    sf::Vector2f scale;
    Direction direction;

    sf::View camera;
    sf::Vector2f cameraSize;
    float cameraSpeed = 3;

    int spriteDistance;

    CollisionBox hitBox;

    void updateHitBox();
};


#endif //OPENVILLAGE_PLAYER_H
