#ifndef PLAY_MENU_H
#define PLAY_MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

class PlayMenu {
public:

    enum class Option { BACK, NONE };

    PlayMenu(float width, float height);

    void draw(sf::RenderWindow& window);

    void handleEvent(sf::Event event, sf::RenderWindow& window);

    Option getSelectedOption() const;

private:
    sf::Font font;
    std::vector<sf::Text> options;
    int selectedIndex;
};

#endif // PLAY_MENU_H
