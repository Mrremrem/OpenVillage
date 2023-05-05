#include "CollisionBox.h"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

CollisionBox::CollisionBox() {
    CollisionBox(false);
}

CollisionBox::CollisionBox(bool debug): 
debug(debug) {
    box.setFillColor(sf::Color::Transparent);

    if (debug) {
        box.setOutlineColor(sf::Color::Red);
        box.setOutlineThickness(OUTLINE_THICKNESS);
    }
}

/*
 * Tests if this box collides with other box
 * Pre: none
 * Post: Returns true if this box collides
 * with other box
 */
bool CollisionBox::isColliding(CollisionBox& other) {
    return box.getTextureRect().intersects(other.box.getTextureRect());
}

void CollisionBox::update(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f scale) {
    //box.setFillColor(sf::Color::Red);
    //box.setTextureRect(sf::IntRect(0, 0, 16, 16));

    box.setPosition(pos);
    box.setSize(size);
    box.setScale(scale);
}

void CollisionBox::render(sf::RenderWindow& window) {
    window.draw(box);
}