//
// Created by mrremrem on 7/2/22.
//

#ifndef OPENVILLAGE_GAMEMANAGER_H
#define OPENVILLAGE_GAMEMANAGER_H

#include "WindowManager.h"
#include "HomeVillage.h"
#include "Player.h"
#include "TextBox.h"
#include "DebugLog.h"

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
    WindowManager window;
    sf::Clock clock;
    sf::Time elapsedTime;
    const int MAX_FPS = 60;
    sf::Vector2u WINDOW_SIZE = sf::Vector2u(1920, 1080); // can't be const

    Player redMan;
    const int DEFAULT_PLAYER_SPEED = 3;
    const int DEFAULT_PLAYER_SCALE = 5;

    HomeVillage homeVillage;
    DebugLog playerDebug;

    void updateTextbox(); // Updates textbox

    void updatePlayerDebug();
    void updateTextboxDebug();
};


#endif //OPENVILLAGE_GAMEMANAGER_H
