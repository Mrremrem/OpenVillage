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
#include "FontContainer.h"

class DebugLog {
public:
    DebugLog();
    ~DebugLog();

    void add(std::string message);
    void setPosition(sf::Vector2f position);
    void insert(int messageIndex, std::string message);

    int numOfMessages();

    void render(sf::RenderWindow& window);
private:
    // Delete this later and add to FontContainer: const std::string FONT_DIRECTORY = "";
    sf::Text content;
    FontContainer fontList;

    std::vector<std::string> messages; // Holds debug info
    int size = 0;
    sf::Vector2f position;

    const sf::Color TEXT_COLOR = sf::Color::White;
    const int DEFAULT_CHARACTER_SIZE = 30;
    const int DEFAULT_SPACING = 30; // Enter spacing (\n ish)

    //sf::RenderWindow* window;
};


#endif //OPENVILLAGE_DEBUGLOG_H
