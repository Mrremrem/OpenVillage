#include "HealthBar.h"

HealthBar::HealthBar() {

}

HealthBar::HealthBar(int bars) {

}

void HealthBar::render(sf::RenderWindow &window) {
    window.draw(sprite);
}

int HealthBar::getNumOfBars() {
    return numOfBars;
}