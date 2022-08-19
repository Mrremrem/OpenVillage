//
// Created by mrremrem on 7/12/22.
//

#include "DebugLog.h"

DebugLog::DebugLog():
        window(window) {
    if (!font.loadFromFile(FONT_DIRECTORY)){
        std::runtime_error("Error. Could not find font Ubuntu-Regular.ttf");
    }

    content.setFont(font);
    content.setFillColor(TEXT_COLOR);
}

DebugLog::~DebugLog() {
    // Empty
}

void DebugLog::add(std::string message) {
    messages.push_back(message);
}

void DebugLog::insert(int messageIndex, std::string message) {
    messages.at(messageIndex) = message;
}

void DebugLog::setPosition(sf::Vector2f position) {
    this->position = position;
}

void DebugLog::render(sf::RenderWindow& window){
    for (int messageIndex = 0; messageIndex < messages.size(); messageIndex++){
        content.setString(messages.at(messageIndex));

        content.setPosition(position.x, position.y + DEFAULT_SPACING * messageIndex);
        content.setCharacterSize(DEFAULT_CHARACTER_SIZE);
        window.draw(content);
    }
}