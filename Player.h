//
// Created by mrremrem on 6/29/22.
//

#ifndef OPENVILLAGE_PLAYER_H
#define OPENVILLAGE_PLAYER_H

#include <SFML/Graphics.hpp>
<<<<<<< HEAD
#include "Directions.h"
#include "CollisionBox.h"
#include "SpriteSheet.h"
#include "TextureManager.h"
=======
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "Directions.h"
#include "CollisionBox.h"
#include "Entity.h"
#include "SpriteSheet.h"
#include "ResourceManager.h"
>>>>>>> e58c56e (Hurrah! Binary Trees!)

/*
 * What?
 * Handles player information (position, sprite)
 */
<<<<<<< HEAD
class Player {
public:
    // Initializes player sprite
    Player(TextureManager* textures, sf::Vector2f cameraSize, int spriteDistance); 

=======
class Player : public Entity {
public:
    // Initializes player sprite
    Player(ResourceManager<sf::Texture>& textures, sf::Vector2f cameraSize); 

    void handleInput(); // Handles movement direction input
>>>>>>> e58c56e (Hurrah! Binary Trees!)
    void update(); // Updates collision box
    void render(sf::RenderWindow& window); // Renders player to screen


    void setDirection(Direction direction); // Sets player direction
<<<<<<< HEAD
    void setPosition(sf::Vector2f position);
    void setSpeed(sf::Vector2f speed);

    sf::Vector2f getPosition();
    Direction getDirection();
    sf::View getCameraView();

    void move();

private:
    std::string PLAYER_SHEET_DIR = "Assets/Media/SpriteSheets/Player_Sheet.txt";
    SpriteSheet playerSheet;
=======
    void setPosition(sf::Vector2f position); // Sets player position
    void setScale(sf::Vector2f scale); // Sets player scale
    void setSpeed(sf::Vector2f speed); // Sets player speed
    void setAnimation(const std::string& animation); // Sets sprite animation
    //void setLayerNum(int layerNum); // Sets player's layer

    sf::Vector2f getPosition(); // Gets player position
    Direction getDirection(); // Gets player direction
    sf::View& getView(); // Gets view
    SpriteSheet& getSpriteSheet(); // Gets SpriteSheet container

    const bool isColliding(Entity& other); // Tests if player collides with other entity
    const std::string getID(); // Gets entity ID
    //const int getLayerNum(); // Gets layer player is in

    // For comparisons (used for sorting)
    /*bool operator<(Entity& other);
    bool operator==(Entity& other);*/

private:
    void moveSprite();
    void updateWalkingAnimation();
    void updateHitBox();

    const std::string ID = "Player";
    const std::string PLAYER_SHEET_DIR = "Assets/Media/SpriteSheets/Player_Sheet.ini";
    SpriteSheet spriteSheet;
>>>>>>> e58c56e (Hurrah! Binary Trees!)

    sf::Vector2f speed;
    Direction direction;
    Direction prevDirection;
    

<<<<<<< HEAD
    sf::View camera;
    sf::Vector2f cameraSize;
    float cameraSpeed = 3;
=======
    sf::View view;
    sf::Vector2f viewSize;
    float viewSpeed = 3;
>>>>>>> e58c56e (Hurrah! Binary Trees!)

    int spriteDistance;

    CollisionBox hitBox;

<<<<<<< HEAD
    void updateHitBox();
=======
    //int layerNum;
>>>>>>> e58c56e (Hurrah! Binary Trees!)
};


#endif //OPENVILLAGE_PLAYER_H
