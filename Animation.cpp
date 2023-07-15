#include "Animation.h"

/*
 * Sets base for animation
 * Pre: none
 * Post: Initializes base sprite for animation
 */
 #include <iostream>
#include <stdexcept>
Animation::Animation(sf::Sprite& baseSprite, std::string& animationName, std::string& spriteName):
animationName(animationName),
spriteName(spriteName),
sprite(&baseSprite) {
    frameIndex = 0;
    //std::cout << "Animation.cpp for " << sprite << ":" << " Sprite address: " << sprite << " Pointer address: " << &sprite << " baseSprite address: " << &baseSprite << " baseSprite's pointer address: " << "none" << std::endl;
}

/*
 * Updates sprite to next frame
 * Pre: frameList.size() > 0
 * Post: none
 */

void Animation::update() {
    // Tests precondition
    if (frameList.size() <= 0) {
        throw std::logic_error("Animation::update() error: Failed precondition. "
        "frameList.size() must be > 0");
    }

    if (frameList.size() > 1) {
        Frame* currentFrame = &frameList.at(frameIndex);
        elapsed += clock.getElapsedTime();

        if (elapsed.asSeconds() >= currentFrame->duration.asSeconds()) {
            frameIndex++;

            if (frameIndex >= frameList.size()) {
                frameIndex = 0;
            }
            std::cout << "Running frame.at at Animation::update()" << std::endl;
            Frame* nextFrame = &frameList.at(frameIndex);
            std::cout << "Finished frame.at at Animation::update()" << std::endl;
            sprite->setTextureRect(nextFrame->area);
            elapsed -= currentFrame->duration;
        }
    } else if (frameList.size() == 1) {
        Frame newFrame = frameList.at(0);
        sprite->setTextureRect(newFrame.area);
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
    frame.area = area;
    frame.duration = duration;

    //std::cout << "Animation: Now adding frame (area rect) at x = " << area.left << " y = " << area.top << " width = " << area.width << " height = " << area.height << " Sprite scale X: " << sprite->getScale().x << " Sprite scale Y: " << sprite->getScale().y << std::endl;

    frameList.push_back(frame);
    /*std::cout << "Animation: After adding frame: x = " << frameList.back().area.left << " y = " << frameList.back().area.top << " width = " << frameList.back().area.width << " height = " << frameList.back().area.height << " Sprite scale X: " << sprite->getScale().x << " Sprite scale Y: " << sprite->getScale().y << std::endl;
    std::cout << "End of adding frame for " << animationName << "\n" << std::endl;*/
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

    sprite->setTextureRect(frameList.at(0).area);
    frameIndex = 0;
    elapsed = sf::seconds(0);
    clock.restart();
}

Frame* Animation::getFrame(int index) {
    return &frameList.at(index);
}

int Animation::getNumOfFrames() {
    return frameList.size();
}

std::string Animation::getAnimationName() const{
    return animationName;
}

std::string Animation::getSpriteName() const{
    return spriteName;
}

/*
 * Changes base sprite used for animation
 * Pre: None
 * Post: None
 */
void Animation::changeBaseSprite(sf::Sprite& sprite) {
    this->sprite = nullptr;
    this->sprite = &sprite;
}