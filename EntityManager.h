//
// Created by mrremrem on 12/19/22.
//

#ifndef OPENVILLAGE_ENTITYMANAGER_H
#define OPENVILLAGE_ENTITYMANAGER_H

#include <string>
#include <map>
#include <unordered_map>
#include "Entity.h"

/*
 * Key for entityList
 * Used for sorting entities by layers/ID
 */
struct EntityKey {
public:
    EntityKey(std::string ID, int layerNum):
    ID(ID),
    layerNum(layerNum) {}

    const std::string& getID() const { return ID; }
    const int getLayerNum() const { return layerNum; }

    /*
     * Comparator for EntityKey
     * Used for comparing two EntityKeys
     */
    const bool operator<(const EntityKey& other) const {
        if (layerNum != other.layerNum) {
            return layerNum < other.layerNum;
        }
        return ID < other.ID;
    }
    
    // For static casts. Types can be Player, Flower, Sign, etc. Entity by default
    std::string entityType = "Entity";
private:
    std::string ID; // Unique ID. Example: Player_RedMan

    int layerNum; // Layer number for drawing on window. Also used for sorting.
};

/*
 * Base EntityManager class
 * Holds each entity, and creates unique names
 * when added to list. */
class EntityManager {
public:
    EntityManager();
    ~EntityManager();

    void add(const std::string& entityName, int layer, Entity* entity); // Appends entity to list
    bool remove(const std::string& entityID); // Removes entity from list

    Entity* get(const std::string& entityID); // Gets entity by ID, returns nullptr if not present

    bool setLayer(const std::string& entityID, int layerNum); // Changes layer

    int size(); // Returns # of entities stored

    // Gets # of entities created with entityType in EntityManager's lifetime
    int getLifetimeTypeCount(const std::string& entityType);

    // For iterations
    std::map<EntityKey, Entity*>::iterator begin();
    std::map<EntityKey, Entity*>::iterator end();
private:
    // Hold entities. Keys are Entity ID, Entity name. Sorts entities by layerNum's
    std::map<EntityKey, Entity*> entityList;

    std::unordered_map<std::string, int> entityCountList; // Holds # of entities made in lifetime
    std::unordered_map<std::string, int> entityLayerList; // Holds each entity's layerNum
};

#endif //OPENVILLAGE_ENTITYMANAGER_H