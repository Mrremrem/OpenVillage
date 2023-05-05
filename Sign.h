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
#include "TileInfo.h"
class Sign : public Entity {
public:
    Sign(Tile* tile);

    void update();
    void render(sf::RenderWindow& window);

private:
    TextBox textbox;

    Tile* tile;

    const int ID = 12;
};

#endif // OPENVILLAGE_SIGN_H