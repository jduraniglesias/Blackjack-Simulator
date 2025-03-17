#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "SimulateMenu.h"

enum class GameState { MAIN_MENU, PLAY, SIMULATE };

int main() {
    sf::RenderWindow window(sf::VideoMode({ 960, 720 }), "Game");
    sf::RectangleShape background;
    background.setSize(sf::Vector2f(960.f, 720.f));
    sf::Texture backgroundImage;
    backgroundImage.loadFromFile("assets/mainMenuBackground.jpg");
    background.setTexture(&backgroundImage);

    MainMenu mainMenu(960, 720);
    SimulateMenu simulateMenu(960, 720);
    
    GameState currState = GameState::MAIN_MENU;

    window.setMouseCursorVisible(true);
    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            switch (currState) {
            case GameState::MAIN_MENU:
                mainMenu.handleEvent(*event, window);
                if (const auto* mouseButton = event->getIf<sf::Event::MouseButtonReleased>()) {
                    if (mouseButton->button == sf::Mouse::Button::Left) {
                        MainMenu::Option selected = mainMenu.getSelectedOption();
                        if (selected == MainMenu::Option::PLAY) {
                            currState = GameState::PLAY;
                        }
                        else if (selected == MainMenu::Option::SIMULATE) {
                            currState = GameState::SIMULATE;
                        }
                        else if (selected == MainMenu::Option::EXIT) {
                            window.close();
                        }
                    }
                }
                break;

            case GameState::SIMULATE:
                simulateMenu.handleEvent(*event);
                if (simulateMenu.goBack(*event)) {
                    currState = GameState::MAIN_MENU;
                }
                break;

            case GameState::PLAY:
                if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>()) {
                    if (keyReleased->scancode == sf::Keyboard::Scancode::Escape) {
                        currState = GameState::MAIN_MENU;
                    }
                }
                break;
            }
        }

        window.clear();
        switch (currState) {
        case GameState::MAIN_MENU:
            window.draw(background);
            mainMenu.draw(window);
            break;
        case GameState::SIMULATE:
            simulateMenu.draw(window);
            break;
        case GameState::PLAY:
            break;
        }

        window.display();
    }
    return 0;
}
