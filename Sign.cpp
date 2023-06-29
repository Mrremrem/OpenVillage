#include "Sign.h"
#include "Entity.h"
#include <SFML/System/Vector2.hpp>

<<<<<<< HEAD
Sign::Sign(Tile* tile):
Entity(ID, EntityType::Base, EntityState::Idle),
tile(tile) {
    // Empty
    position = tile->spriteSheet.getSprite()->getPosition();
}

void Sign::update() {
    position.x += 1;
    //setPosition(pos);
    //tile->sprite.scale(100, 100);
    tile->spriteSheet.getSprite()->setPosition(position);
}

void Sign::render(sf::RenderWindow &window) {
    //std::cout << "Sign render runs!" << std::endl; 
    
    //window.draw(tile->sprite);
    //std::cout << "Sign render finished!" << std::endl;
}
=======
Sign::Sign():
Entity(EntityType::Base, EntityState::Idle) {
    // Empty
}

void Sign::update() {
    // Empty for now
}

void Sign::render(sf::RenderWindow &window) {
    // Empty
}

/*
 * Tests if this entity is less than other entity
 * Pre: none
 * Post: Returns true if this entity is less than
 * other entity
 */
/*bool Sign::operator<(Entity& other) {
    if (layerNum != other.getLayerNum()) {
        return layerNum < other.getLayerNum();
    }

    return ID < other.getID();
}*/

/*
 * Tests if this entity is less than other entity
 * Pre: none
 * Post: Returns true if this entity is less than
 * other entity
 */
/*bool Sign::operator==(Entity& other) {
    return layerNum == other.getLayerNum() && ID == other.getID();
}*/
>>>>>>> e58c56e (Hurrah! Binary Trees!)
