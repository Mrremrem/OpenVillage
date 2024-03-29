//
// Created by mrremrem on 7/3/22.
//

#ifndef OPENVILLAGE_MAP_H
#define OPENVILLAGE_MAP_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include "EntityManager.h"
#include "ResourceManager.h"
#include "TileManager.h"
#include "Entity.h"
#include "Player.h"
#include "Sign.h"

/*
 * Stores maps and renders them
 */
class Map {
public:
    // Forms map from path and stores tile info
    Map(ResourceManager<sf::Texture>& textures, ResourceManager<sf::Font>& fonts, 
        const std::string& tileInfoPath, std::vector<sf::View>& playerViewsList);
    ~Map();

    void update();// Updates entities
    void render(sf::RenderWindow& window); // Renders map to window

    void initializeMap(const std::string& mapPath); // Initializes map from path

    EntityManager& getEntityList();
private:
    sf::Vector2f worldSize;
    sf::Vector2f spriteSize;
    sf::Vector2f spriteScale;

    //void addLayers(int numOfLayers);

    void loadMapData(); // Loads map from data file
    void loadEntity(); // Loads entity from data file
    void initEntityPos(Entity& entity, int posX, int posY);

    // Appends entities with incrementing postfixes
    void appendEntity(const std::string& entityName, int layerNum, Entity* entity);

    //bool compareEntities(Entity& Entity1, Entity& Entity2);

    bool outOfBounds(int posX, int posY);

    ResourceManager<sf::Texture>& textures;
    ResourceManager<sf::Font>& fonts;
    TileManager tiles;

    EntityManager entityList;
    std::vector<sf::View>& playerViewsList;
    
    std::ifstream mapFile;
};


#endif //OPENVILLAGE_MAP_H
