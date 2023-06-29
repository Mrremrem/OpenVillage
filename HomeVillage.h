//
// Created by mrremrem on 6/30/22.
//

#ifndef OPENVILLAGE_HOMEVILLAGE_H
#define OPENVILLAGE_HOMEVILLAGE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
<<<<<<< HEAD
#include <SFML/System/Vector2.hpp>
#include <string>
#include "TextureManager.h"
#include "Map.h"
#include "TileInfo.h"
=======
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include "DebugLog.h"
#include "ResourceManager.h"
#include "Map.h"
#include "TileManager.h"
>>>>>>> e58c56e (Hurrah! Binary Trees!)
#include "Player.h"
#include "TextBox.h"

/*
 * Max blocks (at least in my screen):
 * Columns: 24
 * Rows: 15
 */


class HomeVillage {
public:
<<<<<<< HEAD
    HomeVillage(TextureManager* textures, sf::Vector2u windowSize); // Initializes map
    ~HomeVillage(); // Destroys backdrop

    void update(sf::RenderWindow& window, Player& player);
=======
    HomeVillage(ResourceManager<sf::Texture>& textures, const sf::Vector2f& windowSize); // Initializes map
    ~HomeVillage(); // Destroys backdrop

    void handleInput();
    void update(sf::RenderWindow& window);
>>>>>>> e58c56e (Hurrah! Binary Trees!)
    void render(sf::RenderWindow& window); // Displays tiles


    int getBlockSize();
private:
    // Common directories (change as needed)
<<<<<<< HEAD
    const std::string WORLD_MAP_DIR = "Assets/Media/Maps/base_world_v2.txt";
    const std::string TILE_CONFIG_DIR = "Assets/tiles_cfg.txt";
=======
    const std::string WORLD_MAP_DIR = "Assets/Media/Maps/BaseLevel_HomeVillage.ini";
    const std::string TILE_CONFIG_DIR = "Assets/tiles_cfg.ini";
>>>>>>> e58c56e (Hurrah! Binary Trees!)

    // Sprite info
    int BLOCK_SIZE = 5;
    int SPRITE_SIZE = 16;
    const int SPRITE_DISTANCE = BLOCK_SIZE * SPRITE_SIZE;

    Map worldMap; // World map

    //SpriteSheet spriteSheet; // Holds sprite info

<<<<<<< HEAD
    sf::Vector2u windowSize;
    
    TextBox textbox;
    bool isEnterPressed;
=======
    sf::Vector2f windowSize;

    //Player redMan;

    DebugLog viewDebugLog;
    
    /*TextBox textbox;
>>>>>>> e58c56e (Hurrah! Binary Trees!)

    void updateTextbox(sf::RenderWindow& window); // Updates textbox
    void updateTextboxControls(sf::RenderWindow& window); // Updates textbox from keyboard inputs
    void updateTextboxArea(sf::RenderWindow& window); // Textbox area helper function

<<<<<<< HEAD
    void setupTextbox();
=======
    void setupTextbox();*/
>>>>>>> e58c56e (Hurrah! Binary Trees!)
};


#endif //OPENVILLAGE_HOMEVILLAGE_H
