//
// Created by mrremrem on 3/6/22.
//

#ifndef OPENVILLAGE_WINDOWMANAGER_H
#define OPENVILLAGE_WINDOWMANAGER_H

#include "SFML/Graphics.hpp"
#include <cstring>


class WindowManager {
public:
    // Creates a default 640x480 window
    WindowManager();

    // Creates window with default style
    WindowManager(const std::string& title, const sf::Vector2u& size);

    // Closes window
    ~WindowManager();

    void beginDraw(); // Clears window
    void draw(sf::Drawable& drawable); // Adds drawable object to window buffer
    void endDraw(); // Displays window
    void update(); // Processes events

    bool isTerminated();
    bool isFullScreen();

    sf::Vector2u getWindowSize();
    sf::RenderWindow* getRenderWindow();

    void toggleFullScreen(); // Toggles fullscreen

private:
    void setup(const std::string title, const sf::Vector2u size); // Sets instances and creates window
    void create(); // Creates window
    void destroy(); // Closes window

    // SFML window (different when making a new object)
    sf::RenderWindow window;
    std::string windowTitle;
    sf::Vector2u windowSize;
    bool isWindowFullscreen;
    bool isWindowTerminated;
};

#endif //OPENVILLAGE_WINDOWMANAGER_H