//
// Created by mrremrem on 7/3/22.
//

#ifndef OPENVILLAGE_TILEMANAGER_H
#define OPENVILLAGE_TILEMANAGER_H

#include "SpriteSheet.h"
#include "ResourceManager.h"
#include "Tile.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <cstring>
#include <fstream>
#include <unordered_map>

/*
 * Stores all TileData in container
 */
class TileManager {
public:
    TileManager(ResourceManager<sf::Texture>& textures, const std::string& TileManagerPath);

    Tile getTile(const std::string& ID);
private:
    // Textures
    ResourceManager<sf::Texture>& textures;
    const std::string TEXTURE_NAME = "Tile_Textures";

    // Tile info (by id, no duplicates)
    std::unordered_map<std::string, Tile> tileList;

    // config file for TileManager
    std::ifstream tilesFile;

    void setupConfig();
    void setTile();
};


#endif //OPENVILLAGE_TILEMANAGER_H
