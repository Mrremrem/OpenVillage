//
// Created by mrremrem on 7/3/22.
//

#include "Map.h"
#include "Entity.h"
#include "TextureManager.h"
#include <SFML/Graphics/Texture.hpp>
#include <vector>

/*
 * */
Map::Map(TextureManager* textures, const std::string& tileInfoPath):
tileInfo(textures, tileInfoPath) {
    // Empty, only initializes tileInfo
    // Add map layers with addLayer(path)
    
}

/*
 * Destroys all layers
 * Pre: None
 * Post: Removes layers from heap
 */
Map::~Map() {
    for (std::vector<Tile>* layerIndex : layerList) {
        delete layerIndex;
        layerIndex = nullptr;
    }
}

/* 
 * Adds layer to render buffer
 * Pre: mapPath must be a valid text file
 * Post: layerList.size() = layerList.size() + 1
 */
void Map::addLayer(const std::string& mapPath) {
    mapFile.open(mapPath);
    if (mapFile.bad() || !mapFile.good()) {
        throw std::invalid_argument("Cannot add layer. Invalid map path or bad file.");
    }

    loadMapData();
    mapFile.close();
}

/*
 * Updates entities
 * Pre: None
 * Post: None
 */
void Map::update() {
    entities.update();
    for (std::vector<Tile>* layerIndex : layerList) {
        for (Tile tileIndex : *layerIndex) {
            tileIndex.spriteSheet.update();
        }
    }
}

/*
 * Renders each map layer
 * Pre: layerList.size() > 0
 * Post: renders map to window
 */
void Map::render(sf::RenderWindow &window) {
    // Tests precondition
    if (layerList.size() <= 0) {
        throw std::out_of_range("Error: could not render map. "
                            "layerList.size must be > 0 (did you add a layer?)");
    }

    for (std::vector<Tile>* layerIndex : layerList) {
        for (Tile tileIndex : *layerIndex) {
            window.draw(*tileIndex.spriteSheet.getSprite());
        }
    }

    entities.render(window);
}

/*
 * Loads map data from config
 * Pre: none
 * Post: Configures map data
 */
void Map::loadMapData() {
    std::vector<Tile>* currentLayerTiles = new std::vector<Tile>;

    while (mapFile.good()) {
        // Retrieves current type
        std::string type;
        mapFile >> type;

        // All types
        const std::string WORLD_SIZE = "WORLD_SIZE";
        const std::string SPRITE_SIZE = "SPRITE_SIZE";
        const std::string SPRITE_SCALE = "SPRITE_SCALE";
        const std::string TILE = "TILE";
        const std::string ENTITY = "ENTITY";
        const std::string COMMENT = "#";

        if (type == TILE || type == ENTITY) {
            // Assigns tile ID
            int id;
            mapFile >> id;

            // Retrieves tile position
            int posX;
            int posY;
            mapFile >> posX >> posY;

            // Forms and stores tile to current layer
            Tile currentTile = tileInfo.getTile(id);
            initializeTile(&currentTile, posX, posY);
            currentLayerTiles->push_back(currentTile);

            // Stores current tile to entity (if type == ENTITY)
            if (type == ENTITY) {
                const int SIGN_ID = 12;
                if (id == SIGN_ID) {
                    Entity* entity = new Sign(&currentLayerTiles->back());
                    entities.add(entity);
                }
            }
        } else if (type == COMMENT) {
            // Stores and ignores comment
            std::string storeComment;
            std::getline(mapFile, storeComment);
        } else if (type == WORLD_SIZE) {
            mapFile >> worldSize.x >> worldSize.y; // WORLD_SIZE
        } else if (type == SPRITE_SIZE) {
            mapFile >> spriteSize.x >> spriteSize.y; // SPRITE_SIZE
        } else if (type == SPRITE_SCALE) {
            mapFile >> spriteScale.x >> spriteScale.y; // SPRITE_SCALE
        }
    }

    
    
    layerList.push_back(currentLayerTiles);
}

/*
 * Initializes tile to sprite
 * Pre: 0 <= posX < worldSize.x,
 *      0 <= posY < worldSize.y
 * Post: Sets up tile's sprite
 */
void Map::initializeTile(Tile* currentTile, int posX, int posY) {
    // Tests if tile is oob
    if (outOfBounds(posX, posY)) {
        throw std::out_of_range("Tile out of range. "
        "x must be within 0 <= posX < worldSize.x, "
        "y must be within 0 <= posY < worldSize.y");
    }

    // Sets tile sprite based on ID
    int spriteDistance = spriteSize.x * spriteScale.x;
    currentTile->spriteSheet.getSprite()->setPosition(
        sf::Vector2f(posX * spriteDistance, posY * spriteDistance));
}

/*
 * Tests if position exceeds world bounds
 * Pre: none
 * Post: Tests if:
 *          0 <= posX < worldSize.x
 *          0 <= posY < worldSize.y
 */
bool Map::outOfBounds(int posX, int posY) {
    return posX < 0 || posX >= worldSize.x || posY < 0 || posY >= worldSize.y;
}