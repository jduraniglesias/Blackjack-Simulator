#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class MainMenu {
public:
    // An enum to track the different options
    enum class Option { PLAY, SIMULATE, EXIT, NONE };

    MainMenu(float width, float height);
    ~MainMenu();

    // Render the menu items
    void draw(sf::RenderWindow& window);

    // Handle input events (up, down, etc.)
    void handleEvent(sf::Event event);

    // Return the option selected when Enter is pressed
    Option getSelectedOption() const;

private:
    std::vector<sf::Text> options;
    sf::Font font;
    int selectedIndex;
};

#endif // MAIN_MENU_H
