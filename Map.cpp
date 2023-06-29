//
// Created by mrremrem on 7/3/22.
//

#include "Map.h"
#include "Entity.h"
<<<<<<< HEAD
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
=======

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
    for (auto entityIndex : entityList) {
        delete entityIndex.second;
        entityIndex.second = nullptr;
    }
}

/*
 * Updates tiles and entities
>>>>>>> e58c56e (Hurrah! Binary Trees!)
 * Pre: None
 * Post: None
 */
void Map::update() {
<<<<<<< HEAD
    entities.update();
    for (std::vector<Tile>* layerIndex : layerList) {
        for (Tile tileIndex : *layerIndex) {
            tileIndex.spriteSheet.update();
        }
=======
    // Updates every layer
    //std::cout << "Update runs!" << std::endl;
    for (auto entityIndex : entityList) {
        entityIndex.second->update();
>>>>>>> e58c56e (Hurrah! Binary Trees!)
    }
}

/*
<<<<<<< HEAD
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
=======
 * Renders Tiles and entities
 * Pre: layerList.size() > 0
 * Post: renders map to window
 */
void Map::render(sf::RenderWindow& window) {
    //EntityKey playerKey("Player0", 0);
    Player* redMan = static_cast<Player*>(entityList.at({"PLAYER0", 1}));
    window.setView(redMan->getView());
    
    //std::cout << "Begin of render... " << std::endl;
    for (auto entityIndex : entityList) {
        entityIndex.second->render(window);
        //std::cout << "Rendering " << entityIndex.first.ID << std::endl;
    }
    //std::cout << "End of render \n" << std::endl;

    
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
>>>>>>> e58c56e (Hurrah! Binary Trees!)
}

/*
 * Loads map data from config
 * Pre: none
 * Post: Configures map data
 */
void Map::loadMapData() {
<<<<<<< HEAD
    std::vector<Tile>* currentLayerTiles = new std::vector<Tile>;

=======
>>>>>>> e58c56e (Hurrah! Binary Trees!)
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
<<<<<<< HEAD
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
=======
            loadEntity();
>>>>>>> e58c56e (Hurrah! Binary Trees!)
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
<<<<<<< HEAD

    
    
    layerList.push_back(currentLayerTiles);
}

/*
 * Initializes tile to sprite
=======
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
        
        appendEntity(ID, currentLayer, newPlayer);
    } else { // Has to be a Tile
        Tile* newTile = new Tile(tiles.getTile(ID));
        
        int spriteDistance = spriteSize.x * spriteScale.y;
        newTile->setPosition(sf::Vector2f(posX * spriteDistance, posY * spriteDistance));
        newTile->setAnimation(animationType);

        appendEntity(ID, currentLayer, newTile);
    }
}

/*
 * Appends entity to map
 * For every entity appeneded that already exists,
 * its postfix is incremented by one.
 * Example: Tile0, Tile1, Tile2, etc.
 * Pre: none
 * Post: entityList.size() = entityList.size() + 1
 */
void Map::appendEntity(std::string& entityName, int layerNum, Entity* entity) {
    if (entityCountList.find(entityName) == entityCountList.end()) {
        entityCountList.emplace(entityName, 0);
    }

    int entityCount = entityCountList.at(entityName);
    std::string newEntityName = entityName + std::to_string(entityCount);
    EntityKey newEntityKey(newEntityName, layerNum);

    entityList.emplace(newEntityKey, entity);
    entityCountList.at(entityName) = entityCount + 1;
}

/*
 * Initializes tile position to world coords
>>>>>>> e58c56e (Hurrah! Binary Trees!)
 * Pre: 0 <= posX < worldSize.x,
 *      0 <= posY < worldSize.y
 * Post: Sets up tile's sprite
 */
<<<<<<< HEAD
void Map::initializeTile(Tile* currentTile, int posX, int posY) {
    // Tests if tile is oob
    if (outOfBounds(posX, posY)) {
        throw std::out_of_range("Tile out of range. "
=======
void Map::initEntityPos(Entity& entity, int posX, int posY) {
    // Tests if tile is oob
    if (outOfBounds(posX, posY)) {
        throw std::out_of_range("Map::initTilePos(): Precondition failed. "
        "Tile coords are out of range. "
>>>>>>> e58c56e (Hurrah! Binary Trees!)
        "x must be within 0 <= posX < worldSize.x, "
        "y must be within 0 <= posY < worldSize.y");
    }

    // Sets tile sprite based on ID
<<<<<<< HEAD
    int spriteDistance = spriteSize.x * spriteScale.x;
    currentTile->spriteSheet.getSprite()->setPosition(
        sf::Vector2f(posX * spriteDistance, posY * spriteDistance));
=======
    int spriteDistance = spriteSize.x * spriteScale.y;
    entity.setPosition(sf::Vector2f(posX * spriteDistance, posY * spriteDistance));
>>>>>>> e58c56e (Hurrah! Binary Trees!)
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