//
// Created by mrremrem on 7/3/22.
//

#include "TileInfo.h"

TileInfo::TileInfo(const std::string& path):
        path(path),
        tilesFile(path) {

    if (tilesFile.fail()){
        throw std::runtime_error("Error: invalid tiles config. Could not find path");
    }

    setupTiles();
}

TileInfo::~TileInfo() {
    // Empty
}

std::string TileInfo::getPath() {
    return path;
}

std::string TileInfo::getName(int id) {
    return tileList.at(id).name;
}

float TileInfo::getFrictionX(int id) {
    return tileList.at(id).frictionX;
}

float TileInfo::getFrictionY(int id) {
    return tileList.at(id).frictionY;
}

bool TileInfo::isDeadly(int id) {
    return tileList.at(id).isDeadly;
}

void TileInfo::setupTiles() {
    // Stores tiles info
    std::getline(tilesFile, tilesOrder);

    // Scans every line from tiles
    while (tilesFile.good()){
        // Gets line information
        int id;
        std::string name;
        float frictionX;
        float frictionY;
        bool isDeadly; // For boolean
        tilesFile >> id >> name >> frictionX
        >> frictionY >> isDeadly;

        // Stores data
        tileList.emplace(id, TileData());
        tileList.at(id).name = name;
        tileList.at(id).frictionX = frictionX;
        tileList.at(id).frictionY = frictionY;
        tileList.at(id).isDeadly = isDeadly;
    }
}