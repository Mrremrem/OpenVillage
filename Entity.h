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

class Entity {
public:
    Entity(int id, EntityType, EntityState);

    virtual void update();
    virtual void render(sf::RenderWindow& window);

    int getID();


    bool isColliding(Entity other);
protected:
    sf::Vector2f position;

    // Entity info
    int id;
    EntityType entityType;
    EntityState entityState;

    CollisionBox hitBox;
};

#endif // OPENVILLAGE_ENTITY_H