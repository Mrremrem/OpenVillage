//
// Created by mrremrem on 12/17/22.
//

#ifndef OPENVILLAGE_HEALTHBAR_H
#define OPENVILLAGE_HEALTHBAR_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class HealthBar {
public:
    HealthBar();
    HealthBar(int bars); // Initializes health bar

    void render(sf::RenderWindow& window);

    
    int getNumOfBars();
private:
    int numOfBars;
    sf::Texture heartTexture;
    sf::Sprite sprite;
};

#endif // OPENVILLAGE_HEALTHBAR_H