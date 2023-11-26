#include "CollisionBox.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

/*
 * Takes in a reference texture
 * The reference texture is so that the
 * collision box can follow the texture for
 * the rest of its lifetime
 */
CollisionBox::CollisionBox(sf::Transformable& referenceTexture):
referenceTexture(referenceTexture) {
    CollisionBox(referenceTexture, false);
}

/*
 * Explicitely sets debug mode
 * Takes in a reference texture
 * The reference texture is so that the
 * collision box can follow the texture for
 * the rest of its lifetime
 */
CollisionBox::CollisionBox(sf::Transformable& referenceTexture, bool debug):
referenceTexture(referenceTexture),
debug(debug) {
    box.setFillColor(sf::Color::Magenta);

    if (debug) {
        box.setOutlineColor(sf::Color::Red);
        box.setOutlineThickness(OUTLINE_THICKNESS);
    }
}

/*
 * Updates collision box
 * Pre: none
 * Post: none
 */
void CollisionBox::update() {
    if (debug) {
        box.setFillColor(sf::Color(0, 0, 0, 0));
        box.setOutlineColor(sf::Color::Magenta);

        const int TEMP_SIZE = 16;
        box.setSize(sf::Vector2f(TEMP_SIZE, TEMP_SIZE));
        box.setOutlineThickness(1);
    }

    box.setPosition(referenceTexture.getPosition());
    box.setScale(referenceTexture.getScale());
}

/*
 * Renders collision box
 * Pre: none
 * Post: displays collision box on screen (if in debug mode)
 */
void CollisionBox::render(sf::RenderWindow& window) {
    window.draw(box);
}

/*
 * Tests if this box collides with other box
 * Pre: none
 * Post: Returns true if this box collides
 * with other box
 */
bool CollisionBox::isColliding(const CollisionBox& other) {
    sf::FloatRect thisBounds = box.getGlobalBounds();
    sf::FloatRect otherBounds = other.box.getGlobalBounds();
    
    return thisBounds.intersects(otherBounds);
}