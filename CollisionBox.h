//
// Created by mrremrem on 7/16/22.
//

#ifndef OPENVILLAGE_COLLISIONBOX_H
#define OPENVILLAGE_COLLISIONBOX_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Transformable.hpp>
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
    CollisionBox(sf::Transformable& referenceTexture);

    // Draws red outline on collision box if debug == true
    CollisionBox(sf::Transformable& referenceTexture, bool debug); 

    void update();
    void render(sf::RenderWindow& window);


    bool isColliding(const CollisionBox& otherBox);
    void setPosition(sf::Vector2f pos);
private:
    sf::RectangleShape box;
    sf::Transformable& referenceTexture; // A reference to 
    bool debug;
    const float OUTLINE_THICKNESS = .5f;
};


#endif // OPENVILLAGE_COLLISIONBOX_H