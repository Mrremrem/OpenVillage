//
// Created by mrremrem on 7/3/22.
//

#ifndef OPENVILLAGE_TILEINFO_H
#define OPENVILLAGE_TILEINFO_H

#include "SpriteSheet.h"
#include "TextureManager.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <cstring>
#include <fstream>
#include <unordered_map>

/*
 * Stores data from tiles. Only used for single, arbitrary tiles
 * for TileInfo
 */
struct Tile {
    Tile(TextureManager* textures, const std::string& sheetPath);
    
    std::string name;
    int frictionX;
    int frictionY;
    bool isDeadly;

    SpriteSheet spriteSheet;
};

/*
 * Stores all TileData in container
 */
class TileInfo {
public:
    TileInfo(TextureManager* textures, const std::string& tileInfoPath);

    Tile getTile(int id);
private:
    // Textures
    TextureManager* textures;
    const std::string TEXTURE_NAME = "Tile_Textures";

    // Tile info (by id, no duplicates)
    std::unordered_map<int, Tile> tileList;

    // config file for TileInfo
    std::ifstream tilesFile;

    void setupConfig();
    void setTile();
};


#endif //OPENVILLAGE_TILEINFO_H
