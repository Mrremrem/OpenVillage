//
// Created by mrremrem on 6/30/22.
//

#ifndef OPENVILLAGE_HOMEVILLAGE_H
#define OPENVILLAGE_HOMEVILLAGE_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Map.h"
#include "TileInfo.h"
#include "Player.h"
#include "TextBox.h"

/*
 * Max blocks (at least in my screen):
 * Columns: 24
 * Rows: 15
 */


class HomeVillage {
public:
    HomeVillage(sf::Vector2u windowSize); // Initializes map
    ~HomeVillage(); // Destroys backdrop

    void update(sf::RenderWindow& window, Player& player);
    void render(sf::RenderWindow& window); // Displays tiles

    int getBlockSize();
private:
    // Common directories (change as needed)
    std::string MAP_DIRECTORY = "Assets/Media/Maps/map.txt";
    std::string TEXTURE_DIRECTORY = "Assets/Media/Textures/Tile_Textures.png";
    std::string TILE_CONFIG_DIRECTORY = "Assets/tiles_cfg.txt";

    // Sprite info
    int BLOCK_SIZE = 5;
    int SPRITE_SIZE = 16;
    const int SPRITE_DISTANCE = BLOCK_SIZE * SPRITE_SIZE;

    Map villageMap; // World map
    TileInfo tileInfo; // Tile info

    // Holds textures/sprites
    sf::Texture tileTextures;
    sf::Sprite tileSprite;

    //SpriteSheet spriteSheet; // Holds sprite info

    sf::Vector2u windowSize;

    void setTile(int id);

    TextBox textbox;
    bool isEnterPressed;

    void updateTextbox(sf::RenderWindow& window); // Updates textbox
    void updateTextboxControls(sf::RenderWindow& window); // Updates textbox from keyboard inputs
    void updateTextboxArea(sf::RenderWindow& window); // Textbox area helper function
    void updateTextboxFont();

    void setupTextbox();
};


#endif //OPENVILLAGE_HOMEVILLAGE_H
