#include "SpriteSheet.h"
#include <cstddef>
#include <iostream>

/*
 * Initializes sprite sheet
 * Pre: none
 * Post: initializes textures and reads spritesheet config
 */
SpriteSheet::SpriteSheet(TextureManager* textures, const std::string& path):
textures(textures) {

    std::cout << "SpriteSheet constructor runs! " << std::endl;
    std::cout << "SpriteSheet: attempting to open " << path << std::endl;
    currentAnimation = "EMPTY";

    loadSheet(path);
}

/*SpriteSheet::SpriteSheet(const SpriteSheet& other) {
    textures = other.textures;
    animationList = other.animationList;
    currentAnimation = other.currentAnimation

    this->sprite = other.sp
}*/

/*
 * Updates current animation
 * Pre: currentAnimation must have a valid animation
 * Post: Updates current animation
 */
void SpriteSheet::update() {
    //std::cout << "SpriteSheet update() runs! " << std::endl;
    if (currentAnimation == "EMPTY") {
        return;
    } else if (animationList.count(currentAnimation) <= 0) {
        throw std::out_of_range("No animations present for: \"" + currentAnimation + "\" (Animation list is empty)");
    }

    std::cout << "Current Animation before segmentation fault: " << currentAnimation << std::endl;

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
        if (animationList.count(animation) == 0) {
            throw std::out_of_range("No animations present for: \"" + currentAnimation + "\"");
        }
        
        if (animationList.count(currentAnimation) == 1) {
            std::cout << "This runs!" << std::endl;
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
void SpriteSheet::loadSheet(const std::string path) {
    std::ifstream spriteFile(path);

    if (!spriteFile.good()) {
        throw std::invalid_argument("Error: Unable to open sprite config. Bad file");
    }

    std::cout << "SpriteSheet loadSheet runs! " << std::endl;
    while (spriteFile.good()) {
        const std::string COMMENT = "#";
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

            sprite.setTexture(*textures->getTexture(textureName));
        } else if (type == SIZE) {
            spriteFile >> size.x >> size.y;
        } else if (type == SCALE) {
            spriteFile >> scale.x >> scale.y;
            sprite.setScale(scale);
        }
    }
    std::cout << "End of adding sheet\n" << std::endl;
}

/*
 * Adds animation from start frame (inclusive)
 * to end frame (exclusive)
 * Pre: none
 * Post: Stores animations to list
 */
void SpriteSheet::addAnimation(std::ifstream& spriteFile) {
    std::string name;
    int startFrame;
    int endFrame;
    int row;
    std::string timeType;
    
    spriteFile >> name >> startFrame >> endFrame >> row >> timeType;
    std::cout << "SpriteSheet: addAnimation runs!" << std::endl;
    
    const std::string CONSTANTFRAMES = "CONSTANT";
    if (timeType == CONSTANTFRAMES) {
        // Gets time
        float time;
        spriteFile >> time;
        sf::Time timeAsSeconds = sf::seconds(time);
        std::cout << "startFrame: " << startFrame << " endFrame: " << endFrame << " row: " << row << " type: " << timeType << " time (float): " << time << "time (sec): " << timeAsSeconds.asSeconds() << std::endl;

        // Adds frames to animation
        Animation newAnimation(sprite, name);
        for (int frameIndex = startFrame; frameIndex < endFrame; frameIndex++) {
            int topGridX = frameIndex * size.x;
            int topGridY = row * size.y;
            int gridWidth = size.x;
            int gridHeight = size.y;

            std::cout << "SpriteSheet: Adding animation " + name << " at x = " << topGridX << " y = " << topGridY << " width = " << size.x << " height = " << size.y << std::endl;
            
            sf::IntRect spriteArea(topGridX, topGridY, gridWidth, gridHeight);
            newAnimation.addFrame(spriteArea, timeAsSeconds);

            
        }

        animationList.emplace(name, newAnimation);
    }
}

/*
 * Gets current sprite being used
 * Pre: none
 * Post: Returns current sprite reference
 */
sf::Sprite* SpriteSheet::getSprite() {
    return &sprite;
}