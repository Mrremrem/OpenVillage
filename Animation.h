//
// Created by mrremrem on 12/24/22.
//

#ifndef OPENVILLAGE_ANIMATION_H
#define OPENVILLAGE_ANIMATION_H

#include <vector>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <string>
struct Frame {
    sf::IntRect* area;
    sf::Time duration;
};

class Animation {
public:
    Animation(sf::Sprite& baseSprite, std::string name);

    void update();


    void addFrame(sf::IntRect area, sf::Time duration);

    void reset();
private:
    std::vector<Frame> frameList;
    int frameIndex;
    
    sf::Clock clock;
    sf::Time elapsed;

    sf::Sprite* sprite;

    std::string name;
};

#endif // OPENVILLAGE_ANIMATION_H