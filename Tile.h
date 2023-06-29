//
// Created by mrremrem on 5/30/23. (I turned Tile from a single
// struct to a full blown class).
//

#include "ResourceManager.h"
#include "Entity.h"
#include "SpriteSheet.h"
#include <SFML/System/Vector2.hpp>

/*
 * Creates an abstract Tile.
 * Tile ID's are abstract, its look & behavior
 * is abstract... I think you get it :)
 * Just supply enough information (as in, modify
 * its layer number and Tile ID if sorting is needed)
 */
class Tile : public Entity {
public:
    Tile(ResourceManager<sf::Texture>& textures, const std::string& sheetPath);

    void update(); // Updates tile
    void render(sf::RenderWindow& window); // Renders tile to window

    void setPosition(const sf::Vector2f position); // Sets tile position
    void setID(const std::string& ID); // Sets tile ID
    void setFriction(const sf::Vector2f friction); // Sets friction on both axis
    void setDeadliness(bool isDeadly); // Sets deadlyness
    void setAnimation(const std::string& animation); // Sets animation
    //void setLayerNum(int layerNum); // Sets tile layer

    const std::string getID(); // Gets ID
    const sf::Vector2f getFriction(); // Gets friction
    const bool isDeadly(); // Tests if tile is deadly

    const bool isColliding(Entity& other); // Tests if tile collides with other entity
    //const int getLayerNum(); // Gets layer number

    // For sorting comparisions:
    /*bool operator<(Entity& other);
    bool operator==(Entity& other);*/
private:
    
    std::string ID;
    sf::Vector2f friction;
    bool isConsideredDeadly;

    SpriteSheet spriteSheet;
};