//
// Created by mrremrem on 5/30/23.
//

#include "Tile.h"
#include "CollisionBox.h"
#include <SFML/System/Vector2.hpp>

// Constructor for struct Tile 
Tile::Tile(ResourceManager<sf::Texture>& textures, const std::string& path):
Entity(EntityType::Base, EntityState::Idle),
spriteSheet(textures, path) {
    // Empty
}

void Tile::update() {
    spriteSheet.update();
}

void Tile::render(sf::RenderWindow &window) {
    window.draw(spriteSheet.getSprite());
}

void Tile::setPosition(const sf::Vector2f position) {
    spriteSheet.getSprite().setPosition(position);
}

void Tile::setID(const std::string& ID) {
    this->ID = ID;
}

void Tile::setFriction(const sf::Vector2f friction) {
    this->friction = friction;
}

void Tile::setDeadliness(bool isDeadly) {
    this->isConsideredDeadly = isDeadly;
}

void Tile::setAnimation(const std::string& animation) {
    spriteSheet.setAnimation(animation);
}

/*
 * Sets layer number
 * Pre: layerNum >= 0
 * Post: this->layerNum = layerNum*/
/*void Tile::setLayerNum(int layerNum) {
    this->layerNum = layerNum;
}*/

const std::string Tile::getID() {
    return ID;
}

const sf::Vector2f Tile::getFriction() {
    return friction;
}

const bool Tile::isDeadly() {
    return isConsideredDeadly;
}

const bool Tile::isColliding(CollisionBox& other) {
    return false;
}

/*const int Tile::getLayerNum() {
    return layerNum;
}*/

/*
 * Tests if this entity is less than other entity
 * Pre: none
 * Post: Returns true if this entity is less than
 * other entity
 */
/*bool Tile::operator<(Entity& other) {
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
/*bool Tile::operator==(Entity& other) {
    return layerNum == other.getLayerNum() && ID == other.getID();
}*/