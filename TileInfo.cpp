//
// Created by mrremrem on 7/3/22.
//

#include "TileInfo.h"
#include "SpriteSheet.h"
#include "TextureManager.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <stdexcept>

TileInfo::TileInfo(TextureManager* textures, const std::string& tileInfoPath):
textures(textures),
tilesFile(tileInfoPath) {
    if (tilesFile.fail()){
        throw std::runtime_error("Error: invalid tiles config. Could not find path");
    }

    setupConfig();
}

Tile TileInfo::getTile(int id) {
    if (tileList.count(id) == 0) {
        throw std::out_of_range("Error: Could not load tile ID " + id);
    }

    return tileList.at(id);
}

void TileInfo::setupConfig() {
    // Stores tiles info |id|name| etc.
    std::string tileLine;
    std::getline(tilesFile, tileLine);

    // Scans every line from tiles
    while (tilesFile.good()){
        std::string type;
        tilesFile >> type;

        const std::string TILE = "TILE";
        const std::string COMMENT = "#";

        if (type == TILE) {
            setTile();
        }
    }
}

void TileInfo::setTile() {
    // Gets line information
    int id;
    std::string name;
    float frictionX;
    float frictionY;
    bool isDeadly; // For boolean
    tilesFile >> id >> name >> frictionX
    >> frictionY >> isDeadly;

    // Stores tile data to list
    std::string sheetPath = "Assets/Media/SpriteSheets/" + name + "_Sheet.txt";
    Tile newTile(textures, sheetPath);
    newTile.name = name;
    newTile.frictionX = frictionX;
    newTile.frictionY = frictionY;
    newTile.isDeadly = isDeadly;
    tileList.emplace(id, newTile);
}

// Constructor for struct Tile 
Tile::Tile(TextureManager* textures, const std::string& path):
spriteSheet(textures, path) {
    // Empty
}