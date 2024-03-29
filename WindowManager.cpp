//
// Created by mrremrem on 6/29/22.
//

#include "WindowManager.h"
#include "Tile.h"
#include <SFML/Config.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>

// Creates a default 640x480 window
WindowManager::WindowManager() {
    setup("Untitled window", sf::Vector2u(640, 480), sf::Style::Default);
}

// Creates window with default style
WindowManager::WindowManager(const std::string& title, const sf::Vector2u& size) {
    setup(title, size, sf::Style::Default);
}

// Creates window with provided style
WindowManager::WindowManager(const std::string& title, const sf::Vector2u& size,
 sf::Uint32 style) {
    setup(title, size, style);
}

// Closes window
WindowManager::~WindowManager() {
    destroy();
}

// Clears window
void WindowManager::beginDraw() {
    window.clear(sf::Color::Black);
}

// Adds drawable object to window buffer
void WindowManager::draw(sf::Drawable &drawable) {
    window.draw(drawable);
}

// Displays window
void WindowManager::endDraw() {
    window.display();
}

// Sets instances and creates window
void WindowManager::setup(const std::string title, const sf::Vector2u size, sf::Uint32 style) {
    windowTitle = title;
    windowSize = size;
    windowStyle = style;

    isWindowFullscreen = false;
    isWindowTerminated = false;

    create();
}

// Processes events
void WindowManager::update() {
    sf::Event event;
    // Processes all events
    while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed) {
            isWindowTerminated = true;
        } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5){
            toggleFullScreen();
        } else if (event.type == sf::Event::Resized) {
            sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
            window.setView(sf::View(visibleArea));
        }
    }
}

void WindowManager::toggleFullScreen() {
    isWindowFullscreen = !isWindowFullscreen;
    destroy();
    create();
}

bool WindowManager::isTerminated() {
    return isWindowTerminated;
}

bool WindowManager::isFullScreen() {
    return isWindowFullscreen;
}

sf::Vector2u WindowManager::getWindowSize() {
    return windowSize;
}

sf::RenderWindow* WindowManager::getRenderWindow() {
    return &window;
}

// Creates window
void WindowManager::create() {
    window.create(sf::VideoMode::getDesktopMode(), windowTitle, windowStyle);

    const int BITS_PER_PIXEL = 32;
    window.create({ windowSize.x, windowSize.y, BITS_PER_PIXEL}, windowTitle, windowStyle);
}

// Closes window
void WindowManager::destroy() {
    window.close();
}