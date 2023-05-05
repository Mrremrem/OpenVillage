//
// Created by mrremrem on 6/29/22.
//

#ifndef OPENVILLAGE_PLAYER_H
#define OPENVILLAGE_PLAYER_H

#include <SFML/Graphics.hpp>
#include "Directions.h"
#include "CollisionBox.h"
#include "SpriteSheet.h"
#include "TextureManager.h"

/*
 * What?
 * Handles player information (position, sprite)
 */
class Player {
public:
    // Initializes player sprite
    Player(TextureManager* textures, sf::Vector2f cameraSize, int spriteDistance); 

    void update(); // Updates collision box
    void render(sf::RenderWindow& window); // Renders player to screen


    void setDirection(Direction direction); // Sets player direction
    void setPosition(sf::Vector2f position);
    void setSpeed(sf::Vector2f speed);

    sf::Vector2f getPosition();
    Direction getDirection();
    sf::View getCameraView();

    void move();

private:
    std::string PLAYER_SHEET_DIR = "Assets/Media/SpriteSheets/Player_Sheet.txt";
    SpriteSheet playerSheet;

    sf::Vector2f speed;
    Direction direction;
    Direction prevDirection;
    

    sf::View camera;
    sf::Vector2f cameraSize;
    float cameraSpeed = 3;

    int spriteDistance;

    CollisionBox hitBox;

    void updateHitBox();
};


#endif //OPENVILLAGE_PLAYER_H
