//
// Created by mrremrem on 7/3/22.
//

#ifndef OPENVILLAGE_TILEINFO_H
#define OPENVILLAGE_TILEINFO_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>


class TileInfo {
public:
    TileInfo(const std::string& path);
    ~TileInfo();

    std::string getPath();

    std::string getName(int id);
    int getFrictionX(int id);
    int getFrictionY(int id);
    bool isDeadly(int id);
private:
    void setupTiles();

    std::string path;

    // Tile info (by id)
    std::vector<std::string> nameList; // List of tile names
    std::vector<std::pair<int, int> > frictionList; // x and y tile frictions
    std::vector<bool> isDeadlyList; //

    std::ifstream tilesFile; // config
    std::string tilesOrder; // stores id, name, friction, etc. line
};


#endif //OPENVILLAGE_TILEINFO_H
