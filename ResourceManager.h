//
// Created by mrremrem on 5/23/23. (Yes I made this a year later. 
// It proved to be a necessity after I wanted to add in both 
// Textures and Fonts in a single container without having to
// write managers for each type.
//

#ifndef OPENVILLAGE_RESOURCEMANAGER_H
#define OPENVILLAGE_RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <fstream>
#include <stdexcept>
#include <string>

/*
 * Manages resources by holding resource paths and their 
 * names. The derived class will have their own load(name)
 * function that will retrieve the path and load the resource 
 * TGenericResource is a generic type for a resource such as
 * sf::Texture, sf::Font, etc.
 * More types will be supported in the future--I believe that
 * sf::SoundBuffer doesn't have a loadFromFile() function and
 * that (might) make things iffy
*/
template<typename TGenericResource>
class ResourceManager {
public:
    ResourceManager(const std::string& configPath);
    ~ResourceManager();

    void loadConfig(const std::string& configPath);

    void add(const std::string& id, const std::string& texturePath);
    TGenericResource* getResource(const std::string& id);
private:
    std::unordered_map<std::string, TGenericResource*> resourceList;
};

#include "ResourceManager.inl"
#endif // OPENVILLAGE_RESOURCEMANAGER_H 