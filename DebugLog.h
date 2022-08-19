//
// Created by mrremrem on 7/12/22.
//

#ifndef OPENVILLAGE_DEBUGLOG_H
#define OPENVILLAGE_DEBUGLOG_H

#include <SFML/Graphics.hpp>
#include <cstring>
#include <vector>
#include "Player.h"
#include "WindowManager.h"

using DebugContainer = std::vector<std::string>;

class DebugLog {
public:
    DebugLog();
    ~DebugLog();

    void add(std::string message);
    void setPosition(sf::Vector2f position);
    void insert(int messageIndex, std::string message);

    void render(sf::RenderWindow& window);
private:
    sf::Font font;
    const std::string FONT_DIRECTORY = "Assets/Fonts/Ubuntu-Regular.ttf";
    sf::Text content;

    DebugContainer messages; // Holds debug info
    sf::Vector2f position;

    const sf::Color TEXT_COLOR = sf::Color::White;
    const int DEFAULT_CHARACTER_SIZE = 30;
    const int DEFAULT_SPACING = 30; // Enter spacing (\n ish)

    sf::RenderWindow* window;
};


#endif //OPENVILLAGE_DEBUGLOG_H
