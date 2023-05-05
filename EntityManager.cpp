#include "EntityManager.h"
#include "Entity.h"
#include <vector>

/*
 * Deletes all entities from heap
 * Pre: none
 * Post: none
 */
EntityManager::~EntityManager() {
    for (auto entityListIndex : entityList) {
        for (Entity* entityIndex : entityListIndex.second) {
            delete entityIndex;
            entityIndex = nullptr;
        }
    }
}

/*
 * Adds entity to list of entities from ID
 * Pre: none
 * Post: size() = size() + 1
 */
void EntityManager::add(Entity* entity) {
    if (entityList.count(entity->getID()) <= 0) {
        entityList.emplace(entity->getID(), std::vector<Entity*>());
    }

    entityList.at(entity->getID()).emplace_back(entity);
    entitySize++;
}

/*
 * Calls each entity's update() method
 * Pre: none
 * Post: Updates each entity
 */
void EntityManager::update() {
    for (auto const& entityListIndex : entityList) {
        for (Entity* entityIndex : entityListIndex.second) {
            entityIndex->update();
        }
    }
}

/*
 * Calls each entity's render() method
 * Pre: none
 * Post: Renders each entity to window
 */
void EntityManager::render(sf::RenderWindow &window) {
    for (auto const& entityListIndex : entityList) {
        for (Entity* entityIndex : entityListIndex.second) {
            entityIndex->render(window);
        }
    }
}

int EntityManager::size() {
    return entitySize;
}