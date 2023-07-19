#include "EntityManager.h"
#include "Entity.h"
#include <stdexcept>

EntityManager::EntityManager() {
    // Empty for now
}

/*
 * Destroys all entities from list
 */
EntityManager::~EntityManager() {
    for (auto entityIndex : entityList) {
        delete entityIndex.second;
        entityIndex.second = nullptr;
    }
}

/*
 * Appends entity to entityList
 * For every existing entityName being appended,
 * its postfix is incremented by one, giving each
 * entity a unique ID when emplaced.
 * Example: Tile0, Tile1, Tile2, etc.
 * Pre: none
 * Post: entityList.size() = entityList.size() + 1
 */
void EntityManager::add(const std::string& entityName, int layerNum, Entity* entity) {
    if (entityCountList.find(entityName) == entityCountList.end()) {
        entityCountList.emplace(entityName, 0);
    }

    int entityCount = entityCountList.at(entityName);

    // Names entity with # + entity count
    const char NUMBER_SYMBOL = '#';
    std::string newEntityName = entityName + NUMBER_SYMBOL + std::to_string(entityCount);
    
    EntityKey newEntityKey(newEntityName, layerNum);
    entityList.emplace(newEntityKey, entity);

    entityCountList.at(entityName) = entityCount + 1; // No checks needed
    
    // Stores layerNum from entity
    entityLayerList.emplace(newEntityName, layerNum);
}

/*
 * Removes entity from entityList
 * Pre: none
 * Post: 
 * entityList.size() = entityList.size() - 1
 *  ^ if entityID is present,
 * returns true if present and removed,
 * false otherwise
 */
bool EntityManager::remove(const std::string& entityID) {
    auto entityLayerListIt = entityLayerList.find(entityID);
    if (entityLayerListIt == entityLayerList.end()) {
        return false;
    }
    
    auto entityListIt = entityList.find({entityID, entityLayerListIt->second});
    entityLayerList.erase(entityLayerListIt);
    if (entityListIt == entityList.end()) {
        /* 
         * This isn't supposed to run--ever
         * (if entityID is present in entityLayerList, 
         * it has to be present in entityList)
         */
        throw std::runtime_error("(CRITICAL) Error in EntityManager::remove(): "
        "Entity was never added for " + entityID + ". Good luck.");
    }

    entityList.erase(entityListIt);

    return true;
} 

/*
 * Gets entity from entityList
 * Pre: none
 * Post: Returns entity if present,
 *       Returns nullptr otherwise
 */
Entity* EntityManager::get(const std::string& entityID) {
    // Tests if entityID is present
    auto entityLayerListIt = entityLayerList.find(entityID);
    if (entityLayerListIt == entityLayerList.end()) {
        return nullptr;
    }

    return entityList.at({entityID, entityLayerListIt->second});
}

/*
 * Sets entity's layer
 * Pre: none
 * Post: Returns true if layer has been
 * changed
 */
bool EntityManager::setLayer(const std::string& entityID, int layerNum) {
    auto entityLayerListIt = entityLayerList.find(entityID);
    if (entityLayerListIt == entityLayerList.end()) {
        throw std::runtime_error("Error in EntityManager::setLayer: entity" + entityID
        + " not found");
    } else if (entityLayerListIt->second == layerNum) {
        return false;
    }

    auto entityListIt = entityList.find({entityID, entityLayerListIt->second});
    if (entityListIt == entityList.end()) {
        /* 
         * This isn't supposed to run--ever
         * (if entityID is present in entityLayerList, 
         * it has to be present in entityList)
         */
        throw std::runtime_error("(CRITICAL) Error in EntityManager::setLayer(): "
        "Entity was never added for " + entityID + ". Good luck.");
    }

    // Stores copy of entity, then deletes original entity
    Entity* entityCopy = entityListIt->second;
    entityList.erase(entityListIt);

    // Edits entity's layerNum, then stores entity back in list
    entityLayerListIt->second = layerNum;
    EntityKey copyEntityKey(entityID, layerNum);
    entityList.emplace(copyEntityKey, entityCopy);
}

/*
 * Returns beginning of entityList iterator
 * This iterator comes from the map container itself
 * Pre: none
 * Post: Returns front of entityList map as iterator
 */
std::map<EntityKey, Entity*>::iterator EntityManager::begin() {
    return entityList.begin();
}

/*
 * Returns end of entityList iterator
 * This iterator comes from the map container itself
 * Pre: none
 * Post: Returns end of entityList map as iterator
 */
std::map<EntityKey, Entity*>::iterator EntityManager::end() {
    return entityList.end();
}