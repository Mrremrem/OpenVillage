//
// Created by mrremrem on 7/3/22.
//

#ifndef OPENVILLAGE_MAP_H
#define OPENVILLAGE_MAP_H

<<<<<<< HEAD
#include "EntityManager.h"
#include "TextureManager.h"
#include "TileInfo.h"
=======
>>>>>>> e58c56e (Hurrah! Binary Trees!)
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
<<<<<<< HEAD
#include <vector>
#include <fstream>
#include <sstream>
#include "Sign.h"

/*
=======
#include <map>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "ResourceManager.h"
#include "TileManager.h"
#include "Entity.h"
#include "Player.h"
#include "Sign.h"

/*
 * Key for entityList
 * Used for sorting entities by layers/ID
 */
struct EntityKey {
    EntityKey(std::string ID, int layerNum):
    ID(ID),
    layerNum(layerNum) {}

    std::string ID;
    int layerNum;
};

/*
 * Comparator for EntityKey
 * Used for comparing two EntityKeys
 */
struct EntityKeyComparator {
    template<typename TArbitraryKey>
    bool operator()(TArbitraryKey& key1, TArbitraryKey& key2) {
        if (key1.layerNum != key2.layerNum) {
            return key1.layerNum < key2.layerNum;
        } 
        
        return key1.ID < key2.ID;
    }
};

/*
>>>>>>> e58c56e (Hurrah! Binary Trees!)
 * Stores maps and renders them
 */
class Map {
public:
    // Forms map from path and stores tile info
<<<<<<< HEAD
    Map(TextureManager* textures, const std::string& tileInfoPath);
    ~Map();

    // Updates entities
    void update();
    
    // Renders map to window
    void render(sf::RenderWindow& window);
    

    // Adds layer to map
    void addLayer(const std::string& mapPath);

=======
    Map(ResourceManager<sf::Texture>& textures, const std::string& tileInfoPath);
    ~Map();

    void update();// Updates entities
    void render(sf::RenderWindow& window); // Renders map to window

    void initializeMap(const std::string& mapPath); // Initializes map from path
>>>>>>> e58c56e (Hurrah! Binary Trees!)
private:
    sf::Vector2f worldSize;
    sf::Vector2f spriteSize;
    sf::Vector2f spriteScale;

<<<<<<< HEAD
    void loadMapData();
    void initializeTile(Tile* tile, int posX, int posY);

    bool outOfBounds(int posX, int posY);

    // Holds each layer
    std::vector<std::vector<Tile>* > layerList;
    
    TileInfo tileInfo;

    EntityManager entities;
=======
    //void addLayers(int numOfLayers);

    void loadMapData(); // Loads map from data file
    void loadEntity(); // Loads entity from data file
    void appendEntity(std::string& entityName, int layer, Entity* entity); // Adds entity to list
    void initEntityPos(Entity& entity, int posX, int posY);

    //bool compareEntities(Entity& Entity1, Entity& Entity2);

    bool outOfBounds(int posX, int posY);

    ResourceManager<sf::Texture>& textures;
    TileManager tiles;

    // Hold entities. Keys are Entity ID, Entity name
    std::map<EntityKey, Entity*, EntityKeyComparator> entityList;
    std::unordered_map<std::string, int> entityCountList; // Holds # of entities available
>>>>>>> e58c56e (Hurrah! Binary Trees!)
    
    std::ifstream mapFile;
};


#endif //OPENVILLAGE_MAP_H
