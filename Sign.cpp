#include "Sign.h"
#include "Entity.h"
#include "ResourceManager.h"
#include <SFML/System/Vector2.hpp>

Sign::Sign(ResourceManager<sf::Font>& fonts):
Entity(EntityType::Base, EntityState::Idle),
textbox(fonts) {
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