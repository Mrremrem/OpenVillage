//
// Created by mrremrem on 12/24/22.
//

#include "SpriteSheet.h"

/*
 * Initializes sprite sheet
 * Pre: none
 * Post: initializes textures and reads spritesheet config
 */
SpriteSheet::SpriteSheet(ResourceManager<sf::Texture>& textures, const std::string& path):
textures(textures) {

    std::cout << "SpriteSheet constructor runs for " << name << "! " << std::endl;
    std::cout << "SpriteSheet: attempting to open " << path << std::endl;

    /*
     * Initializes every single sprite with "Default"
     * Assumes that every sprite has a "Default" animation
     */
    const std::string DEFAULT_ANIMATION_ID = "Default";
    currentAnimation = DEFAULT_ANIMATION_ID;

    loadSheet(path);
}

/*
 * SpriteSheet copy constructor. Used to update
 * animationList's sprite pointer to its copy
 * Pre: none
 * Post: none
 */
SpriteSheet::SpriteSheet(const SpriteSheet& other):
sprite(other.sprite),
name(other.name),
currentAnimation(other.currentAnimation),
size(other.size),
scale(other.scale),
animationList(other.animationList),
textures(other.textures) {
    sprite = sf::Sprite(other.sprite);

    for (auto otherAnimationIndex : other.animationList) {
        animationList.emplace(otherAnimationIndex.first, otherAnimationIndex.second);
        animationList.at(otherAnimationIndex.first).changeBaseSprite(sprite);
    }
}

/*
 * Updates current animation
 * Pre: currentAnimation must have a valid animation
 * Post: Updates current animation
 */
void SpriteSheet::update() {
    //std::cout << "SpriteSheet update() runs! " << std::endl;
    if (animationList.count(currentAnimation) <= 0) {
        throw std::out_of_range("No animations present for: \"" + currentAnimation + "\" for sprite \"" + name + "\" (Animation list is empty)");
    }

    //std::cout << "SpriteSheet.cpp: Updating sprite " << name << " with animation " << currentAnimation << " Scale: " << sprite.getScale().x << ", " << sprite.getScale().y << " SpriteSheet.cpp: Sprite address: " << &sprite << std::endl;
    //std::cout << "SpriteSheet.cpp: Updating new sprite " << name << " with sprite address: " << &sprite << std::endl;
    //std::cout << "SpriteSheet.cpp: updating all animations for " << name << " with animationList.size() = " << animationList.size();
    animationList.at(currentAnimation).update();
    //std::cout << "SpriteSheet update() ends! " << std::endl;
}

/*
 * Renders animated/non animated sprite
 * Pre: none
 * Post: none
 */
void SpriteSheet::render(sf::RenderWindow &window) {
    window.draw(sprite);
}

/*
 * Sets current animation for sprite
 * Pre: currentAnimation must have a valid animation
 * Post: sets current animation for sprite
 */
void SpriteSheet::setAnimation(const std::string& animation) {
    if (animation != currentAnimation) {
        // animation does not exist (ex: Z_axis_walking_animation)
        if (animationList.count(animation) == 0) {
            throw std::out_of_range("No animations present for: \"" + animation 
            + "\" for sprite \"" + name + "\".");
        }
        
        if (animationList.count(currentAnimation) == 1) {
            animationList.at(currentAnimation).reset();
        }
        
        currentAnimation = animation;
        animationList.at(currentAnimation).reset();
    }
}

/*
 * Loads sprite info from file
 * Pre: none
 * Post: Sets up spritesheet config
 */
void SpriteSheet::loadSheet(const std::string& path) {
    std::ifstream spriteFile(path);

    if (!spriteFile.good()) {
        throw std::invalid_argument("SpriteSheet.cpp:loadSheet: Unable to open sprite config. Bad file");
    }

    //std::cout << "SpriteSheet.cpp:loadSheet: SpriteSheet loadSheet runs! " << std::endl;
    while (spriteFile.good()) {
        const std::string COMMENT = "#";
        const std::string NAME = "NAME";
        const std::string SIZE = "SIZE";
        const std::string SCALE = "SCALE";
        const std::string ADD_ANIMATION = "ANIMATION";
        const std::string TEXTURE = "TEXTURE";

        // Retrieves current type
        std::string type;
        spriteFile >> type;

        if (type == ADD_ANIMATION) {
            addAnimation(spriteFile);
        } else if (type == COMMENT) {
            // Ignores name and comment
            std::string storeComment;
            std::getline(spriteFile, storeComment);
        } else if (type == TEXTURE) {
            std::string textureName;
            spriteFile >> textureName;

            sprite.setTexture(*textures.getResource(textureName));
        } else if (type == SIZE) {
            spriteFile >> size.x >> size.y;
        } else if (type == SCALE) {
            spriteFile >> scale.x >> scale.y;
            // CHECK THIS SCALE IF THEY"RE BEING INPUTTED CORRECTLY@@@
            sprite.setScale(scale);
        } else if (type == NAME) {
            spriteFile >> name;
        }
    }

    //std::cout << "SpriteSheet.cpp:loadSheet: End of adding sheet\n" << std::endl;
    std::cout << "SpriteSheet: Current sprite: " << name << ". Original sprite address: " << &sprite << std::endl;
}

/*
 * Adds animation from start frame (inclusive)
 * to end frame (exclusive)
 * Pre: none
 * Post: Stores animations to list
 */
void SpriteSheet::addAnimation(std::ifstream& spriteFile) {
    std::string animationName;
    int startFrame;
    int endFrame;
    int row;
    std::string timeType;
    
    spriteFile >> animationName >> startFrame >> endFrame >> row >> timeType;
    std::cout << "SpriteSheet: addAnimation runs!" << std::endl;
    
    const std::string CONSTANTFRAMES = "CONSTANT";
    if (timeType == CONSTANTFRAMES) {
        // Gets time
        float time;
        spriteFile >> time;
        sf::Time timeAsSeconds = sf::seconds(time);
        std::cout << "startFrame: " << startFrame << " endFrame: " << endFrame << " row: " << row << " type: " << timeType << " time (float): " << time << "time (sec): " << timeAsSeconds.asSeconds() << std::endl;

        // Adds frames to animation
        Animation newAnimation(sprite, animationName, name);
        for (int frameIndex = startFrame; frameIndex < endFrame; frameIndex++) {
            int topGridX = frameIndex * size.x;
            int topGridY = row * size.y;
            int gridWidth = size.x;
            int gridHeight = size.y;

            std::cout << "SpriteSheet for " << name << ": Adding animation " + animationName << " at x = " << topGridX << " y = " << topGridY << " width = " << size.x << " height = " << size.y << std::endl;
            
            sf::IntRect spriteArea(topGridX, topGridY, gridWidth, gridHeight);
            newAnimation.addFrame(spriteArea, timeAsSeconds);
        }

        animationList.emplace(animationName, newAnimation);
    }
}

/*
 * Gets current sprite being used
 * Pre: none
 * Post: Returns current sprite reference
 */
sf::Sprite& SpriteSheet::getSprite() {
    return sprite;
}

Animation* SpriteSheet::getAnimation(const std::string& animationName) {
    return &animationList.at(animationName);
}

std::string SpriteSheet::getName() {
    return name;
}