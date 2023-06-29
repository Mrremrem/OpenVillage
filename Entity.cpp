#include "Entity.h"
#include "CollisionBox.h"
#include <SFML/System/Vector2.hpp>

Entity::Entity(int id, EntityType type, EntityState state) {
    this->id = id;
    entityType = type;
    entityState = state;
}

void Entity::update() {
    // Empty
}

void Entity::render(sf::RenderWindow &window) {
    // Empty
}

bool Entity::isColliding(Entity other) {
    return hitBox.isColliding(other.hitBox);
}

int Entity::getID() {
    return id;
}