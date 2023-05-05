//
// Created by mrremrem on 12/20/22.
//

#ifndef OPENVILLAGE_ENTITYMANAGER_H
#define OPENVILLAGE_ENTITYMANAGER_H

#include "Entity.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <cstring>
#include <unordered_map>
#include <vector>

class EntityManager {
public:
    ~EntityManager();
    void add(Entity* entity);

    void update();
    void render(sf::RenderWindow& window);
    

    //void remove(unsigned int id);
    int size();
private:
    // Stores each unique entity in list by ID
    std::unordered_map<unsigned int, std::vector<Entity*> > entityList;
    int entitySize;
};

#endif // OPENVILLAGE_ENTITYMANAGER_H