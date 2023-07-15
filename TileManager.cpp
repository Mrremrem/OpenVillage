//
// Created by mrremrem on 7/3/22.
//

#include "TileManager.h"
#include "Entity.h"
#include <SFML/System/Vector2.hpp>
#include <stdexcept>

/*
 * Reads config file for Tiles
 * Pre: none
 * Post: sets each Tile's attributes from config
 */
TileManager::TileManager(ResourceManager<sf::Texture>& textures, const std::string& tileInfoPath):
textures(textures),
tilesFile(tileInfoPath) {

    if (tilesFile.fail()){
        throw std::runtime_error("Error: invalid tiles config. Could not find path");
    }

    setupConfig();
}

/*
 * Gets Tile from ID
 * Pre: tileList.size() > 0,
 *      tileList.count(ID) > 0
 * Post: Returns tile at tileList
 */
Tile TileManager::getTile(const std::string& ID) {
    if (tileList.size() == 0) {
        throw std::out_of_range("Error: Could not load tile ID " + ID);
    }

    std::cout << "Running tile.at at TileManager::getTile() (return)" << std::endl;

    auto tileListIt = tileList.find(ID);
    if (tileListIt == tileList.end()) {
        throw std::out_of_range("Error in TileManager::getTile(): No such Tile with ID " + ID);
    }

    return tileListIt->second;
}

/*
 * Sets up Tile config
 * Pre: none
 * Post: Stores each Tile's attributes from
 * config file
 */
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

/*
 * Sets a single Tile from the next
 * Tile config stream
 * Pre: none
 * Post: none
 */
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