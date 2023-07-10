//
// Created by mrremrem on 12/19/22.
//

#ifndef OPENVILLAGE_ENTITY_H
#define OPENVILLAGE_ENTITY_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <unordered_map>
#include <vector>
#include "CollisionBox.h"

enum class EntityType {
    Base,
    Enemy,
    Player
};

enum class EntityState {
    Idle, Walking, Jumping, Attacking, Hurt, Dying
};

/*
 * Base entity class
 * Allows for an easy way to update/render every entity
 * Every entity has similar attributes such as
 * their hitbox. The current goal is to make this as minimal
 * as possible before conflicts occur with future entity classes.
 */
class Entity {
public:
    Entity(EntityType, EntityState); // Creates entity with Type and State

    virtual void update() = 0; // Updates entity
    virtual void render(sf::RenderWindow& window) = 0; // Renders entity to window

    virtual void setPosition(sf::Vector2f position) = 0; // Sets entity's position

    virtual const bool isColliding(Entity& other) = 0;
    virtual const std::string getID() = 0;
    //virtual const int getLayerNum() = 0;

    /*virtual bool operator<(Entity& other) = 0;
    virtual bool operator==(Entity& other) = 0;*/
protected:
    sf::Vector2f position;

    // Entity info
    EntityType entityType;
    EntityState entityState;
};

#endif // OPENVILLAGE_ENTITY_H