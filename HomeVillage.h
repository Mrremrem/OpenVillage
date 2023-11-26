//
// Created by mrremrem on 6/30/22.
//

#ifndef OPENVILLAGE_HOMEVILLAGE_H
#define OPENVILLAGE_HOMEVILLAGE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <vector>
#include "DebugLog.h"
#include "ResourceManager.h"
#include "EventManager.h"
#include "Map.h"
#include "TileManager.h"
#include "Player.h"
#include "TextBox.h"

/*
 * Max blocks (at least in my screen):
 * Columns: 24
 * Rows: 15
 */

/*
 * To do: write comments for HomeVillage
 */
class HomeVillage {
public:
    // Initializes HomeVillage map
    HomeVillage(ResourceManager<sf::Texture>& textures, 
        ResourceManager<sf::Font>& fonts, 
        std::vector<sf::View>& playerViewsList);

    void handleInput();
    void update(sf::RenderWindow& window);
    void render(sf::RenderWindow& window); // Displays tiles


    int getBlockSize();
private:
    // Common directories (change as needed)
    const std::string WORLD_MAP_DIR = "Assets/Media/Maps/BaseLevel_HomeVillage.ini";
    const std::string TILE_CONFIG_DIR = "Assets/tiles_cfg.ini";

    // Sprite info
    int BLOCK_SIZE = 5;
    int SPRITE_SIZE = 16;
    const int SPRITE_DISTANCE = BLOCK_SIZE * SPRITE_SIZE;

    std::vector<sf::View>& playerViewsList;

    Map worldMap; // World map

    //SpriteSheet spriteSheet; // Holds sprite info

    //Player redMan;

    DebugLog viewDebugLog;

    void updatePlayerViews(sf::RenderWindow& window); // Updates all player views

    void updatePlayerCollisions(); // Updates collisions from signs
    
    /*TextBox textbox;

    void updateTextbox(sf::RenderWindow& window); // Updates textbox
    void updateTextboxControls(sf::RenderWindow& window); // Updates textbox from keyboard inputs
    void updateTextboxArea(sf::RenderWindow& window); // Textbox area helper function

    void setupTextbox();*/
};


#endif //OPENVILLAGE_HOMEVILLAGE_H
