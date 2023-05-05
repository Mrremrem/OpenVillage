//
// Created by mrremrem on 12/24/22.
//

#ifndef OPENVILLAGE_SPRITESHEET_H
#define OPENVILLAGE_SPRITESHEET_H

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <stdexcept>
#include "TextureManager.h"
#include "Animation.h"

class SpriteSheet {
public:
    SpriteSheet(TextureManager* textures, const std::string& sheetPath);
    //SpriteSheet(const SpriteSheet& other); // Copy constructor

    void update();
    void render(sf::RenderWindow& window);


    void setAnimation(const std::string& animation);
    sf::Sprite* getSprite();
private:
    TextureManager* textures;

    void loadSheet(std::string sheetPath);
    void addAnimation(std::ifstream& spriteFile);

    std::unordered_map<std::string, Animation> animationList;
    std::string currentAnimation;

    // Sprite info
    sf::Sprite sprite;
    sf::Vector2i size;
    sf::Vector2f scale;
    
};

#endif // OPENVILLAGE_SPRITESHEET_H