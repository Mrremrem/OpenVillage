//
// Created by mrremrem on 7/12/22.
//

#ifndef OPENVILLAGE_DEBUGLOG_H
#define OPENVILLAGE_DEBUGLOG_H

#include <SFML/Graphics.hpp>
#include <cstring>
#include <vector>
#include "ResourceManager.h"
#include "Player.h"
#include "WindowManager.h"

class DebugLog {
public:
    DebugLog(ResourceManager<sf::Font>& fonts);
    ~DebugLog();

    void add(std::string message);
    void setPosition(sf::Vector2f position);
    void insert(int messageIndex, std::string message);

    int numOfMessages();

    void render(sf::RenderWindow& window);
private:
    ResourceManager<sf::Font>& fonts;
    sf::Text content;

    std::vector<std::string> messages; // Holds debug info
    int size = 0;
    sf::Vector2f position;

    const sf::Color TEXT_COLOR = sf::Color::White;
    const int DEFAULT_CHARACTER_SIZE = 30;
    const int DEFAULT_SPACING = 30; // Enter spacing (\n ish)

    //sf::RenderWindow* window;
};


#endif //OPENVILLAGE_DEBUGLOG_H
