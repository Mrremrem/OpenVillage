//
// Created by mrremrem on 7/3/22.
//

#ifndef OPENVILLAGE_MAP_H
#define OPENVILLAGE_MAP_H

#include <string>
#include <vector>
#include <fstream>

class Map {
public:
    Map(std::string path);
    ~Map();

    std::string getName();
    std::string getPath();
    int getLength();
    int getHeight();

    int getTileAt(int row, int col); // Gets tile info

private:
    void setupMap();

    // Map information
    std::string name;
    std::string path;

    // Map size
    int length;
    int height;

    std::vector<std::vector<int> > tiles; // Holds tiles (id's)

    std::ifstream mapFile;
};


#endif //OPENVILLAGE_MAP_H
