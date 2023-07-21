//
// Created by mrremrem on 7/3/22.
//

#include "Map.h"
#include "Entity.h"
#include <stdexcept>

/*
 * */
Map::Map(ResourceManager<sf::Texture>& textures, const std::string& tileInfoPath):
textures(textures),
tiles(textures, tileInfoPath) {
    // Empty, only initializes tiles
    // Add map layers with addLayer(path)
}

/*
 * Destroys all entity layers
 * Pre: None
 * Post: entityLayerList.size() = 0
 */
Map::~Map() {
    
}

/*
 * Updates tiles and entities
 * Pre: None
 * Post: None
 */
void Map::update() {
    // Updates every layer
    std::cout << "Update runs!" << std::endl;
    for (auto entityIndex : entityList) {
        entityIndex.second->update();
    }
}

/*
 * Renders Tiles and entities
 * Pre: layerList.size() > 0
 * Post: renders map to window
 */
void Map::render(sf::RenderWindow& window) {
    std::cout << "Rendering map..." << std::endl;
    
    std::cout << "Begin of render... \n" << std::endl;
    for (auto entityIndex : entityList) {
        entityIndex.second->render(window);
        std::cout << "Rendering " << entityIndex.first.getID() << " At layer: " << entityIndex.first.getLayerNum() << std::endl;
    }
    std::cout << "\nEnd of render \n" << std::endl;

    
    /*std::cout << "View X: " << redMan->getView().getCenter().x << 
    " View Y: " << redMan->getView().getCenter().y << std::endl; */
}

void Map::initializeMap(const std::string& mapPath) {
    mapFile.open(mapPath);
    if (mapFile.bad() || !mapFile.good()) {
        throw std::invalid_argument("Map::initializeMap(): Cannot add layer. "
        "Invalid map path or bad file. Path: " + mapPath);
    }

    loadMapData();
    mapFile.close();
}

/*
 * Loads map data from config
 * Pre: none
 * Post: Configures map data
 */
void Map::loadMapData() {
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
            loadEntity();
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
}

/*
 * Appends entity to entityLayerList
 * Pre: none
 * Post: entityQueue.size() = entityqueue.size() + 1
 */
void Map::loadEntity() {
    // Assigns tile ID and layer
    std::string ID;
    int currentLayer;
    mapFile >> ID >> currentLayer;

    // Initializes tile position
    int posX;
    int posY;
    mapFile >> posX >> posY;

    // Stores animation type
    std::string animationType;
    mapFile >> animationType;

    const std::string ENTITY_PLAYER = "PLAYER";
    if (ID == ENTITY_PLAYER) {
        Player* newPlayer = new Player(textures, sf::Vector2f(1920, 1080));
        
        int spriteDistance = spriteSize.x * spriteScale.y;
        newPlayer->setPosition(sf::Vector2f(posX * spriteDistance, posY * spriteDistance));
        newPlayer->setScale(spriteScale);
        newPlayer->setAnimation(animationType);
        newPlayer->getView();
        
        entityList.add(ID, currentLayer, newPlayer);
    } else { // Has to be a Tile
        Tile* newTile = new Tile(tiles.getTile(ID));
        
        int spriteDistance = spriteSize.x * spriteScale.y;
        newTile->setPosition(sf::Vector2f(posX * spriteDistance, posY * spriteDistance));
        newTile->setAnimation(animationType);

        entityList.add(ID, currentLayer, newTile);
    }
}

/*
 * Initializes tile position to world coords
 * Pre: 0 <= posX < worldSize.x,
 *      0 <= posY < worldSize.y
 * Post: Sets up tile's sprite
 */
void Map::initEntityPos(Entity& entity, int posX, int posY) {
    // Tests if tile is oob
    if (outOfBounds(posX, posY)) {
        throw std::out_of_range("Map::initTilePos(): Precondition failed. "
        "Tile coords are out of range. "
        "x must be within 0 <= posX < worldSize.x, "
        "y must be within 0 <= posY < worldSize.y");
    }

    // Sets tile sprite based on ID
    int spriteDistance = spriteSize.x * spriteScale.y;
    entity.setPosition(sf::Vector2f(posX * spriteDistance, posY * spriteDistance));
}

/*
 * Appends entity to entityList
 * Pre: none
 * Post: entityList.size() = entityList.size() + 1
 */
void Map::appendEntity(const std::string& entityName, int layerNum, Entity* entity) {
    
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