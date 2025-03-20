#include "SimulateMenu.h"

SimulateMenu::SimulateMenu(float width, float height) {
    if (!font.openFromFile("assets/ttfFont.ttf")) {
        std::cout << "Font not found!" << std::endl;
    }
    sf::Text backButton(font, "Back", 50);
    backButton.setFillColor(sf::Color::White);
    backButton.setPosition(sf::Vector2f(10.f, height - 70.f));
    options.push_back(backButton);
}

void SimulateMenu::draw(sf::RenderWindow& window) {
    window.draw(options[0]);
}

void SimulateMenu::handleEvent(sf::Event event, sf::RenderWindow& window) {
    if (event.is<sf::Event::MouseMoved>()) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        for (int i = 0; i < options.size(); i++) {
            if (options[i].getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
                options[selectedIndex].setFillColor(sf::Color::Yellow);
                selectedIndex = i;
            }
            else {
                options[i].setFillColor(sf::Color::White);
            }
        }
    }
}

SimulateMenu::Option SimulateMenu::getSelectedOption() const {
    switch (selectedIndex) {
    case 0: return Option::BACK;
    default: return Option::NONE;
    }
}


