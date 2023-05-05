//
// Created by mrremrem on 7/16/22.
//

#ifndef OPENVILLAGE_COLLISIONBOX_H
#define OPENVILLAGE_COLLISIONBOX_H

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

/*
 * Creates collision box
 * Used by entities with collision detection
 * Takes in rectangles for now
 * (Might use polymorphism in the future for
 * more shapes, depends)
 */
class CollisionBox {
public:
    // Makes collision box
    CollisionBox();

    // Draws red outline on collision box if debug == true
    CollisionBox(bool debug); 

    void update(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f scale);
    void render(sf::RenderWindow& window);


    bool isColliding(CollisionBox& otherBox);
    void setPosition(sf::Vector2f pos);
private:
    sf::RectangleShape box;
    bool debug;
    const float OUTLINE_THICKNESS = .5f;
};


#endif // OPENVILLAGE_COLLISIONBOX_H