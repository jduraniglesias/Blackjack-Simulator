#include "PlayMenu.h"

PlayMenu::PlayMenu(float width, float height) {
    if (!font.openFromFile("assets/ttfFont.ttf")) {
        std::cout << "Font not found!" << std::endl;
    }
    sf::Text backButton(font, "Back", 50);
    sf::Text playButton(font, "Play", 50);
    backButton.setFillColor(sf::Color::White);
    backButton.setPosition(sf::Vector2f(10.f, height - 70.f));
    playButton.setFillColor(sf::Color::White);
    playButton.setPosition(sf::Vector2f(width / 2.1f, height - (height / 2.5f)));
    options.push_back(backButton);
    options.push_back(playButton);
}

void PlayMenu::draw(sf::RenderWindow& window) {
    for (int i = 0; i < options.size(); i++) {
        window.draw(options[i]);
    }
} 

void PlayMenu::handleEvent(sf::Event event, sf::RenderWindow& window) {
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

PlayMenu::Option PlayMenu::getSelectedOption() const {
    switch (selectedIndex) {
    case 0: return Option::BACK;
    case 1: return Option::START;
    default: return Option::NONE;
    }
}

