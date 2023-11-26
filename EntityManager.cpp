#include "EntityManager.h"
#include "Entity.h"
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

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
void EntityManager::add(const std::string& entityID, int layerNum, Entity* entity) {
    EntityKey newEntityKey(entityID, layerNum);
    entityList.emplace(newEntityKey, entity);

    incrementCounters(entity->getType());
    
    // Stores layerNum from entity
    layerNumList.emplace(entityID, layerNum);
}

/*
 * Removes entity from entityList
 * Pre: none
 * Post: 
 * entityList.size() = entityList.size() - 1 if 
 * entityID is present. Throws error otherwise
 */
void EntityManager::remove(const std::string& entityID) {
    // layerNum is needed to access entityList, might as well use it as a check
    auto layerNumListIt = layerNumList.find(entityID);
    if (layerNumListIt == layerNumList.end()) {
        throw std::runtime_error("Error in EntityManager::remove(): entity with ID " 
        + entityID + " does not exist.");
    }
    
    // Retreives entity now that we have layerNum, layerNum is no longer needed
    auto entityListIt = entityList.find({entityID, layerNumListIt->second});
    layerNumList.erase(layerNumListIt);
    if (entityListIt == entityList.end()) {
        // This isn't supposed to run... ever
        throw std::runtime_error("(CRITICAL) Error in EntityManager::remove(): "
        "Entity was never added for " + entityID + ". Good luck.");
    }

    decrementTypeCounter(entityListIt->second->getType());
    entityList.erase(entityListIt);
} 

/*
 * Gets entity from entityList
 * Pre: none
 * Post: Returns entity if present,
 *       Returns nullptr otherwise
 */
Entity* EntityManager::get(const std::string& entityID) {
    // Tests if entityID is present
    auto layerNumListIt = layerNumList.find(entityID);
    if (layerNumListIt == layerNumList.end()) {
        return nullptr;
    }

    return entityList.at({entityID, layerNumListIt->second});
}

/*
 * Sets entity's layer
 * Pre: none
 * Post: Returns true if layer has been changed
 */
bool EntityManager::setLayer(const std::string& entityID, int layerNum) {
    auto layerNumListIt = layerNumList.find(entityID);
    if (layerNumListIt == layerNumList.end()) {
        throw std::runtime_error("Error in EntityManager::setLayer: entity" + entityID
        + " not found");
    } else if (layerNumListIt->second == layerNum) {
        return false;
    }

    auto entityListIt = entityList.find({entityID, layerNumListIt->second});
    if (entityListIt == entityList.end()) {
        /* 
         * This isn't supposed to run--ever
         * (if entityID is present in layerNumList, 
         * it has to be present in entityList)
         */
        throw std::runtime_error("(CRITICAL) Error in EntityManager::setLayer(): "
        "Entity was never added for " + entityID + ". Good luck.");
    }

    // Stores copy of entity, then deletes original entity
    Entity* entityCopy = entityListIt->second;
    entityList.erase(entityListIt);

    // Edits entity's layerNum, then stores entity back in list
    layerNumListIt->second = layerNum;
    EntityKey copyEntityKey(entityID, layerNum);
    entityList.emplace(copyEntityKey, entityCopy);

    return true;
}

/*
 * Returns layerNum for entity
 * Pre: entityID must exist in entityList
 * Post: Returns layerNum for entityID
 */
int EntityManager::getLayerNum(const std::string& entityID) {
    auto layerNumListIt = layerNumList.find(entityID);

    if (layerNumListIt == layerNumList.end()) {
        throw std::runtime_error("Error in EntityManager::getLayerNum(): entity" 
        + entityID + " does not exist");
    }

    return layerNumListIt->second;
}

/*
 * Returns # of entities made
 * Pre: none
 * Post: Returns entityList.size()
 */
int EntityManager::size() {
    return entityList.size();
}

/*
 * Gets total # of types in entityList
 * Pre: None
 * Post: Returns # of type(s) made
 */
int EntityManager::getTotalTypeCount(EntityType type) {
    auto typeCountIt = typeCountList.find(type);

    // Has to be zero if type isn't present
    return (typeCountIt == typeCountList.end()) ? 0 : typeCountIt->second;
}

/*
 * Gets # of entities created with entityType 
 * in EntityManager's lifetime
 * Useful for making arbitrary entities with 
 * incrementing postfixes for ID's
 * Pre: none
 * Post: Returns # of entityTypes ever made
 */
int EntityManager::getLifetimeTypeCount(EntityType type) {
    auto typeCountIt = lifetimeTypeCountList.find(type);

    // Has to be zero if type isn't present
    return (typeCountIt == lifetimeTypeCountList.end()) ? 0 : typeCountIt->second;
}

/*
 * Gets list of single EntityTypes
 * Pre: entityList.size() > 0
 * Post: Returns list of every entity that has
 * EntityType of type (as in, returns a list of all
 * players if type passed is EntityType::Player)
 * Returns empty list if no type was added
 */
 #include <iostream>
std::vector<Entity*> EntityManager::getEntityTypeList(EntityType type) {
    std::vector<Entity*> entityTypeList;
    int totalTypes = getTotalTypeCount(type);

    std::cout << "totalTypes: " << totalTypes << std::endl;

    for (int typeIndex = 0; typeIndex < totalTypes; typeIndex++) {
        int typeVal = static_cast<int>(type);
        std::string entityID = ENTITY_TYPE_STR[typeVal] +  std::to_string(typeIndex);

        std::cout << "Getting type " << ENTITY_TYPE_STR[typeVal] << " with " << entityID << std::endl;
        entityTypeList.emplace_back(get(entityID));
    }

    return entityTypeList;
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

/*
 * Helper method for typeCountList and lifetimeTypeCountList
 * Increments counter for type by one
 * Pre: None
 * Post: lifetimeTypeCountList.at(type) = lifetimeTypeCountList.at(type) + 1
 */
void EntityManager::incrementCounters(EntityType type) {
    auto typeCounterIt = typeCountList.find(type);

    if (typeCounterIt == typeCountList.end()) {
        typeCounterIt = typeCountList.emplace(type, 0).first;
    }

    auto lifetimeTypeCounterIt = lifetimeTypeCountList.find(type);

    if (lifetimeTypeCounterIt == lifetimeTypeCountList.end()) {
        lifetimeTypeCounterIt = lifetimeTypeCountList.emplace(type, 0).first;
    }

    lifetimeTypeCounterIt->second = lifetimeTypeCounterIt->second + 1;
}

/*
 * Decrements counter for typeCountList
 * Pre: None
 * Post: Returns true if type's counter was changed
 * typeCountList.at(type) = typeCountList.at(type) - 1 if 
 * type exists in counter
 */
bool EntityManager::decrementTypeCounter(EntityType type) {
    auto typeCounterIt = typeCountList.find(type);

    if (typeCounterIt == typeCountList.end()) {
        return false;
    }

    typeCounterIt->second = typeCounterIt->second - 1;
    return true;
}