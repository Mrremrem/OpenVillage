#include "Entity.h"
#include "CollisionBox.h"

Entity::Entity(EntityType type, EntityState state):
entityType(type),
entityState(state)
{}

EntityType Entity::getType() {
    return entityType;
}

EntityState Entity::getState() {
    return entityState;
}