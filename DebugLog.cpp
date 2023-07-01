//
// Created by mrremrem on 7/12/22.
//

#include "DebugLog.h"
#include "ResourceManager.h"

DebugLog::DebugLog(ResourceManager<sf::Font>& fonts):
fonts(fonts) {

    sf::Font* currentFont = fonts.getResource("Ubuntu_Font");
    content.setFont(*currentFont);
    content.setFillColor(TEXT_COLOR);
}

DebugLog::~DebugLog() {
    // Empty
}

void DebugLog::add(std::string message) {
    messages.push_back(message);
    size++;
}

/*
 * Inserts debug message in container
 * Pre: messageIndex <= numOfMessages()
 * Post: numOfMessages() = numOfMessages + 1
 */
void DebugLog::insert(int messageIndex, std::string message) {
    if (messageIndex > numOfMessages()) {
        throw std::invalid_argument("DebugLog: Invalid messageIndex. "
        "messageIndex must be < numOfMessages()");
    } else if (messageIndex == numOfMessages()) {
        add(message);
    } else {
        messages.at(messageIndex) = message;
    }
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

int DebugLog::numOfMessages() {
    return size;
} 