#include "MainMenu.h"

MainMenu::MainMenu(float width, float height) : selectedIndex(0) {
    if (!font.openFromFile("assets/ttfFont.ttf")) {
        std::cout << "Font not found!" << std::endl;
    }

    // Create Play option
    sf::Text playText(font, "Play", 70);
    playText.setFillColor(sf::Color::Yellow);
    playText.setPosition(sf::Vector2f(100.f, 200.f));

    // Create Simulate option
    sf::Text simulateText(font, "Simulate", 70);
    simulateText.setFillColor(sf::Color::White);
    simulateText.setPosition(sf::Vector2f(100.f, 300.f));

    // Create Exit option
    sf::Text exitText(font, "Exit", 70);
    exitText.setFillColor(sf::Color::White);
    exitText.setPosition(sf::Vector2f(100.f, 400.f));

    options.push_back(playText);
    options.push_back(simulateText);
    options.push_back(exitText);
}

MainMenu::~MainMenu() {
    // Cleanup if necessary
}

void MainMenu::draw(sf::RenderWindow& window) {
    for (const auto& option : options) {
        window.draw(option);
    }
}

void MainMenu::handleEvent(sf::Event event) {
    if (const auto keyReleased = event.getIf<sf::Event::KeyReleased>()) {
        if (keyReleased->scancode == sf::Keyboard::Scancode::Up) {
            options[selectedIndex].setFillColor(sf::Color::White);
            selectedIndex = (selectedIndex == 0) ? options.size() - 1 : selectedIndex - 1;
            options[selectedIndex].setFillColor(sf::Color::Yellow);
        }
        else if (keyReleased->scancode == sf::Keyboard::Scancode::Down) {
            options[selectedIndex].setFillColor(sf::Color::White);
            selectedIndex = (selectedIndex + 1) % options.size();
            options[selectedIndex].setFillColor(sf::Color::Yellow);
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
