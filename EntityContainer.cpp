/*#include "EntityContainer.h"
#include <string>

EntityContainer::EntityContainer() {
    // Empty
}*/

/*
 * Adds entity to container
 * Pre: none
 * Post: size() = size() + 1
 *//*
void EntityContainer::add(std::string ID, Entity* entity) {
    if (entityIDCountList.find(ID) == entityIDCountList.end()) {
        entityIDCountList.emplace(0); // Creates new entity counter
    }

    std::string entityName = ID + std::to_string(entityIDCountList.at(ID));
    entityList.emplace(entityName, entity);
    
}

int EntityContainer::size() {
    return entityList.size();
}*/