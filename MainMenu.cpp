#include "MainMenu.h"

MainMenu::MainMenu(float width, float height) : selectedIndex(0) {
    if (!font.openFromFile("assets/ttfFont.ttf")) {
        std::cout << "Font not found!" << std::endl;
    }

    sf::Text playText(font, "Play", 70);
    playText.setFillColor(sf::Color::Yellow);
    playText.setPosition(sf::Vector2f(100.f, 200.f));

    sf::Text simulateText(font, "Simulate", 70);
    simulateText.setFillColor(sf::Color::White);
    simulateText.setPosition(sf::Vector2f(100.f, 300.f));

    sf::Text exitText(font, "Exit", 70);
    exitText.setFillColor(sf::Color::White);
    exitText.setPosition(sf::Vector2f(100.f, 400.f));

    options.push_back(playText);
    options.push_back(simulateText);
    options.push_back(exitText);
}

MainMenu::~MainMenu() {

}

void MainMenu::draw(sf::RenderWindow& window) {
    for (const auto& option : options) {
        window.draw(option);
    }
}

void MainMenu::handleEvent(sf::Event event, sf::RenderWindow& window) {
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

MainMenu::Option MainMenu::getSelectedOption() const {
    switch (selectedIndex) {
    case 0: return Option::PLAY;
    case 1: return Option::SIMULATE;
    case 2: return Option::EXIT;
    default: return Option::NONE;
    }
}

sf::FloatRect MainMenu::getSelectedOptionPos() const {
    return options[selectedIndex].getGlobalBounds();
}
