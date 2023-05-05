#include "FontContainer.h"

/*
 * Gets font from name
 * Pre: fontName != "" (empty string)
 *      dir != "" (empty string)
 *      dir must be a font directory
 * Post: fonts.size() = fonts.size() + 1
 */
void FontContainer::addFont(std::string fontName, std::string dir) {
    // Tests preconditions
    if (fontName == "" || dir == "") {
        throw std::invalid_argument("Error: fontName must not be empty!");
    }

    fontList.emplace(fontName, dir);
}

/*
 * Returns font from list
 * Pre: fontName != "" (empty string)
 * Post: Returns font */
sf::Font* FontContainer::getFont(std::string fontName) {
    // Tests precondition
    if (fontName == "") {
        throw std::invalid_argument("Error: fontName must not be empty!");
    }

    // Self reminder: method loads font too ;P
    if (!currentFont.loadFromFile(fontList.at(fontName))) {
        throw std::invalid_argument("Error: Unknown font " + fontName + " (font not added?)");
    }

    return &currentFont;
}