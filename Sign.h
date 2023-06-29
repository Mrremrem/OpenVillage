//
// Created by mrremrem on 12/19/22.
//

#ifndef OPENVILLAGE_SIGN_H
#define OPENVILLAGE_SIGN_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include "Entity.h"
#include "CollisionBox.h"
#include "TextBox.h"
#include "TileManager.h"
class Sign : public Entity {
public:
    Sign();

    void update();
    void render(sf::RenderWindow& window);

    // For comparisons (used for sorting)
    /*bool operator<(Entity& other);
    bool operator==(Entity& other);*/

private:
    TextBox textbox;

    const std::string ID = "Sign";
    //int layerNum;
};

#endif // OPENVILLAGE_SIGN_H