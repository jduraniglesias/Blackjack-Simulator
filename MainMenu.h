#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class MainMenu {
public:
    enum class Option { PLAY, SIMULATE, EXIT, NONE };

    MainMenu(float width, float height);
    ~MainMenu();

    void draw(sf::RenderWindow& window);
    void handleEvent(sf::Event event, sf::RenderWindow& window);

    Option getSelectedOption() const;
    sf::FloatRect getSelectedOptionPos() const;

private:
    std::vector<sf::Text> options;
    sf::Font font;
    int selectedIndex;
};

#endif // MAIN_MENU_H
