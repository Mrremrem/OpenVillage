//
// Created by mrremrem on 7/3/22.
//

#include "Map.h"

Map::Map(std::string path):
        path(path),
        mapFile(path) {
    if (mapFile.fail()){
        throw std::runtime_error("Error: invalid map data. Could not find path");
    }

    setupMap();
}

Map::~Map() {
    // Empty
}

std::string Map::getName() {
    return name;
}

std::string Map::getPath() {
    return path;
}

int Map::getTileAt(int row, int col) {
    if (tiles.empty()){
        std::runtime_error("Error. Tiles have not been initialized");
    } else if (row < 0 || row >= length || col < 0 || col >= height) {
        std::runtime_error("Error. Tile row or column not in range.");
    }

    return tiles[row][col];
}

int Map::getLength() {
    return length;
}

int Map::getHeight() {
    return height;
}

void Map::setupMap() {
    // Gets name
    std::getline(mapFile, name);

    // Scans every line from map
    while (mapFile){
        // Stores current line
        std::string currentLine;
        mapFile >> currentLine;

        // Stores each row's tiles as ints
        std::vector<int> currentRowTiles;
        for (int lineIndex = 0; lineIndex < currentLine.length(); lineIndex++){
            int currentTile = currentLine[lineIndex] - '0'; // as int
            currentRowTiles.push_back(currentTile); // Stores row
        }

        // Stores row
        tiles.push_back(currentRowTiles);
    }

    // Stores dimensions
    height = tiles.size() - 1;
    length = tiles.at(0).size();
}