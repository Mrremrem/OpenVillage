//
// Created by mrremrem on 12/25/22.
//

#ifndef OPENVILLAGE_TEXTUREMANAGER_H
#define OPENVILLAGE_TEXTUREMANAGER_H

#include <SFML/Graphics/Texture.hpp>
#include <unordered_map>
#include <fstream>
#include <stdexcept>

class TextureManager {
public:
    TextureManager(std::string configPath);
    ~TextureManager();

    void loadConfig(std::string configPath);

    void add(std::string name, std::string texturePath);
    sf::Texture* getTexture(std::string textureName);
private:
    std::unordered_map<std::string, sf::Texture*> textureList;

    bool hasConstructorRan = false;
};

#endif // OPENVILLAGE_TEXTUREMANAGER_H 