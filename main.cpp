#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "SimulateMenu.h"
#include "PlayMenu.h"

enum class GameState { MAIN_MENU, PLAY, SIMULATE };

int main() {
    sf::RenderWindow window(sf::VideoMode({ 960, 720 }), "Game");
    sf::RectangleShape menuBackground;
    sf::RectangleShape settingsBackground;
    menuBackground.setSize(sf::Vector2f(960.f, 720.f));
    settingsBackground.setSize(sf::Vector2f(960.f, 720.f));
    sf::Texture menuBackgroundImage;
    sf::Texture settingsBackgroundImage;
    menuBackgroundImage.loadFromFile("assets/mainMenuBackground.jpg");
    settingsBackgroundImage.loadFromFile("assets/settingsBackground.png");
    menuBackground.setTexture(&menuBackgroundImage);
    settingsBackground.setTexture(&settingsBackgroundImage);

    MainMenu mainMenu(960, 720);
    SimulateMenu simulateMenu(960, 720);
    PlayMenu playMenu(960, 720);
    
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
                simulateMenu.handleEvent(*event, window);
                if (const auto* mouseButton = event->getIf<sf::Event::MouseButtonReleased>()) {
                    if (mouseButton->button == sf::Mouse::Button::Left) {
                        SimulateMenu::Option selected = simulateMenu.getSelectedOption();
                        if (selected == SimulateMenu::Option::BACK) {
                            currState = GameState::MAIN_MENU;
                        }
                    }
                }
                break;

            case GameState::PLAY:
                if (const auto* mouseButton = event->getIf<sf::Event::MouseButtonReleased>()) {
                    if (mouseButton->button == sf::Mouse::Button::Left) {
                        PlayMenu::Option selected = playMenu.getSelectedOption();
                        if (selected == PlayMenu::Option::BACK) {
                            currState = GameState::MAIN_MENU;
                        }
                    }
                }
                break;
            }
        }

        window.clear();
        switch (currState) {
        case GameState::MAIN_MENU:
            window.draw(menuBackground);
            mainMenu.draw(window);
            break;
        case GameState::SIMULATE:
            window.draw(settingsBackground);
            simulateMenu.draw(window);
            break;
        case GameState::PLAY:
            window.draw(settingsBackground);
            playMenu.draw(window);
            break;
        }

        window.display();
    }
    return 0;
}
