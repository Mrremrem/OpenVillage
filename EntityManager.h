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

    void setType(const std::string& entityType);

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
private:
    std::string ID; // Unique ID. Example: Player_RedMan
    int layerNum; // Layer number for drawing on window. Also used for sorting.
};

/*
 * Base EntityManager class
 * Holds each entity, and creates unique names
 * when added to list. 
 */
class EntityManager {
public:
    EntityManager();
    ~EntityManager();

    void add(const std::string& entityID, int layerNum, Entity* entity); // Appends entity to list
    void remove(const std::string& entityID); // Removes entity from list

    Entity* get(const std::string& entityID); // Gets entity by ID, returns nullptr if not present

    bool setLayer(const std::string& entityID, int layerNum); // Changes layer

    int getLayerNum(const std::string& entityID);

    int size(); // Returns # of entities stored

    int getTotalTypeCount(EntityType type); // Gets total number of types available

    // Gets # of entities created with entityType in EntityManager's lifetime
    int getLifetimeTypeCount(EntityType type);

    // For iterations
    std::map<EntityKey, Entity*>::iterator begin();
    std::map<EntityKey, Entity*>::iterator end();
private:
    void incrementCounters(EntityType type); // Increments type from lifetimeTypeCountList
    bool decrementTypeCounter(EntityType type); // Decrements counter for type in typeCountList



    // Hold entities. Refer to EntityKey for doc. Sorts entities by layerNum's
    std::map<EntityKey, Entity*> entityList;

    // Counters
    std::unordered_map<EntityType, int> typeCountList; // Holds each # of types in total
    std::unordered_map<EntityType, int> lifetimeTypeCountList; // Holds # of types during lifetime

    std::unordered_map<std::string, int> layerNumList; // Holds each entity's layerNum
};

#endif //OPENVILLAGE_ENTITYMANAGER_H