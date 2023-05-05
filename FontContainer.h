//
// Created by mrremrem on 12/14/22.
//

#ifndef OPENVILLAGE_FONTCONTAINER_H
#define OPENVILLAGE_FONTCONTAINER_H

#include <SFML/Graphics.hpp>
#include <cstring>
#include <unordered_map>

/*
 * Small font container
 * Holds font names and directories
 */
class FontContainer {
public:
    void addFont(std::string fontName, std::string fontDir); // Appends font to container
    sf::Font* getFont(std::string fontName); // Returns this font pointer from name

private:
    sf::Font currentFont;
    std::unordered_map<std::string, std::string> fontList;
};

#endif //OPENVILLAGE_FONTCONTAINER_H