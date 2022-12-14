//
// Created by mrremrem on 6/30/22.
//

#include "HomeVillage.h"
#include "Map.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

HomeVillage::HomeVillage(sf::Vector2u windowSize):
        worldMap(TEXTURE_DIR, sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE), SPRITE_SIZE),
        windowSize(windowSize),
        textbox() {

    setupTextbox();
    worldMap.addLayer(WORLD_MAP_DIR);
    worldMap.addLayer(ENTITY_MAP_DIR);
} // QQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ

HomeVillage::~HomeVillage() {
    // Empty
}

int HomeVillage::getBlockSize() {
    return BLOCK_SIZE;
}

void HomeVillage::update(sf::RenderWindow& window, Player &player) {
    if (player.getDirection() != Direction::None){
        player.move();
    }

    // Sets player in middle of view
    player.setPosition(player.getCameraView().getCenter());

    updateTextbox(window);
}

void HomeVillage::render(sf::RenderWindow &window) {
    worldMap.render(window);
    textbox.render(window);
}

void HomeVillage::updateTextbox(sf::RenderWindow& window) {
    // Textbox controls

    //
    updateTextboxControls(window);
    updateTextboxArea(window);
    textbox.update();
}

void HomeVillage::updateTextboxControls(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed){
            switch (event.key.code) {
                case sf::Keyboard::T:
                    textbox.setPageNumber(0);
                    textbox.setVisibility(true);
                    break;
                case sf::Keyboard::Return:
                    textbox.next();
                    break;
                case sf::Keyboard::Space:
                    textbox.next();
                    break;
                case sf::Keyboard::Escape:
                    textbox.previous();
                    break;
            }
        }
    }
}

void HomeVillage::updateTextboxArea(sf::RenderWindow& window) {
    const int BOX_WIDTH = 22; // 22
    const int BOX_HEIGHT = 4; // 4
    sf::Vector2f boxSize(SPRITE_DISTANCE * BOX_WIDTH, SPRITE_DISTANCE * BOX_HEIGHT);
    sf::Vector2f boxPosition(window.mapPixelToCoords(
            sf::Vector2i(SPRITE_DISTANCE, windowSize.y - SPRITE_DISTANCE * BOX_HEIGHT)));

    textbox.setSize(boxSize);
    textbox.setPosition(boxPosition);
}

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
}