//
// Created by mrremrem on 12/19/22.
//

#ifndef OPENVILLAGE_SIGN_H
#define OPENVILLAGE_SIGN_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include "EventManager.h"
#include "Entity.h"
#include "ResourceManager.h"
#include "CollisionBox.h"
#include "SpriteSheet.h"
#include "TextBox.h"
#include "TileManager.h"
class Sign : public Entity {
public:
    Sign(ResourceManager<sf::Texture>& textures, ResourceManager<sf::Font>& fonts);

    void update();
    void render(sf::RenderWindow& window);

    void setScale(sf::Vector2f scale); // Sets sign's sprite scale
    void setAnimation(const std::string& animation); // Sets sign's sprite animation

    void setPosition(sf::Vector2f position); // Sets entity's position

    // Tests if sign is colliding with other entity
    const bool isColliding(CollisionBox& otherBox); 

    CollisionBox& getCollisionBox(); // Gets Sign's hitBox

    void toggleTextbox(); // Toggles textbox
    void setTextBoxVisiblility(bool isVisible);

    const std::string getID(); // Gets unique ID

private:
    const std::string ID = "Sign";
    const std::string SIGN_SHEET_DIR = "Assets/Media/SpriteSheets/Sign_Sheet.ini";

    SpriteSheet spriteSheet;

    TextBox textbox;

    CollisionBox hitBox;
    //int layerNum;
};

#endif // OPENVILLAGE_SIGN_H