//
// Created by mrremrem on 7/14/22.
//

#include "TextBox.h"

TextBox::TextBox(ResourceManager<sf::Font>& fonts):
fonts(fonts) {
    // Sets up backdrop with default arguments
    const float DEFAULT_THICKNESS = 6.f;
    const sf::Vector2f DEFAULT_POSITION = sf::Vector2f(1000, 1000);
    const sf::Vector2f DEFAULT_AREA = sf::Vector2f(1700, 250);
    const sf::Color LIGHT_BROWN = sf::Color(252, 219, 143);
    const sf::Color DARK_BROWN = sf::Color(226,192,113);
    position = DEFAULT_POSITION;
    size = DEFAULT_AREA;
    backdropColor = LIGHT_BROWN;
    outlineColor = DARK_BROWN;
    outlineThickness = DEFAULT_THICKNESS;
}

TextBox::~TextBox() {
    // Empty
}

// Remind me why this was needed . _.
/*
 * So this is what I'm gonna organize
 * addText just adds text to 
 */
/*void TextBox::addText(std::string text){
    // Adds newlines for every line
    numOfLines = text.size() / getMaxCharsPerLine();
    newlineText(text);

    // Adds pages for every nth lines that exceeds max # of lines
    int totalPages = numOfLines / getMaxLinesPerPage() + 1 + numOfPages;
    addPages(text, totalPages);
    numOfPages += totalPages;

} // Also make add page*/

void TextBox::addPage(std::string text) {
    numOfLines = text.size() / getMaxCharsPerLine();
    newlineText(text);

    // Adds pages for every nth lines that exceeds max # of lines
    int totalPages = 1;
    addPages(text, totalPages);
    numOfPages += totalPages;
}

void TextBox::addPages(std::string& text, int totalPages) {
    //numOfLines = text.size() / getMaxCharsPerLine();
    //numOfPages = numOfLines / getMaxLines() + 1;
    // Places each paragraph into pages
    for (int pageIndex = 0; pageIndex < totalPages; pageIndex++){
        int minSubstring = getMaxCharsPerLine() * getMaxLinesPerPage() * pageIndex;
        int maxSubstring = getMaxCharsPerLine() * getMaxLinesPerPage();

        /* String concatination in C++ is O(1)(maybe?)
         * ^ according to the few stackoverflow sources
         * I briefly looked over (if so wow!)
         * So theoretically this should be okay
         * But lmk if I'm making this O(N^2) (to
         * the CS majors who are reading me, hi)
        */
        std::string pageText = text.substr(minSubstring, maxSubstring);
        pages.push_back(pageText);
    }
}

int TextBox::getMaxCharsPerLine() {
    /*
     * Let me explain how I got numbers 1760 and 65
     * I just used a random width such as 1760
     * The number of characters that looked good is 65 (for that width)
     * So I just made a proportion that works with those numbers that looked good:
     * 1760/65 = width/characters
     * So I just plug in an arbitrary width and solve for the # of characters for 
     * that arbitrary width :)
     */
    const int REFERENCE_NUM_OF_CHARACTERS = 65;
    const int REFERENCE_WIDTH = 1760;

    return REFERENCE_NUM_OF_CHARACTERS * size.x / REFERENCE_WIDTH;
}

int TextBox::getMaxLinesPerPage() {
    /*
     * ^ See getMaxCharsPerLine() for details ^
     * ^ on how I got these constants   :3    ^
     */
    const int REFERENCE_NUM_OF_LINES = 4;
    const int REFERENCE_HEIGHT = 250;

    return REFERENCE_NUM_OF_LINES * size.y / REFERENCE_HEIGHT;
}

void TextBox::newlineText(std::string& text) {
    // Adds \n for every line
    for (int lineIndex = 1; lineIndex <= numOfLines; lineIndex++){
        // Checks if max lines have been reached (from page)
        if (lineIndex % getMaxLinesPerPage() != 0){
            int newlinePos = lineIndex * getMaxCharsPerLine();
            text.insert(newlinePos, "\n");
        }
    }
}

void TextBox::setFont(std::string name) {
    sf::Font* currentFont = fonts.getResource(name);
    content.setFont(*currentFont);
}

/*
 * Increments a page
 * Pre: none
 * Post: numOfPages = numOfPages + 1
 */
void TextBox::next() {
    // Tests if page # exceeds max page number
    if (currentPage + 1 < numOfPages) {
        currentPage++;
        numOfTextDisplayed = 0;
    } else {
        toggleVisibility();
    }
}

/*
 * Decrements a page
 * Pre: none
 * Post: numOfPages = numOfPages - 1
 */
void TextBox::previous() {
    // Tests if page # goes below zero
    if (currentPage - 1 >= 0) {
        currentPage--;
        numOfTextDisplayed = 0;
    }
}

void TextBox::setPageNumber(int pageIndex) {
    numOfTextDisplayed = 0;
    currentPage = pageIndex;
}

void TextBox::setBackdropColor(sf::Color color) {
    backdropColor = color;
}

void TextBox::setOutlineColor(sf::Color color) {
    outlineColor = color;
}

void TextBox::setPosition(sf::Vector2f position) {
    this->position = position;
}

void TextBox::setSize(sf::Vector2f area) {
    size = area;
}

void TextBox::setOutlineThickness(float thickness) {
    outlineThickness = thickness;
}

void TextBox::setVisibility(bool isVisible) {
    this->isVisible = isVisible;
}

void TextBox::toggleVisibility() {
    isVisible = !isVisible;
}

int TextBox::getPageNumber() {
    return currentPage;
}

sf::Vector2f TextBox::getPosition() {
    return position;
}

sf::Vector2f TextBox::getSize() {
    return size;
}

void TextBox::update() {
    // Checks if textbox is visible
    if (!isVisible){
        return;
    }

    updateBackdrop();
    updateText();
}

void TextBox::updateBackdrop() {
    // Sets backdrop
    backdrop.setFillColor(backdropColor);
    backdrop.setOutlineColor(outlineColor);
    backdrop.setOutlineThickness(outlineThickness);
    backdrop.setPosition(position);
    backdrop.setSize(size);
}

void TextBox::updateText() {
    const int SPACE_FROM_WIDTH = 20;
    const int SPACE_FROM_HEIGHT = 10;
    content.setPosition(position.x + SPACE_FROM_WIDTH, position.y + SPACE_FROM_HEIGHT);
    content.setCharacterSize(DEFAULT_CHARACTER_SIZE);
    content.setFillColor(sf::Color::Black);

    // Checks if there's at least one page
    if (!pages.empty()) {
        // Checks if more text should be shown
        std::string text = pages.at(currentPage);
        if (numOfTextDisplayed < text.size()) {
            numOfTextDisplayed++;
        }

        // Sets text to be displayed
        content.setString(text.substr(0, numOfTextDisplayed));
    }
}

void TextBox::render(sf::RenderWindow& window) {
    // Checks if textbox is visible
    if (!isVisible){
        return;
    }

    window.draw(backdrop);
    window.draw(content);
}