//
// Created by mrremrem on 7/3/22.
//

#include "TileManager.h"
#include "Entity.h"
#include <SFML/System/Vector2.hpp>

TileManager::TileManager(ResourceManager<sf::Texture>& textures, const std::string& tileInfoPath):
textures(textures),
tilesFile(tileInfoPath) {

    if (tilesFile.fail()){
        throw std::runtime_error("Error: invalid tiles config. Could not find path");
    }

    setupConfig();
}

Tile TileManager::getTile(const std::string& ID) {
    if (tileList.size() == 0) {
        throw std::out_of_range("Error: Could not load tile ID " + ID);
    }

    return tileList.at(ID);
}

void TileManager::setupConfig() {
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

void TileManager::setTile() {
    // Gets line information
    std::string ID;
    float frictionX;
    float frictionY;
    bool isDeadly; // For boolean
    tilesFile >> ID >> frictionX
    >> frictionY >> isDeadly;

    // Stores tile data to list
    std::string sheetPath = "Assets/Media/SpriteSheets/" + ID + "_Sheet.ini";
    Tile newTile(textures, sheetPath);
    newTile.setID(ID);
    newTile.setFriction(sf::Vector2f(frictionX, frictionY));
    newTile.setDeadliness(isDeadly);
    std::cout << "Adding ID " << ID << " to tile list with path " << sheetPath
    << "\n---" << std::endl;
    tileList.emplace(ID, newTile);
}