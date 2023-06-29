//
// Created by mrremrem on 7/3/22.
//

#ifndef OPENVILLAGE_MAP_H
#define OPENVILLAGE_MAP_H

#include "EntityManager.h"
#include "TextureManager.h"
#include "TileInfo.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Sign.h"

/*
 * Stores maps and renders them
 */
class Map {
public:
    // Forms map from path and stores tile info
    Map(TextureManager* textures, const std::string& tileInfoPath);
    ~Map();

    // Updates entities
    void update();
    
    // Renders map to window
    void render(sf::RenderWindow& window);
    

    // Adds layer to map
    void addLayer(const std::string& mapPath);

private:
    sf::Vector2f worldSize;
    sf::Vector2f spriteSize;
    sf::Vector2f spriteScale;

    void loadMapData();
    void initializeTile(Tile* tile, int posX, int posY);

    bool outOfBounds(int posX, int posY);

    // Holds each layer
    std::vector<std::vector<Tile>* > layerList;
    
    TileInfo tileInfo;

    EntityManager entities;
    
    std::ifstream mapFile;
};


#endif //OPENVILLAGE_MAP_H
