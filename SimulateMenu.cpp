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

void SimulateMenu::handleEvent(sf::Event event) {
}

bool SimulateMenu::goBack(sf::Event event) {
    if (const auto keyReleased = event.getIf<sf::Event::KeyReleased>()) {
        if (keyReleased->scancode == sf::Keyboard::Scancode::Escape) {
            return true;
        }
    }
    return false;
}
