//
// Created by mrremrem on 6/29/22.
//

#include "WindowManager.h"
<<<<<<< HEAD
=======
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
>>>>>>> e58c56e (Hurrah! Binary Trees!)

// Creates a default 640x480 window
WindowManager::WindowManager() {
    setup("Untitled window", sf::Vector2u(640, 480));
}

// Creates window with default style
WindowManager::WindowManager(const std::string& title, const sf::Vector2u& size) {
    setup(title, size);
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
void WindowManager::setup(const std::string title, const sf::Vector2u size) {
    windowTitle = title;
    windowSize = size;
    isWindowFullscreen = false;
    isWindowTerminated = false;
    create();
}

// Processes events
void WindowManager::update() {
    sf::Event event;
<<<<<<< HEAD

=======
>>>>>>> e58c56e (Hurrah! Binary Trees!)
    // Processes all events
    while (window.pollEvent(event)){
        if (event.type == sf::Event::Closed){
            isWindowTerminated = true;
        } else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F5){
            toggleFullScreen();
<<<<<<< HEAD
=======
        } else if (event.type == sf::Event::Resized) {
            sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
            window.setView(sf::View(visibleArea));
>>>>>>> e58c56e (Hurrah! Binary Trees!)
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
    auto style = (isWindowFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    window.create({ windowSize.x, windowSize.y, 32}, windowTitle, style);
}

// Closes window
void WindowManager::destroy() {
    window.close();
}