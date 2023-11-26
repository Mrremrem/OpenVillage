//
// Created by mrremrem on 6/30/22.
//

#include "HomeVillage.h"
#include "DebugLog.h"
#include "Entity.h"
#include "Player.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>
#include <vector>
HomeVillage::HomeVillage(ResourceManager<sf::Texture>& textures, 
ResourceManager<sf::Font>& fonts, 
std::vector<sf::View>& playerViewsList):
    worldMap(textures, fonts, TILE_CONFIG_DIR, playerViewsList),
    viewDebugLog(fonts),
    playerViewsList(playerViewsList) {

    //worldMap.addLayer(WORLD_MAP_DIR);
    worldMap.initializeMap(WORLD_MAP_DIR);
    //worldMap.addLwindow.setView(window.getDefaultView());vayer(ENTITY_MAP_DIR);
} // QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ

/*
 * Returns block size
 * Pre: none
 * Post: Returns BLOCK_SIZE
 */
int HomeVillage::getBlockSize() {
    return BLOCK_SIZE;
}

void HomeVillage::handleInput() {
    //redMan.handleInput();
}

/*
 * Updates map, views, and player collisions
 * Pre: none
 * Post: calls worldMap's update()
 */
void HomeVillage::update(sf::RenderWindow& window) {
    worldMap.update();
    updatePlayerViews(window);

    updatePlayerCollisions();
}

/*
 * Sets view and renders map
 * Pre: none
 * Post: calls worldMap's render()
 */
void HomeVillage::render(sf::RenderWindow& window) {
    window.setView(window.getDefaultView());
    worldMap.render(window);
}

/*
 * Updates player views
 * Pre: none
 * Post: Updates each player view's aspect ratio
 */
void HomeVillage::updatePlayerViews(sf::RenderWindow& window) {
    for (sf::View& viewIndex : playerViewsList) {
        sf::Vector2f oldCenter(viewIndex.getCenter());
        sf::Vector2f newSize(window.getSize().x, window.getSize().y);
        
        viewIndex.setSize(newSize);
        viewIndex.setCenter(oldCenter);

        viewIndex.setViewport(sf::FloatRect(0, 0, 1, 1));
    }
}

/*
 * Updates player collisions with other entities
 * Pre: none
 * Post: Updates entities if there's player collision
 */
void HomeVillage::updatePlayerCollisions() {
    std::vector<Entity*> playerList = 
        worldMap.getEntityList().getEntityTypeList(EntityType::Player);
    std::vector<Entity*> signList = 
        worldMap.getEntityList().getEntityTypeList(EntityType::Sign);

    int i = 0;
    std::cout << "playerList.size(): " << playerList.size() << " signList.size(): " << signList.size() << std::endl;
    for (Entity* playerIndex : playerList) {
        Player* currentPlayer = static_cast<Player*>(playerIndex);
        std::cout << "Loop running for player" << i << std::endl; i++;
        for (Entity* signIndex : signList) {
            Sign* currentSign = static_cast<Sign*>(signIndex);
            if (currentPlayer->isColliding(currentSign->getCollisionBox())) {
                EventManager::getInstance().publish("PlayerCollision");
                EventManager::getInstance().publish("SignCollision");
                std::cout << "Hey there's collision!\n" << std::endl;
            }
        }

        // Add more entities below
    }
}

// Yeah, I don't really need this anymore, but I'll get rid of it later
// (I still want to use the dialogue for future testing :P)
/*
void HomeVillage::setupTextbox() {
    //textbox.addText("QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ"
    //                "QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ");
    textbox.addPage("lllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllll"
                    "lllllllllllllllllllllllllllllllllllll");
    textbox.addPage("Lorem ipsum dolor sit amet, consectetur adipiscing elit,"
                    " sed do eiusmod tempor incididunt ut labore et dolore magna aliqua."
                    " Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris"
                    " nisi ut aliquip ex ea commodo consequat.");
    textbox.addPage("WHOAAA!");
    textbox.addPage("This is pretty cool! I can finally talk!");
    textbox.addPage("It's been awhile since I could express my thoughts."
                    " I'm       normally the protagonist so I really just go with the"
                    " flow and listen to anyone that helps me progress through my"
                    "         adventures. "
                    "Just like that guy Ash Ketchup.");
    textbox.addPage("Come to think of it, I only read text bubbles most of the     time."
                    " I don't even know if I've heard some toad's voice at   all."
                    " Now that I think of it, that fairy that flew next to    that green"
                    " warrior spoke to me once...");
    textbox.addPage("The fairy said something about \"Hey listen!\" and"
                    " how Hyrule   was falling apart and how it nee d my help to save"
                    " a chick  named Zoolda.");
    textbox.addPage("My mind went away after that.");
    textbox.addPage("You know, it's been pretty windy since this large ocean of    water"
                    " appeared out of nowhere. It's hitting directly at my   silky smooth"
                    " hair, too.");
    textbox.addPage("Speaking of sexy, I think I can also make my voice a bit      deeper...");
    textbox.addPage("This is Mr. Narrator speaking. As you can see, Redman has     entirely lost"
                    " focused on his role by trying to prove that he is a dominant hombre."
                    " We shall wait until he stops his       ramblings about his \'masculinity.\'");
    textbox.addPage("Also, being a narrator does give me a really nice narrator    voice,"
                    " don't you think?");
    textbox.addPage("And that's how I met your mother!");
    textbox.addPage("...");
    textbox.addPage("I wonder if I was made by nature or a creator...");
    textbox.setFont("DynaPuff");
    //textbox.addText(test1);
}*/