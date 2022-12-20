//
// Created by mrremrem on 7/3/22.
//

#include "Map.h"

Map::Map(std::string texturePath, sf::Vector2f tileScale, int spriteSize):
tileScale(tileScale) {
    if (!tileTextures.loadFromFile(texturePath)){
        std::runtime_error("Error: Could not open texture " + texturePath);
    }

    tileSprite.setTexture(tileTextures);
    this->spriteSize = spriteSize;
}

/*
 * Renders maps
 * Pre: mapLayers.size() > 0
 * Post: draws maps to window
 */
void Map::render(sf::RenderWindow &window) {
    if (mapLayers.size() <= 0) {
        throw std::out_of_range("Could not render map. "
        "mapLayers.size() must be > 0 (did you add any layer?)");
    }

    tileSprite.setScale(tileScale);

    int length = mapLayers.at(0).length;
    int height = mapLayers.at(0).height;
    for (int worldRow = 0; worldRow < height; worldRow++){
        for (int worldCol = 0; worldCol < length; worldCol++){
            // Draws tiles from each layer
            for (int mapIndex = 0; mapIndex < mapLayers.size(); mapIndex++) {
                drawTile(window, mapLayers.at(mapIndex), worldRow, worldCol);
            }
        }
    }
}

/*
 * Draws tile from map
 */
void Map::drawTile(sf::RenderWindow &window, MapContainer& mapData, int row, int col) {
    int currentTile = mapData.getTileAt(row, col);

    // Skips empty tile (Air)
    if (currentTile != 0) {
        int textureLocation = currentTile * spriteSize; // Gets texture location
        tileSprite.setTextureRect(sf::IntRect(textureLocation, 0, spriteSize, spriteSize));

        int spriteDistance = spriteSize * tileScale.x;
        tileSprite.setPosition(col * spriteDistance,
                                row * spriteDistance);
        window.draw(tileSprite);
    }
}

/* Adds layer to map
 * Pre: path must be a valid text file
 * Post: adds map layer to render buffer
 */
void Map::addLayer(std::string path) {
    mapLayers.push_back(MapContainer(path));
}


/*
 * Forms map from path
 * Pre: path must be a valid text file
 * Post: stores map data
 */
MapContainer::MapContainer(std::string path):
        path(path),
        mapFile(path) {
    if (mapFile.fail()){
        throw std::runtime_error("Error: invalid map data. Could not find path");
    }

    setupMap();
    // Stores dimensions
    height = tiles.size() - 1;
    length = tiles.at(0).size();
}

/*
 * Gets tile ID from row and col
 * Pre: 0 <= row <= length
 *      0 <= col <= height
 * Post: Returns tile ID in row and col
 */
int MapContainer::getTileAt(int row, int col) {
    if (tiles.empty()){
        std::runtime_error("Error. Tiles have not been initialized");
    } else if (row < 0 || row >= length || col < 0 || col >= height) {
        std::runtime_error("Error. Tile row or column not in range.");
    }

    return tiles[row][col];
}

/*
 * Sets up 2x2 map from directory
 * Pre: none
 * Post: Stores 2x2 map in tiles
 */
void MapContainer::setupMap() {
    // Gets name
    std::getline(mapFile, name);

    // Scans every line from map
    while (mapFile.good()){
        // Stores current line
        std::string currentLine;
        std::getline(mapFile, currentLine);

        // Stores each row's tiles as ints
        std::vector<int> currentRowTiles;
        std::stringstream tileStream(currentLine);
        int id = 0;
        while (tileStream >> id) {
            currentRowTiles.push_back(id);
        }

        // Stores row
        tiles.push_back(currentRowTiles);
    }
}