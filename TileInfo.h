//
// Created by mrremrem on 7/3/22.
//

#ifndef OPENVILLAGE_TILEINFO_H
#define OPENVILLAGE_TILEINFO_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <unordered_map>

/*
 * Stores tile data on current tile
 */
struct TileData {
    std::string name;
    int frictionX;
    int frictionY;
    bool isDeadly;
};

class TileInfo {
public:
    TileInfo(const std::string& path);
    ~TileInfo();

    std::string getPath();

    std::string getName(int id);
    float getFrictionX(int id);
    float getFrictionY(int id);
    bool isDeadly(int id);
private:
    void setupTiles();

    std::string path;

    // Tile info (by id)
    std::unordered_map<int, TileData> tileList;

    std::ifstream tilesFile; // config
    std::string tilesOrder; // stores id, name, friction, etc. line
};


#endif //OPENVILLAGE_TILEINFO_H
