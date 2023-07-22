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

/*
 * List of entity types
 * Update this enum every time you introduce
 * a new type. It's better to have it as
 * enums than strings since you'll have to 
 * manually type check when casting.
 */
enum class EntityType {
    Base,
    Tile,
    Player,
    Sign
};

/*
 * Current entity state
 */
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

    virtual const bool isColliding(Entity& other) = 0; // Tests if entity is colliding with other

    virtual const std::string getID() = 0; // Gets unique ID

    EntityType getType(); // Gets entity type. Used for casting
    EntityState getState();
protected:
    sf::Vector2f position;

    // Entity info
    EntityType entityType;
    EntityState entityState;
};

#endif // OPENVILLAGE_ENTITY_H