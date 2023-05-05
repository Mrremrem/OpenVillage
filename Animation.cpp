#include "Animation.h"
#include <SFML/Config.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Time.hpp>
#include <stdexcept>

/*
 * Sets base for animation
 * Pre: none
 * Post: Initializes base sprite for animation
 */
Animation::Animation(sf::Sprite& baseSprite, std::string name):
name(name) {
    sprite = &baseSprite;
    frameIndex = 0;
}

/*
 * Updates sprite to next frame
 * Pre: frameList.size() > 0
 * Post: none
 */
 #include <iostream>
void Animation::update() {
    std::cout << "Name: " << name 
    << "Animation: frameIndex: " << frameIndex 
    << " frameList.size(): " << frameList.size() 
    << " Sprite scale X (Should be 5): " << sprite->getScale().x 
    << " Sprite scale Y (Should be 5): " << sprite->getScale().y 
    << " Sprite rect size X: " << sprite->getTextureRect().width 
    << " Sprite rect size Y: " << sprite->getTextureRect().height 
    << std::endl;

    if (frameList.size() > 1) {
        //std::cout << "Animation: Current frameIndex: " << frameIndex << std::endl;
        Frame* currentFrame = &frameList.at(frameIndex);
        elapsed += clock.getElapsedTime();
        //std::cout << "Elapsed: " << elapsed.asSeconds() << " Duration: " << currentFrame->duration.asSeconds() << std::endl;
        if (elapsed.asSeconds() >= currentFrame->duration.asSeconds()) {
            frameIndex++;
            if (frameIndex >= frameList.size()) {
                std::cout << "Resetted frameIndex to 0" << std::endl;
                frameIndex = 0;
            }

            Frame* newFrame = &frameList.at(frameIndex);
            sprite->setTextureRect(*newFrame->area);
            elapsed -= currentFrame->duration;
            
            //std::cout << "Animation has changed!" << std::endl;
        }
    } else if (frameList.size() == 1) {
        sf::IntRect rect = *frameList.at(0).area;
        sprite->setTextureRect(*frameList.at(0).area);
        std::cout << "Animation: Running prints..." << std::endl;
        //std::cout << "Animation: Default at 0: X = " << frameList.at(0).area->left << " Y = " << frameList.at(0).area->top << " Width = " << frameList.at(0).area->width << " Height = " << frameList.at(0).area->height << std::endl;
        std::cout << "Animation: Default rect: X = " << rect.left << " Y = " << rect.top << " Width = " << rect.width << " Height = " << rect.height << std::endl;
    }

    clock.restart();
}

/*
 * Adds frame to list of frames
 * Pre: none
 * Post: Adds frame to animate
 */
void Animation::addFrame(sf::IntRect area, sf::Time duration) {
    Frame frame;
    frame.area = new sf::IntRect(area);
    frame.duration = duration;

    std::cout << "Animation: Adding frame at x = " << area.left << " y = " << area.top << " width = " << area.width << " height = " << area.height << "Sprite scale X: " << sprite->getScale().x << "Sprite scale Y: " << sprite->getScale().y << std::endl;

    frameList.push_back(frame);
    std::cout << "Animation: After adding frame: x = " << frameList.back().area->left << " y = " << frameList.back().area->top << " width = " << frameList.back().area->width << " height = " << frameList.back().area->height << "Sprite scale X: " << sprite->getScale().x << "Sprite scale Y: " << sprite->getScale().y << std::endl;
    clock.restart();
}

/*
 * Resets sprite to base sprite
 * Pre: frameList.size() > 0
 * Post: resets clock and sprite points to first frame
 */
void Animation::reset() {
    if (frameList.size() <= 0) {
        throw std::out_of_range("Could not reset animation. frameList.size() must be > 0");
    }

    sprite->setTextureRect(*frameList.at(0).area);
    frameIndex = 0;
    elapsed = sf::seconds(0);
    clock.restart();
}