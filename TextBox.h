//
// Created by mrremrem on 7/14/22.
//

#ifndef OPENVILLAGE_TEXTBOX_H
#define OPENVILLAGE_TEXTBOX_H

#include <SFML/Graphics.hpp>
#include <cstring>
#include <vector>
#include "ResourceManager.h"

class TextBox {
public:
    TextBox(ResourceManager<sf::Font>& fonts);
    TextBox(sf::Vector2f position, sf::Vector2f scale);
    ~TextBox();

    void update(); // Updates position, colors, text, etc.
    void render(sf::RenderWindow& window); // Displays textbox


    void addText(std::string text); // Adds text to textbox
    void addPage(std::string text); // Adds text to new page

    void addFont(std::string name, std::string directory); // Adds font to list of fonts
    void setFont(std::string name); // Sets font from list of fonts

    void next(); // Next paragraph;
    void previous(); // Previous paragraph

    void setPageNumber(int pageIndex); // Sets current page number
    void setBackdropColor(sf::Color color); // Sets textbox color
    void setOutlineColor(sf::Color color); // Sets color around box
    void setPosition(sf::Vector2f position); // Sets textbox position
    void setSize(sf::Vector2f area); // Sets textbox area
    void setOutlineThickness(float thickness); // Sets outline girth
    void setVisibility(bool isVisible);

    void toggleVisibility(); // Toggles if textbox gets updated

    int getPageNumber();
    std::string getFont();
    sf::Vector2f getPosition(); // Gets textbox topleft position
    sf::Vector2f getSize(); // Gets textbox area in world coords

private:
    // Font containers
    ResourceManager<sf::Font>& fonts;
    sf::Text content;
    sf::Color fontColor;

    // Textbox shape
    sf::RectangleShape backdrop;

    // Textbox details
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color backdropColor;
    sf::Color outlineColor;
    float outlineThickness; // Outline girth

    // Text config
    const int DEFAULT_CHARACTER_SIZE = 50;
    int numOfLines = 0; // Number of lines from text
    int numOfTextDisplayed = 0;

    // Page containers
    std::vector<std::string> pages;
    int numOfPages = 0; // Number of pages to go through
    int currentPage = 0; // Current page (every four lines)

    bool isVisible; // If textbox is visible

    void updateBackdrop(); // Updates size, colors, etc.
    void updateText(); // Updates position, color, etc.

    int getMaxCharsPerLine(); // Gets max characters that fit in textbox
    int getMaxLinesPerPage(); // Gets max lines that fit in textbox

    // Newlines text (adds \n's, I'm using newline as a verb)
    void newlineText(std::string& text); // Adds lines based on text length
    void addPages(std::string& text, int totalPages); // Adds pages based on text length
};


#endif //OPENVILLAGE_TEXTBOX_H
