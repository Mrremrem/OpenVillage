#include "Sign.h"
#include "CollisionBox.h"
#include "Entity.h"
#include "ResourceManager.h"
#include "SpriteSheet.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

Sign::Sign(ResourceManager<sf::Texture>& textures, ResourceManager<sf::Font>& fonts):
Entity(EntityType::Sign, EntityState::Idle),
spriteSheet(textures, SIGN_SHEET_DIR),
hitBox(spriteSheet.getSprite(), true),
textbox(fonts) {
    textbox.setVisibility(false);

    EventManager::getInstance().subscribe("DisplayTextBox", std::bind(&Sign::toggleTextbox, this));
}

void Sign::update() {
    spriteSheet.update();

    // Updates hitbox
    hitBox.update();
}

void Sign::render(sf::RenderWindow &window) {
    window.draw(spriteSheet.getSprite());
    hitBox.render(window);

    // Renders sign's textbox
    textbox.render(window);
}

/*
 * Sets sign's sprite scale
 * Pre: none
 * Post: Sets player's scale to scale
 */
void Sign::setScale(sf::Vector2f scale) {
    spriteSheet.getSprite().setScale(scale);
}

/*
 * Sets sign's sprite animation
 * Pre: none
 * Post: none
 */
void Sign::setAnimation(const std::string& animation) {
    spriteSheet.setAnimation(animation);
}

/*
 * Sets sign's position
 * Pre: none
 * Post: spriteSheet.getSprite().getPosition() == position
 */
void Sign::setPosition(sf::Vector2f position) {
    spriteSheet.getSprite().setPosition(position);
}

/*
 * Tests whether sign is colliding with an entity
 * Pre: none
 * Post: Returns true if sign is touching another entity
 */
const bool Sign::isColliding(CollisionBox& otherBox) {
    return hitBox.isColliding(otherBox);
}

/*
 * Returns sign's collision box
 * Pre: none
 * Post: Returns hitBox
 */
CollisionBox& Sign::getCollisionBox() {
    return hitBox;
}

/*
 * Toggles textbox upon toggle event
 * Pre: none
 * Post: Toggles textbox if player collides with 
 * this sign and activates event
 */
void Sign::toggleTextbox() {
    textbox.toggleVisibility();
}

/*
 * Sets textbox visibility
 * Pre: none
 * Post: Enables or disables textbox
 */
void Sign::setTextBoxVisiblility(bool isVisible) {
    textbox.setVisibility(isVisible);
}

/*
 * Returns ID
 * Pre: none
 * Post: Returns current sign ID
 */
const std::string Sign::getID() {
    return ID;
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