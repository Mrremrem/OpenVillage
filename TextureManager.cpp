#include "TextureManager.h"

/*
 * Loads texture config from file
 * Pre: 
 * Post: none
 */

TextureManager::TextureManager(std::string path) {
    hasConstructorRan = true;

    loadConfig(path);
}

/*
 * Removes texture references from the heap
 * Pre: none
 * Post: none
 */
TextureManager::~TextureManager() {
    for (auto textureIndex : textureList) {
        delete textureIndex.second;
        textureIndex.second = nullptr;
    }
}

/*
 * Loads texture config
 * Pre: path must be a valid text file
 * Post: maps textureList with textures
 */
void TextureManager::loadConfig(std::string path) {
    std::ifstream textureConfig(path);
    
    if (textureConfig.fail()) {
        throw std::invalid_argument("Error: Could not load texture config in TextureManager::loadConfig(). Bad file/path. Path: " + path);
    }

    while (textureConfig.good()) {
        const std::string PATH = "PATH";
        const std::string COMMENT = "#";

        std::string type;
        textureConfig >> type;
        
        if (type == PATH) {
            std::string name;
            std::string path;

            textureConfig >> name >> path;
            add(name, path);
        } else if (type == COMMENT) {
            // Stores and ignores comment
            std::string storeComment;
            std::getline(textureConfig, storeComment);
        }
    }
}

/*
 * Appends texture to list of textures
 * Pre: path must include a valid texture
 * Post: textureList.size() = textureList.size() + 1
 */

void TextureManager::add(std::string name, std::string path) {
    sf::Texture* newTexture = new sf::Texture();

    if (!newTexture->loadFromFile(path)) {
        delete newTexture;
        newTexture = nullptr;

        throw std::invalid_argument("Error: Cannot add texture "
        "to list of textures from path " + path);
    }

    textureList.emplace(name, newTexture);
}

/*
 * Gets texture from name
 * Pre: name must exist in list of textures
 *      at least one texture added (textureList.size() > 0)
 * Post: Returns texture pointer
 */
sf::Texture* TextureManager::getTexture(std::string name) {
    if (textureList.empty()) {
        throw std::out_of_range("Error: No textures were added. textureList.size() must be > 0");
    }

    if (textureList.count(name) <= 0) {
        throw std::invalid_argument("Error: Texture " + name + 
        " does not exist in added textures");
    }

    return textureList.at(name);
}