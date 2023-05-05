#include "Sign.h"
#include "Entity.h"
#include <SFML/System/Vector2.hpp>

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