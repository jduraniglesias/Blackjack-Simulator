#ifndef SIMULATE_MENU_H
#define SIMULATE_MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

class SimulateMenu {
public:

    enum class Option { BACK, NONE };

    SimulateMenu(float width, float height);

    void draw(sf::RenderWindow& window);

    void handleEvent(sf::Event event, sf::RenderWindow& window);

    Option getSelectedOption() const;


private:
    sf::Font font;
    std::vector<sf::Text> options;
    int selectedIndex;
};

#endif // SIMULATE_MENU_H
