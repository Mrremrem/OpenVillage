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
<<<<<<< HEAD
#include "TextureManager.h"
#include "Animation.h"

class SpriteSheet {
public:
    SpriteSheet(TextureManager* textures, const std::string& sheetPath);
    //SpriteSheet(const SpriteSheet& other); // Copy constructor
=======
#include "ResourceManager.h"
#include "Animation.h"
#include <iostream>

/*
 * Creates an arbitrary spritesheet for
 * an individual sprite and handles animations
 */
class SpriteSheet {
public:
    SpriteSheet(ResourceManager<sf::Texture>& textures, const std::string& sheetPath);
    SpriteSheet(const SpriteSheet& other); // Copy constructor
>>>>>>> e58c56e (Hurrah! Binary Trees!)

    void update();
    void render(sf::RenderWindow& window);


    void setAnimation(const std::string& animation);
<<<<<<< HEAD
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
    
=======
    Animation* getAnimation(const std::string& animationName);
    std::string getName();

    sf::Sprite& getSprite();
private:
    ResourceManager<sf::Texture>& textures;

    void loadSheet(const std::string& sheetPath);
    void addAnimation(std::ifstream& spriteFile);

    std::unordered_map<std::string, Animation> animationList;

    // Sprite info
    sf::Sprite sprite;
    std::string name;
    std::string currentAnimation;
    sf::Vector2i size;
    sf::Vector2f scale;
>>>>>>> e58c56e (Hurrah! Binary Trees!)
};

#endif // OPENVILLAGE_SPRITESHEET_H