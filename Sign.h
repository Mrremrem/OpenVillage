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
<<<<<<< HEAD
#include "TileInfo.h"
class Sign : public Entity {
public:
    Sign(Tile* tile);
=======
#include "TileManager.h"
class Sign : public Entity {
public:
    Sign();
>>>>>>> e58c56e (Hurrah! Binary Trees!)

    void update();
    void render(sf::RenderWindow& window);

<<<<<<< HEAD
private:
    TextBox textbox;

    Tile* tile;

    const int ID = 12;
=======
    // For comparisons (used for sorting)
    /*bool operator<(Entity& other);
    bool operator==(Entity& other);*/

private:
    TextBox textbox;

    const std::string ID = "Sign";
    //int layerNum;
>>>>>>> e58c56e (Hurrah! Binary Trees!)
};

#endif // OPENVILLAGE_SIGN_H