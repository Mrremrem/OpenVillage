//
// Created by mrremrem on 7/2/22.
//

#ifndef OPENVILLAGE_GAMEMANAGER_H
#define OPENVILLAGE_GAMEMANAGER_H

#include "WindowManager.h"
#include "ResourceManager.h"
#include "HomeVillage.h"
#include "Player.h"
#include "TextBox.h"
#include "DebugLog.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>

/*
 * To do: Write comments for GameManager
 */
class GameManager {
public:
    GameManager();
    ~GameManager();

    void handleInput();
    void update();
    void render();

    sf::Time getElapsedTime();
    void restartClock();

    WindowManager* getWindow();
private:
    // Initializes window
    const sf::Vector2u WINDOW_SIZE = sf::Vector2u(1920, 1080);
    WindowManager window;

    // Loads up textures
    const std::string TEXTURE_CONFIG_DIR = "Assets/textures_cfg.ini";
    ResourceManager<sf::Texture> textures;

    // Loads up fonts
    const std::string FONT_CONFIG_DIR = "Assets/fonts_cfg.ini";
    ResourceManager<sf::Font> fonts;

    sf::Clock clock;
    sf::Time elapsedTime;
    const int MAX_FPS = 60;

    std::vector<sf::View> playerViewsList;

    HomeVillage homeVillage;

    const int DEFAULT_PLAYER_SPEED = 3;
    const int DEFAULT_PLAYER_SCALE = 5;

    //sf::Vector2f CAMERA_SIZE = sf::Vector2f(1920, 1080);
    //DebugLog playerDebug;

    

    /*void updateTextbox(); // Updates textbox

    void updatePlayerDebug();
    void updateTextboxDebug();*/
};


#endif //OPENVILLAGE_GAMEMANAGER_H
