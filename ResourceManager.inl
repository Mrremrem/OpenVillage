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
ResourceManager<TGenericResource>::ResourceManager(const std::string& path) {
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
void ResourceManager<TGenericResource>::loadConfig(const std::string& path) {
    std::ifstream resourceConfig(path);
    
    if (resourceConfig.fail()) {
        throw std::invalid_argument("Error: Could not load texture config in "
        "ResourceManager::loadConfig(). Bad file/path. Path provided: " + path);
    }

    while (resourceConfig.good()) {
        const std::string PATH = "PATH";
        const std::string COMMENT = "#";

        std::string type;
        resourceConfig >> type;
        
        if (type == PATH) {
            std::string name;
            std::string path;

            resourceConfig >> name >> path;
            add(name, path);
        } else if (type == COMMENT) {
            // Stores and ignores comment
            std::string storeComment;
            std::getline(resourceConfig, storeComment);
        }
    }
}

/*
 * Appends resource from file to list of resources
 * Pre: path must include a valid resource
 * Post: resourceList.size() = resourceList.size() + 1
 */
template <typename TGenericResource>
void ResourceManager<TGenericResource>::add(const std::string& name, const std::string& path) {
    TGenericResource* resource = new TGenericResource;

    if (!resource->loadFromFile(path)) {
        throw std::invalid_argument("Error in ResourceManager::add(): could not add" + name
        + ". Invalid path, wrong type, or corrupted resource. Path provided: " + path);
    }

    resourceList.emplace(name, resource);
}

/*
 * Gets resource from name
 * Pre: name must exist in list of resource
 *      at least one resource added (resourceList.size() > 0)
 * Post: Returns resource pointer
 */
template <typename TGenericResource>
TGenericResource* ResourceManager<TGenericResource>::getResource(const std::string& name) {
    if (resourceList.empty()) {
        throw std::out_of_range("Error in ResourceManager::getResource(): "
        "No resource were added. resourceList.size() must be > 0");
    }

    if (resourceList.count(name) <= 0) {
        throw std::invalid_argument("Error: Resource " + name + 
        " does not exist in added resources");
    }

    
    return resourceList.at(name);
}

#endif // RESOURCE_MANAGER_INL