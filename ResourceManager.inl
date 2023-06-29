//
// Created by mrremrem on 5/23/23.
//

#ifndef RESOURCE_MANAGER_INL
#define RESOURCE_MANAGER_INL

//#include "ResourceManager.h"
#include <cstddef>
#include <stdexcept>
/*
 * Loads resource config from file
 * Pre: 
 * Post: none
 */
template <typename TGenericResource>
ResourceManager<TGenericResource>::ResourceManager(std::string& path) {
    loadConfig(path);
}

/*
 * Removes resource references from the heap
 * Pre: none
 * Post: none
 */
template <typename TGenericResource>
ResourceManager<TGenericResource>::~ResourceManager() {
    for (auto textureIndex : resourceList) {
        delete textureIndex.second;
        textureIndex.second = nullptr;
    }
}

/*
 * Loads resource config
 * Pre: path must be a valid text file
 * Post: maps resourceList with resource
 */
template <typename TGenericResource>
void ResourceManager<TGenericResource>::loadConfig(std::string& path) {
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
 * Appends resource from file to list of resources
 * Pre: path must include a valid texture
 * Post: textureList.size() = textureList.size() + 1
 */
template <typename TGenericResource>
void ResourceManager<TGenericResource>::add(std::string& name, std::string& path) {
    TGenericResource* resource = new TGenericResource;

    if (!resource->loadFromFile(path)) {
        throw std::invalid_argument("Error in ResourceManager::add(): could not add" + name
        + ". Invalid path, wrong type, or corrupted resource: " + path);
    }

    resourceList.emplace(name, resource);
}

/*
 * Gets texture from name
 * Pre: name must exist in list of resource
 *      at least one texture added (textureList.size() > 0)
 * Post: Returns texture pointer
 */
template <typename TGenericResource>
TGenericResource* ResourceManager<TGenericResource>::getResource(std::string& name) {
    if (resourceList.empty()) {
        throw std::out_of_range("Error in ResourceManager::getResource(): "
        "No resource were added. textureList.size() must be > 0");
    }

    if (resourceList.count(name) <= 0) {
        throw std::invalid_argument("Error: Texture " + name + 
        " does not exist in added resource");
    }

    return resourceList.at(name);
}

#endif // RESOURCE_MANAGER_INL