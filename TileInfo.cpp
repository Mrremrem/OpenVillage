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
    return nameList[id];
}

int TileInfo::getFrictionX(int id) {
    return frictionList[id].first;
}

int TileInfo::getFrictionY(int id) {
    return frictionList[id].second;
}

bool TileInfo::isDeadly(int id) {
    return isDeadlyList[id];
}

void TileInfo::setupTiles() {
    // Stores tiles info
    std::getline(tilesFile, tilesOrder);

    // Scans every line from tiles
    while (tilesFile){
        // Gets line information
        int id;
        std::string name;
        float frictionX;
        float frictionY;
        bool isDeadly; // For boolean
        tilesFile >> id >> name >> frictionX
        >> frictionY >> isDeadly;

        // Stores
        nameList.push_back(name);
        frictionList.emplace_back(frictionX, frictionY);
        isDeadlyList.push_back(isDeadly);
    }
}