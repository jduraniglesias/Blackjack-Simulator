#ifndef SIMULATE_MENU_H
#define SIMULATE_MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

class SimulateMenu {
public:
    SimulateMenu(float width, float height);

    // Render the simulate menu (for now just the back button)
    void draw(sf::RenderWindow& window);

    // Handle input events if necessary (e.g., for other buttons)
    void handleEvent(sf::Event event);

    // Return true if the back command is triggered (Escape key pressed)
    bool goBack(sf::Event event);

private:
    sf::Font font;
    std::vector<sf::Text> options;
    int selectedIndex;
};

#endif // SIMULATE_MENU_H
